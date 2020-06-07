#include <iostream>
#include <iomanip>
using namespace std;
//请在此处补充Account类的定义
class Account
{
	public:
	void init(char *Na,char *Nb,char *Nc,int Nn,double Nx);
	void printmoney();
	void deposit(double q);
	void withdraw(double p);
	private:
		char *a,*b;
		char *c;
		int n;
		double x;
};
	void Account::init(char *Na,char *Nb,char *Nc,int Nn,double Nx)
	{
		b=Nb;
		c=Nc;
		n=Nn;
		if((long)(Nx*1000)%10==0)
		x=Nx;
		else
		{
			cout<<"您输入的金额不合法"<<endl;
			x=0;
		}
	}
	void Account::printmoney()
	{
		cout<<b<<"的存款为"<<fixed<<setprecision(2)<<x<<endl; 
	}
	void Account::deposit(double q)
	{
		if((long)(q*1000)%10==0)
		{
			x+=q;
		}
		else 
		cout<<"您输入的金额不合法"<<endl;
	}
	void Account::withdraw(double p)
	{
			if((long)(p*1000)%10==0&&p<=x)
		{
			x-=p;
		}
		else if((long)(p*1000)%10==0&&p>x)cout<<"您的存款金额不足"<<endl;
		else 
		cout<<"您输入的金额不合法"<<endl;
	}


int main()
{
    Account tom;
    tom.init("32020320011001876X", "Tom Black", "男", 19, 2000.89);
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(89.471);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(10000);
    tom.printmoney();//输出：Tom Black的存款为12000.89
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.123);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.9);//输出：您的存款金额不足
    tom.printmoney();//输出：Tom Black的存款为1999.89
    Account jerry;
    jerry.init("320203200910116569", "Jerry Black", "女", 11, 100.956);//输出：您输入的金额不合法
    jerry.printmoney();//输出：Jerry Black的存款为0.00
}

