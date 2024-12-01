#include "../inc/c_error.h"

using namespace std;




cfgv_exception::cfgv_exception(const hibakod code): code(code){
    switch(code){
        case KONTINENS_HIBA:
            this->message = "Hibasan adta meg a kontinenst!";
            break;
        case ROSSZ_VALASZ:
            this->message = "Ismeterlen valaszt adott meg! (y / n)";
            break;
        case ALACSONY_ELETKOR:
            this->message = "A program 16 eves kortol szamitja a napi dohanyzas szintjet! Az altala megadott eletkor kevesebb mint 16!";
            break;
        case MAGAS_ELETKOR:
            this->message = "Tul magas szamot adott meg kornak! (16-99 intervallumon kell megadni!)";
            break;
        case ROSSZ_C_SZAM:
            this->message = "Rossz szamot adott meg naponta fogyasztot cigarettaknak! (1-40 intervallumon kell megadni!";
            break;
        case ROSSZ_C_AR:
            this->message = "Tul magas szamot adott meg a cigarettadoboz atlagos bekerulesi ertekenek! (100-5000 intervallumon kell megadni!)";
            break;
        case HELYTELEN_SZAMOLAS:
            this->message = "A bemeneti adatok nem engedelyezik a helyes szamolast!";
            break;
        case ISMERETLEN_HIBA:
            this->message = "Ismeretlen hiba tortent!";
            break;
        default:
            this->message = "Hiba tortent!";
            break;
    }
}

    [[nodiscard]] const char* cfgv_exception::what() const noexcept {
        return message.c_str();
    }
