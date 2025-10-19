#include <iostream> //pour cout et cin
#include <vector>

using namespace std;

#include <cstring> // pour strlen
// #include <ctype> // pour toascii

#include "entierlong.h" //pour le type t_EntierLong
#include "operations.h"
#include "utilitaires.h"

t_EntierLong addition_ms(t_EntierLong a, t_EntierLong b)
{
    // initialisation des variable de retenu et de resusltat
    int retenu = 0;
    t_EntierLong res;
    res.negatif = a.negatif; // a et b on le même signe donc le resultat sera du meme signe.

    // boucle pour additionner chaque case du vecteur 1 par 1 en commençant par le poid faible.
    for (int i = 0; i < MAXCHIFFRES; i++)
    {

        res.chiffres[i] = (a.chiffres[i] + b.chiffres[i] + retenu) % 10;

        retenu = ((a.chiffres[i] + b.chiffres[i]) + retenu) / 10;
    }

    return res;
}

// soustraction de même signe avec |a| > |b|
t_EntierLong soustraction_ms(t_EntierLong a, t_EntierLong b)
{

    t_EntierLong res;

    // transmition du signe
    res.negatif = a.negatif;

    // soustraction case par case en commençant par le poid faible
    for (int i = 0; i < MAXCHIFFRES; i++)
    {
        // gestion du système de retenu comme pour les soustractions posées
        if (a.chiffres[i] < b.chiffres[i])
        {
            a.chiffres[i] += 10;
            b.chiffres[i + 1] += 1;
        }

        res.chiffres[i] = (a.chiffres[i] - b.chiffres[i]);
    }

    return res;
}

// addition avec gestion de signe différent
t_EntierLong add(t_EntierLong a, t_EntierLong b)
{
    t_EntierLong res;

    char plusgrand = 'g';
    int i = MAXCHIFFRES - 1;

    // boucle pour chercher le nombre le plus grand des 2 en commençant par le poid fort
    do
    {
        if (a.chiffres[i] != 0 || b.chiffres != 0)
        {
            if (a.chiffres[i] > b.chiffres[i])
            {
                plusgrand = 'a';
            }
            if (a.chiffres[i] < b.chiffres[i])
            {
                plusgrand = 'b';
            }
        }
        i--;
    } while ((plusgrand != 'a') && (plusgrand != 'b') && (i > 0));

    // en cas de signes identiques on réalise l'addtion classqiue
    if (a.negatif == b.negatif)
    {

        res = addition_ms(a, b);
    }
    else // sinon on réalise une soustraction du nombre le plus grand par le nombre le plus petit
    {
        if (plusgrand == 'a')
        {

            res = soustraction_ms(a, b);
            res.negatif = a.negatif;
        }
        else if (plusgrand == 'b')
        {
            res = soustraction_ms(b, a);
            res.negatif = b.negatif;
        }
    } // le resultat prend le signe du plus grand
    return res;
}

// la soustration est une addition avec un changement du signe du deuxième nombre
t_EntierLong sous(t_EntierLong a, t_EntierLong b)
{

    b.negatif = !b.negatif;
    return add(a, b);
}


/**
 * @brief 
 * fonction servant à la multiplication en faisant une suite d'addition
 * la boucle additionne 'a' n fois avec n=limite
 * 
 * @param a 
 * @param limite 
 * @return int 
 */
int suiteadd(t_EntierLong a, int limite)
{
    t_EntierLong res = inttolong(0);

    for (int i = 0; i < limite; i++)
    {
        res = add(res, a);

        
    }

    return longtoint(res);
}



/**
 * @brief 
 * comme une multiplication posé, on va multiplier a par chaque valeur de b
 * en y multipliant le resltat par 10^i de la boucle de b.
 * ces valeurs seront stocké dans un vecteur d'entier long
 * 
 * 
 * @param a 
 * @param b 
 * @return t_EntierLong 
 */

t_EntierLong mult(t_EntierLong a, t_EntierLong b)
{



    vector<int> listeadd; // vecteur qui va contenir l'ensemble des additions réalisées.

    // cette boucle va rajouter au vecteur la somme 'a' n fois par l'unité de 'b', puis la dizaine de 'b', la centaine de 'b', etc...
    for (int i = 0; i < MAXCHIFFRES - 1; i++)
    {
        listeadd.push_back(suiteadd(a, b.chiffres[i]));
    }

    // on fait la somme des termes du vecteur en rajoutant un nouveau 0 a la fin du terme i fois.
    int somme = 0;
    int puissance = 1;
    for (int i = 0; i < sizeof(listeadd) - 1; i++)
    {

        somme += (listeadd[i] * puissance);
        puissance*=10;
    }

    // transmition du signe, + si meme signe sinon -
    t_EntierLong res;
    res = inttolong(somme);

    if (a.negatif != b.negatif)
    {
        res.negatif = true;
    }
    else
    {
        res.negatif = false;
    }

    return res;
}
