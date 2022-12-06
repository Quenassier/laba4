#include <iostream>
#include <fstream>
#include <locale.h>
using namespace std;

int number(int b)
{
    int count = 1;
    for (int i = 1; i < b; i++)
    {
        
        if (b % i == 0)
        {
            
            count++;
        }
        
    }
    return count;   
}

int main()
{
    setlocale(LC_ALL, "ru");

    ifstream f_input;
    ofstream f_output;
   ofstream result("result.txt ");

    int count = 0;
    int numberInTheFile;
    int num;
    
    do
    {
        cout << "Введите целое число: ";
       cin >> num;

        if (num != 0)
        {
            f_output.open("R.txt" );

            if (!f_output.is_open())
            {
                cout << "Ошибка открытия файла";
                return 1;
            }
            else
            {
                f_output << num << '\n';
                f_output.close();
            }
        }
        else
        {
            cout << "Последовательность завершена!";
        }
    } while (num != 0);

    f_input.open("R.txt", ios_base::app);

    if (!f_input.is_open())
    {
        cout << "Ошибка открытия файла";
        return 1;
    }
    else
    {
        while (f_input >> numberInTheFile)
        {
            
            result << number(numberInTheFile) << endl;
                   
        }
       result << "Общие количество простых чисел в последовательности равно: " << count;
       f_input.close();
    }
    return 0;

}
