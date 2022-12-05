#include <iostream>
#include <fstream>
#include <locale.h>
#include <cmath>
using namespace std;

int all(int n1,int n2,int n3){
    if(n1+n2<n3 or n1+n3<n2 or n2+n3<n1){
        printf("Треугольника со сторонами (%d,%d,%d) не существует",n1,n2,n3);
        return 0;
    }
    if(n1==n2 and n2==n3 and n1==n3){
        printf("Треугольник со сторонами (%d,%d,%d) является равносторонним",n1,n2,n3);
        return 0;
    }
    if(n1==n2 or n2==n3 or n1 == n3){
        printf("Треугольник со сторонами (%d,%d,%d) является равнобедренным",n1,n2,n3);
        return 0;
    }
    if(n1!=n2 and n2!=n3 and n1!=n3){
        int max = n1,x1 = n2,x2 = n3; 
        
        if(n1<n2){
            max = n2;
            x1 = n1;
            
            if(n2<n3){
                max = n3;
                x2 = n2;
            }
        }
        if(n2<n3){
            max = n3;
            x2 = n2;
            }
        
        if(pow(max,2) == pow(x1,2)+pow(x2,2)){
            printf("Треугольник со сторонами (%d,%d,%d) является прямоугольным",n1,n2,n3);
            return 0;
        }
        else{
            printf("Треугольник со сторонами (%d,%d,%d) является разносторонним",n1,n2,n3);
            return 0;
        }
    }

}

int main(){
    setlocale(LC_ALL,"Russian");
    int n1,n2,n3,sum = 0;
    ifstream f1;
    f1.open("numbers.txt");
    
    while(!f1.eof()){
        f1>>n1;
        f1>>n2;
        f1>>n3;
        all(n1,n2,n3);
   }
    f1.close();
}
