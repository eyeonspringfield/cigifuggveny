//
// Created by Márk on 12/22/2023.
//

#ifndef CIGIFUGGVENYCPP_C_SYSTEM_H
#define CIGIFUGGVENYCPP_C_SYSTEM_H
#include <iostream>
#include <string>

#include "c_user.h"

using namespace std;

class excecution{
private:
    int run;

public:

    explicit excecution(int run);

    ~excecution() = default;

    void set_run(const int& input);

    static void self_check(const user& u);

    void ujraszamolas();

    static int bekeres(const string& input);

    [[nodiscard]] static string kontinens_bekeres() ;

    static void alap_adat_kiiras(user& u) ;

    static void kiiras(user& u) ;

    void execute();
};

#endif //CIGIFUGGVENYCPP_C_SYSTEM_H
