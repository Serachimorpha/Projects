#include <iostream>
#include <thread>
using namespace std;

void hilo1(){
    cout<<"HOLA"<<endl;
}

int main(){
    thread t1(hilo1);
    t1.join(); //ESPERA A QUE EL HILO t1 termine
    cout<<"ADIOS"<<endl;
}