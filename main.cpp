#include <iostream>

#include "entierlong.h"
#include "lit_ecrit.h"
#include "operations.h"
#include"utilitaires.h"
using namespace std;


int main ( ){
     
    t_EntierLong ayo1 = litEntierLong();
    t_EntierLong ayo2 = litEntierLong();

    
    
    afficheEntierLong(mult(ayo1,ayo2));
    

    return 0;
}