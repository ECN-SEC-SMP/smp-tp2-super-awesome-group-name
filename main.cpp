#include <iostream>
#include "entierlong.h"
#include "lit_ecrit.h"
#include "utilitaires.h"



using namespace std;

int main ( ){
    int nbr;
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

    
    bool Egal;
    Egal = Egalite(byo,ayo);
    if (Egal ==1)
    {
        cout <<"Les 2 chiffres sont egaux\n";
    }
    else{
        cout <<"Les 2 chiffres ne sont pas egaux\n";
    }
    bool EgalAbs;
    EgalAbs = EgaliteAbs(byo,ayo);
    if (EgalAbs ==1)
    {
        cout <<"Les 2 chiffres sont egaux absolu\n";
    }
    else{
        cout <<"Les 2 chiffres ne sont pas egaux absolu\n";
    }
    

}