#include <iostream>
using namespace std;
class Book
{
//请在此处补充Book类的定义
	private:
		unsigned int ID;//编号
		string Name;//书名
		string Introduction;//简介
		string Author;//作者
		string Date;//日期
		unsigned int Page;//页数
	public:
		unsigned int GetID();
		string GetName();
		string GetIntroduction();
		string GetAuthor();
		string GetDate();
		unsigned int GetPage();
		void SetID(unsigned int ID);
		void SetName(string Name);
		void SetIntroduction(string Introduction);
		void SetAuthor(string Author);
		void SetDate(string Date);
		void SetPage(unsigned int Page);
		Book();//将m_ID初始化为0，表示这个一个未赋值对象
		virtual ~Book();//无具体的工作
		Book(const Book& other);//实现所有成员变量的拷贝

};
//请在此处补充Book类的成员函数实现
void Book::SetID(unsigned int ID) {
	this->ID=ID;
}
void Book::SetName(string Name) {
	this->Name=Name;
}
void Book::SetIntroduction(string Introduction) {
	this->Introduction=Introduction;
}
void Book::SetAuthor(string Author) {
	this->Author=Author;
}
void Book::SetDate(string Date) {
	this->Date=Date;
}
void Book::SetPage(unsigned int Page) {
	this->Page=Page;
}
unsigned int Book::GetID() {
	return ID;
}
string Book::GetName() {
	return Name;
}
string Book::GetIntroduction() {
	return Introduction;
}
string Book::GetAuthor() {
	return Author;
}
string Book::GetDate() {
	return Date;
}
unsigned int Book::GetPage() {
	return Page;
}
Book::Book():ID(0) {
}
Book::Book(const Book& other) {
	ID=other.ID;
	Name=other.Name;
	Introduction=other.Introduction;
	Author=other.Author;
	Date=other.Date;
	Page=other.Page;
}
Book::~Book() {
}

class Store
{
//请在此处补充Store类的定义
private:
		Book *pBook;
		unsigned int Count;//表示库存中图书的数量
	public:
		void SetCount(unsigned int Count);
		unsigned int GetCount();
		Store();
		Store(int n);
		Store(const Store& other);
		virtual ~Store();
		void in(Book &b);
		void out(string name);
		Book findbyID(int ID);
		Book findbyName(string name);
		void printList();

};
//请在此处补充Store类的成员函数实现
void Store::SetCount(unsigned int Count) {
	this->Count=Count;
}
unsigned int Store::GetCount() {
	return Count;
}
Store::Store() {
	Count=0;
	pBook=NULL;
	cout<<"Store default constructor called!"<<endl;
}
Store::Store(int n) {
	Count=n;
	pBook=new Book[n];
	cout<<"Store constructor with (int n) called!"<<endl;
}
Store::Store(const Store& other) {
	Count=other.Count;
	pBook=new Book[Count];
	for(int i=0; i<Count; i++)
		pBook[i]=other.pBook[i];
	cout<<"Store copy constructor called!"<<endl;
}
Store::~Store() {
	Count=0;
	if(pBook!=NULL) {
		delete[] pBook;
	}
	cout<<"Store destructor called!"<<endl;
}
void Store::in(Book &b) {
	Count++;
	if(pBook==NULL) {
		pBook=new Book[1];
		pBook[0]=b;
	} else {
		Book *p=new Book[Count];
		int i=0;
		for(; i<Count-1; i++)
			p[i]=pBook[i];
		p[i]=b;
		delete[] pBook;
		pBook=p;
		//delete[] p;
	}
}
void Store::out(string name) {
	Count--;
	int j=0;
	Book *p=new Book[Count];
	for(int i=0; i<Count+1; i++) {
		if(pBook[i].GetName()!=name)
			p[j++]=pBook[i];
	}
	delete[] pBook;
	pBook=p;
}
Book Store::findbyID(int ID) {
	int i;
	for(i=0; i<Count; i++) {
		if(pBook[i].GetID()==ID) {
			return pBook[i];
			break;
		}
	}
	if(i==Count) {
		Book x;
		return x;
	}
}
Book Store::findbyName(string name) {
	int i;
	for(i=0; i<Count; i++) {
		if(pBook[i].GetName()==name) {
			return pBook[i];
			break;
		}
	}
	if(i==Count) {
		Book x;
		return x;
	}
}
void Store::printList() {
	cout<<"There are totally "<<Count<<" Books:"<<endl;
	for(int i=0; i<Count; i++) {
		cout<<"ID="<<pBook[i].GetID()<<";"<<"  Name:"<<pBook[i].GetName()<<";"<<"  Author:"<<pBook[i].GetAuthor()<<";"<<"  Date:"<<pBook[i].GetDate()<<";"<<endl;
	}
}

int main()
{
    Store s;
    Book b1,b2,b3;
    b1.SetID(1);
    b1.SetName("C++ 语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout<<"第一本书入库"<<endl;
    s.in(b1);
    cout<<"第二本书入库"<<endl;
    s.in(b2);
    cout<<"第三本书入库"<<endl;
    s.in(b3);
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;
    cout <<"查找并出库图书：离散数学" << endl;
    Book tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
    {
        s.out("离散数学");
        cout <<"离散数学 已成功出库" << endl;
    }
    else
        cout<<"没有找到name为离散数学的书"<<endl;
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;

    cout <<"查找图书 ID：3" << endl;
    tmpbook=s.findbyID(3);
    if(tmpbook.GetID()!=0)
        cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
    else
        cout<<"没有找到ID为"<<3<<"的书"<<endl;

    cout <<"查找图书 name：离散数学" << endl;
    tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
        cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
    else
        cout<<"没有找到name为离散数学的书"<<endl;

    cout<<"输出所有库存图书的信息"<<endl;
    s.printList();
    cout<<"程序运行结束"<<endl;
    return 0;
}


