/////////////////////
//Matrix.cpp
#include "Matrix.h"
using namespace std;
Matrix::Row::Row(int C)
{
	v = new int[C];
	for (int j = 0; j < C; j++)
		v[j] = 0;
}
int& Matrix::Row::operator[](int j)
{
	return v[j];
}

Matrix::Matrix()
{
	K = 3;
	N = 3;
	m = new Row[K];
	for (int i = 0; i < K; i++)
	{
		m[i] = Row(N);
	}
}
Matrix::Matrix(int R, int C)
{
	this->K = R < 1 ? 1 : R;
	this->N = C < 1 ? 1 : C;
	m = new Row[this->K];
	for (int i = 0; i < this->K; i++)
	{
		m[i] = Row(this->N);
	}
}
Matrix::Matrix(const Matrix& r)
{
	this->K = r.K;
	this->N = r.N;
	m = new Row[this->K];
	for (int i = 0; i < this->K; i++)
	{
		m[i] = Row(this->N);
	}
	for (int i = 0; i < this->K; i++)
		for (int j = 0; j < this->N; j++)
			m[i][j] = r.m[i][j];
}
Matrix::Row& Matrix::operator[](int i)
{
	return m[i];
}
bool Matrix::Compare(Matrix r, Matrix l)
{
	if (r.K != l.K || r.N != l.N)
		return false;
	else
	{
		for (int i = 0; i < r.K; i++)
			for (int j = 0; j < l.N; j++)
			{
				if (r[i][j] != l[i][j])
					return false;
			}
		return true;
	}
}
double Matrix::Norm(Matrix r)
{
	double min = r[0][0];
	double max = r[0][0];
	long Norm = 0;
	for (int i = 0; i < K; i++)
		for (int j = 0; j < N; j++)
			if (min > r[i][j])
				min = r[i][j];
			else if(max < r[i][j])
			{
				max = r[i][j];
			}
	cout << "max =" << max << endl;
	cout << "min =" << min << endl;
	return abs(max - min);
}
Matrix::~Matrix()
{
	for (int i = 0; i < K; i++)
	{
		if (m[i].v != nullptr)
			delete[](m[i].v);
	}
	if (m != nullptr)
		delete[] m;
}
Matrix& Matrix::operator=(const Matrix& r)
{
	for (int i = 0; i < K; i++)
	{
		if (m[i].v != nullptr)
			delete[](m[i].v);
	}
	if (m != nullptr)
		delete[] m;
	this->K = r.K;
	this->N = r.N;
	m = new Row[this->K];
	for (int i = 0; i < this->K; i++)
	{
		m[i] = Row(this->N);
	}
	for (int i = 0; i < this->K; i++)
		for (int j = 0; j < this->N; j++)
			m[i][j] = r.m[i][j];
	return *this;
}
Matrix::operator string() const
{
	stringstream sout;
	int row1 = getK();
	int col1 = getN();
	for (int i = 0; i < row1; i++)
	{
		for (int j = 0; j < col1; j++)
			sout << m[i][j] << " ";
		sout << endl;
	}
	return sout.str();
}
istream& operator>>(istream& in, Matrix& a)
{
	for (int i = 0; i < a.K; i++)
	{
		for (int j = 0; j < a.N; j++)
		{
			cout << "a[" << i << "][" << j << "]="; in >> a.m[i][j];
		}
		cout << endl;
	}
	return in;
}
ostream& operator<<(ostream& out, const Matrix& a)
{
	out << string(a);
	return out;
}
Matrix operator+(Matrix r, Matrix l)
{
	Matrix t(r.K, r.N);
	if (r.K == l.K && r.N == l.N)
	{
		for (int i = 0; i < r.K; i++)
			for (int j = 0; j < r.N; j++)
				t[i][j] = r[i][j] + l[i][j];
	}
	else cout << "Error has occured!" << endl;
	return t;
}