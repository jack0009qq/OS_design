#include "platform.h"

    # 每個核心1024bytes
    .equ STACK_SIZE, 1024
    .global _fuckyoustart
    .text
_fuckyoustart:
    #選第0個核心
    csrr    t0, mhartid   
    mv      tp, t0
    bnez    t0, park
    #設定stack pointer
    slli    t0, t0, 10              #移動1024byte
    la      sp, stacks + STACK_SIZE #設定sp的位置 在stack尾巴
    add     sp, sp, t0              #移動到目前核心的sp
    j   start_kernel

park:
    wfi
    j   park
stacks:
    .skip	STACK_SIZE * MAXNUM_CPU # allocate space for all the harts stacks
    .end				# End of file
