#include <iostream>
using namespace std;

/*void functionMas(int a, int b){
    cout << "La solución es " << (a + b) << "\n"; 
}

void functionMult(double a, double b){
    cout << "La solucion es " << (a * b) << "\n";
}

int main(){
    functionMas(4, 2);
    functionMult(4.2, 2.2);
}*/

// overloaded function
int operate (int a, int b){
    return (a*b);
}

float operate (float a, float b){
    return (a/b);
}

int main (){

    int x=5, y=2;
    float n=5.0, m=2.0;

    cout << operate (x,y);
    cout << "\n";
    cout << operate (n,m);
    cout << "\n";

    return 0;
}