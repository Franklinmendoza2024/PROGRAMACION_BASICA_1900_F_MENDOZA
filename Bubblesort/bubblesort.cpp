#include <iostream>
using namespace std;
int main () {
    // arreglo de numeros a ordenar
int numeros [] = {22, 44, 33, 11, 55};
//  i = contador de ciclos, j = contador de ciclos
// aux = variable auxiliar para el intercambio de valores
// aux Guarda temporalmente un valor para no sobrescribirlo ni perderlo al intercambiar dos posiciones del arreglo
int i,j,aux;

//algoritomo del metodo burbuja 

//inicia el ciclo externo desde i = 0 mientras i sea menor que 5, sumando 1 en cada vuelta (i++).
for(i=0;i<5;i++){ 

    //inicia el ciclo interno desde j = 0 mientras j sea menor que 5, avanzando de uno en uno (j++).
    for(j=0;j<5;j++){

        //comprueba si el elemento actual es mayor que el elemento que está justo a su derecha.
       if (numeros[j] > numeros[j+1] ){

        //copia el valor de numeros[j] dentro de aux
        aux = numeros[j];

        //mueve el valor menor (que estaba a la derecha) hacia la posición j (a la izquierda).
        numeros[j] = numeros[j+1];

        //coloca el valor guardado en aux (el mayor) en la posición j + 1 (a la derecha).
        numeros[j+1] = aux;
        }
    }
}

cout<<"orden ascendente: "; 

//recorre los índices del arreglo desde 0 hasta 4
for(i=0;i<5;i++){
    cout<<numeros[i]<<" ";
}


cout<<"\norden decendente: ";

//inicia i en 4 (último índice del arreglo), continúa mientras i sea mayor o igual que 0 (i >= 0) y resta 1 en cada paso (i--).
for(i=4;i>=0;i--){
cout<<numeros[i]<<" "; 

}

    return 0;
}