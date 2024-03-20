// Implementation of a Doubly Linked List
// Templated to work with various data types, providing flexibility and reusability.
// A doubly linked list is a data structure consisting of a sequence of elements, where each element contains a reference to the next and previous elements in the sequence.
// Unlike a singly linked list, which only points to the next element, a doubly linked list allows traversal in both forward and backward directions.
// This flexibility enables efficient insertion and deletion operations at both the beginning and end of the list, as well as traversal in either direction.
// Each node in a doubly linked list contains three components: the data value, a pointer to the previous node (prev), and a pointer to the next node (next).
// The list is typically accessed through a reference to the first node (head) and sometimes a reference to the last node (tail), allowing efficient insertion and deletion operations.

#include <iostream>

using namespace std;

/* NODE CLASS */
template<class T>
class Node
{
public:
	
	T Data;
	Node<T> *prev;
	Node<T> *next;	
};

/* DOUBLY LINKED LIST CLASS */
template<class T>
class DoublyLinkedList
{
private:
	
	Node<T> *first;
	Node<T> *last;
	int length;		

public:
	
	DoublyLinkedList();
	~DoublyLinkedList();
	
	//functions
	void Insert(int, T); 		// params - position, element to be inserted
	void Delete(int, T&);		// params - position and reference to element to be deleted
	bool Find(int, T&);			// params - position and reference to element to be found, returning boolean (true/false)
	int Search(T);				// params - element to search, returns its position
	int Length();				// returns the length of the linked list.
	bool isEmpty();				// check if it's empty and returns true or false 
	bool isFull();				// check if it's full and returns true or false
	void Display();				// display all the elements in the list
		
		
};

/* CONSTRUCTOR */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	first = NULL;
	last = NULL;
	length = 0;	
}

/* DESTRUCTOR */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	
}

template <class T>
void DoublyLinkedList<T>::Insert(int pos, T Element)
{
	Node<T> *temp;
	temp = new Node<T>;
	temp->Data = Element;
	temp->prev = NULL;
	temp->next = NULL;
	
	
	// if is the first position
	// if first node is not valid, so the list is empty. We'll be inserting in the first node then.
	
	if(length == 0) 
	{
		first = temp;
		last = temp;
	}
	else 
	{
		if(pos == 1) // if is first position
		{
			temp->next = first;
			first->prev =  temp;
			first = temp;	
		}
		else if (pos == length +1) // if last position
		{
			temp->prev = last;
			last->next = temp;
			last = temp;
		}
		else	// middle position
		{
			Node<T> *p = first;
			
			for (int i = 1; i <= pos-2; i++)
			{
				p = p->next;
			}
			temp->next = p->next;
			temp->prev = p;
			p->next->prev = temp;
			p->next = temp;
		}
	}
	length++;
}






/* DISPLAY */
template<class T>
void DoublyLinkedList<T>::Display()
{
	Node<T> *p;
	p = first;
	while(p)
	{
		cout<<p->Data<<"->";
		p = p->next;
	}	
}

main()
{
	DoublyLinkedList<int> DLL;
	
	
	DLL.Insert(1, 10);
	DLL.Insert(2, 20);
	DLL.Insert(3, 30);
	DLL.Insert(4, 40);
	DLL.Insert(5, 50);
	DLL.Insert(6, 60);

	
	DLL.Display();
	
	return 0;
};
