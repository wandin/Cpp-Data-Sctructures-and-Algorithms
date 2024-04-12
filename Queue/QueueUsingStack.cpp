//Queue using Stack

#include <iostream>

using namespace std;

template<class T>
class Stack
{
private:
	T *S;
	int Top, Size;
public:
	
	Stack();
	~Stack();
	void Push(T);
	T Pop();
	bool isEmpty();
};

template<class T>
Stack<T>::Stack()
{
	cout<<"Enter the size of the Stack: .."<<endl;
	cin>>Size;
	S = new T[Size];
	Top = -1;
}

template<class T>
Stack<T>::~Stack()
{
	delete [] S;
}


template<class T>
void Stack<T>::Push(T Element)
{
	if(Top == Size -1)
	{
		cout<<"Stack Overflows = STACK FULL!"<<endl;
		return;
	}
	S[++Top] = Element;
}


template<class T>
T Stack<T>::Pop()
{
	T Element;
	if(isEmpty())
	{
		cout<<"Stack underflows  = STACK EMPTY"<<endl;
		return 0;
	}
	Element = S[Top--];
	return Element;
}


template<class T>
bool Stack<T>::isEmpty()
{
	return Top == -1;
}


template<class T>
class QueueUsingStack
{
public:
	Stack<int> stack1, stack2;
	 
	QueueUsingStack() {	}
	void deQueue();
	void enQueue(T x);
};

template<class T>
void QueueUsingStack<T>::enQueue(T x)
{
	T y;
	while(!stack1.isEmpty())
	{
		y = stack1.Pop();
		stack2.Push(y);
	}
	
	stack1.Push(x);
	cout<<"Element inserted in Stack following QUEUE property FIFO is: "<<x<<endl;

	while(!stack2.isEmpty())
	{
		y = stack2.Pop();
		stack1.Push(y);
	}
}

template<class T>
void QueueUsingStack<T>::deQueue()
{
	if(stack1.isEmpty())
	{
		cout<<"Queue is Empty"<<endl;
		return;
	}
	
	T x;
	x = stack1.Pop();
	cout<<"\nElement Deleted is..."<<x;
}


int main()
{
	QueueUsingStack<int> Q;
	
	Q.enQueue(1);
	Q.enQueue(2);
	Q.enQueue(3);
	Q.enQueue(4);
		
	Q.deQueue();
	Q.deQueue();
	Q.deQueue();
	Q.deQueue();
	
	return 0;
}



