// Implementation of a Circular Linked List (also known as Circular Singly LinkedList)
// Templated to work with various data types, providing flexibility and reusability.

// Circular linked list is a type of Singly Linked List where the last node's pointer points back to the first node,
// effectively creating a circular structure. This implementation does not utilize a head node.
// Note: Another variation exists that uses a head node, but it's not implemented here.
// When using a head node, even in an empty list, the head node points to itself.


#include <iostream>

using namespace std;

/* Node Class*/
template<class T>
class Node
{
	public:
	T Data;
	Node<T> *link;	// link to next Node
};

/* Circular Linked List class */
template<class T>
class CircularLinkedList
{
	
private:
		
	Node<T> *first;
	Node<T> *last;
	int length;
		
public:
	
	CircularLinkedList();
	~CircularLinkedList();
	
	void Insert(int, T);    // Method to insert an element into the circular linked list at a specified position
	void Delete(int, T&);   // Method to delete an element from the circular linked list at a specified position
	bool Find(int, T&); 	// Method to find an element at a specified position in the circular linked list, Returns true if the element is found, false otherwise
	int Search(T);    		// Method to search for an element in the circular linked list, Returns the position of the element if found, -1 otherwise
	void Display();    		// Method to display the elements of the circular linked list
	int Length();    		// Method to return the length of the circular linked list
	bool isEmpty();	    	// Method to check if the circular linked list is empty, Returns true if the circular linked list is empty, false otherwise
	
};

/* CONSTRUCTOR */
template<class T>
CircularLinkedList<T>::CircularLinkedList()
{
	length = 0;
	first = NULL;
	last = NULL;
};

/* DESTRUCTOR */
template<class T>
CircularLinkedList<T>::~CircularLinkedList()
{
	Node<T> *p = first;
	
	cout<<"\n **DESTRUCTOR EXECUTION"<<endl;
	
    while(p->link != first)
        p = p->link;
    while(p!=first)
    {
        p->link = first->link;
        cout<<first->Data<<" Deleted \n";
        delete first;
        first = p->link;

    }
    if(p == first)
    {
        cout<<first->Data<<" Deleted \n";
        delete first;
        first = NULL;
    }
};


// Function to insert an element into the circular linked list at a specified position
template<class T>
void CircularLinkedList<T>::Insert(int pos, T Element)
{
    Node<T> *temp; // Create a temporary node pointer
    temp = new Node<T>; // Allocate memory for the new node
    temp->Data = Element; // Assign the data of the new node
    temp->link = temp; // Make the new node point to itself initially
    
    // Check if the list is empty
    if(length == 0)
    {
        // If the list is empty, set both first and last pointers to the new node
        first = last = temp;
    }
    else
    {
        // If the list is not empty
        if(pos == 1)
        {
            // If the position is 1, insert the new node at the beginning of the list
            temp->link = first; // Make the new node point to the current first node
            first = temp; 		// Update the first pointer to point to the new node
            last->link = first; // Make the last node point to the new first node to maintain circularity
        }
        else if(pos == length+1)
        {
            // If the position is at the end of the list, insert the new node at the end
            last->link = temp; // Make the current last node point to the new node
            last = temp; 		// Update the last pointer to point to the new node
            last->link = first; // Make the new last node point to the first node to maintain circularity
        }
        else
        {
            // If the position is neither at the beginning nor at the end
            Node<T> *p = first; // Create a traversal pointer and initialize it to the first node
            for (int i = 1; i <= pos - 2; i++)
            {
            	p = p->link; // Traverse the list to reach the node just before the insertion position
			}
            temp->link = p->link; // Make the new node point to the node at the insertion position
            p->link = temp; // Make the previous node point to the new node
        }
    }
    length++; // Increment the length of the list
}


/* DELETE */
template<class T>
void CircularLinkedList<T>::Delete(int pos, T& Element)
{
    // Check if the list is empty
    if(length == 0 )
    {
        cout<< "Nothing to be deleted - Linked List is empty!";
        return;
    }
    
    Node<T> *p, *q; // Create two pointers for traversal
    p = q = first; 	// Initialize both pointers to point to the first node
    
    // If the position is the first node
    if(pos == 1)
    {
        first = first->link; 	// Update the first pointer to point to the next node
        last->link = first; 	// Make the last node point to the new first node to maintain circularity
    }
    // If the position is the last node
    else if(pos == length)
    {
        // Traverse the list to reach the node just before the last node
        for (int i = 1; i <= pos -2; i++)
        {
            p = p->link;
        }
        q = last; 			// Set q pointer to the last node
        last = p; 			// Update the last pointer to point to the node before the last node
        last->link = first; // Make the new last node point to the first node to maintain circularity
    }
    else
    {
        // If the position is neither the first nor the last node
        // Traverse the list to reach the node just before the position to be deleted
        for (int i = 1; i <= pos -2; i++)
        {
            p = p->link;
        }
        q = p->link; 		// Set q pointer to the node to be deleted
        p->link = q->link; 	// Adjust the link of the previous node to skip over the node to be deleted
    }
    Element = q->Data; 	// Retrieve the data of the deleted node
    delete q; 			// Deallocate memory for the deleted node
    length--; 			// Decrement the length of the list
}

/* FIND */
template<class T>
bool CircularLinkedList<T>::Find(int pos, T &Element)
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
template<class T>
int CircularLinkedList<T>::Search(T Element)
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

/* DISPLAY LINKED LIST*/ 
template<class T>
void CircularLinkedList<T>::Display()
{
	Node<T> *p = first;
	cout<<p->Data<<"->";
	p = p->link;
	while (p != first)
	{
		cout<<p->Data<<"->";
		p = p->link;
	}
	cout <<"\n";
}

/* RETURN LENGTH OF LINKED LIST */
template<class T>
int CircularLinkedList<T>::Length()
{
	return length;
}

/* RETURN IF LINKED LIST IS EMPTY */ 
template<class T>
bool CircularLinkedList<T>::isEmpty()
{
	return first == NULL;
}

main()
{
	CircularLinkedList<int> CLL;
	
	// INSERTING
	cout<<"\n**Insert Method"<<endl;
	CLL.Insert(1, 100); 	// 1st pos
	CLL.Insert(2, 200);	// 2nd pos
	CLL.Insert(3, 300);	// 3rd pos
	CLL.Insert(4, 400);	// 4th pos
	CLL.Insert(5, 500);	// 5th pos
	CLL.Insert(5, 600);	// 6th pos
	CLL.Insert(1, 10); 	// here we are inserting (0) in 1st position again, so the previous value (1) in 1st position becomes the 2nd position. 
	CLL.Display();		// output = 0->1->2->3->4->6->5->	// USING THE NORMAL ITERATIVE DISPLAY METHOD
	cout<<"-------------------"<<endl;
	//END OF INSERTING//
	
	
	//DELETING
	cout<<"\n**Delete Method"<<endl;
	int tobeDeleted;			
	cout<<"Element To be Deleted is: "<<tobeDeleted<<endl;
	CLL.Delete(1,tobeDeleted);	// we delete the given integer at position 1
	cout<<"List after deleting the element "<<tobeDeleted<<endl;
	CLL.Display();				// output = 1->2->3->4->6->5->
	cout<<"-------------------"<<endl;
	//END OF DELETING
	
	
	// FIND//
	cout<<"\n**Find Method"<<endl;
	int tobeFound;
	if(CLL.Find(1, tobeFound))		// check if we find something with the given parameters
	{
		cout<<"Element found, true! Element is "<< tobeFound<<endl;
	}
	else
	{
		cout<<"Element not found!"<<endl;
	}
	cout<<"-------------------"<<endl;
	// END OF FIND
	
	
	// SEARCH METHOD
	cout<<"\n**Search Method"<<endl;
	int tobeSearched = 200;
	int position = CLL.Search(tobeSearched);
	if(position > -1)
	{
		cout << "Successful Search at position: "<<CLL.Search(tobeSearched)<<endl;
	}
	else
	{
		cout<<"SEARCH NOT SUCCESFUL!"<<endl;
	}
	cout<<"-------------------"<<endl;
	// END OF SEARCH
	
	
	// LENGTH METHOD
	cout<<"\n**Lenght Method"<<endl;
	int listLength = CLL.Length();
	cout <<"Length is: "<<listLength<<endl;
	cout<<"-------------------"<<endl;
	// END OF LENGTH

	
	// Is EMPTY METHOD
	cout<<"\n**IsEmpty Method"<<endl;
	int result = CLL.isEmpty();
	if(result == 0)
	{	
		cout<<"NOT EMPTY! "<<endl;
	}
	else
	{
		cout<<"EMPTY INDEED!"<<endl;
	}
	cout<<"-------------------"<<endl;
	// END OF EMPTY


};
