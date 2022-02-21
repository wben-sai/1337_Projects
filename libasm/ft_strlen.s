global _ft_strlen

_ft_strlen: 
    mov rax, 0
    loop:
        cmp BYTE[rdi], 0
            je return
        add rax, 1
        add rdi,1
    jmp loop
    return:
        ret