// Stack using Linked List - Stack Linked representation

#include <iostream>

using namespace std;


template <class T>
class Node
{
	
public:
	T Data;
	Node<T> *link;
	
};


template <class T>
class StackLinked
{
private:
	
	Node<T> *top;
	int length;

public:
	
	StackLinked();
	~StackLinked();
	
	void Push(T);
	void Pop(T&);
	void Display();
	bool Find(int, T&);
	bool isEmpty();
	int Search(T);
	int Length();

};

//Constructor
template <class T>
StackLinked<T>::StackLinked()
{
    top = NULL;     // Initialize top pointer to NULL
    length = 0;     // Initialize length to 0
}

//Destructor
template <class T>
StackLinked<T>::~StackLinked()
{
    Node<T> *temp = top;    // Temporary pointer to traverse the stack
    while(temp)
    {
        top = top->link;    // Move top pointer to the next node
        cout << "Deleted: " << temp->Data << endl;    // Display the deleted element
        delete temp;    	// Delete the current node
        temp = top;     	// Move temp pointer to the next node
    }
}

// Push operation to insert element
template <class T>
void StackLinked<T>::Push(T Element)
{
    Node<T> *temp;      	// Temporary pointer to create a new node
    temp = new Node<T>; 	// Create a new node
    temp->Data = Element;   // Assign data to the new node
    temp->link = NULL;  	// Initialize link of the new node to NULL
    
    if(temp == NULL)
    {
        cout << "Stack Overflows.." << endl;    // Check for stack overflow
        return;
    }
    if(length == 0)
    {
        top = temp;     // If stack is empty, assign top to the new node
    }
    else
    {
        temp->link = top;   // Link new node to the current top node
        top = temp;         // Make new node as top
    }
    length++;   // Increment length of the stack
}

// Pop operation to delete element
template <class T>
void StackLinked<T>::Pop(T& Element)
{
    Node<T> *temp;  // Temporary pointer to hold node to be deleted
    
    if(length == 0)
    {
        cout << "Stack underflows(Empty)." << endl;    // Check for stack underflow
        return;
    }
    else
    {
        temp = top;     		// Assign top to temp
        top = top->link;    	// Move top to the next node
        Element = temp->Data;   // Retrieve data of the node to be deleted
        delete temp;    		// Delete the node
        length--;   			// Decrement length of the stack
    }
}

// Display all elements in the stack
template <class T>
void StackLinked<T>::Display()
{
    Node<T> *temp = top;    // Temporary pointer to traverse the stack
    
    if(length == 0)
    {
        cout << "There's nothing to display, stack is empty." << endl;   // Check if stack is empty
    }
    while(temp)
    {
        cout << "Element " << temp->Data << "-> ";   // Display each element of the stack
        temp = temp->link;  						// Move to the next node
    }
}

// Find element at given position
template <class T>
bool StackLinked<T>::Find(int pos, T& Element)
{
    if (pos < 1 || pos > length)
    {
        cout << "Invalid position." << endl;   // Check for valid position
        return false;
    }
    Node<T> *temp = top;    		// Temporary pointer to traverse the stack
    for (int i = 1; i < pos; i++)
    {
        temp = temp->link;  		// Move to the desired position
    }
    Element = temp->Data;   		// Retrieve data at the desired position
    return true;
}

// Check if stack is empty
template <class T>
bool StackLinked<T>::isEmpty()
{
    return length == 0;     // Check if length is zero
}

// Search for element in the stack
template <class T>
int StackLinked<T>::Search(T Element)
{
    Node<T> *temp = top;    	// Temporary pointer to traverse the stack
    while (temp)
    {
        if (temp->Data == Element)
            return temp->Data;   // Return index if element is found
        temp = temp->link;  	// Move to the next node
    }
    return -1;              	// Element not found
}

// returns length
template <class T>
int StackLinked<T>::Length()
{
	return length;
}


main()
{

    StackLinked<int> SL;

    // Inserting elements
    cout << "\nInserting elements using 'Push()': " << endl;
    SL.Push(1);
    SL.Push(2);
    SL.Push(3);
    SL.Push(4);
    SL.Display();
    cout << "\n\n-------------------------------------------------------------" << endl<<endl;

    // Deleting an element
    cout << "Deleting an element using 'Pop()': " << endl;
    int x;
    SL.Pop(x);
    SL.Display();
    cout << "\n\n-------------------------------------------------------------" << endl;

    // Finding an element
    cout << "\nFinding an element at position 2: ";
    if (SL.Find(2, x))
        cout << "Element is " << x << endl;
    cout << "\n-------------------------------------------------------------" << endl;

    // Checking if stack is empty
    cout << "\nIs the stack empty? ";
    if (SL.isEmpty())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "\n-------------------------------------------------------------" << endl;

    // Searching for an element
    cout << "\nSearching for an element: ";
    int index = SL.Search(4);
    if (index != -1)
        cout << "Element found at position " << index << endl;
    else
        cout << "Element not found in the stack." << endl;
    cout << "\n-------------------------------------------------------------" << endl;

    // Displaying length of the stack
    cout << "\nLength of the stack: " << SL.Length() << endl;
    cout << "\n-------------------------------------------------------------" << endl;

    // Destructor called
    cout << "Destructor called!" << endl;

    return 0;
};
