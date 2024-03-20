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
	Node<T> *p = first;
	while(p)
	{
		first = first->next;
		delete p;
		p = first;
	}
}

template <class T>
void DoublyLinkedList<T>::Insert(int pos, T Element)
{
    Node<T> *temp;
    temp = new Node<T>; // Create a new node
    temp->Data = Element; // Assign data to the new node
    temp->prev = NULL;
    temp->next = NULL;
	
    // If the list is empty
    if(length == 0) 
    {
        first = temp; // Set the new node as both first and last node
        last = temp;
    }
    else 
    {
        // If inserting at the beginning
        if(pos == 1) 
        {
            temp->next = first; 	// Set the next of the new node to the current first node
            first->prev =  temp; 	// Set the previous of the current first node to the new node
            first = temp; 			// Update the first pointer to the new node	
        }
        // If inserting at the end
        else if (pos == length +1) 
        {
            temp->prev = last; 		// Set the previous of the new node to the current last node
            last->next = temp; 		// Set the next of the current last node to the new node
            last = temp; 			// Update the last pointer to the new node
        }
        else	// Inserting in the middle
        {
            Node<T> *p = first;
            // Traverse to the node before the position to be inserted
            for (int i = 1; i <= pos-2; i++)
            {
                p = p->next;
            }
            temp->next = p->next; 	// Set the next of the new node to the next of the current node
            temp->prev = p; 		// Set the previous of the new node to the current node
            p->next->prev = temp; 	// Set the previous of the next node to the new node
            p->next = temp; 		// Set the next of the current node to the new node
        }
    }
    length++; // Increase the length of the list
}



/* DELETE FUNCTION */
template<class T>
void DoublyLinkedList<T>::Delete(int pos, T& Element)
{
	Node<T> *p, *q;
	
	if(length == 0)
	{
		cout<<"Nothing to delete - List is empty"<<endl;
	}
	if(pos == 1)
	{
        p = first; 				// Store the first node
        first = first->next; 	// Update the first pointer to the next node
        first->prev = NULL; 	// Set the previous of the new first node to NULL
        Element = p->Data; 		// Store the data of the deleted node
        delete p; 				// Delete the node
	}
	else if(pos == length)
	{
        p = last; 				// Store the last node
        last = last->prev; 		// Update the last pointer to the previous node
        last->next = NULL; 		// Set the next of the new last node to NULL
        Element = p->Data; 		// Store the data of the deleted node
        delete p; 				// Delete the node
	}
	else
	{
        p = first; // Start from the first node
        for (int i = 1; i <= pos-2; i++) // Traverse to the node before the position to be deleted
        {
            p = p->next;
        }
        q = p->next; 			// Store the node to be deleted
        q->next->prev = p; 		// Update the previous pointer of the next node
        Element = q->Data; 		// Store the data of the deleted node
        delete q; 				// Delete the node
	}
	length--;					// Decrease the length of the list
}

template<class T> 
bool DoublyLinkedList<T>::Find(int pos, T& Element)
{
   	Node<T> *p = first;
	
	if(pos < 1 || pos > length) // if position is before first, or after last, doesn`t exist
	{
		return false;
	}
	// else we loop through
	for (int i = 1; i < pos; i++)
	{
		p = p->next;
	}
	Element = p->Data;
	return true;
}

template <class T>
int DoublyLinkedList<T>::Search(T Element)
{
	Node<T> *p = first;
	int index = 1;
	while(p)
	{
		if(p->Data == Element)
		{
			return index;
		}
		p = p->next;
		index++;
	}
	return -1;	
}

/* LENGTH */
template <class T>
int DoublyLinkedList<T>::Length()
{
	return length;
}

/* is Empty */
template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
	return first == NULL;
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
	
	/* Insert Method */
	cout<<"\nINSERT"<<endl;
	DLL.Insert(1, 100);
	DLL.Insert(2, 200);
	DLL.Insert(3, 300);
	DLL.Insert(4, 400);
	DLL.Insert(5, 500);
	DLL.Insert(6, 600);
	DLL.Display();
	cout<<"\n---------------------------"<<endl;
		
	/* Delete Method*/
	cout<<"\nDELETE"<<endl;
	int deleted;
	DLL.Delete(6,deleted);
	DLL.Display();
	cout<<"\n---------------------------"<<endl;
	
	/* FIND Method*/
	cout<<"\nFIND"<<endl;
	int find;
	if(DLL.Find(4, find))
	{
		cout <<"Element found: "<<find<<endl;
	}
	cout<<"\n---------------------------"<<endl;

	// EMPTY
	cout<<"\nEMPTY"<<endl;
	if(DLL.isEmpty())
        cout<<"\nList is EMPTY...\n";
    else
        cout<<"\nList is NOT EMPTY...\n";
	cout<<"\n---------------------------"<<endl;


	/* SEARCH Method*/
	cout<<"\nSEARCH"<<endl;
	int searched = DLL.Search(300);
	cout<<"\nElement Found at Position "<<searched<<endl;
	cout<<"\n---------------------------"<<endl;

	// RETURN LENGTH
	cout<<"\nLENGTH"<<endl;
    cout<<"\nThe Length of the List is..."<<DLL.Length();
	

	
	return 0;
};
