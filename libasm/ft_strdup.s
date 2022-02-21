global _ft_strdup
extern ___error

_ft_strdup:
    mov rsi, rdi
    push rsi
    extern _ft_strlen
    call _ft_strlen
    mov rdi,rax
    inc rdi
    extern _malloc
    call _malloc
    jc errors
    pop rsi
    mov rdi,0
    loop:
        cmp BYTE[rsi], 0
           je return
        mov cl, BYTE[rsi]
        mov BYTE[rax + rdi], cl
        inc rdi
        inc rsi
    jmp loop
return:
    mov BYTE[rax + rdi], 0
    ret

errors:
    push rax
    call ___error
    pop qword[rax]
    mov rax, -1
    ret