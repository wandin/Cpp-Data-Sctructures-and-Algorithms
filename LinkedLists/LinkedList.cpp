// SINGLY LINKED LIST - ADT - abstract data type
// Templated to work with various data types, providing flexibility and reusability.


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
class LinkedList
{
private:
	
	Node<T> *first, *last;
	int length;
	
public:
		
	LinkedList();
	~LinkedList(){};
	
	// Default constructor and destructor
	LinkedList();
	~LinkedList(){};
	
	void Insert(int, T);	// Function to insert a new node at a specified position	
	void Delete(int, T&);	// Function to delete a node at a specified position
	bool Find(int, T&);		// Function to find the data at a specified position
	int Search(T);			// Function to search for a given data in the linked list
	void Display();			// Function to display the elements of the linked list
	int Length();			// Function to return the length of the linked list
	bool IsEmpty();			// Function to check if the linked list is empty
	bool IsFull(); 			// Function to check if the linked list is full (not necessary for linked lists)
	void Concat(LinkedList<T> *a, LinkedList<T> *b);	// Function to concatenate two linked lists
	void Merge(LinkedList<T> *a, LinkedList<T> *b);		// Function to merge two sorted linked lists
	void ReverseUsingArray();				// Function to reverse the linked list using a temporary array
	void ReverseByRearrangingPointers();	// Function to reverse the linked list by rearranging pointers


};

/* CONSTRUCTOR */
template<class T>
LinkedList<T>::LinkedList()
{
	first = NULL;
	last = NULL;
	length = 0;
}


/* INSERT */
template<class T>
void LinkedList<T>::Insert(int pos, T Element) 
{
	Node<T> *temp = new Node<T>; //temporarily node.. 
	
	temp->Data = Element;
	temp->link = NULL;
	if(length == 0)
	{
		first = last = temp; // first and second node are equal to our temp node, as we only have 1 Node at this point(Node *temp)
	}
	else
	{
		if(pos == 1)			//(pos = index + 1)
		{
			temp->link = first; // if we already have one node, we assign the link of first node to temp.
			first = temp;		// now first is temp.
		}
		else if(pos == length+1)	// INSERTING ON LAST POSITION 
		{
			last->link = temp;	//transfer the link of the last node to temp. 
			last = temp;		// now last is temp.
		}
		else
		{
			Node<T> *p = first;
			for (int i = 0; i <= pos-2; i++)
			{
				 p = p->link;
			}
			temp->link = p->link;
			p->link = temp;
		}
	}
	length++;
}

/* DELETE */
template<class T>
void LinkedList<T>::Delete(int pos, T &Element)
{
	Node<T> *p, *nodeToBeDeleted;	// Pointers p and q initially set to the first node of the list
	p = nodeToBeDeleted = first;
	
	if(length == 0)				// check list empty
	{
		cout<<"List is Empty"<<endl;
		return;
	}
	if(IsEmpty())
	{
		cout<<"List is Empty2"<<endl; //second approach using our function

	}
	if(pos == 1)
	{
		nodeToBeDeleted = first;
		first = first->link;	// Update the first pointer to point to the next node
	}
	else if(pos == length)			// if pos == len we are at the last node
	{
		for (int i = i <= pos -2; i++;)	// Traverse the list to the node before the last node
		{
			p = p->link;
		}
		p->link = NULL;				// Set the last node to NULL and update the last pointer
		last = p;
	}
	else				// Node to be deleted is in the middle of the list
	{
		for (int i = i <= pos -2; i++;)
		{
			p = p->link;	
		}
		nodeToBeDeleted = p->link;			// Set pointer q to the node to be deleted

		p->link = nodeToBeDeleted->link;		// Update the link of the previous node to bypass the node to be deleted
	}
	Element = nodeToBeDeleted->Data;
	delete nodeToBeDeleted;
	length--;
}


/* FIND */
template <class T>
bool LinkedList<T>::Find(int pos, T &Element)
{
	Node<T> *p = first;
	
	if(pos < 1 || pos > length) // if position is before first, or after last, doesn`t exist
	{
		return false;
	}
							// else we loop through
	for (int i = 1; i < pos; i++)
	{
		p = p->link;
	}
	Element = p->Data;
	return true;
}


/* SEARCH */
template <class T>
int LinkedList<T>::Search(T Element)
{
	Node<T> *p = first;

	for (int i = 1; i <= length; i++)
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
bool LinkedList<T>::IsEmpty()
{		
	return first == NULL;
}


template<class T>
bool LinkedList<T>::IsFull()
{
	Node<T> *temp = new Node<T>;
}


/* DISPLAY */
template<class T>
void LinkedList<T>::Display()
{
	Node<T> *temp;
	temp = first;
	while(temp != NULL)
	{
		cout<<temp->Data<<"->";
		temp = temp->link;
	}	
}	


template<class T>
void LinkedList<T>::Concat(LinkedList<T> *a, LinkedList<T> *b)
{
	Node<T> *f, *s;
	f = a->first;
	s = b->first;
	Node<T> *p=f;
	while(p->link)
	{
		p = p->link;
	}
	p->link=s;
	s = NULL;
	cout<<"\n\nConcatenated list...\n";
	Node<T> *temp = f;
	while(temp != NULL)
	{
		cout << temp->Data<<"->";
		temp=temp->link;
	}
}

/* Merging LinkedList by rearranging pointers! */
template<class T>
void LinkedList<T>::Merge(LinkedList<T> *a, LinkedList<T> *b)
{

	Node<T> *f, *s; // Pointers to the first nodes of LinkedLists a and b
	f = a->first;   // Set f to point to the first node of LinkedList a
	s = b->first;   // Set s to point to the first node of LinkedList b
	
	Node<T> *p;     // Pointer for tracking the current node while merging

	// Determine the starting node of the merged LinkedList
	// we basicaly check which of first Nodes will be the start of the merged LinkedList.
	// if the first->Data is smaller than second->Data, it means the first node of our merged linked list will be the same as the F, else, S
	if(f->Data < s->Data)	
	{
		first = p = f;  // Set first and p to the first node of LinkedList a
		f = f->link;    // Move f to the next node in LinkedList a
	}
	else
	{
		first = p = s;  // Set first and p to the first node of LinkedList b
		s = s->link;    // Move s to the next node in LinkedList b
	}
	
	first->link = NULL; // Set the link of the first node of the merged LinkedList to NULL

	// Merge the LinkedLists
	while (f && s) 	// Continue until both LinkedLists are not NULL
	{
		if(f->Data < s->Data)   // If the data in node f is smaller than that in node s
		{
			p->link = f;    // Set the link of p to node f
			p = f;          // Update p to point to node f
			f = f->link;    // Move f to the next node in LinkedList a
		}
		else
		{
			p->link = s;    // Set the link of p to node s
			p = s;          // Update p to point to node s
			s = s->link;    // Move s to the next node in LinkedList b
		}
		p->link = NULL;     // Set the link of the current node to NULL
	}

	// Append remaining nodes of either LinkedList, if any
	if(f)
	{
		p->link = f;    // If LinkedList a has remaining nodes, append them to the merged LinkedList
	}
	else
	{
		p->link = s;    // If LinkedList b has remaining nodes, append them to the merged LinkedList
	}
}

template<class T>
void LinkedList<T>::ReverseUsingArray()
{
	Node<T> *p = first;     // Pointer p points to the first node of the LinkedList
	Node<T> *q = first;     // Pointer q points to the first node of the LinkedList
	T *temp;                // Temporary array to store data while reversing
	temp = new T[length];      // Allocate memory for the temporary array
	int i = 0;              // Initialize an index variable for the temporary array

	// Traverse the LinkedList and store its elements in the temporary array
	while(p)
	{
		temp[i] = p->Data;  // Store the data of the current node in the temporary array
		p = p->link;        // Move p to the next node
		i++;                // Increment the index variable
	}
	i--;                    // Decrement i to point to the last index of the temporary array

	// Traverse the LinkedList again and update its elements with the reversed data from the temporary array
	while(q)
	{
		q->Data = temp[i];  // Update the data of the current node with the data from the temporary array
		i--;                // Decrement the index variable
		q = q->link;        // Move q to the next node
	}

	delete[] temp;          // Deallocate memory for the temporary array to avoid memory leaks
}

template<class T>
void LinkedList<T>::ReverseByRearrangingPointers()
{
    Node<T> *r = NULL;  // Pointer to the previous node
    Node<T> *p;         // Pointer to the current node
    Node<T> *q = NULL;  // Pointer to the next node
    p = first;          // Initialize p to the first node of the linked list
    
    // Traverse the linked list
    while (p)
    {
        r = q;          // Update the previous node pointer to the current node
        q = p;          // Update the next node pointer to the current node
        p = p->link;    // Move to the next node in the linked list
        q->link	= r;   // Reverse the link direction to the previous node
    }
    first = q;          // Update the head pointer to point to the last node, which is now the first node
}

int main()
{
	LinkedList<int> SLL;
	
	int x;
	// inserting (index, value)
	SLL.Insert(1, 10);
	SLL.Insert(2, 20);
	SLL.Insert(3, 30);
	SLL.Insert(4, 40);
	SLL.Insert(5, 50);
	SLL.Insert(1, 100); 
	SLL.Display();// displaying inserted elements
	
	
	// deleting
	SLL.Delete(1,x);
	SLL.Delete(1,x);	
	SLL.Delete(1,x);
	SLL.Delete(1,x);
	SLL.Delete(1,x);
	SLL.Delete(1,x);
	SLL.Delete(1,x);
	cout<<"DELETED Element was: "<<x<<endl;
	SLL.Display(); // displaying after delete an element

	
	if(SLL.Find(1, x))		// check if we find something with given parameters
	{
		cout<<"Element found, true! Element is"<< x<<endl;
	}
	else
	{
		cout<<"Element not found!"<<endl;
	}
	
	cout<<"Search found: "<<SLL.Search(50)<<endl;
	
	x = SLL.IsEmpty();
	if(x == 0)
	{	
		cout<<"NOT EMPTY! "<<endl;
	}
	else
	{
		cout<<"EMPTY INDEED!"<<endl;
	}
	
	/* -------------------	*/
	//For Concatenating example
	LinkedList<int>  a,b,c;
	
	a.Insert(1,1);
	a.Insert(2,2);
	a.Insert(3,3);
	a.Insert(4,4);
	a.Insert(5,5);
	
	cout<<"\n\n\n***TO BE CONCATENATED***\n";
	cout<<"First Linked List...\n";
	a.Display();
		
	b.Insert(1,6);
	b.Insert(2,7);
	b.Insert(3,8);
	b.Insert(4,9);
	b.Insert(5,10);
	cout<<"\n\nSecond Linked List...\n";
	b.Display();
	
	c.Concat(&a, &b);
	
	/*-------------------------*/
	// For merging example
	cout<<"\n----------------------------------------"<<endl;

	LinkedList<int>  firstLL,secondLL,mergedLL;
	
	firstLL.Insert(1,1);
	firstLL.Insert(2,15);
	firstLL.Insert(3,40);
	firstLL.Insert(4,45);
	cout<<"\n***TO BE MERGED***\n";
	cout<<"First Linked List...\n";
	firstLL.Display();
		
	secondLL.Insert(1,5);
	secondLL.Insert(2,14);
	secondLL.Insert(3,60);
	cout<<"\n\nSecond Linked List...\n";
	secondLL.Display();
	
	
	mergedLL.Merge(&firstLL, &secondLL);
	cout<<"\n\nMerged LinkedList..\n";
	mergedLL.Display();
	
	cout<<"\n----------------------------------------"<<endl;
	
	/* REVERSE BY USING A TEMPORARY ARRAY */
	LinkedList<int>  ReversebyArray;
	ReversebyArray.Insert(1,1);
	ReversebyArray.Insert(2,15);
	ReversebyArray.Insert(3,40);
	ReversebyArray.Insert(4,45);
	cout<<"\n***TO BE REVERSED WITH TEMP ARRAY***"<<endl;
	ReversebyArray.Display();
	
	ReversebyArray.ReverseUsingArray();
	cout<<"\n\nLinkedList reversed using a temporary Array:"<<endl;
	ReversebyArray.Display();
	cout<<"\n----------------------------------------"<<endl;

	/* END */
	

	LinkedList<int>  ReverseByPointers;
	ReverseByPointers.Insert(1,1);
	ReverseByPointers.Insert(2,15);
	ReverseByPointers.Insert(3,40);
	ReverseByPointers.Insert(4,45);
	cout<<"\n*** TO BE REVERSED BY REARRANGING POINTERS ***\n";

	ReverseByPointers.Display();
	
	/* -- REVERSE Rearranging pointers */
	ReverseByPointers.ReverseByRearrangingPointers();
	cout<<"\n\nLinkedList reversed rearranging pointers:"<<endl;
	ReverseByPointers.Display();

	
	return 0;
}
