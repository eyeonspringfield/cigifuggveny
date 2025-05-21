.intel_syntax noprefix

.text
.global user_set_eletkor
extern MIN_ELETKOR
extern MAX_ELETKOR
user_set_eletkor:

    push ebp
    mov ebp, esp

    mov edx, [ebp + 8]

    cmp edx, [MIN_ELETKOR]
    jl throw_ala_ele

    cmp edx, [MAX_ELETKOR]
    jg throw_mag_ele

    mov [ecx], edx          # eletkor is at offset 0 in user object

    mov esp, ebp
    pop ebp
    ret

throw_ala_ele:
    push 3
    push ecx
    call cfgv_exception     # cfgv_exception never returns

throw_mag_ele:
    push 4
    push ecx
    call cfgv_exception     # doesn't return