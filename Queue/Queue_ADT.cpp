// Queue ADT - using abstract Data Type

#include <iostream>

using namespace std;

template<class T>
class Queue
{

private:
		
	int Front, Rear, Size, Len;
	T* Q;
		
public:

	Queue(int s);			// constructor
	~Queue() { delete [] Q; } 	// destructor
	void Enqueue(T);
	void Dequeue(T&);
	bool Find(int, T&);
	int Search(T);
	bool isEmpty();
	bool isFull();
	int Length() { return Len;}
	void Display();
};


template<class T>
Queue<T>::Queue(int s)
{
	Size = s;
	Q = new T[Size];
	Front = Rear = -1;
	Len = 0;
}


template<class T>
void Queue<T>::Enqueue(T Element)
{
	if(isFull())
	{
		cout<<"Queue is full!!"<<endl;
		return;
	}
	Rear++;
	Q[Rear] = Element;
	Len++;
}


template<class T>
void Queue<T>::Dequeue(T& Element)
{
	if(isEmpty())
	{
		cout<<"Queue is Empty, nothing to dequeue!"<<endl;
		return;
	}
	Front++;
	Element = Q[Front];
	Len--;
}


template<class T>
bool Queue<T>::isFull()
{
	return Rear == Size -1;
}

template<class T>
bool Queue<T>::isEmpty()
{
	return Front == Rear;
}


template<class T>
bool Queue<T>::Find(int pos, T& Element)
{
	if(pos < 1 || pos > Len)
	{
		cout<<"\nInvalid Position"<<endl;
		return false;
	}
	Element = Q[pos];
	return true;
}

template<class T>
int Queue<T>::Search(T Element)
{
	for (int i = 0; i < Len; i++)
	{
		if(Element == Q[i])
		{
			return i+1;
		}
		return -1;
	}
}

template<class T>
void Queue<T>::Display()
{
	for (int i = Front + 1; i <= Rear; i++)
	{
		cout <<Q[i]<<" ";
	}
	cout << endl;
}

int main()
{
	Queue<char> qq(10);
	
	char x;
	qq.Enqueue('A');
	qq.Enqueue('B');
	qq.Enqueue('C');
	qq.Enqueue('D');
	qq.Enqueue('E');
	
	qq.Display();
	cout <<"-------------------------"<<endl;
	
	qq.Dequeue(x);
	qq.Display();
	cout<<"\nDeleted element is: "<<x<<endl;
	cout <<"-------------------------"<<endl;

	
	return 0;
};

