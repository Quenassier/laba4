#include <iostream>
#include <fstream>

using namespace std;

int num(int b)
{
	if (b < 10 , b >= 0)
	{
		return 1;
	}
	else if (b > 9 , b <= 99)
	{
		return 2;
	}
	else if (b > 99 , b <= 999)
	{
		return 3;
	}
	else
		return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");

	ifstream f_input;
	ofstream f_output;
	ofstream result("result.txt");

	int number;
	int numberInTheFile;
	int counter = 0;
	int counter1 = 0;
	int counter2 = 0;

	do
	{
		cout << "Введите положительное число:";
		cin >> number;

		if (number != 0)
		{
			f_output.open("number.txt", std::ofstream::app);

			if (!f_output.is_open())
			{
				cout << "Ошибка открытия файла";
				return 1;
			}
			else
			{
				f_output << number << '\n';
				f_output.close();
			}

		}

	} while (number != 0);

	f_input.open("number.txt", std::ios_base::in);

	if (!f_input.is_open())
	{
		cout << "Ошибка открытия файла";
		return 1;
	}
	else
	{
		while (f_input >> numberInTheFile)
		{

			if (num(numberInTheFile) == 1)
			{
				counter++;
			}
			else if (num(numberInTheFile) == 2)
			{
				counter1++;
			}
			else if (num(numberInTheFile) == 3)
			{
				counter2++;
			}
			else if (numberInTheFile > 999)
			{
				cout << "Число " << numberInTheFile << " больше 999" << '\n';
			}
			else
			{
				cout << "Число " << numberInTheFile << " отрицательное" << '\n';
			}



		}
		f_input.close();
		if (number == 0)
		{
			result << "Количество однозначных чисел: " << counter << '\n' <<
				"Количество двухзначных чисел: " << counter1 << '\n' <<
				"Количество трехзначных чисел: " << counter2 << '\n';
		}

	}
	return 0;
}
