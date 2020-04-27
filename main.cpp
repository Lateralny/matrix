/*
autor: Piotr G³adysz
numer albumu: 116967
email: piotrjgladysz@gmail.com
powtarzanie przedmiotu
Microsoft Visual Studio Enterprise 2017
Wersja 15.7.2
VisualStudio.15.Release/15.7.2+27703.2018
*/

#include "Matrix.h"
#include <iostream>

using namespace std;

int main()
{
	int kolumna, wiersz, bruh;
	cout << "Wprowadz ilosc wierszy macierzy:" << endl;
	cin >> wiersz;
	cout << "Wprowadz ilosc kolumn macierzy:" << endl;
	cin >> kolumna;
	cout << "Wprowadz liczbe ktora chcesz wypelnic macierz:" << endl;
	cin >> bruh;

	Matrix macierz1(wiersz, kolumna);
	Matrix macierz2(wiersz, kolumna);
	Matrix macierz3(wiersz);
	Matrix macierz7(wiersz, kolumna);
	Matrix macierz8(wiersz, kolumna);

	for (int i = 0; i < wiersz; i++)
	{
		for (int j = 0; j < kolumna; j++) macierz1.set(i,j,bruh);
	}
	cout << '\n'<<"Macierz prostokatna\n";
	macierz1.print();
	cout << "=============\n";
	
	cout << "Macierz kwadratowa\n";
	macierz3.print();
	cout << "=============\n"<<'\n';
	
	macierz1.set(1, 1, 9.0);//na sztywno ustawiam te wartosci
	macierz2.set(2, 2, 8.0);//poniewaz jest napisane aby
	macierz2.set(1, 1, 8.0);//jedynie zademonstrowac dzialanie
							// programu

	macierz7.set(1, 1, 3.0);
	macierz8.set(1, 1, 3.0);

	Matrix* wynikowa_add = macierz1.add(macierz2);
	cout << "Dzialania na macierzach\n";
	cout << "Dodawanie macierzy\n";
	macierz1.print();
	cout << "=============\n";
	macierz2.print();
	cout << "=============\n";
	wynikowa_add->print();
	cout << '\n';
	
	cout << "Dodawanie macierzy operatorem '+'\n";
	Matrix operator_add = macierz1 + macierz2;
	macierz1.print();
	cout << "=============\n";
	macierz2.print();
	cout << "=============\n";
	operator_add.print();
	cout << '\n';
	
	Matrix* wynikowa_sub = macierz1.subtract(macierz2);
	cout << "Odejmowanie macierzy\n";
	macierz1.print();
	cout << "=============\n";
	macierz2.print();
	cout << "=============\n";
	wynikowa_sub->print();
	cout << '\n';

	Matrix operator_sub = macierz1 - macierz2;
	cout << "Odejmowanie macierzy operatorem '-'\n";
	macierz1.print();
	cout << "=============\n";
	macierz2.print();
	cout << "=============\n";
	operator_sub.print();
	cout << '\n';
	
	
	Matrix* wynikowa_multi = macierz1.multiply(macierz2);
	cout << "Mnozenie macierzy\n";
	macierz1.print();
	cout << "=============\n";
	macierz2.print();
	cout << "=============\n";
	wynikowa_multi->print();
	cout << '\n';

	Matrix operator_multi = macierz1 * macierz2;
	cout << "Mnozenie macierzy operatorem '*'\n";
	macierz1.print();
	cout << "=============\n";
	macierz2.print();
	cout << "=============\n";
	operator_multi.print();
	cout << '\n';
	
	bool wynik_por = macierz7 == macierz8;
	cout << "porownanie macierzy operator ==\n";
	cout << "zapis bolean: 1 - prawda, 0 - falsz\n";
	cout << macierz7; //wykorzystanie przeladowanego operatora << (zamiast macierz7.print();)
	cout << "=============\n";
	cout << macierz8; //wykorzystanie przeladowanego operatora << (zamiast macierz8.print();)
	cout << "=============\n";
	cout << "wynik porownania: " << wynik_por << "\n";
	macierz1.cols();
	macierz1.rows();

	cout << '\n';
	cout << "printowanie wybranego wiersza za pomoca przeladowanego operatora[]\n";
	std:list<double> jakis_wiersz = macierz1[1];
	for (int n : jakis_wiersz) {
		std::cout << n << ' ';
	}
	cout << "\n";

	cout << '\n';
	cout << "Macierz pobrana z pliku"<< endl;
	macierz1.store("MacierzPlik", "C:\\Users\\piotr\\Desktop\\"); //aby obs³uga pliku dzialala nalezy tylko zamienic sciezke
	Matrix macierz4("C:\\Users\\piotr\\Desktop\\MacierzPlik.txt"); //jak wyzej
	macierz4.print();

	system("pause");
	return 0;
}
