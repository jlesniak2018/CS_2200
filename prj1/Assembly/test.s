!addi $t0, $t0, 3
!addi $t1, $t1, 3
!beq $t0, $t1, done
!add $t0, $t0, $t1

!done: halt
la $a0, testLabel
halt

testLabel: .word 0x12
