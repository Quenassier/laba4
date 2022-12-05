#include <iostream>
#include <fstream>
#include <locale.h>
#include <vector>
#include <cmath>
using namespace std;

double get_S(double n1, double n2, double n3) {
    double P, S;
    P = (n1 + n2 + n3) / 2;
    S = pow((P * (P - n1) * (P - n2) * (P - n3)), 0.5);
    cout << S << "\n";
    return S;
}

std::vector<double> get_v() {
    int number;
    vector<double> all;
    ifstream f1;
    f1.open("number.txt");

    while (!f1.eof()) {
        f1 >> number;
        all.push_back(number);
    }
    f1.close();

    f1.open("number.txt");
    f1 >> number;
    all.push_back(number);

    f1.close();
    return all;

}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<double> all_n;
    all_n = get_v();
    double S = 0;
    
    for(int i = 0; i < all_n.size() - 2 ;i++){
        S += get_S(all_n[i], all_n[i+1], all_n[i+2]);
        cout<<endl;
    }
    cout<<"S 12-ugolnika - "<<S;
}
