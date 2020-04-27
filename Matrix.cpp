#include "Matrix.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
using namespace std;

Matrix::Matrix(int m, int n)//macierz o podanych rozmiarach
{
	int i, j;
	this->m_ = m;
	this->n_ = n;

	tab = new double *[m];
	for (i = 0; i < m; i++) tab[i] = new double[n];
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) tab[i][j] = 0.0;
}

Matrix::Matrix(int m)//macierz kwadratowa
{
	this->m_ = m;
	this->n_ = m;
	int i, j;

	tab = new double *[m];
	for (i = 0; i < m; i++) tab[i] = new double[m];
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++) tab[i][j] = 0.0;
}
Matrix::Matrix(string gosciu)
{
	string line;
	const char* path_c = gosciu.c_str();
	ifstream fsi(path_c);
	if (fsi.is_open())
	{
		int m, n;
		fsi >> m >> n;

		this->m_ = m;
		this->n_ = n;

		tab = new double*[m_];
		for (int i = 0; i < m_; ++i)
			tab[i] = new double[n_];

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				fsi >> tab[i][j];

		fsi.close();
	}
	else cout << "Nie mo¿na otworzyæ pliku." << endl;
}
 Matrix Matrix::operator+(Matrix &m2)
{
	Matrix* operator_add = new Matrix(this->m_, this->n_);
	for (int i = 0; i < m_; i++)
		for (int j = 0; j < n_; j++)
			operator_add->set(i, j, this->get(i, j) + m2.get(i, j));
	return *operator_add;

}
 Matrix Matrix::operator-(Matrix & m2)
 {
	 Matrix* operator_sub = new Matrix(this->m_, this->n_);
	 for (int i = 0; i < m_; i++)
		 for (int j = 0; j < n_; j++)
			 operator_sub->set(i, j, this->get(i, j) - m2.get(i, j));
	 return *operator_sub;
 }
 Matrix Matrix::operator*(Matrix & m2)
 {
	 Matrix* operator_multi = new Matrix(this->m_, this->n_);
	 for (int i = 0; i < m_; i++)
		 for (int j = 0; j < n_; j++)
			 operator_multi->set(i, j, this->get(i, j) * m2.get(i, j));
	 return *operator_multi;
 }
 bool Matrix::operator==(Matrix & m2)
 {
	 //Matrix* por = new Matrix(this->m_, this->n_);
	 for (int i = 0; i < m_; i++)
		 for (int j = 0; j < n_; j++)
			 if (this->get(i, j) != m2.get(i, j))
				 return false;
	 return true;
 }
 std::ostream & operator<<(std::ostream & s, Matrix & m2)
 {
	 for (int i = 0; i < m2.m_; i++)
	 {
		 for (int j = 0; j < m2.n_; j++) s << m2.tab[i][j] << " ";
		 s << endl;
	 }
	 return s;
 }
 std::list<double> Matrix::operator[](int index)
 {
	 std::list<double> tmpList;
	 for (int i = 0; i < n_; i++)
		 tmpList.push_back(tab[index][i]);
	 return tmpList;
 }
void Matrix::set(int m, int n, double val)
{
	tab[m][n] = val;
}
double Matrix::get(int m, int n)
{
	return tab[m][n];
}
void Matrix::print()
{
	for (int i = 0; i < m_; i++)
	{
		for (int j = 0; j < n_; j++) cout << tab[i][j] << " ";
		cout << endl;
	}
}
Matrix* Matrix::add(Matrix m2)
{
	Matrix* wynikowa_add = new Matrix(this->m_, this->n_);
	for (int i = 0; i < m_; i++)
		for (int j = 0; j < n_; j++)
			wynikowa_add->set(i, j, this->get(i, j) + m2.get(i, j));
	return wynikowa_add;
}
Matrix * Matrix::subtract(Matrix m2)
{
	Matrix* wynikowa_sub = new Matrix(this->m_, this->n_);
	for (int i = 0; i < m_; i++)
		for (int j = 0; j < n_; j++)
			wynikowa_sub->set(i, j, this->get(i, j) - m2.get(i, j));
	return wynikowa_sub;
}
Matrix * Matrix::multiply(Matrix m2)
{
	Matrix* wynikowa_multi = new Matrix(this->m_, this->n_);
	for (int i = 0; i < m_; i++)
		for (int j = 0; j < n_; j++)
			wynikowa_multi->set(i, j, this->get(i, j) * m2.get(i, j));
	return wynikowa_multi;
}
void Matrix::cols()
{
		cout << "Liczba kolumn: " << n_ << endl;
}
void Matrix::rows()
{
	cout << "Liczba wierszy: " << m_ << endl;
}
void Matrix::store(std::string filename,std::string path)
{
	std::ofstream fs;
	string tmp;
	tmp += path;
	tmp += filename;
	tmp += ".txt";
	const char* cstr = tmp.c_str();
	fs.open(cstr, ios::out);
	if (fs.is_open())
	{
		fs << this->m_ << " " << this->n_ << endl;
		for (int i = 0; i < m_; i++)
		{
			for (int j = 0; j < n_ - 1; j++)
			{
				fs << to_string(tab[i][j]) << " ";
			}
			fs << to_string(tab[i][n_ - 1]) << endl;
		}
		fs << flush;
		fs.close();
	}
	else cout << "Nie mozna otworzyc pliku." << endl;
}
Matrix::~Matrix()
{
	if (tab == nullptr)
		for (int i = 0; i < m_; i++)
			delete[] tab[i];
	//delete[] tab;
}

