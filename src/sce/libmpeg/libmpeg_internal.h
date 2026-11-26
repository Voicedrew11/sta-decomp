/*
 * sce/libmpeg/libmpeg_internal.h  (derived name: the file name is ours)
 *
 * libmpeg's declarations that are not public SDK API: the decoder's shared
 * state (var.o's and init.o's globals) and the helpers the members call
 * across files.  Each declaration is the definition's in sce/libmpeg.  A
 * reference image (_refFrame0 and the rest, 26 ints) is passed as the int
 * pointer var.o declares it.
 */
#ifndef SCE_LIBMPEG_LIBMPEG_INTERNAL_H
#define SCE_LIBMPEG_LIBMPEG_INTERNAL_H

#include <libipu.h>

/* one entry of the callback table, by callback type */
typedef struct { /* field names derived */
    sceMpegCallback func;
    void *data;
} MpegCb; /* derived name */

/* the arena the frame buffers and the stream-callback table are allocated
 * out of: the work area after the decoder record.  Allocations past the
 * dynamic mark are released by _alalcFree on each new sequence size. */
typedef struct {          /* field names derived */
    unsigned int base;    /* 0x00 */
    unsigned int size;    /* 0x04 */
    unsigned int cur;     /* 0x08 the next free byte */
    unsigned int dynamic; /* 0x0C where the per-sequence allocations start */
} MpegHeap; /* derived name */

/* one reference's copy descriptor, the argument a lumaCopy or chromaCopy
 * routine takes: where the prediction goes, the horizontal fraction, the rows
 * read from the first and the second source block, the source row step and
 * the two source blocks (the second is the next block down) */
typedef struct { /* field names derived */
    void *dst;   /* 0x00 */
    int xoff;    /* 0x04 */
    int rows0;   /* 0x08 */
    int rows1;   /* 0x0C */
    int stride;  /* 0x10 */
    void *src0;  /* 0x14 */
    void *src1;  /* 0x18 */
} MCRefDesc; /* derived name */
/* one macroblock's motion-compensation record, 0x140 bytes: _motionComp0 sets
 * the flags and the destination, _getRef0 appends one reference per call
 * (the two source addresses DMA'd into refBuf, the copy routines and their
 * descriptors), _decMB0 has the IPU write its output (the intra block or the
 * residual) into ipuBuf and _doMC finishes it.  Every field name is ours. */
typedef struct {           /* field names derived */
    int refBuf;            /* 0x000 scratchpad area the references land in */
    int ipuBuf;            /* 0x004 scratchpad area the IPU writes into */
    void *srcAddr[2][4];   /* 0x008 */
    void (*lumaFn[4])();   /* 0x028 */
    void (*chromaFn[4])(); /* 0x038 */
    MCRefDesc luma[4];     /* 0x048 */
    MCRefDesc chroma[4];   /* 0x0B8 */
    void *dst;             /* 0x128 */
    int count;             /* 0x12C */
    int intra;             /* 0x130 */
    int coded;             /* 0x134 */
    int busy;              /* 0x138 the reference DMA is under way */
    int skip;              /* 0x13C no residual: the prediction is the block */
} MCRecord; /* derived name */

/* SDK 2.2 var.o's _mbcont, the SDK 2.5 record's mbcont: two records,
 * double-buffered (one is filled while the other is finished), and the
 * index of the current one.  init.c declares its own view. */
typedef struct {     /* field names derived */
    MCRecord rec[2]; /* 0x000 */
    int cur;         /* 0x280 */
    int aux;         /* 0x284 zeroed beside cur, read by no member */
} MCState; /* derived name */

/* the decoder's own record, 0x118 bytes at the head of the work area
 * sceMpegCreate is given; the handle's sys field points at it.  Every field
 * name here, in MpegCb and in MpegHeap is ours. */
typedef struct MpegSys { /* field names derived */
    int isEnd;           /* 0x000 the stream's end was reached */
    int refCount;        /* 0x004 pictures decoded since the last flush */
    int outState;        /* 0x008 0 none yet, 1 decoding, 2 output started */
    MpegCb cb[7];        /* 0x00C by callback type */
    struct StrCb *strCb; /* 0x044 sceMpegAddStrCallback's table, 64 entries */
    int nStrCb;          /* 0x048 */
    sceIpuDmaEnv dmaEnv; /* 0x04C what sceIpuStopDMA saves */
    int usePtsGap;       /* 0x070 sceMpegSetDefaultPtsGap */
    int pad74;           /* 0x074 */
    long long ptsGap;    /* 0x078 */
    int lastPts;         /* 0x080 the stamp of the picture last output */
    int pad84;           /* 0x084 */
    long long lastShow;  /* 0x088 and its display count */
    int halfCount;       /* 0x090 odd half-gaps carried */
    int ni, np, nb;      /* 0x094 sceMpegSetDecodeMode */
    int iCount;          /* 0x0A0 I, P and B pictures seen in the GOP */
    int pCount;          /* 0x0A4 */
    int bCount;          /* 0x0A8 */
    int frameBase;       /* 0x0AC _totalFrames at the first output */
    int csc;             /* 0x0B0 sceMpegGetPicture: convert to RGB */
    int centerOffX[3];   /* 0x0B4 frame_centre_horizontal_offset */
    int centerOffY[3];   /* 0x0C0 frame_centre_vertical_offset */
    int dispWidth;       /* 0x0CC display_horizontal_size */
    int dispHeight;      /* 0x0D0 display_vertical_size */
    int picStructure;    /* 0x0D4 the first picture's structure */
    int imageBuff;       /* 0x0D8 the output buffer, uncached */
    int buffWidth;       /* 0x0DC in pixels, 0 for a packed buffer */
    int buffHeight;      /* 0x0E0 */
    int buffSize;        /* 0x0E4 in macroblocks */
    int brokenLink;      /* 0x0E8 sceSetBrokenLink */
    int padEC;           /* 0x0EC */
    long long ptm;       /* 0x0F0 sceSetPtm */
    int ptmState;        /* 0x0F8 1 set, 2 armed, 0 used */
    int frameBuff[3];    /* 0x0FC the three reference frames */
    MpegHeap heap;       /* 0x108 */
    /* SAB: SDK 2.5 keeps the decoder's former globals here, after the SDK 2.2
       record; names are SDK 2.2's globals (mpeg2decode's) where the use is
       the same, the pads are fields no matched code here reads yet */
    int totalFrames;                 /* 0x118 */
    int isError;                     /* 0x11C */
    int isSecondField;               /* 0x120 */
    int horizontal_size;             /* 0x124 */
    int vertical_size;               /* 0x128 */
    int widthMB;                     /* 0x12C */
    int heightMB;                    /* 0x130 */
    int bit_rate_value;              /* 0x134 */
    int vbv_buffer_size_value;       /* 0x138 */
    int progressive_sequence;        /* 0x13C */
    int chroma_format;               /* 0x140 */
    int matrix_coefficients;         /* 0x144 */
    int display_horizontal_size;     /* 0x148 */
    int display_vertical_size;       /* 0x14C */
    int picture_coding_type;         /* 0x150 */
    int full_pel_forward_vector;     /* 0x154 */
    int forward_f_code;              /* 0x158 */
    int full_pel_backward_vector;    /* 0x15C */
    int backward_f_code;             /* 0x160 */
    int f_code[2][2];                /* 0x164 */
    int picture_structure;           /* 0x174 */
    int top_field_first;             /* 0x178 */
    int frame_pred_frame_dct;        /* 0x17C */
    int concealment_motion_vectors;  /* 0x180 */
    int repeat_first_field;          /* 0x184 */
    int progressive_frame;           /* 0x188 */
    int frame_center_horizontal_offset[3]; /* 0x18C */
    int frame_center_vertical_offset[3];   /* 0x198 */
    int closed_gop;                  /* 0x1A4 */
    int broken_link;                 /* 0x1A8 */
    int trFrameNumber;               /* 0x1AC */
    int sp_dcr;                      /* 0x1B0 */
    int qscqsc;                      /* 0x1B4 */
    int *forwFrame, *backFrame, *curFrame, *zFrame; /* 0x1B8 */
    int *forwTop, *backTop, *curTop, *zTop;         /* 0x1C8 */
    int *forwBot, *backBot, *curBot, *zBot;         /* 0x1D8 */
    int refFrame0[26], refFrame1[26], refFrame2[26]; /* 0x1E8 */
    int refTop0[26], refTop1[26], refTop2[26];       /* 0x320 */
    int refBot0[26], refBot1[26], refBot2[26];       /* 0x458 */
    MCState mbcont;                  /* 0x590 the macroblock state */
    int isTop32dirty;                /* 0x818 */
    int refBlockp;                   /* 0x81C */
    int isOutputPicture;             /* 0x820 */
    int pad824;                      /* 0x824 */
    long long headerPts;             /* 0x828 */
    long long headerDts;             /* 0x830 */
    int top32;                       /* 0x838 */
    int top32len;                    /* 0x83C */
    int load_intra_quantizer_matrix; /* 0x840 */
    int load_non_intra_quantizer_matrix; /* 0x844 */
    int isMpeg2;                     /* 0x848 */
    int tmpRefBase;                  /* 0x84C */
    int trFrameNumberA;              /* 0x850 */
    int tmpRefGOPreset;              /* 0x854 */
    sceMpeg *mp;                     /* 0x858 the handle this record belongs to */
    int pad85C[9];                   /* 0x85C */
    long long tagBuf[264];           /* 0x880 _sendDataToIPU's DMA chain, rounded up to a quadword */
} MpegSys; /* derived name */

/* SAB: the SDK 2.5 record's layout, checked */
#define MPEG_SYS_AT(f, o) typedef char mpeg_sys_##f[(int)&((MpegSys *)0)->f == (o) ? 1 : -1]
MPEG_SYS_AT(totalFrames, 0x118);
MPEG_SYS_AT(sp_dcr, 0x1B0);
MPEG_SYS_AT(refFrame0, 0x1E8);
MPEG_SYS_AT(mbcont, 0x590);
MPEG_SYS_AT(isTop32dirty, 0x818);
MPEG_SYS_AT(headerPts, 0x828);
MPEG_SYS_AT(isMpeg2, 0x848);
MPEG_SYS_AT(mp, 0x858);
MPEG_SYS_AT(tagBuf, 0x880);
typedef char mpeg_sys_size[sizeof(MpegSys) == 0x10C0 ? 1 : -1];

/* SAB: units converted to SDK 2.5 define LIBMPEG25, which gives the SDK 2.5
   signatures where they changed (most take the decoder record) */
void _ErrMessage(char *msg);
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _Error(MpegSys *p, char *msg);
#else
void _Error(char *msg);
#endif
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _Error1(MpegSys *p, char *fmt, int val);
#else
void _Error1(char *fmt, int val);
#endif
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
int _alalcAlloc(MpegSys *p, MpegHeap *heap, int size, unsigned int align);
#else
int _alalcAlloc(MpegHeap *heap, int size, unsigned int align);
#endif
void _alalcFree(MpegHeap *heap);
void _alalcInit(MpegHeap *heap, int base, int size);
void _alalcSetDynamic(MpegHeap *heap);
extern int _alternate_scan;
extern int _aspect_ratio_information;
extern int *_backBot;
extern int *_backFrame;
extern int *_backTop;
extern int _backward_f_code;
extern int _bit_rate_value;
extern int _broken_link;
extern int _bsDataSize;
extern int _bsDatap;
extern int _burst_amplitude;
extern int _cHeight;
extern int _cWidth;
extern int _chroma_420_type;
extern int _chroma_format;
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _clearEach(MpegSys *p);
#else
void _clearEach(void);
#endif
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _clearOnce(MpegSys *p);
#else
void _clearOnce(void);
#endif
extern int _closed_gop;
extern int _color_description;
extern int _color_primaries;
extern int _composite_display_flag;
extern int _concealment_motion_vectors;
extern int _constrained_parameters_flag;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _copyAddRefImage(void *dst, void *ref, void *diff);
#endif

#endif

#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _copyRefImage(void *dst, void *src);
#endif

#endif

extern int _copyright_flag;
extern int _copyright_identifier;
extern int _copyright_number_1;
extern int _copyright_number_2;
extern int _copyright_number_3;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _cpr8(int *im);
#endif

#endif

void _csc_storeRefImage(MpegSys *p, int *img); /* SAB: SDK 2.5 */
extern int *_curBot;
extern int *_curFrame;
extern int *_curTop;

#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _decMB0(int *mb_type, int *motion_type, int *dct_type, int PMV[2][2][2], int mv_field_sel[2][2],
            int *dmvector);
#endif

#endif


#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _decPicture(int frame, int refCount);
#endif

#endif
int _decodeOrSkip(sceMpeg *mp, int count, int limit);
int _decodeOrSkipField(sceMpeg *mp, int count, int limit);
int _decodeOrSkipFrame(sceMpeg *mp, int count, int limit);
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _decode_motion_vector(int *pred, int r_size, int motion_code, int motion_r, int full_pel);
#endif

#endif

int _defRestartDMA(sceMpeg *mp, void *cbdata, void *data);
int _defStopDMA(sceMpeg *mp, void *cbdata, void *data);
int _dispatchMpegCallback(sceMpeg *mp, int *cbdata);
void _dispatchMpegCbNodata(sceMpeg *mp);
extern unsigned char _defIQM[64];
extern unsigned char _defNIQM[64];
extern int _display_horizontal_size;
extern int _display_vertical_size;
void _doCSC2(MpegSys *p, int addr, int n); /* SAB: SDK 2.5 */
#ifndef LIBMPEG25
void _doMC(int idx);
#endif

extern int _drop_frame_flag;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _dispRefImage(int *img, int frame);
#endif

#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _dispRefImageField(int *top, int *bot, int frame);
#endif

#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _dualPrimeVector(int *DMV, int *dmvector, int mvx, int mvy);
#endif

#endif

#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _extensionAndUserData(void);
#endif

#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _extrainfo(void);
#endif

#endif

extern int _f_code[2][2];
extern int _field_sequence;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _flushBuf(int bits);
#endif

#endif


#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _getAllRefs(int x, int y, int mbflags, int motion_type, int PMV[2][2][2],
                 int mv_field_sel[2][2], int *dmvector);
#endif

#endif


extern int *_forwBot;
extern int *_forwFrame;
extern int *_forwTop;
extern int _forward_f_code;
extern int _frame_center_horizontal_offset[];
extern int _frame_center_vertical_offset[];
extern int _frame_pred_frame_dct;
extern int _frame_rate_code;
extern int _frame_rate_extension_d;
extern int _frame_rate_extension_n;
extern int _full_pel_backward_vector;
extern int _full_pel_forward_vector;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _getPtsDtsFlags(int *img, long long *pts, long long *dts, long long *flags);
#endif

#endif

int _getpic(sceMpeg *mp);

#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _getRef0(int *img, int lineOff, int predIdx, int yoff, int h, int x, int y, int mvx, int mvy,
              int fld, int avg);
#endif

#endif


#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _groupOfPicturesHeader(void);
#endif

#endif

extern long long _headerDts;
extern long long _headerPts;
extern int _heightMB;
extern int _horizontal_size;

#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _initRefImages(int *frame0, int *frame1, int *frame2, int *top0, int *top1, int *top2,
                    int *bot0, int *bot1, int *bot2, int y, int cb, int cr, int width, int height);
#else
void _initRefImages(int *frame0, int *frame1, int *frame2, int *top0, int *top1, int *top2,
                    int *bot0, int *bot1, int *bot2, int y, int cb, int cr);
#endif

void _initSeq(sceMpeg *mp);
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _initSeqAgain(MpegSys *p);
#else
void _initSeqAgain(void);
#endif
extern int _isError;
extern int _isMpeg2;
extern int _isOutputPicture;
extern int _isSecondField;
extern int _isTop32dirty;
extern int _intra_dc_precision;
extern int _intra_slice;
extern int _intra_vlc_format;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _ipuSetMPEG1(int on);
#endif

#endif

#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _ipuVdec(int tbl);
#endif

#endif

#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _isOutSizeOK(int *p);
#endif

#endif

#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _lastFrame(MpegSys *p);
#else
void _lastFrame(int frame);
#endif
extern int _load_intra_quantizer_matrix;
extern int _load_non_intra_quantizer_matrix;
extern int _low_delay;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _markOutput(void);
#endif

#endif

extern int _matrix_coefficients;
extern int _maxval;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _mbAddressIncrement(void);
#endif

#endif




#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _motionComp0(int mba, int inc, int mb_type, int motion_type, int PMV[2][2][2],
                 int mv_field_sel[2][2], int *dmvector);
#endif

#endif


#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _motionVector(int *PMV, int *dmvector, int h_r_size, int v_r_size, int dmv, int mvscale,
                   int full_pel);
#endif

#endif


#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _motionVectors(int PMV[2][2][2], int *dmvector, int mv_field_sel[2][2], int s, int mv_count,
                    int mv_format, int h_r_size, int v_r_size, int dmv, int mvscale);
#endif

#endif


#ifndef LIBMPEG25
#ifndef LIBMPEG25
unsigned int _nextBit(int bits);
#endif

#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _nextHeader(void);
#endif

#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _nextStartCode(void);
#endif

#endif

extern int _original_or_copy;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _outputFrame(int frame, int refCount);
#endif

#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _peepBit(int bits);
#endif

#endif

extern int _picHeight;
extern int _picWidth;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _pictureData0(int frame);
#endif

#endif

#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _pictureHeader(void);
#endif

#endif

#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _pictureSpatialScalableExtension(MpegSys *p);
#else
void _pictureSpatialScalableExtension(void);
#endif
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _pictureTemporalScalableExtension(MpegSys *p);
#else
void _pictureTemporalScalableExtension(void);
#endif
extern int _picture_coding_type;
extern int _picture_structure;
extern int _profile_and_level_indication;
extern int _progressive_frame;
extern int _progressive_sequence;
extern int _q_scale_type;
extern int _qscqsc;
extern int _refBlockp;
extern int _refBot0[];
extern int _refBot1[];
extern int _refBot2[];
extern int _refFrame0[];
extern int _refFrame1[];
extern int _refFrame2[];
extern int _refTop0[];
extern int _refTop1[];
extern int _refTop2[];
extern int _repeat_first_field;
int _sceMpegFlush(sceMpeg *mp);
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _sendDataToIPU(MpegSys *p, int data, int size);
#else
void _sendDataToIPU(int data, int size);
#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _sendIpuCommand(unsigned int cmd);
#endif

#endif
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _sequenceDisplayExtension(MpegSys *p);
#else
void _sequenceDisplayExtension(void);
#endif
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _sequenceExtension(MpegSys *p);
#else
void _sequenceExtension(void);
#endif
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _sequenceHeader(MpegSys *p);
#else
void _sequenceHeader(void);
#endif
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _sequenceScalableExtension(MpegSys *p);
#else
void _sequenceScalableExtension(void);
#endif
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _setDefaultQM(MpegSys *p, int cmd, unsigned char *qm);
#else
void _setDefaultQM(int cmd, unsigned char *qm);
#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _skipMB0(int PMV[2][2][2], int *motion_type, int mv_field_sel[2][2], int *mb_type);
#endif

#endif

#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _slice0(int frame, int total);
#endif

#endif

#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _sliceA0(int total, int *mba, int *inc, int PMV[2][2][2]);
#endif

#endif

#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _sliceB(void);
#endif

#endif

extern int _sp_dcr;
extern int _sprtag;
extern int _sub_carrier;
extern int _sub_carrier_phase;
int _sysbitGet(int *self, int n);
void _sysbitInit(int *bs, int base, int wrap, int size);
void _sysbitJump(int *bs, int bytes);
int _sysbitMarker(int *self);
int _sysbitNext(void *bs, int n);
int _sysbitPtr(int *bs, int bits);
extern int _temporal_reference;
extern sceMpeg *_theSceMpeg;
extern int _time_code_hours;
extern int _time_code_minutes;
extern int _time_code_pictures;
extern int _time_code_seconds;
extern int _top32;
extern int _top32len;
extern int _top_field_first;
extern int _totalFrames;
extern int _trFrameNumber;
extern int _transfer_characteristics;
long long _type2id(int type, int ch);
#ifdef LIBMPEG25 /* SAB: the SDK 2.5 form */
void _unknown_extension(MpegSys *p);
#else
void _unknown_extension(void);
#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _updateRefImage(int second);
#endif

#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _updateTempTackData(void);
#endif

#endif

extern int _v_axis;
extern int _vbv_buffer_size_value;
extern int _vbv_delay;
extern int _vertical_size;
extern int _video_format;
extern int _widthMB;
#ifndef LIBMPEG25
#ifndef LIBMPEG25
int _waitBdecOut(void);
#endif

#endif

#ifndef LIBMPEG25
#ifndef LIBMPEG25
void _waitIpuIdle(void);
#endif

#endif
#ifndef LIBMPEG25
#ifndef LIBMPEG25
long long _waitIpuIdle64(void);
#endif

#endif

extern int *_zBot;
extern int *_zFrame;
extern int *_zTop;

/* SAB: mpc.o SDK 2.5 prototypes (generated) */
#ifdef LIBMPEG25
int _motionComp0(MpegSys *p, int mba, int inc, int mb_type, int motion_type, int PMV[2][2][2], int mv_field_sel[2][2], int *dmvector);
void _getAllRefs(MpegSys *p, int x, int y, int mbflags, int motion_type, int PMV[2][2][2], int mv_field_sel[2][2], int *dmvector);
void _getRef0(MpegSys *p, int *img, int lineOff, int predIdx, int yoff, int h, int x, int y, int mvx, int mvy, int fld, int avg);
void _doMC(MpegSys *p, int idx);
void _copyAddRefImage(void *dst, void *ref, void *diff);
void _copyRefImage(void *dst, void *src);
void _ipuSetMPEG1(int on);
int _waitBdecOut(MpegSys *p);
int _dmVector(MpegSys *p);
void _dualPrimeVector(MpegSys *p, int *DMV, int *dmvector, int mvx, int mvy);
int _mbAddressIncrement(MpegSys *p);
int _pictureData0(MpegSys *p);
int _sliceA0(MpegSys *p, int total, int *mba, int *inc, int PMV[2][2][2]);
int _slice0(MpegSys *p, int total);
int _skipMB0(MpegSys *p, int PMV[2][2][2], int *motion_type, int mv_field_sel[2][2], int *mb_type);
int _decMB0(MpegSys *p, int *mb_type, int *motion_type, int *dct_type, int PMV[2][2][2], int mv_field_sel[2][2], int *dmvector);
void _decode_motion_vector(int *pred, int r_size, int motion_code, int motion_r, int full_pel);
void _motionVectors(MpegSys *p, int PMV[2][2][2], int *dmvector, int mv_field_sel[2][2], int s, int mv_count, int mv_format, int h_r_size, int v_r_size, int dmv, int mvscale);
void _motionVector(MpegSys *p, int *PMV, int *dmvector, int h_r_size, int v_r_size, int dmv, int mvscale, int full_pel);
void _sendIpuCommand(MpegSys *p, unsigned int cmd);
void _waitIpuIdle(MpegSys *p);
long long _waitIpuIdle64(MpegSys *p);
int _ipuVdec(MpegSys *p, int tbl);
int _peepBit(MpegSys *p, int bits);
void _flushBuf(MpegSys *p, int bits);
unsigned int _nextBit(MpegSys *p, int bits);
void _nextStartCode(MpegSys *p);
int _sliceB(MpegSys *p);
int _nextHeader(MpegSys *p);
void _pictureHeader(MpegSys *p);
void _extensionAndUserData(MpegSys *p);
void _pictureCodingExtension(MpegSys *p);
void _extrainfo(MpegSys *p);
void _updateTempTackData(MpegSys *p, int tr);
void _groupOfPicturesHeader(MpegSys *p);
void _quantMatrixExtension(MpegSys *p);
void _pictureDisplayExtension(MpegSys *p);
void _copyrightExtension(MpegSys *p);
int _decPicture(MpegSys *p);
void _outputFrame(MpegSys *p, int frame, int refCount);
int _updateRefImage(MpegSys *p, int second);
int _isOutSizeOK(MpegSys *p, int *pq);
void _cpr8(MpegSys *p, int *im);
int _markOutput(MpegSys *p);
void _getPtsDtsFlags(MpegSys *p, int *img, long long *pts, long long *dts, long long *flags);
void _dispRefImage(MpegSys *p, int *img, int frame);
void _dispRefImageField(MpegSys *p, int *top, int *bot, int frame);
#endif
/* end mpc.o SDK 2.5 prototypes */
#endif /* SCE_LIBMPEG_LIBMPEG_INTERNAL_H */
