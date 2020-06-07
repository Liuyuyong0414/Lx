#include <iostream>
#include <cmath>
using namespace std;

//判断是否为素数
int isPrime(long num)
{
long i;
for(i=2;i<=sqrt(num);i++)
if(num%i==0)break;
if(i>sqrt(num))return 1;
else return 0;

}

//计算质因素分解，
void factorization(long n,long a[100],int &x
)
{
long j;
	for(j=2;j<=n;j++)
	{
		end:if(n%j==0&&isPrime(j))
		{
			a[x++]=j;
			n=n/j;
			goto end;
		}
	}

    return;
}

int main()
{
    long n;
    long factor[100];
    int numofFactor = 0;
    cin >> n;
    factorization(n, factor, numofFactor);
    for (int i = 0; i < numofFactor; i++)
    {
        cout << factor[i] << " ";
    }
    cout << endl;
    return 0;
}

