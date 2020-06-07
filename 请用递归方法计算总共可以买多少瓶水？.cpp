#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	int is(int a,int b);
	x=x+is(x,x);
	cout<<x;
}
int is(int a,int b)
{
	int m,n;//m表示瓶子，n表示瓶盖
	int k=0;
	k+=a/2+b/3;
	m=a%2+k;
	n=b%3+k;
	if(m<2&&n<3)return k;
	else return is(m,n)+k;
}

