#include <iostream>
#include <string>

#include "../inc/c_system.h"

using namespace std;


excecution::excecution(const int run): run(run){
    cout << "Csorgo-fele cigifuggveny C++ port v0.1" << endl;
}

void excecution::set_run(const int& input){
    this->run = input;
}

void excecution::self_check(const user& u) {
    if(u.get_napok_hatra() - 5840 <= 0){
        throw cfgv_exception(HELYTELEN_SZAMOLAS);
    }
}

void excecution::ujraszamolas(){
    cout << "Szeretne ujra kiszamolni az adatokat? (y/n)" << endl;
    char input;
    cin >> input;
    if(input == 'y' || input == 'Y'){
        set_run(1);
    } else if(input == 'n' || input == 'N'){
        set_run(0);
    } else {
        throw cfgv_exception(ROSSZ_VALASZ);
    }
}

int excecution::bekeres(const string& input){
    int output = 0;
    if(input[0] == 'a' || input[0] == 'e' || input[0] == 'i' || input[0] == 'o' || input[0] == 'u') {
        cout << "Kerem, adja meg az " + input + "t! (egesz szam)" << endl;
    } else {
        cout << "Kerem, adja meg a " + input + "t! (egesz szam)" << endl;
    }
    cin >> output;
    return output;
}

[[nodiscard]] string excecution::kontinens_bekeres() {
    string output;
    cout << "Kerem adja meg, melyik kontinensen lakik! (magyarul, ekezet nelkul, kisbetukkel)" << endl;
    cin >> output;
    return output;
}

void excecution::alap_adat_kiiras(user& u) {
    u.set_napok_hatra(u.get_varhato_elet_hatra(u.get_varhato_elet(kontinens_bekeres())));
    cout << "Onnek meg " + to_string(u.get_napok_hatra()) + " napja van hatra az eletebol, tehat " + to_string((u.get_napok_hatra()) / 365) + " eve." << endl;
}

void excecution::kiiras(user& u) {
    cout << "On eddig " + to_string(u.get_eddig_szivott_cigi()) + " cigarettat szivott, ami " + to_string(u.get_eddig_koltott_cigi()) + " HUF-ba kerult." << endl;
    cout << "Elete soran meg " + to_string(u.get_varhato_szivott_cigi(u.get_napok_hatra())) + " cigarettat fog szivni, ami " + to_string(u.get_varhato_koltott_cigi(u.get_napok_hatra())) + " HUF-ba fog kerulni." << endl;
    cout << "Ez osszesen " + to_string(u.get_eddig_szivott_cigi() + u.get_varhato_szivott_cigi(u.get_napok_hatra())) + " cigaretta, ami " + to_string(u.get_eddig_koltott_cigi() + u.get_varhato_koltott_cigi(u.get_napok_hatra())) + " HUF osszesen" << endl;
}

void excecution::execute(){
    while(this->run != 0){
        user u{};
        u.set_eletkor(bekeres("eletkora"));
        u.set_cigi_szam(bekeres("naponta elszivott cigarettak szama"));
        u.set_cigi_kolt(bekeres("altala szivott doboz cigi atlagos ara"));
        alap_adat_kiiras(u);
        self_check(u);
        kiiras(u);
        ujraszamolas();
    }
}

