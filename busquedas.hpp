//
//  busquedas.hpp
//  Algoritmos_busqueda_5tipos
//
//  Created by Matías Méndez on 29/08/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef busquedas_hpp
#define busquedas_hpp

#include <stdio.h>
using namespace std;
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

template <class T>
class Busquedas{
private:
    vector<T> elementos;
    //valor a buscar
    int tamArreglo;
    
public:
    int repeat = 10;
    Busquedas();
    Busquedas(vector<T> );
    //busq secuencial
    int bSec(T);
    //busq secuencial de movimiento al frente
   int bSecMoviFrente(T);
    // busq transposición, se intercambia de lugar el elemento buscado, con el primero del vector
    int bTrans(T);
    int bSecOrden(T);
    int bBinaria(T);
    
    
    
};

template <class T>
Busquedas<T>::Busquedas(){
    tamArreglo=0;
    
}

template <class T>
Busquedas<T>::Busquedas(vector<T> elem){
    //typecast a int
    tamArreglo = (int) elem.size();
    
    elementos = elem;
}

template <class T>
//mientras el valor encontrado no sea 1 y la cantidad de bsuqedas (i), no exceda el tamaño del arreglo, se ejecutar el ciclo 
int Busquedas<T>::bSec(T val){
    
        int i = 0;
        int encontrado = -1;

        while (encontrado == -1 && i< tamArreglo ) {
            if (elementos[i] == val) {
                encontrado = i;
                // se termina de contar tiempo
            }
            ++i;
        }
    return encontrado;
}

 template <class T>
 int Busquedas<T>::bSecMoviFrente(T val ){

        int i = 0;
        int encontrado = -1;
        
        while (encontrado == -1 && i < tamArreglo) {
            if (elementos[i] == val) {
                encontrado = i;
                
                
                //se me había ocurrido que sí ya estaba al frente el valor, con un if  se ahorraría el proceso y se fuera directo a sólo imprimir que ya está en la posición 0
                //if (encontrado != 1){
                int primero = elementos.at(encontrado);
                    for (int i= encontrado; i >= 1; --i){
                        //va ir recorriendo todos los elementos para atrás
                        elementos.at(i) = elementos.at(i-1);
                    }//for
                
                //el elemento encontrado lo cambia hasta delante
                elementos.at(0) = primero;
                
                
                
            }//if
            ++i;
    }//while
    return encontrado;
    
}// funcion

 
template <class T>
int Busquedas<T>::bTrans(T val){
 
     int i = 0;
    int encontrado = -1;
     
     while (encontrado == -1 && i< tamArreglo ) {
         if (elementos[i] == val) {
             encontrado = i;
             
             int nueva = elementos.at(encontrado);
             //es importante que aqui sea 0
             int primer = elementos.at(0);
             
             //el elemento encontrado se cambia al primero
             //es importante que aqui sea 0
             elementos.at(0) = nueva;
             //el primer numero se pasa para atrás
             elementos.at(encontrado) = primer;
             

         }
         ++i;
     }//while
return encontrado;
    
}

template <class T>
int Busquedas<T>::bSecOrden(T val){
    //ordenarlos
    sort(elementos.begin(), elementos.end());
        
    int i = 0;
    int encontrado = -1;
    
            while (encontrado == -1 && i < tamArreglo) {
                if (elementos[i] == val) {
                    encontrado = i;

                }
                ++i;
            }
    return encontrado;
        
}

template <class T>
int Busquedas<T>::bBinaria(T val){
    
    sort(elementos.begin(), elementos.end());
    
        
        int inf = 0;
        //aqui no estoy seguro si es así
        int sup = tamArreglo;
        int mitad = (inf + sup)/2;
        int encontrado = -1;

        
        while (encontrado == -1 ) {
            if (elementos[mitad] == val) {
                encontrado = mitad;
            }//if
            
            if (elementos[mitad] > val){
                sup = mitad;
                mitad = (inf + sup)/2;
            }
            
            if (elementos[mitad] < val){
                inf = mitad;
                mitad = (inf + sup)/2;
            }
            
            //se acabará el ciclo cuando cuando se encuentre el número, mientras tanto solo seguirá partiendose en mitades
            
        }//while
    return encontrado;
}


#endif /* busquedas_hpp */
