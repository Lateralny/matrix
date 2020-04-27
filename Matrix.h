#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <list>

class Matrix
{
	double **tab;
	int m_, n_;
	std::string path;
	std::string filename;
	std::string gosciu;

public:
	Matrix(int, int);//macierz o podanych rozmiarach
	Matrix(int);//macierz kwadratowa o podanych rozmiarach
	Matrix(std::string);
	Matrix operator+(Matrix &m2);
	Matrix operator-(Matrix &m2);
	Matrix operator*(Matrix &m2);
	bool operator==(Matrix &m2);
	friend std::ostream & operator<<(std::ostream &s, Matrix &m2);
	std::list<double> operator[](int index);
	void set(int m, int n, double val);
	double get(int m, int n); // m,n
	void print();

	Matrix* add(Matrix m2);
	Matrix* subtract(Matrix m2);
	Matrix* multiply(Matrix m2);

	void cols();
	void rows();

	void store(std::string filename, std::string path);
	~Matrix();
};