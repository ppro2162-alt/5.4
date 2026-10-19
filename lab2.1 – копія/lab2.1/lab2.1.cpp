// Lab_02.cpp
//<Ivan Stasiuk>
//Лабораторна робота №2.
//Лінійні програми.
//Варіант 27
#include <iostream>
#include <cmath>
using namespace std;	
int main() 
{ 
	double Pi = 4 * atan(1.0); //Число пі
	double alpha; //Вхідний параметр
	double z1; //Результат обчислення виразу 1
	double z2; //Результат обчислення виразу 2
	
	cout << " alpha = "; cin >> alpha; //Запит на введення значення параметра
		z1 = pow(cos(3. / 8 * Pi - alpha / 4) , 2) - pow(cos(11. / 8 * Pi + alpha / 4) , 2);
	    z2 = sqrt(2.)/2 * sin(alpha/2); 
		cout << endl;
		cout << "z1 = " << z1 << endl; //Виведення результату обчислення виразу 1
		cout << "z2 = " << z2 << endl; //Виведення результату обчислення виразу 2
		


		cin.get();
		cin.get();
		return 0;
}  