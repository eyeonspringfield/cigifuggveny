.intel_syntax noprefix

.data
KONTINENS_HIBA: .asciz "Hibasan adta meg a kontinenst!\n"
ROSSZ_VALASZ: .asciz "Ismeterlen valaszt adott meg! (y / n)\n"
ALACSONY_ELETKOR: .asciz "A program 16 eves kortol szamitja a napi dohanyzas szintjet! Az altala megadott eletkor kevesebb mint 16!\n"
MAGAS_ELETKOR: .asciz "Tul magas szamot adott meg kornak! (16-99 intervallumon kell megadni!)\n"
ROSSZ_C_SZAM: .asciz "Rossz szamot adott meg naponta fogyasztot cigarettaknak! (1-40 intervallumon kell megadni!)\n"
ROSSZ_C_AR: .asciz "Tul magas szamot adott meg a cigarettadoboz atlagos bekerulesi ertekenek! (100-5000 intervallumon kell megadni!)\n"
HELYTELEN_SZAMOLAS: .asciz "A bemeneti adatok nem engedelyezik a helyes szamolast!\n"
ISMERETLEN_HIBA: .asciz "Ismeretlen hiba tortent!\n"
DEFAULT: .asciz "Hiba tortent!\n"

.text
extern printf
global cfgv_exception
cfgv_exception:
    push ebp
    mov ebp, esp

    mov eax, [ebp + 8]
    mov edx, [ebp + 12]
    mov [eax], edx

    cmp edx, 0
    je kon_hib
    cmp edx, 1
    je ros_val
    cmp edx, 2
    je ala_ele
    cmp edx, 3
    je mag_ele
    cmp edx, 4
    je ros_c_sz
    cmp edx, 5
    je ros_c_ar
    cmp edx, 6
    je hel_sza
    cmp edx, 7
    je ism_hib

    mov ecx, offset DEFAULT
    jmp store

kon_hib:
    mov ecx, offset KONTINENS_HIBA
    jmp store
ros_val:
    mov ecx, offset ROSSZ_VALASZ
    jmp store
ala_ele:
    mov ecx, offset ALACSONY_ELETKOR
    jmp store
mag_ele:
    mov ecx, offset MAGAS_ELETKOR
    jmp store
ros_c_sz:
    mov ecx, offset ROSSZ_C_SZAM
    jmp store
ros_c_ar:
    mov ecx, offset ROSSZ_C_AR
    jmp store
hel_sza:
    mov ecx, offset HELYTELEN_SZAMOLAS
    jmp store
ism_hib:
    mov ecx, offset ISMERETLEN_HIBA

store:
    mov [eax + 4], ecx

    push ecx
    call printf
    add esp, 4

    mov esp, ebp
    pop ebp
    mov eax, 1
    mov ebx, 1
    int 0x80 // syscall for exit since exception does not return control