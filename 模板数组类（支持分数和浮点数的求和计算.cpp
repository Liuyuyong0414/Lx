#include <iostream>
#include <vector>
#include<typeinfo>
using namespace std;
int gcd(int n,int m) {
	int temp,r;
	if(n<m) {
		temp=n;
		n=m;
		m=temp;
	}
	while(m!=0) {
		r=n%m;
		n=m;
		m=r;
	}
	return n;
}
template <typename T>
class Array {
//请完成类的设计
	public:
		vector<T>str;
		Array(int n) {
		}
		void input(int n) {
			for(int i=0; i<n; i++) {
				T tmp;
				cin>>tmp;
				str.push_back(tmp);

			}
		}
			T& operator [](int i) {
				return str[i];
			}
		};
		class Fract {
//请完成类的设计
			public:
				int n,m;
				Fract(int n=0,int m=0) {
					int j=gcd(n,m);
					if(j<0)j=-j;
					n=n/j;
					m=m/j;
					this->n=n;
					this->m=m;
				}
				void show()
				{
					if(n==0||m==1)cout<<n<<endl;
					else cout<<n<<"/"<<m<<endl;
				}
				Fract &operator +=(Fract &p) {
					Fract q(p.n*m+p.m*n,p.m*m);
					return *this=q;
				}
				operator double()
				{
					return (double)n/m*1.0;
				}
				friend istream &operator>>(istream &is,Fract &f) {
					is>>f.n>>f.m;
					return is;
				}

		};
		int main() {
			unsigned int n;
			cin >> n;
			Array<double> db(n);
			db.input(n);
			double dbsum(0.0);
			for (unsigned int i = 0; i < n; i++)
				dbsum += db[i];
			cout << dbsum << endl;

			cin >> n;
			Array<Fract> fr(n);
			fr.input(n);
			Fract frsum(0, 1);
			for (unsigned int i = 0; i < n; i++)
				frsum += fr[i];
			frsum.show();
		}

