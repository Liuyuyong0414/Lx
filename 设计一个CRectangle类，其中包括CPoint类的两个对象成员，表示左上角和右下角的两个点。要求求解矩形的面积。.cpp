#include <iostream>
using namespace std;
//请在这里补充CPoint，CRectangle类的定义
class CPoint {
		friend class CRectangle;
	public:
		CPoint(int Na,int Nb);
		CPoint(CPoint &q);
		void f(CPoint q);
	private:
		int a,b;

};
CPoint::CPoint(int Na=0,int Nb=0) {
	this->a=Na;
	this->b=Nb;
	cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
}
CPoint::CPoint(CPoint &q) {
	this->a=q.a;
	this->b=q.b;
	cout<<"CPoint copy contstructor is called."<<endl;
}
void CPoint::f(CPoint q)
{
	this->a=q.a;
	this->b=q.b;
}
class CRectangle {
		CPoint x,y;
	public:
		CRectangle();
		CRectangle(CPoint Nx,CPoint Ny);
		CRectangle(int Na,int Nb,int Nc,int Nd);
		CRectangle(CRectangle &p);
		int GetArea();
};
CRectangle::CRectangle() {
	cout<<"CRectangle default contstructor is called."<<endl;
}
CRectangle::CRectangle(CPoint Nx,CPoint Ny) 
:x(Nx),y(Ny){
	cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
}
CRectangle::CRectangle(int Na,int Nb,int Nc,int Nd)
 :x(Na,Nb),y(Nc,Nd){
	cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle::CRectangle(CRectangle &p)
:x(p.x),y(p.y) {
	cout<<"CRectangle copy contstructor is called."<<endl;
}
int CRectangle::GetArea() {
	return (y.a-x.a)*(y.b-x.b);
}


int main()
{
    int a=1, b=1, c=6, d=11;
    cout<<"# Define p1 ######"<<endl;
    CPoint p1;
    cout<<"# Define p2 ######"<<endl;
    CPoint p2(10,20);
    cout<<"# Define rect1 ######"<<endl;
    CRectangle rect1;
    cout<<"# Define rect2 ######"<<endl;
    CRectangle rect2(p1, p2);
    cout<<"# Define rect3 ######"<<endl;
    CRectangle rect3(a, b, c, d);
    cout<<"# Define rect4 ######"<<endl;
    CRectangle rect4(rect2);
    cout<<"# Calculate area ######"<<endl;
    cout << "rect1面积为" << rect1.GetArea() << endl;
    cout << "rect2面积为" << rect2.GetArea() << endl;
    cout << "rect3面积为" << rect3.GetArea() << endl;
    cout << "rect4面积为" << rect4.GetArea() << endl;
    system("pause");
    return 0;
}



