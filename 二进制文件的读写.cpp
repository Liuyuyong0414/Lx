#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	short int stu_id;
	short int score;
};
int main()
{
	int n,i;
	cin>>n;
	student *a=new student[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i].stu_id>>a[i].score;
	}
	ofstream file("out.txt",ios::out|ios::binary);
	file.write((char *)a,sizeof(student));
	file.close();
	ifstream file1("out.txt",ios::in|ios::binary);
	student *b=new student[n];
	for(i=0;i<n;i++)
	{
	file1.read((char *)b+i,sizeof(student));
	}
	file1.close();
	ofstream file2("out.txt",ios::ate);
	file2.write((char *)b,sizeof(student));
	file2.close();
	delete[] a;
	delete[] b;
}


