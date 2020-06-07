#include <iostream>
using namespace std;
class Point
{
	int x,y;
	public:
		Point(int Nx=0,int Ny=0):x(Nx),y(Ny){
		};
		Point(Point &p)
		{
			x=p.x;
			y=p.y;
		}
	    friend ostream& operator<<(ostream &s,const Point &z);
		Point& operator ++()
		{
			x++;
			y++;
			return *this;
		};
		Point operator ++(int )
		{
			Point a=*this;
			++(*this);
			return a;
		}
};
ostream& operator << (ostream & s,const Point &z)
{
	s<<"("<<z.x<<","<<z.y<<")"<<endl<<endl;
	return s;
}

int main()
{
    Point a(1,3);
    cout<<a;
    cout<<a++;
    cout<<++a;
    return 0;
}

