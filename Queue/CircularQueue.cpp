//	Circular Queue - Abstract Data Type

#include <iostream>

using namespace std;


template <class T>
class CircularQueue
{
private:
	
	T *CQ;
	int Front, Rear, Size, Len;

public:
	
	CircularQueue(int);
	~CircularQueue() { delete [] CQ;}
	void EnQueue(T);
	void DeQueue(T&);
	T FrontElement() { return CQ[(Front + 1) % Size]; }
	T RearElement()	{ return CQ[Rear];}
	void Display();
	int Length() { return Len;}
	bool isEmpty();
	bool isFull();		
};


template<class T>
CircularQueue<T>::CircularQueue(int s)
{
	Size = s;
	CQ = new T[Size];
	Rear = 0;
	Front = 0;
	Len = 0;
}

template<class T>
bool CircularQueue<T>::isEmpty()
{
	return Front == Rear;
}

template<class T>
bool CircularQueue<T>::isFull()
{
	return Front == (Rear + 1) % Size;
}


template<class T>
void CircularQueue<T>::EnQueue(T Element)
{
	// just printing to debug
	cout<<"Rear: "<<Rear<<endl;	
	cout<<"Front: "<<Front<<endl;
	if(isFull())
	{
		cout<<"\nQueue is FUll!"<<endl;
		cout<<"Front is at: "<<Front<<endl;
		return;
	}
	else
	{
		Rear = (Rear + 1) % Size;
		CQ[Rear] = Element;
		Len++;
	}
}

template<class T>
void CircularQueue<T>::DeQueue(T& Element)
{
	if(isEmpty())
	{
		cout<<"Queue is Empty"<<endl;
		return;
	}
	else
	{
		Front = (Front + 1) % Size;			// similar to Enqueue method, but in this case we Dequeue the first element, which is pointed by Front
		Element = CQ[Front];
		Len--;
	}
}


template<class T>
void CircularQueue<T>::Display()
{
	// Set (i) to our Front + 1 using the incrementing method for Circular Queue i + 1 % Size, and increment (i) by 1 at each loop the same way    
    int i = (Front + 1) % Size;
    int count = 0;
    
    while (i != (Rear + 1) % Size && count < Len)
    {
        cout << CQ[i] << " ";
        i = (i + 1) % Size;
        count++;
    }
    cout << endl;
}


int main()
{
	CircularQueue<char> CircularQ(10);
	
	CircularQ.EnQueue('A');
	CircularQ.EnQueue('B');
	CircularQ.EnQueue('C');
	CircularQ.EnQueue('D');
	CircularQ.EnQueue('E');	

	cout<<"-----------------------------"<<endl;
	CircularQ.Display();
	cout<<"-----------------------------"<<endl;

	cout<<"FrontMost Element is: "<<CircularQ.FrontElement()<<endl;
	cout<<"Rear Element is: "<<CircularQ.RearElement()<<endl;
	cout<<"-----------------------------"<<endl;

	char x;
	CircularQ.DeQueue(x);
	cout<<"Element Dequeued was: "<<x<<endl;
	CircularQ.Display();



	
	return 0;
}
