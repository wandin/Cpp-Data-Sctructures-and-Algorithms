//Queue Class to use in OUr Binary Tree using Queue

#include <iostream>

using namespace std;

class Node
{
public:
	int Data;
	Node* LChild;
	Node* RChild;
};

class Queue
{
private:
	int Size;
	int Front;
	int Rear;
	Node** Q; // <Node*> * -> Pointer to Pointer to Node class

public:
	Queue(int Size);
	~Queue();
	bool isFull();
	bool isEmpty();
	void EnQueue(Node*);
	Node* DeQueue();
};

Queue::Queue(int Size)
{
	this->Size = Size;
	Front = -1;
	Rear = -1;
	Q = new Node*[Size];
}

Queue::~Queue()
{
	delete [] Q;
}

bool Queue::isEmpty()
{
	if(Front == Rear)
	{
		return true;
	}
	return false;
}

bool Queue::isFull()
{
	if(Rear == Size-1)
	{
		return true;
	}
	return false;
}

void Queue::EnQueue(Node* Element)
{
	if(isFull())
	{
		cout<<"Queue Overflow - FULL"<<endl;
	}
	else
	{
		Rear++;
		Q[Rear] = Element;
	}
}

Node* Queue::DeQueue()
{
	Node* temp = nullptr;
	if(isEmpty())
	{
		cout<<"Queue Underflow - Empty"<<endl;
	}
	else
	{
		Front++;
		temp = Q[Front];
	}
	return temp;
}
