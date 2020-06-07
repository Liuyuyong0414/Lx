#include <bits/stdc++.h> 
using namespace std;
const double PI=3.1415926;
class cylinder
{
	public:
	double getvolumn();
	double getarea();
	cylinder(double Nh,double Nr);
	~cylinder();
	private:
		double r,h;
};
double cylinder::getvolumn()
{
	return r*PI*r*h;
 } 
double cylinder::getarea()
{
	return 2*PI*r*r+2*PI*r*h;
}
cylinder::cylinder(double Nh,double Nr)
{
	cout<<"构造函数被调用"<<endl;
	r=Nr;
	h=Nh;
}
cylinder::~cylinder()
{
	cout<<"析构函数被调用"<<endl;
}
int main()
{
    double d,h;
    cin>>d>>h;
    cylinder can(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}


