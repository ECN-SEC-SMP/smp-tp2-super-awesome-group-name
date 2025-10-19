/**
 * @file operations.h
 * @author Simon l'Hinguerat && Jean-Marc KERVIL
 * @brief 
 * @version 0.1
 * @date 2025-10-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream> //pour cout et cin
#include <vector>
#include <cstring> // pour strlen
// #include <ctype> // pour toascii

#include "entierlong.h" //pour le type t_EntierLong
#include "utilitaires.h"


t_EntierLong addition_ms(t_EntierLong ,t_EntierLong);
t_EntierLong soustraction_ms(t_EntierLong ,t_EntierLong);
t_EntierLong add(t_EntierLong ,t_EntierLong);
t_EntierLong sous(t_EntierLong ,t_EntierLong);
int suiteadd(t_EntierLong,int);
t_EntierLong mult(t_EntierLong,t_EntierLong);