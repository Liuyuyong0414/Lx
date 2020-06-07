#include <iostream>
using namespace std;
class Complex {
		double r,i;
	public:
		Complex(double Nr=0,double Ni=0) {
			r=Nr;
			i=Ni;
		}
		friend Complex operator +(Complex &x,Complex &y) ;
		friend Complex operator +(Complex &x,double y) ;
		friend Complex operator +(double x,Complex &y) ;
		friend Complex operator -(Complex &x,Complex &y);
		friend Complex operator -(Complex &x,double y) ;
		friend Complex operator -(double x,Complex &y) ;
		void print()
		{
			
			cout<<'('<<this->r<<')'<<"+"<<'('<<this->i<<"i"<<')'<<endl;
		}
};
Complex operator +(Complex &x,Complex &y) {
	Complex temp(x.r+y.r,x.i+y.i);
	return temp;
}
Complex operator +(Complex &x,double y) {
	Complex temp(x.r+y,x.i);
	return temp;
}
Complex operator -(Complex &x,Complex &y) {
	Complex temp(x.r-y.r,x.i-y.i);
	return temp;
}
Complex operator +(double x,Complex &y) 
{
	Complex temp(x+y.r,y.i);
	return temp;
}
Complex operator -(Complex &x,double y) {
	Complex temp(x.r-y,x.i);
	return temp;
}
Complex operator -(double x,Complex &y) 
{
	Complex temp(x-y.r,-y.i);
	return temp;
}

int main()
{
    Complex a(3,4),b(1,-1),c;
    c=a+b;
    cout<<"a+b=";
    c.print();
    cout<<endl;
    c=a-b;
    cout<<"a-b=";
    c.print();
    cout<<endl;
    c=a+100;
    cout<<"a+100=";
    c.print();
    cout<<endl;
    c=a-2.5;
    cout<<"a-2.5=";
    c.print();
    cout<<endl;
    c=100+a;
    cout<<"100+a=";
    c.print();
    cout<<endl;
    c=2.5-a;
    cout<<"2.5-a=";
    c.print();
    cout<<endl;
    return 0;
}


