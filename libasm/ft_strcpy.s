global _ft_strcpy

_ft_strcpy:
    mov rcx, rsi
    loop:
        cmp BYTE[rsi], 0
           je return
        mov al, BYTE[rsi]
        mov BYTE[rdi], al
        inc rdi
        inc rsi
    jmp loop
return:
    mov BYTE[rdi],0
    mov rax,rcx
    ret
