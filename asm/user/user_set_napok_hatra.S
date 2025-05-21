.intel_syntax noprefix

.text
.global user_set_napok_hatra
user_set_napok_hatra:

    push ebp
    mov ebp, esp

    mov edx, [ebp + 8]
    mov [ecx + 12], edx

    mov esp, ebp
    pop ebp
    ret
