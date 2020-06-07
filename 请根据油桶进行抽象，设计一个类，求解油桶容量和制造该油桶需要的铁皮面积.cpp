#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

const double PI=3.1415926;
//请在此处完善类的设计
class cylinder
{
	public:
	void init(double Nh,double Nr);
	double getvolumn();
	double getarea();
	private:
		double r,h;
};
void cylinder::init(double Nh,double Nr)
{
	h=Nh;
	r=Nr;
}
double cylinder::getvolumn()
{
	return PI*r*r*h;
}
double cylinder::getarea()
{
	return 2*PI*r*h+2*PI*r*r;
}


int main()
{
    double d,h;
    cin>>d>>h;
            cylinder can;

    can.init(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}



