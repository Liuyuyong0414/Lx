#include "iostream"
using namespace std;

class vehicle
{
	public:
		vehicle(int maxspeed,int weight);
		~vehicle();
		void run();
		void stop();
	protected:
	private:
		int maxspeed;
		int weight;
};
vehicle::vehicle(int maxspeed,int weight)
{
	this->maxspeed=maxspeed;
	this->weight=weight;
	cout<<"vehicle constructor called. "<<"maxspeed:"<<this->maxspeed<<";"<<" weight"<<this->weight<<endl;
}

vehicle::~vehicle()
{
	cout<<"vehicle destructor called. "<<"maxspeed:"<<this->maxspeed<<";"<<" weight"<<this->weight<<endl;
}

void vehicle::run()
{
	cout<<"vehicle run"<<endl;
}

void vehicle::stop()
{
	cout<<"vehicle stop"<<endl;
}
class bicycle :virtual public vehicle
{
	public:
		bicycle(int i,int j,int k);
		~bicycle();
	protected:
	private:
		int height;
};
bicycle::bicycle(int i,int j,int k):vehicle(j,k)
{
	height=i;
	cout<<"bicycle constructor called."<<" height:"<<this->height<<endl;
}

bicycle::~bicycle()
{
	cout<<"bicycle destructor called."<<" height:"<<this->height<<endl;
}
class motorcar :virtual public vehicle
{
	public:
		motorcar(int i,int j,int k);
		~motorcar();
	protected:
	private:
		int seatnum;
};
motorcar::motorcar(int i,int j,int k):vehicle(j,k)
{
		seatnum=i;
	cout<<"motorcar constructor called. seatnum:"<<this->seatnum<<endl;
}

motorcar::~motorcar()
{
	cout<<"motorcar destructor called. seatnum:"<<this->seatnum<<endl;
}
class motorcycle : public bicycle,public motorcar
{
	public:
		motorcycle(int i,int j,int k,int p);
		~motorcycle();
	protected:
	private:
		
};
motorcycle::motorcycle(int i,int j,int k,int p):bicycle(i,k,p),motorcar(j,k,p),vehicle(k,p)
{
	cout<<"motorcycle constructor called"<<endl;
}

motorcycle::~motorcycle()
{
	cout<<"motorcycle destructor called"<<endl;
}


int main(int argc, char *argv[])
{
    motorcycle m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
    m.run();
    m.stop();
    return 0;
}

