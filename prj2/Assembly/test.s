beq $zero, $zero, loop
addi $a4, $zero, 9
sw $a4, 0x4($zero)
add $zero, $zero, $zero
loop: addi $a1, $zero, 9
add $a2, $a1, $a1
sw $a2, 0x0($zero)
lw $a3, 0x0($zero)
addi $a3, $a3, 2
sw $a3, 0x0($zero)
