# libkernl.a: SDK 2.5's hand-written TLB refill and exception trap (SAB:
# not in kfiv-decomp; the member name and labels are derived).  tlbfunc.o's
# _kSetTLBRefillFunc points the TLB refill vectors at _kTLBTrap and
# _kSetExceptionHandler the others at _kExceptionTrap: each saves the
# registers, HI/LO/SA and EPC in _kTrapSave, returns from the exception into
# the C handler (tlbfunc.o's _kTLBRefillFunc, or the _kExceptionHandler entry
# for the cause), which comes back through a syscall (-84, registered at
# _kTLBTrap+0x140), and restores.

	.text
	.set	noreorder
	.set	noat
	.align	6
	.globl	_kTLBTrap
	.type	_kTLBTrap, @function
_kTLBTrap:
	lui $26, %hi(_kTrapSave)
	addiu $26, $26, %lo(_kTrapSave)
	sq $1, 0x10($26)
	sq $2, 0x20($26)
	sq $3, 0x30($26)
	sq $4, 0x40($26)
	sq $5, 0x50($26)
	sq $6, 0x60($26)
	sq $7, 0x70($26)
	sq $8, 0x80($26)
	sq $9, 0x90($26)
	sq $10, 0xA0($26)
	sq $11, 0xB0($26)
	sq $12, 0xC0($26)
	sq $13, 0xD0($26)
	sq $14, 0xE0($26)
	sq $15, 0xF0($26)
	sq $16, 0x100($26)
	sq $17, 0x110($26)
	sq $18, 0x120($26)
	sq $19, 0x130($26)
	sq $20, 0x140($26)
	sq $21, 0x150($26)
	sq $22, 0x160($26)
	sq $23, 0x170($26)
	sq $24, 0x180($26)
	sq $25, 0x190($26)
	sq $28, 0x1C0($26)
	sq $29, 0x1D0($26)
	sq $30, 0x1E0($26)
	sq $31, 0x1F0($26)
	mfhi $2
	lui $1, %hi(_kTrapSave+0x200)
	sd $2, %lo(_kTrapSave+0x200)($1)
	mfhi1 $2
	lui $1, %hi(_kTrapSave+0x208)
	sd $2, %lo(_kTrapSave+0x208)($1)
	mflo $2
	lui $1, %hi(_kTrapSave+0x210)
	sd $2, %lo(_kTrapSave+0x210)($1)
	mflo1 $2
	lui $1, %hi(_kTrapSave+0x218)
	sd $2, %lo(_kTrapSave+0x218)($1)
	mfsa $2
	lui $1, %hi(_kTrapSave+0x220)
	sd $2, %lo(_kTrapSave+0x220)($1)
	mfc0 $4, $12
	mfc0 $5, $13
	mfc0 $6, $14
	mfc0 $7, $8
	lui $8, %hi(_kTrapSave)
	addiu $8, $8, %lo(_kTrapSave)
	lui $1, %hi(_kTrapSave+0x228)
	sw $6, %lo(_kTrapSave+0x228)($1)
	lui $1, %hi(.Ltlb_call)
	addiu $1, $1, %lo(.Ltlb_call)
	mtc0 $1, $14
	sync.p
	mfc0 $1, $12
	addiu $2, $0, -0x2
	and $1, $1, $2
	mtc0 $1, $12
	sync.p
	eret
.Ltlb_call:
	lui $1, %hi(_kTLBRefillFunc)
	lw $1, %lo(_kTLBRefillFunc)($1)
	lui $29, %hi(_kTrapSave)
	jalr $1
	addiu $29, $29, %lo(_kTrapSave)
	addiu $3, $0, -0x54
	syscall 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	mfc0 $1, $12
	addiu $26, $0, -0x1C
	and $1, $1, $26
	mtc0 $1, $12
	sync.p
	lui $2, %hi(_kTrapSave+0x228)
	lw $2, %lo(_kTrapSave+0x228)($2)
	mtc0 $2, $14
	sync.p
	lui $2, %hi(_kTrapSave+0x200)
	ld $2, %lo(_kTrapSave+0x200)($2)
	mthi $2
	lui $2, %hi(_kTrapSave+0x208)
	ld $2, %lo(_kTrapSave+0x208)($2)
	mthi1 $2
	lui $2, %hi(_kTrapSave+0x210)
	ld $2, %lo(_kTrapSave+0x210)($2)
	mtlo $2
	lui $2, %hi(_kTrapSave+0x218)
	ld $2, %lo(_kTrapSave+0x218)($2)
	mtlo1 $2
	lui $2, %hi(_kTrapSave+0x220)
	ld $2, %lo(_kTrapSave+0x220)($2)
	mtsa $2
	sync.p
	lui $26, %hi(_kTrapSave)
	addiu $26, $26, %lo(_kTrapSave)
	lq $1, 0x10($26)
	lq $2, 0x20($26)
	lq $3, 0x30($26)
	lq $4, 0x40($26)
	lq $5, 0x50($26)
	lq $6, 0x60($26)
	lq $7, 0x70($26)
	lq $8, 0x80($26)
	lq $9, 0x90($26)
	lq $10, 0xA0($26)
	lq $11, 0xB0($26)
	lq $12, 0xC0($26)
	lq $13, 0xD0($26)
	lq $14, 0xE0($26)
	lq $15, 0xF0($26)
	lq $16, 0x100($26)
	lq $17, 0x110($26)
	lq $18, 0x120($26)
	lq $19, 0x130($26)
	lq $20, 0x140($26)
	lq $21, 0x150($26)
	lq $22, 0x160($26)
	lq $23, 0x170($26)
	lq $24, 0x180($26)
	lq $25, 0x190($26)
	lq $28, 0x1C0($26)
	lq $29, 0x1D0($26)
	lq $30, 0x1E0($26)
	lq $31, 0x1F0($26)
	mfc0 $26, $12
	ori $26, $26, 0x13
	mtc0 $26, $12
	sync.p
	eret
	nop
	nop
	nop
_kExceptionTrap:
	lui $26, %hi(_kTrapSave)
	addiu $26, $26, %lo(_kTrapSave)
	sq $1, 0x10($26)
	sq $2, 0x20($26)
	sq $3, 0x30($26)
	sq $4, 0x40($26)
	sq $5, 0x50($26)
	sq $6, 0x60($26)
	sq $7, 0x70($26)
	sq $8, 0x80($26)
	sq $9, 0x90($26)
	sq $10, 0xA0($26)
	sq $11, 0xB0($26)
	sq $12, 0xC0($26)
	sq $13, 0xD0($26)
	sq $14, 0xE0($26)
	sq $15, 0xF0($26)
	sq $16, 0x100($26)
	sq $17, 0x110($26)
	sq $18, 0x120($26)
	sq $19, 0x130($26)
	sq $20, 0x140($26)
	sq $21, 0x150($26)
	sq $22, 0x160($26)
	sq $23, 0x170($26)
	sq $24, 0x180($26)
	sq $25, 0x190($26)
	sq $28, 0x1C0($26)
	sq $29, 0x1D0($26)
	sq $30, 0x1E0($26)
	sq $31, 0x1F0($26)
	mfhi $2
	lui $1, %hi(_kTrapSave+0x200)
	sd $2, %lo(_kTrapSave+0x200)($1)
	mfhi1 $2
	lui $1, %hi(_kTrapSave+0x208)
	sd $2, %lo(_kTrapSave+0x208)($1)
	mflo $2
	lui $1, %hi(_kTrapSave+0x210)
	sd $2, %lo(_kTrapSave+0x210)($1)
	mflo1 $2
	lui $1, %hi(_kTrapSave+0x218)
	sd $2, %lo(_kTrapSave+0x218)($1)
	mfsa $2
	lui $1, %hi(_kTrapSave+0x220)
	sd $2, %lo(_kTrapSave+0x220)($1)
	mfc0 $4, $12
	mfc0 $5, $13
	mfc0 $6, $14
	mfc0 $7, $8
	mfc0 $8, $23
	lui $9, %hi(_kTrapSave)
	addiu $9, $9, %lo(_kTrapSave)
	lui $1, %hi(.Lexc_call)
	addiu $1, $1, %lo(.Lexc_call)
	mtc0 $1, $14
	sync.p
	mfc0 $1, $12
	addiu $2, $0, -0x2
	and $1, $1, $2
	mtc0 $1, $12
	sync.p
	eret
.Lexc_call:
	andi $2, $5, 0x7C
	lui $1, %hi(_kExceptionHandler)
	addu $1, $1, $2
	lw $1, %lo(_kExceptionHandler)($1)
	lui $29, %hi(_kTrapSave)
	jalr $1
	addiu $29, $29, %lo(_kTrapSave)
	break 1023, 1023
	.size	_kTLBTrap, . - _kTLBTrap
	.globl	_kExceptionTrap

	.bss
	.align	6
	.globl	_kTrapSave
_kTrapSave:
	.space	0x22C
