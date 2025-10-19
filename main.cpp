/**
 * @file main.cpp
 * @author Simon l'Hinguerat && Jean-Marc KERVIL
 * @brief 
 * Le main du programme, qui nous permet de tester toutes nos focntions
 * @version 0.1
 * @date 2025-10-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include "entierlong.h"
#include "lit_ecrit.h"
#include "operations.h"
#include"utilitaires.h"
using namespace std;


int main ( ){

    //définition des variables
    int nbr;
    t_EntierLong res ; 

    //entrée des 2 chiffres pour tester notre programme
    cout << "Bonjour à vous\n" ;
    cout << "Entrez un entier positif ou négatif\n";

    t_EntierLong ayo = litEntierLong();
    cout << "Vous avez entré "; 
    afficheEntierLong(ayo);

    cout << "Entrez un entier positif ou négatif\n";
    cin >> nbr;
    t_EntierLong byo = inttolong(nbr);
    cout << "Vous avez entré "; 
    afficheEntierLong(byo);

    // test de l'égalité avec le signe
    bool Egal;
    Egal = Egalite(byo,ayo);
    if (Egal ==1)
    {
        cout <<"Les 2 chiffres sont egaux\n";
    }
    else{
        cout <<"Les 2 chiffres ne sont pas egaux\n";
    }

    // test de l'égalité sans le signe
    bool EgalAbs;
    EgalAbs = EgaliteAbs(byo,ayo);
    if (EgalAbs ==1)
    {
        cout <<"Les 2 chiffres sont egaux absolu\n";
    }
    else{
        cout <<"Les 2 chiffres ne sont pas egaux absolu\n";
    }

    //test de l'addition sans signe
    cout <<"Le résultat de l'addition sans le signe : \n";
    res = addition_ms(ayo,byo);
    afficheEntierLong(res);
    cout << "\n";

    //test de l'addition avec signe
    cout <<"Le résultat de l'addition avec le signe : \n";
    res = add(ayo,byo);
    afficheEntierLong(res);
    cout << "\n";

    // test de la soustraction sans le signe
    cout <<"Le résultat de la soustraction sans le signe : \n";
    res = soustraction_ms(ayo,byo);
    afficheEntierLong(res);
    cout << "\n";

    // test de la soustraction avec le signe
    cout <<"Le résultat de la soustraction avec le signe : \n";
    res = sous(ayo,byo);
    afficheEntierLong(res);
    cout << "\n";

    // test de la multiplication avec le signe
    cout <<"Le résultat de la multiplication avec le signe : \n";
    res = mult(ayo,byo);
    afficheEntierLong(res);
    cout << "\n";

    return 0;
}