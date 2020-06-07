#include <iostream>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int isprime1(int x) {
	if((x%4==0&&x%100!=0)||x%400==0)return 1;
	else return 0;
}
int isprime2(int z,int x,int y) {
	if(!isprime1(z)) {
		if(((x==1||x==3||x==5||x==7||x==8||x==10||x==12)&&y<=31)||((x==2)&&y<=28)||((x==4||x==6||x==9||x==11)&&y<=30))return 1;
		else return 0;
	} else {
		if(((x==1||x==3||x==5||x==7||x==8||x==10||x==12)&&y<=31)||((x==2)&&y<=29)||((x==4||x==6||x==9||x==11)&&y<=30))return 1;
		else return 0;
	}
}
int isprime3(int x,int y,int z) {
	if(x<24&&y<60&&z<60)return 1;
	else return 0;
}
class CTime {
	public:
		CTime(int Nn,int Ny,int Nr,int Ns,int Nf,int Nm);
		CTime(CTime &p);
		void showTime();
		~CTime();
		int isvalid();
		int dayDiff(CTime p);
	private:
		int n,y,r,s,f,m;
};
CTime::CTime(int Nn,int Ny,int Nr,int Ns=0,int Nf=0,int Nm=0) {
	int i,j;
	i=isprime2(Nn,Ny,Nr),j=isprime3(Ns,Nf,Nm);
	if(i&&j) {
		n=Nn,y=Ny,r=Nr,s=Ns,f=Nf,m=Nm;
	} else {
		if(i&&(!j))cout<<"time error!"<<endl;
		else if((!i)&&j)cout<<"date error!"<<endl;
		else cout<<"date and time error!"<<endl;
		n=y=r=s=f=m=0;
	}
	cout<<"构造函数被调用"<<endl;
}
void CTime::showTime() {
	cout<<n<<'/'<<y<<'/'<<r<<' '<<s<<':'<<f<<':'<<m<<endl;
}
CTime::CTime(CTime &p) {
	n=p.n;
	y=p.y;
	r=p.r;
	s=p.s;
	f=p.f;
	m=p.m;
	cout<<"拷贝构造函数被调用"<<endl;
}
CTime::~CTime() {
	cout<<"析构函数被调用"<<endl;
}
int CTime::isvalid() {
	if(s<24&&f<60&&m<60) {
		if(!isprime1(n)) {
			if(((y==1||y==3||y==5||y==7||y==8||y==10||y==12)&&r<=31)||((y==2)&&r<=28)||((y==4||y==6||y==9||y==11)&&r<=30))return 1;
			else return 0;
		} else {
			if(((y==1||y==3||y==5||y==7||y==8||y==10||y==12)&&r<=31)||((y==2)&&r<=28)||((y==4||y==6||y==9||y==11)&&r<=30))return 1;
			else return 0;
		}
	} else return 0;
}
int CTime::dayDiff(CTime p) {
	int sum1=0,sum2=0,sum=0,i,j;
	for(i=1990;i<n;i++)
	{
		if(isprime1(i))sum1+=366;
		else sum1+=365;	
	}
	for(j=1;j<y;j++)
	{
		if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)sum1+=31;
		else if(j==2)
		{
			if(isprime1(i))sum1+=29;
			else sum1+=28;
		}
		else sum1+=30;
	}
	sum1+=r;
	for(i=1990;i<p.n;i++)
	{
		if(isprime1(i))sum2+=366;
		else sum2+=365;	
	}
	for(j=1;j<p.y;j++)
	{
		if(j==1||j==3||j==5||j==7||j==8||j==10||j==12)sum2+=31;
		else if(j==2)
		{
			if(isprime1(i))sum2+=29;
			else sum2+=28;
		}
		else sum2+=30;
	}
	sum2+=p.r;
	sum=sum2-sum1;
	if(sum<0)sum=-sum;
	return sum;
}














     
      


int main()
{
    int year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime t2(2000, 1, 1); //利用默认形参将时间初始化为00:00:00
    if (t1.isvalid())     //如果日期和时间合法，则计算天数
    {
        int days=0;
        days=t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days=t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
}

