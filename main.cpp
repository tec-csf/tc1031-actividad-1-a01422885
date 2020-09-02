//
//  main.cpp
//  Algoritmos_busqueda_5tipos
//
//  Created by Matías Méndez on 29/08/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include <iostream>
#include "busquedas.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> elementos;
        
    
        for (int i = 0; i < 100000; ++i) {
            elementos.push_back(rand() % 100);
        }
     //cuando ahces clase generica con template entre las <tipo>  tienes que poner el tipo de dato
    Busquedas<int> bu(elementos);

     for (int i = 0; i < 10; ++i) {
         // SE CREAN VARIABLES TEMPORALES QUE CAMBIAN CON CADA ITERACION (BEGIN,ENCONTRADO, END, ELAPSED) PARA MEDIR TIEMPO
        cout << "Busqueda secuencial en orden "<< endl;
        auto begin2 = chrono::high_resolution_clock::now();
        
         //AQUI PONGO FUNCIÓN A TRABAJAR
        int encontrado2 = bu.bSec(99);
         
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration <double, milli> elapsed2 = end2 - begin2;
        
        cout << "Elemento encontrado en posicion: "<< encontrado2 << endl;
        cout << "en un tiempo en segundos de "<< elapsed2.count() << endl;
         
     }
    


    
    //bu.bBinaria(4);

    
}
