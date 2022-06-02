/////////////////////////////
//Source.cpp
#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
	Matrix t4;
	cout << t4;
	Matrix q(3, 2);
	Matrix p = q;
	cin >> q;
	cout << q << endl;
	cout << p << endl;
	Matrix c = p + q;
	cout << c << endl;
	cout << "Norma is " << c.Norm(c) << endl;
	Matrix* t1 = new Matrix(q);
	cout << (*t1);
	Matrix t3[2];
	t3[0] = q;
	t3[1] = q;
	if (t3[0].Compare(t3[0], t3[1]))
		cout << "Same" << endl;
	else cout << "Not same" << endl;
	cout << "Norma is " << c.Norm(t3[1]) << endl;
	cout << string(t3[1]) << endl;
	Matrix* y = new Matrix[180];
	cout << y[4];
	return 0;
}