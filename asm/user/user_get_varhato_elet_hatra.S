.intel_syntax noprefix

.text
.global user_get_varhato_elet_hatra
user_get_varhato_elet_hatra:

    push ebp
    mov ebp, esp

    mov eax, [ebp + 8]
    mov edx, [ecx]
    imul edx, edx, 365
    sub eax, edx

    mov esp, ebp
    pop ebp
    ret