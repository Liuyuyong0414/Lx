#include<iostream>
#include<algorithm>
#include<fstream> 
#include<vector>
using namespace std;
bool compare(double a,double b)
{
	return a<b;
}
int main()
{
	ifstream file1;
	file1.open("a.txt");
	if(!file1)cout<<"error"<<endl;
	vector<double>a;
	double j;
	while(file1>>j)
	{
		a.push_back(j);
	}
	sort(a.begin(),a.end(),compare);
	file1.close();
	ofstream file;
	file.open("b.txt",ios_base::out);
	for(int i=0;i<a.size();i++)
	{
		file<<a[i]<<" ";
	}
	file.close();
 } 

