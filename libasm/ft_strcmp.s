global _ft_strcmp

_ft_strcmp:
    loop:
        cmp BYTE[rsi], 0
            je return
        cmp BYTE[rdi], 0
            je return
        mov dh, BYTE[rsi]
        mov dl, BYTE[rdi]
        cmp dh, dl
            jne return
        inc rdi
        inc rsi
    jmp loop 
return:
    movzx rcx,BYTE[rdi]
    movzx rdx,BYTE[rsi]
    sub rcx,rdx
    mov rax,rcx
    ret