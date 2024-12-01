//
// Created by Márk on 12/22/2023.
//

#ifndef CIGIFUGGVENYCPP_C_ERROR_H
#define CIGIFUGGVENYCPP_C_ERROR_H

#include <iostream>
#include <string>

using namespace std;


enum hibakod{
    KONTINENS_HIBA,
    ROSSZ_VALASZ,
    ALACSONY_ELETKOR,
    MAGAS_ELETKOR,
    ROSSZ_C_SZAM,
    ROSSZ_C_AR,
    HELYTELEN_SZAMOLAS,
    ISMERETLEN_HIBA
};


class cfgv_exception : public exception{
    int code;
    string message;
public:
    explicit cfgv_exception(hibakod code);
    [[nodiscard]] const char* what() const noexcept override;
};


#endif //CIGIFUGGVENYCPP_C_ERROR_H
