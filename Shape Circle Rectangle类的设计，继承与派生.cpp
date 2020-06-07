#include <iostream>
using namespace std;
const float pi=3.14159;
class Shape
{
	public:
		Shape(int ID);
		~Shape();
		void setID(int id);
		int getID();
		int getArea();
	private:
		int ID;
};
Shape::Shape(int ID)
{
	this->ID=ID;
	cout<<"Shape constructor called:"<<this->getID()<<endl;
}

Shape::~Shape()
{
	cout<<"Shape destructor called:"<<this->getID()<<endl;
}

void Shape::setID(int id)
{
	ID=id;
}
int Shape::getID()
{
	return ID;
}
int Shape::getArea()
{
	return 0;
}
class Circle : public Shape
{
	public:
		Circle(int r,int id);
		~Circle();
		void setr(int r);
		int getr();
		float getArea();
	private:
		int r;
};
Circle::Circle(int r,int id):Shape(id)
{
	this->r=r;
	cout<<"Circle constructor called:"<<this->getID()<<endl;
}

Circle::~Circle()
{
	cout<<"Circle destructor called:"<<this->getID()<<endl;
}

void Circle::setr(int r)
{
	this->r=r;
}
int Circle::getr()
{
	return r;
}
float Circle::getArea()
{
	return  pi*r*r;
}
class Rectangle : public Shape
{
	public:
		Rectangle(int h,int w,int id);
		~Rectangle();
		void seth(int h);
		int geth();
		void setw(int w);
		int getw();
		int getArea();
	private:
		int h;
		int w;
};
Rectangle::Rectangle(int h,int w,int id) :Shape(id){
	this->h=h;
	this->w=w;
	cout<<"Rectangle constructor called:"<<this->getID()<<endl;
}

Rectangle::~Rectangle() {
	cout<<"Rectangle destructor called:"<<this->getID()<<endl;
}
void Rectangle::seth(int h) {
	this->h=h;
}
int Rectangle::geth() {
	return h;
}
void Rectangle::setw(int w) {
	this->w=w;
}
int Rectangle::getw()
{
	return w;
}
int Rectangle::getArea() {
	return this->h*this->w;
}

int main()
{
    Shape s(1);//1表示ID
    Circle c(4,2);//4表示半径，2表示ID
    Rectangle r(4, 5,3);//4和5表示长和宽，3表示ID
    cout<<"Shape的面积"<<s.getArea()<<endl;
    cout<<"Circle的面积"<<c.getArea()<<endl;
    cout<<"Rectangle的面积"<<r.getArea()<<endl;
}

