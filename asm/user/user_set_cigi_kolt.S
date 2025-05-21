.intel_syntax noprefix

.text
.global user_set_cigi_kolt
extern MIN_CIGI_KOLT
extern MAX_CIGI_KOLT
user_set_cigi_kolt:

    push ebp
    mov ebp, esp

    mov edx, [ebp + 8]

    cmp edx, [MIN_CIGI_KOLT]
    jl throw_ros_c_ar

    cmp edx, [MAX_CIGI_KOLT]
    jg throw_ros_c_ar

    mov [ecx + 8], edx

    mov esp, ebp
    pop ebp
    ret

throw_ros_c_ar:
    push 5
    push ecx
    call cfgv_exception         # does not return