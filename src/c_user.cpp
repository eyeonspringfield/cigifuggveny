#include <string>
#include <unordered_map>

#include "../inc/c_error.h"
#include "../inc/c_user.h"


using namespace std;

void user::set_eletkor(const int e) {
    if(e < MIN_ELETKOR){
        throw cfgv_exception(ALACSONY_ELETKOR);
    }
    if(e > MAX_ELETKOR){
        throw cfgv_exception(MAGAS_ELETKOR);
    }
    this->eletkor = e;
}

void user::set_cigi_szam(const int c) {
    if (c < MIN_NAPI_CIGI || c > MAX_NAPI_CIGI){
        throw cfgv_exception(ROSSZ_C_SZAM);
    }
    this->cigi_szam = c;
}

void user::set_cigi_kolt(const int c) {
    if(c < MIN_CIGI_KOLT || c > MAX_CIGI_KOLT){
        throw cfgv_exception(ROSSZ_C_AR);
    }
    this->cigi_kolt = c;
}

void user::set_napok_hatra(int i){
    this->napok_hatra = i;
}

[[nodiscard]] int user::get_eletkor() const {
    return eletkor;
}

[[nodiscard]] int user::get_cigi_szam() const {
    return cigi_szam;
}

[[nodiscard]] int user::get_cigi_kolt() const {
    return cigi_kolt;
}

[[nodiscard]] int user::get_napok_hatra() const {
    return napok_hatra;
}

kontinens user::enum_converter(const string& input){
    static const unordered_map<string, kontinens> m = {
            {"afrika", AFRIKA},
            {"ausztralia", AUSZTRALIA},
            {"azsia", AZSIA},
            {"del amerika", DEL_AMERIKA},
            {"eszak amerika", ESZAK_AMERIKA},
            {"europa", EUROPA},
            };

    auto it = m.find(input);
    if(it != m.end()){
        return it->second;
    }else{
        throw cfgv_exception(KONTINENS_HIBA);
    }
}

int user::get_varhato_elet(const string& input){
    switch(kontinens input_enum = enum_converter(input)){
        case AFRIKA:
            return 24090;
        case AUSZTRALIA:
            return 30295;
        case AZSIA:
            return 29200;
        case DEL_AMERIKA:
            return 27375;
        case ESZAK_AMERIKA:
            return 28835;
        case EUROPA:
            return 29565;
        default:
            throw cfgv_exception(ISMERETLEN_HIBA);
    }
}

[[nodiscard]] int user::get_varhato_elet_hatra(const int input) const {
    return input - (eletkor * 365);
}

int user::get_eddig_szivott_cigi() const {
    return ((eletkor * 365) - TIZENHAT_EV_NAPOKBAN) * cigi_szam;
}

[[nodiscard]] int user::get_eddig_koltott_cigi() const {
    return get_eddig_szivott_cigi() * (cigi_kolt / SZAL_CIGI_AR);
}

[[nodiscard]] int user::get_varhato_szivott_cigi(const int input) const{
    return ((get_varhato_elet_hatra(input) - TIZENHAT_EV_NAPOKBAN) * cigi_szam);
}

[[nodiscard]] int user::get_varhato_koltott_cigi(const int input) const{
    return get_varhato_szivott_cigi(input) * (cigi_kolt / SZAL_CIGI_AR);
}



