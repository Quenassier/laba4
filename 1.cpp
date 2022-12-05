#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

void all(int x);

int main(){
    setlocale(LC_ALL,"Russian");
    int number;
    ifstream f1;
    f1.open("numbers.txt");
    
    while(!f1.eof()){
        f1>>number;
        all(number);
   }
    f1.close();
}
void all(int x){
    int number1 = x/100 ,number2 = (x/10)%10 ,number3 = x%10;
    int sum,proiz;
    double arethm;
    sum = number1 + number2 + number3;
    proiz = number1 * number2 * number3;
    arethm = (number1 + number2 + number3)/3;
    printf("summa - %d,umnozhenie - %d,areth - %0.2lf \n",sum,proiz,arethm);
}
