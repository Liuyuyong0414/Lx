#include <iostream>
#include <string>
using namespace std;

class CStudent
{
public:
		CStudent() {
			this->a="noname";
			count++;
			cout<<"noname is contructing"<<endl;
		}
		CStudent(string b,int y) {
			this->a=b;
			this->x=y;
			count++;
			cout<<this->a<<" is contructing"<<endl;
		}
		~CStudent() {
			count--;
			cout<<this->a<<" is destructing"<<endl;
		}
		void printname() {
			cout<<"name:"<<this->a<<endl;
		}
		static int getcount() {
			return count;
		}
	private:
		string a;
		int x;
		static int count;

};
//请在这里初始静态成员变量
int CStudent::count=0;


int main()
{
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuB[5];
		stuB[4].printname();
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuA[2] = {CStudent("Tom", 3), CStudent("Jerry", 2)};
		for (int i = 0; i < 2; i++)
		{
			stuA[i].printname();
		}
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;

	return 0;
}

