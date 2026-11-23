#include <iostream>
using namespace std;
int main (){

    //algoritmo ordenamiento por incercion 

    /*pos = Posición / índice actual donde se está evaluando 
    o insertando el elemento tomado.*/
    /*aux = guarda una copia del número numeros[i] antes de que los
     elementos mayores se desplacen a la derecha y sobrescriban esa casilla.*/

    int pos,aux,i; 

    //arreglo de 5 posiciones
int numeros[]{9,2,6,1,8};

/*ciclo externo que inicia i en 0, continúa mientras i sea menor que 5 
(0, 1, 2, 3, 4) e incrementa i en 1 por iteración.*/
for(i=0;i<5;i++){
pos = i;
aux = numeros[i];

//ciclo condicional que se repite mientras se cumplan dos condiciones a la vez//
//pos > 0: todavía hay posiciones a la izquierda (no se ha llegado al índice 0).//
while ((pos>0) &&  (numeros[pos-1]) > aux ){
    //el elemento inmediatamente anterior es mayor que aux.
    numeros[pos] = numeros[pos-1];
    //copia el valor mayor de numeros[pos-1] una posición hacia la derecha (numeros[pos]).
    pos--;
    //decrementa pos en 1 (pos = pos - 1).
numeros[pos] = aux; 
//coloca el valor de aux en la posición pos actual.
}
}
//recorre los índices de 0 a 4 de izquierda a derecha
cout<<"orden ascendente: ";
for(i=0;i<5;i++){   
    cout<<numeros[i]<<" ";
}

cout<<"\norden decendente: ";
/*inicia i en 4, continúa mientras i sea mayor o igual que 0 (i >= 0) 
y resta 1 en cada vuelta (i--)*/
for(i=4;i>=0;i--){
    cout<<numeros[i]<<" ";
}   

    return 0;
}