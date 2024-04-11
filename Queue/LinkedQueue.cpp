//LInked Queue - Abstract Data Type

#include <iostream>

using namespace std;


template<class T>
class Node
{
public:
	
	T Data;
	Node<T> *link;
};

template<class T>
class LinkedQ
{
private:
	Node<T> *Front;
	Node<T> *Rear;
	int len;
	
public:
	
	LinkedQ();
	~LinkedQ();
	void EnQueue(T);
	void DeQueue(T&);
	bool Find(int, T&);
	int Search(T);
	bool isEmpty();
	T FrontMost();
	T RearMost();
	int Length() { return len;	}
	void Display();
};

template<class T>
LinkedQ<T>::LinkedQ()
{
	Front = NULL;
	Rear = NULL;
	len = 0;
}

template<class T>
LinkedQ<T>::~LinkedQ()
{
	Node<T> *p = Front;
	while(p)
	{
		Front = Front->link;
		delete p;
		p = Front;
	}
	cout<<endl<<"Deconstructor finished!..Completely deleted all elements"<<endl;
}

template<class T>
void LinkedQ<T>::EnQueue(T Element)
{
	Node<T> *temp;			//create temp Node
	temp = new Node<T>;		//allocate temp Node
	
	temp->Data = Element;	//allocate the EnQueue Element
	temp->link = NULL;		// assigns the Link to a null
	
	if(isEmpty())			//check if queue is empty
	{
		Front = temp;		//if so, we assign our temp Node to the Front node
	}
	else
	{
		Rear->link = temp;	// if not empty, the last node (Rear) points the new Element Node;
	}
	Rear = temp;			// Update the last node (Rear) to the newly create temp;
	len++;					//Increases the Length of our queue.
}

template<class T>
void LinkedQ<T>::DeQueue(T &Element)
{
	Node<T> *temp;			//create temp Node
	temp = new Node<T>;		//allocate temp Node
	
	temp = Front;			//temp assigns the Front Node
	Front = Front->link;	// Front assigns the next node (the node that Front was pointing to (->link)
	
	Element = temp->Data;	//Element is assigned to the temp->Data, that was originally Front->Data, but we copied into temp previously
	delete temp;			//simply delete
	
	len--;					//decreases the length of our Queue
	
}

template<class T>
bool LinkedQ<T>::Find(int pos, T& Element)
{
	if(pos < 1 || pos > len)
	{
		cout<<"User inserted an invalid position..."<<endl;
		return false;
	}
	
	Node<T> *p = Front;
	for (int i = 1; i < pos; i++)
	{
		p = p->link;
	}
	Element = p->Data;
	return true;
}

template<class T>
int LinkedQ<T>::Search(T Element)
{
	Node<T> *p = Front;
	
	for(int i = 1; p != NULL; i++)
	{
		if(p->Data == Element)
		{
			return i;
		}
		p = p->link;
	}
	return -1;
}



template<class T>
bool LinkedQ<T>::isEmpty()
{
	return Rear == NULL;
}


template<class T>
T LinkedQ<T>::FrontMost()
{
	return Front->Data;
}

template<class T>
T LinkedQ<T>::RearMost()
{
	return Rear->Data;
}

template<class T>
void LinkedQ<T>::Display()
{
	Node<T> *p = Front;
	while(p)
	{
		cout<<p->Data<<" ";
		p = p->link;
	}
}

int main()
{
	LinkedQ<int> lq;
	
	int Element;		// used in some functions below
	
	//Enqueue Elements and display
	lq.EnQueue(1);
	lq.EnQueue(2);
	lq.EnQueue(3);
	lq.EnQueue(4);
	lq.EnQueue(5);
	lq.Display();
	cout<<endl<<"-----------------------"<<endl;
	
	//returns the length of our LinkedQueue	
	cout<<"Length: "<<lq.Length()<<endl;
	cout<<"-----------------------"<<endl;
	
	//Find 
	bool x = lq.Find(3,Element);
	if(x)
		cout<<"Element found: "<<Element<<endl;		
	else
		cout<<"Element not found!"<<endl;
	cout<<"-----------------------"<<endl;

	//Search
	cout<<"Successfull searched Element: "<<lq.Search(Element)<<endl;
	cout<<"-----------------------"<<endl;
	
	//FrontMost
	cout<<"FrontMost: "<<lq.FrontMost()<<endl;
	cout<<"-----------------------"<<endl;
	//RearMost
	cout<<"RearMost: "<<lq.RearMost()<<endl;
	cout<<"-----------------------"<<endl;


	//DeQueue
	lq.DeQueue(Element);
	lq.DeQueue(Element);
	lq.DeQueue(Element);
	lq.DeQueue(Element);
	cout<<"Queue after Dequeing: "<<endl;
	lq.Display();
	cout<<endl<<"-----------------------"<<endl;
	
	//returns the length of our LinkedQueue	after DeQueuing
	cout<<endl<<"Length after DeQueing: "<<lq.Length()<<endl;
	cout<<"-----------------------"<<endl;

	return 0;
}
