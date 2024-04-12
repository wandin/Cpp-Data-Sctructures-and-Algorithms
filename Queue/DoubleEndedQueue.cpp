// Double Ended Queue - DEqueue

#include <iostream>

using namespace std;


template<class T>
class DEQueue
{
private:

	T *DQ;
	int Front, Rear, Size, len;

public:
	
	DEQueue(int);
	~DEQueue() { delete [] DQ ;}
	
	void InsertFromFront(T);	//Insert
	void InsertFromRear(T);		//Insert
	void DeleteFromFront(T&);	//Delete
	void DeleteFromRear(T&);	//Delete
	
	T getFront();
	T getRear();
	
	bool isFull() { return (Front == Rear + 1 || Front == 0 && Rear == Size -1); }
	bool isEmpty() { return Front == -1;}
	
	void Display();

};

template<class T>
DEQueue<T>::DEQueue(int s)
{
	Size = s;
	DQ = new T[Size];
	Front = -1;
	Rear = 0;
	len = 0;
}


template<class T>
void DEQueue<T>::InsertFromFront(T Element)
{
	if(isFull())
	{
		cout<<"Queue Is Full"<<endl;
		return;
	}
	if(Front == -1)
	{
		Front = 0;
	}
	else if(Front == 0)
	{
		Front = Size -1;	
	}
	else
	{
		Front--;
	}
	DQ[Front] = Element;
	len++;
}

template<class T>
void DEQueue<T>::InsertFromRear(T Element)
{
	if(isFull())
	{
		cout<<"Queue Is Full"<<endl;
		return;
	}
	if(Front == -1)
	{
		Front = 0;
	}
	else if(Rear == Size -1)
	{
		Rear = 0;
	}
	Rear++;
	DQ[Rear] = Element;
	len++;
}

template<class T>
void DEQueue<T>::DeleteFromFront(T& Element)
{
	if(isEmpty())
	{
		cout<<"Queue Is Empty"<<endl;
		return;
	}
	Element = DQ[Front];
	if(Front == Rear)
	{
		Front = -1;
		Rear = -1;
	}
	else if(Front == Size -1)
	{
		Front = 0;
	}
	else
		Front++;
	len--;
}

template<class T>
void DEQueue<T>::DeleteFromRear(T& Element)
{
	if(isEmpty())
	{
		cout<<"Queue Is Empty"<<endl;
		return;		
	}
	Element = DQ[Rear];
	if(Rear == Front)
	{
		Front - 1;
		Rear = -1;
	}
	else if(Front == 0)
	{
		Rear = Size -1;
	}
	else
		Rear--;
	len--;
}

template<class T>
T DEQueue<T>::getFront()
{
	if(isEmpty())
	{
		cout<<"\n No Front Element.... Double Q is Empty."<<endl;
		return -1;
	}
	return DQ[Front];
}

template<class T>
T DEQueue<T>::getRear()
{
	if(isEmpty())
	{
		cout<<"\n No Rear Element.... Double Q is Empty."<<endl;
		return -1;
	}
	return DQ[Rear];
}


int main()
{
	DEQueue<int> DEQ(10);
	
	DEQ.InsertFromFront(1);
	cout<<"\n Front = "<<DEQ.getFront()<<endl;
	cout<<"\n Rear = "<<DEQ.getRear()<<endl;
	DEQ.InsertFromFront(2);
	cout<<"\n Front = "<<DEQ.getFront()<<endl;
	cout<<"\n Rear = "<<DEQ.getRear()<<endl;
	
	cout<<"Inserting from Rear"<<endl;
	DEQ.InsertFromRear(3);
	cout<<"\n Front = "<<DEQ.getFront()<<endl;
	cout<<"\n Rear = "<<DEQ.getRear()<<endl;
	DEQ.InsertFromRear(4);
	cout<<"\n Front = "<<DEQ.getFront()<<endl;
	cout<<"\n Rear = "<<DEQ.getRear()<<endl;

	return 0;
}
