.global main

main:
    movb    $0x0e, %ah

    movb    $0x48, %al
    int     $0x10

    movb    $0x65, %al
    int     $0x10

    movb    $0x6c, %al
    int     $0x10

    movb    $0x6c, %al
    int     $0x10

    movb    $0x6f, %al
    int     $0x10

    movb    $0x20, %al
    int     $0x10

    movb    $0x57, %al
    int     $0x10

    movb    $0x6f, %al
    int     $0x10

    movb    $0x72, %al
    int     $0x10

    movb    $0x6c, %al
    int     $0x10
 
    movb    $0x64, %al
    int     $0x10

    je    halt

halt:
	hlt
	jmp   halt
