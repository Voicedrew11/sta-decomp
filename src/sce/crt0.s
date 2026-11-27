# crt0: the SDK's start-up module, the head of .text, assembled from
# /usr/local/sce/ee/lib/crt0.s; sq, syscall and ei have no C spelling.
# The eight zero bytes before <_start> are crt0.s's pre-entry pad, not a
# function and carrying no symbol of its own, and are emitted here as data
# so the run starts at the same address.
# STA: SDK 2.5's _start first clears every register, HI/LO (both pipelines),
# SA and the FPU, pads the .bss clear loop, and moves registers with `or`.
# _stack, _stack_size and _heap_size are the link's (config/linker_syms.txt);
# main is the game's main_3_0012BF40.
#
# The module's .bss (0x144): the argument block _start hands main, argc then
# argv's sixteen pointers and the 256 bytes they point into.
#
# Local: crt0.o's .bss has no global symbol.
    .section .bss
_args: /* derived name */
    .space 4 + 16 * 4 + 256
    .section .text
    .set at
    .set noreorder
    .align 3
    .word 0, 0
    .set reorder
    .set at
    .section .text
    .set noat
    .set noreorder
    .align 3
    .globl _start
    .type _start, @function
_start:
    padduw $1, $0, $0
    padduw $2, $0, $0
    padduw $3, $0, $0
    padduw $4, $0, $0
    padduw $5, $0, $0
    padduw $6, $0, $0
    padduw $7, $0, $0
    padduw $8, $0, $0
    padduw $9, $0, $0
    padduw $10, $0, $0
    padduw $11, $0, $0
    padduw $12, $0, $0
    padduw $13, $0, $0
    padduw $14, $0, $0
    padduw $15, $0, $0
    padduw $16, $0, $0
    padduw $17, $0, $0
    padduw $18, $0, $0
    padduw $19, $0, $0
    padduw $20, $0, $0
    padduw $21, $0, $0
    padduw $22, $0, $0
    padduw $23, $0, $0
    padduw $24, $0, $0
    padduw $25, $0, $0
    padduw $28, $0, $0
    padduw $29, $0, $0
    padduw $30, $0, $0
    padduw $31, $0, $0
    mthi $0
    mthi1 $0
    mtlo $0
    mtlo1 $0
    mtsah $0, 0
    mtc1 $0, $f0
    mtc1 $0, $f1
    mtc1 $0, $f2
    mtc1 $0, $f3
    mtc1 $0, $f4
    mtc1 $0, $f5
    mtc1 $0, $f6
    mtc1 $0, $f7
    mtc1 $0, $f8
    mtc1 $0, $f9
    mtc1 $0, $f10
    mtc1 $0, $f11
    mtc1 $0, $f12
    mtc1 $0, $f13
    mtc1 $0, $f14
    mtc1 $0, $f15
    mtc1 $0, $f16
    mtc1 $0, $f17
    mtc1 $0, $f18
    mtc1 $0, $f19
    mtc1 $0, $f20
    mtc1 $0, $f21
    mtc1 $0, $f22
    mtc1 $0, $f23
    mtc1 $0, $f24
    mtc1 $0, $f25
    mtc1 $0, $f26
    mtc1 $0, $f27
    mtc1 $0, $f28
    mtc1 $0, $f29
    mtc1 $0, $f30
    mtc1 $0, $f31
    adda.s $f0, $f1
    sync.p
    ctc1 $0, $31
    lui $2, %hi(_fbss)
    lui $3, %hi(_end)
    addiu $2, $2, %lo(_fbss)
    addiu $3, $3, %lo(_end)
.L1:
    sq $0, 0x0($2)
    nop
    sltu $1, $2, $3
    nop
    nop
    bnez $1, .L1
    addiu $2, $2, 0x10
    lui $4, %hi(_gp)
    lui $5, %hi(_stack)
    lui $6, %hi(_stack_size)
    lui $7, %hi(_args)
    lui $8, %hi(_root)
    addiu $4, $4, %lo(_gp)
    addiu $5, $5, %lo(_stack)
    addiu $6, $6, %lo(_stack_size)
    addiu $7, $7, %lo(_args)
    addiu $8, $8, %lo(_root)
    or $28, $4, $0
    addiu $3, $0, 0x3C
    syscall 0
    or $29, $2, $0
    lui $4, %hi(_end)
    lui $5, %hi(_heap_size)
    addiu $4, $4, %lo(_end)
    addiu $5, $5, %lo(_heap_size)
    addiu $3, $0, 0x3D
    syscall 0
    jal _InitSys
    nop
    jal FlushCache
    or $4, $0, $0
    ei
    lui $2, %hi(_args)
    addiu $2, $2, %lo(_args)
    lw $4, 0x0($2)
    jal main_3_0012BF40
    addiu $5, $2, 0x4
    j Exit
    or $4, $2, $0
    .size _start, . - _start
    .set reorder
    .set at
    .section .text
    .set at
    .set noreorder
    .align 3
    .globl _exit
    .type _exit, @function
_exit:
    j Exit
    or $4, $0, $0
    .size _exit, . - _exit
    .set reorder
    .set at
    .section .text
    .set at
    .set noreorder
    .align 3
    .globl _root
    .type _root, @function
_root:
    addiu $3, $0, 0x23
    syscall 0
    .size _root, . - _root
    # STA: the module's text ends on a quadword boundary: eight zero bytes
    # before the next object (libgcc's __gtdf2)
    .align 4
    .set reorder
    .set at
