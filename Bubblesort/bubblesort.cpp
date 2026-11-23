#include <iostream>
using namespace std;
int main () {
int numeros [] = {11, 22, 33, 44, 55};
int i,j,aux;
//algoritomo del metodo burbuja 
for(i=0;i<5;i++){
    for(j=0;j<5;j++){
       if (numeros[j] > numeros[j+1] ){
        aux = numeros[j];
        numeros[j] = numeros[j+1];
        numeros[j+1] = aux;
        }
    }
}

cout<<"orden ascendente: "; 
for(i=0;i<5;i++){
    cout<<numeros[i]<<" ";
}


cout<<"\norden decendente: ";

for(i=4;i>=0;i--){
cout<<numeros[i]<<" "; 

}

    return 0;
}