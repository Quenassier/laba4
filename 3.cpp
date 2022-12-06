#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool file_Output(int b, int c)
{
	ofstream fout;


	fout.open("number.txt", std::ofstream::app);

	if (!fout.is_open())
	{
		return false;
	}
	else
	{
		fout << b << '\n' << c << '\n';
		fout.close();
		return true;
	}

}
bool file_Input(int a)
{
	ofstream result("result.txt", std::ofstream::app);
	ifstream fin;

	fin.open("number.txt", std::ios_base::in);

	if (!fin.is_open())
	{
		return false;
	}
	else
	{

		result << "Наибольший общий делитель равен: " << a << '\n';
		return true;

	}
}
void NOD(int firstNumber, int secondNumber)
{
	while (true)
	{
		if (firstNumber == secondNumber)
		{
			file_Input(firstNumber);
			return;
		}
		else if (firstNumber > secondNumber)
		{
			firstNumber -= secondNumber;
		}
		else
		{
			secondNumber -= firstNumber;
		}
	}
}



int main()
{
	setlocale(LC_ALL, "ru");
	int num1;
	int num2;
	int count = 0;

	cout << "Введите 2 положительных числа: ";
	cin >> num1;
	cin >> num2;
	if (num1 > 0 && num2 > 0)
	{
		file_Output(num1, num2);
		NOD(num1, num2);
	}
	else
	{
		cout << "нельзя";
	}
	return 0;
}
