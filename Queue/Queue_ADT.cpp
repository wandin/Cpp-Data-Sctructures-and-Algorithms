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
	Queue<char> qq(10);		 // create new object of Queue type.
	char x;					// declaration of x to be used in some operations. 

	/* Enqueue Elements*/
	qq.Enqueue('A');			// Enqueue Elements
	qq.Enqueue('B');
	qq.Enqueue('C');
	qq.Enqueue('D');
	qq.Enqueue('E');
	qq.Display();				// Display Enqueued Elements 
	cout <<"-------------------------"<<endl;
	/* End of Enqueue*/
	
	/* Dequeue an Element */
	qq.Dequeue(x);
	cout<<"\nDeleted element is: "<<x<<endl;	// Show what element was Dequeued;
	qq.Display();								// Display Queue after dequeuing an element
	cout <<"-------------------------"<<endl;
	/*End of Dequeue */
	
	
	/* Find */
	if(qq.Find(2, x))				// Check if we find an element at given position. 
	{
		cout<<"\nElement found at given position position!!"<<endl;	// confirm we found an element
		
		/* Search Element */
		qq.Search(x);												// Search the given element
		cout<<"\nSearched Element at position 2: "<<x<<endl;						// Print the given element
		cout <<"-------------------------"<<endl;
		/* End of Search */
	}
	else
	{
		cout<<"Element not found!"<<endl;
	}
	
	// Print the Length
	cout<<"Length of queue is: "<<qq.Length()<<endl;
	
	//Isfull
	cout<<"Queue is Full? "<<qq.isFull()<<endl;
	
	//IsEmpty
	cout<<"Queue is Empty? "<<qq.isEmpty()<<endl;
	
	return 0;
};

