/**
 * @file utilitaires.cpp
 * @author Simon l'Hinguerat && Jean-Marc KERVIL
 * @brief 
 * Ce fichier définit les fonctions
 * - inttolong() permet de convertir un int en long
 * - longtoint() permet de convertir un long en int
 * - Egalite() Test l'egalité entre 2 long
 * - EgaliteAbs() Test l'egalité absolue entre 2 long
 * 
 * 
 * @version 0.1
 * @date 2025-10-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "utilitaires.h"
#include <iostream>

using namespace std;

/**
 * @brief Cette fonction permet de convetir un entier 
 * de type int en entier long de type t_EntierLong
 *
 * @param chiffre
 * @return t_EntierLong
 */

t_EntierLong inttolong(int chiffre)
{
    struct t_EntierLong Long; // definition d'une structure Long
    int unit = 0;
    if (chiffre < 0)
    {                        // controle du signe de notre chiffre d'entré
        Long.negatif = true; // mise à 1 de la variable negatif, qui corre'spond au signe de notre entier long
        chiffre *= -1;
    }
    else
    {
        Long.negatif = false; // mise à 1 de la variable negatif, qui corre'spond au signe de notre entier long
    }

    for (int i = 0; i < 20; i++)
    { // tant que l'on divise par une puissance de 10 et que l'on a un resultat supperieur a 0 on continue
        unit = (chiffre % 10);
        Long.chiffres[i] = unit; // ici on inverse les chiffres de chiffre et on les ajoutent dans le tableau de Long.chiffres  chiffre %(int)10^(i)
        chiffre = chiffre / 10;
        // Long.chiffres[i] =0;
    }

    return (Long); // on retourne notre structure
}
/**
 * @brief 
 * permet de convertir un chiffre de type t_EntierLong
 * en entier de type int
 *
 * @param a
 * @return int
 */
int longtoint(t_EntierLong a)
{
    int res = 0;
    int puissance = 1;

    for (int i = 0; i < MAXCHIFFRES; i++)
    {
        res += a.chiffres[i] * puissance;
        puissance *= 10;
    }

    return res;
}

/**
 * @brief
 * Cette fonction contrôle l'égalite entre 2 chiffre de type 
 * t_EntierLong en prennant en compte le signe
 * 
 *
 * @param a
 * @param b
 * @return true
 * @return false
 */
bool Egalite(t_EntierLong a, t_EntierLong b)
{
    bool egal;
    int nbr = 0;

    if (a.negatif == b.negatif)
    { // control du meme signe, pour l'égalité
        // control de la meme valeur de la partie chiffre des chiffres d'entrée
        for (int i = 0; i < 20; i++)
        {
            if (a.chiffres[i] == b.chiffres[i]) // comparaison pour controller que chaque chiffre du tableau de numéros de a ou de b correspondent
            {
                nbr = nbr + 1; // controle du nombre de chiffres coorect
            }
        }
        if (nbr == 20) // si tous les chiffres sont similaires, on met la sortie a 1
        {
            egal = true;
        }
        else
        {
            egal = false;
        }
    }
    else
    {
        egal = false; // si pas le meme signe, on retourne faux
    }
    return egal; // retour du test de légalité
}
/**
 * @brief
 * Cette fonction contrôle l'égalite absolue entre 2 chiffre de 
 * type t_EntierLong
 *
 * @param a
 * @param b
 * @return true
 * @return false
 */
bool EgaliteAbs(t_EntierLong a, t_EntierLong b)
{
    bool egalAbs;
    int nbr = 0;
    for (int i = 0; i < 20; i++)
    {
        if (a.chiffres[i] == b.chiffres[i]) // comparaison pour controller que chaque chiffre du tableau de numéros de a ou de b correspondent
        {
            nbr = nbr + 1; // controle du nombre de chiffres coorect
        }
    }
    if (nbr == 20) // si tous les chiffres sont similaires, on met la sortie a 1
    {
        egalAbs = true;
    }
    else
    {
        egalAbs = false;
    }
    return egalAbs;
}
