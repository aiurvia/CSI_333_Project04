.data 

buf1: .space 50 

buf2: .space 50 

.text


    la $a0,buf1             # address of input buffer 

    addi $a1,$zero,50       # size of input buffer 

    addi $v0,$zero,8        # system call to read string 

    syscall 


    la $t1,buf1             # buf1 pointer 

    la $t2,buf2             # buf2 pointer 

    addi $t3,$zero,0x09     # tab 

    addi $t4,$zero,0x32     # space 

    addi $t5,$zero,0x0A     # newline 

next_char: 

    lbu $t0,0($t1)          # read a character from buf1 

    addi $t1,$t1,1          # advance buf1 pointer 

    beq $t0,$t3,next_char   # don't copy tab 

    beq $t0,$t4,next_char   # don't copy space 

    beq $t0,$t5,next_char   # don't copy newline 

    sb $t0,0($t2)           # copy character into buf2 

    addi $t2,$t2,1          # advance buf2 pointer 

    bne $t0,$zero,next_char # string ends with NUL 



    la $a0,buf2             # address of output buffer 

    addi $v0,$zero,4        # system call to print string 

    syscall 

