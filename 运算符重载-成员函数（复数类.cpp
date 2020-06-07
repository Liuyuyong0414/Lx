#include <iostream>
using namespace std;

class Complex {
		double r,i;
	public:
		Complex(double Nr=0,double Ni=0) {
			r=Nr;
			i=Ni;
		}
		Complex operator +(Complex &x)
		{
			Complex temp;
			temp.r=r+x.r;
			temp.i=i+x.i;
			return temp;
		}
		Complex operator +(double y)
		{
			Complex temp;
			temp.r=r+y;
			temp.i=i;
			return temp;
		}
		Complex operator -(Complex &x)
		{
			Complex temp;
			temp.r=r-x.r;
			temp.i=i-x.i;
			return temp;
		}
		Complex operator -(double y)
		{
			Complex temp;
			temp.r=r-y;
			temp.i=i;
			return temp;
		}
		void print()
		{
			
			cout<<this->r<<"+"<<this->i<<"i"<<endl;
		}
};



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

    return 0;
}


