////////////////////////
//Matrix.h
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Matrix
{
	class Row
	{
	public:
		int* v;
		Row(int C = 1);
		int& operator [] (int j);
	};
	int K, N;
	Row* m;
public:
	Matrix(); 
	Matrix(int R, int C); 
	Matrix(const Matrix&); 
	~Matrix(); 
	int getN() const { return N; }; 
	int getK() const { return K; };
	void SetK(int K) { this->K = K; };
	void SetC(int C) { this->N = C; };
	Matrix& operator=(const Matrix&); 
	operator string () const; 
	friend istream& operator >> (istream& in, Matrix& r); 
	friend ostream& operator <<(ostream& out, const Matrix& r); 
	Row& operator [] (int i); 
	friend Matrix operator + (Matrix r, Matrix l); 
	bool Compare(Matrix r, Matrix l); 
	double Norm(Matrix r); 

};

