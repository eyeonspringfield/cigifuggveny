//
// Created by Márk on 12/18/2023.
//

#ifndef CIGIFUGGVENYCPP_C_USER_H
#define CIGIFUGGVENYCPP_C_USER_H

/**
 * @file c_user.h
 * @author Csörgő Márk Ábrahám
 * @brief File for the user class
 */

#include <string>
#include <unordered_map>

#include "../inc/c_error.h"

using namespace std;

enum kontinens{
    AFRIKA,
    AUSZTRALIA,
    AZSIA,
    DEL_AMERIKA,
    ESZAK_AMERIKA,
    EUROPA
};

#define MIN_ELETKOR 16
#define MAX_ELETKOR 99
#define MIN_NAPI_CIGI 1
#define MAX_NAPI_CIGI 40
#define MIN_CIGI_KOLT 100
#define MAX_CIGI_KOLT 5000
#define TIZENHAT_EV_NAPOKBAN 5840
#define SZAL_CIGI_AR 20

/**
 * @brief A class representing a user.
 *
 * This class represents the user of the program, it is designed to document and do calculations with their age, and their smoking habits.
 */
class user{
private:
    /** @brief The users age in years.*/
    int eletkor;
    /** @brief The user's number of cigarettes smoked per day.*/
    int cigi_szam;
    /** @brief The cost of one pack of cigarettes smoked by the user.*/
    int cigi_kolt;
    /** The approximate days left of users life.*/
    int napok_hatra;

public:
    user() = default;
    /**
     * @brief Sets the age of the user in years.
     * If the parameter is less than 16, or more than 99, it throws a cfgv_exception with an error code of 3 or 4.
     * @param e The age to set.
     */
    void set_eletkor(int e);
    /**
     * @brief Sets the amount of cigarettes smoked in a day.
     * If the parameter is less than 1, or more than 40, it throws a cfgv_exception with an error code of 5.
     * This is because it is unrealistic for a smoker to smoke less than 1, or more than 40 cigarettes a day.
     * @param c The daily smoked cigarettes
     */
    void set_cigi_szam(int c);
    /**
     * @brief Sets the cost of one pack of cigarettes (in hungarian forints).
     * If the parameter is less than 100, or more than 5000, it throws a cfgv_exception with an error code of 6.
     * This is because it is unrealistic for a pack of cigarettes to cost less than 100 HUF or more than 5000 HUF.
     * @param c The cost of the pack of cigarettes.
     */
    void set_cigi_kolt(int c);
    /**
     * @brief Set the days remaining of the users life.
     * This value is previously calculated, and this function is only used to store the calculation within the user class
     * @param i The days remaining of the users life
     */
    void set_napok_hatra(int i);
    /**
     * @brief Returns the age of the user.
     * @return Age of the user.
     */
    [[nodiscard]] int get_eletkor() const;
    /**
     * @brief Returns the number of cigarettes smoked by the user in one day.
     * @return The number of cigarettes smoked by the user in one day.
     */
    [[nodiscard]] int get_cigi_szam() const;
    /**
     * Return the cost of one pack of cigarettes smoked by user.
     * @return The cost of one pack of cigarettes smoked by user.
     */
    [[nodiscard]] int get_cigi_kolt() const;
    /**
     * Returns the days remaining of the users life.
     * @return The days remaining of the users life.
     */
    [[nodiscard]] int get_napok_hatra() const;
    /**
     * @brief Converts the input string into an enum value that can be used in a switch statement.
     * It checks the predefined unordered map, and if the input is one of the keys (string) of the map, it returns the enum value of that key.
     * If the string is not found in the map, it throws a cfgv_exception with an error code of 1.
     * @param input The string to be searched for in the map
     * @return The corresponding enum value of the input string, if it is found in the map.
     */
    static kontinens enum_converter(const string& input);
    /**
     * @brief Returns the life expectancy of the user based on which continent they live in.
     * It converts the input string with the 'enum_converter' function, and then returns the corresponding integer value.
     * If there is an uncaught error stemming from the 'enum_converter' function, then it throws a cfgv_exception, with an error code of 69.
     * @param input The continent the user lives on.
     * @return The life expectancy of the user based on the continent they inputted.
     */
    static int get_varhato_elet(const string& input);
    /**
     * @brief Calculates then returns the days remaining of the users life.
     * @param input The life expectancy of the user.
     * @return The days remaining in the users life.
     */
    [[nodiscard]] int get_varhato_elet_hatra(int input) const;
    /**
     * @brief Returns the number of cigarettes smoked by the user so far.
     * This calculates with the assumption that the user started smoking at age 16.
     * @return The number of cigarettes smoked by the user so far.
     */
    [[nodiscard]] int get_eddig_szivott_cigi() const;
    /**
     * @brief Returns the amount of money the user spent on cigarettes so far.
     * This takes the number of cigarettes smoked by the user so far from the 'get_eddig_szivott_cigi()' function,
     * and multiplies it with the cost of a pack of cigarettes, divided by 20 (to get the cost of one single cigarette).
     * @return The amount of money the user spend on cigarettes so far.
     */
    [[nodiscard]] int get_eddig_koltott_cigi() const;
     /** @brief Returns the approximate amount of cigarettes user will smoke in the rest of their lifetime.
     * This calculates with the assumption that the user started smoking at age 16.
     * @param input The life expectancy of the user.
     * @return The approximate amount of cigarettes the user will smoke in their lifetime.
     */
    [[nodiscard]] int get_varhato_szivott_cigi(int input) const;
    /**
     * @brief Returns the approximate amount of money the user will spend on cigarettes in the rest of their lifetime
     * @param input The life expectancy of the user
     * @return The amount of money the user will spend
     */
    [[nodiscard]] int get_varhato_koltott_cigi(int input) const;

};


#endif //CIGIFUGGVENYCPP_C_USER_H
