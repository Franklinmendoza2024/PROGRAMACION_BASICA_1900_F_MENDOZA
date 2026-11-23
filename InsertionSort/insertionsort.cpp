#include <iostream>
using namespace std;
int main (){

    //algoritmo ordenamiento por incercion 
int pos,aux,i;
int numeros[]{9,2,6,1,8};

for(i=0;i<5;i++){
pos = i;
aux = numeros[i];

while ((pos>0) &&  (numeros[pos-1]) > aux ){
    numeros[pos] = numeros[pos-1];
    pos--;
numeros[pos] = aux; 
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