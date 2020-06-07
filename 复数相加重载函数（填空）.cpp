#include <iostream>
#include <iomanip>
using namespace std;

struct complex
{
    double r;
    double i;
};

complex add(complex x,complex y)
{
	complex z;
	z.i=x.i+y.i;
	z.r=x.r+y.r;
	return z;
}
complex add(complex x,double y)
{
	complex z;
	z.i=x.i;
	z.r=x.r+y;
	return z;
}
complex add(double x,complex y)
{
	complex z;
	z.i=y.i;
	z.r=x+y.r;
	return z;
}


int main()
{
    double num;
    complex a, b, c;
    cin >> a.r >> a.i;
    cin >> b.r >> b.i;
    cin >> num;
    c = add(a, b);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(a, num);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(num, b);
    cout << c.r << "+" << c.i << "i" << endl;
}


