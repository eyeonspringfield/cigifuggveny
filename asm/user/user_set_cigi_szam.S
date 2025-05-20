.intel_syntax noprefix

.text
.global user_set_cigi_szam
extern MIN_NAPI_CIGI
extern MAX_NAPI_CIGI

user_set_cigi_szam:

    push ebp
    mov ebp, esp

    mov edx, [ebp + 8]

    cmp edx, [MIN_NAPI_CIGI]
    jl throw_ros_c_sz

    cmp edx, [MAX_NAPI_CIGI]
    jg throw_ros_c_sz

    mov [ecx + 4], edx          // cigiszam at offset 4 of ecx

    mov esp, ebp
    pop ebp
    ret

throw_ros_c_sz:
    push 4
    push ecx
    call cfgv_exception         // does not return, but add cleanup because i can

    mov esp, ebp
    pop ebp
    ret
