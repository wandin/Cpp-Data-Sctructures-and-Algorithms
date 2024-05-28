// STACK implementation -> using Array representation
// Basic infos:
// - Location(i) = i - 1, same as position 1 = index(i) 0;
// - Templated to work with various data types, providing flexibility and reusability.

#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    T *s; 		// Pointer to the array to store stack elements
    int top; 	// Index of the top element
    int length; // Current number of elements in the stack
    int size; 	// Maximum capacity of the stack

public:
    Stack(int);				// Constructor
    ~Stack();				// Destructor
    
    void Push(T);     		// Push: Inserting an element onto the stack
    void Pop(T &);    		// Pop: Removing the top element from the stack
    bool Find(int, T &);    // Find: Retrieve the element at a given position
    int Search(T);    		// Search: Find the position of a given element in the stack
    int Length();    		// Length: Get the current number of elements in the stack
    bool isEmpty();    		// isEmpty: Check if the stack is empty
    bool isFull();    		// isFull: Check if the stack is full
    void Display();    		// Display: Print all elements in the stack
};

// Constructor
template <class T>
Stack<T>::Stack(int sz)
{
    size = sz;
    s = new T[size];
    top = -1; // Initialize top to -1 to indicate an empty stack
    length = 0; // Initialize the length to 0
}

// Destructor
template <class T>
Stack<T>::~Stack()
{
    delete[] s; // Free the dynamically allocated memory
}

// Push: Inserting an element onto the stack
template <class T>
void Stack<T>::Push(T Element) {
    if(isFull())
	{
        cout << "- STACK OVERFLOWS - Stack is full. Cannot push Element."<<endl;
        return;
    }
    s[++top] = Element; // Increment top and then insert the element
    length++;
}

// Pop: Removing the top element from the stack
template <class T>
void Stack<T>::Pop(T &Element)
{
    if(isEmpty())
	{
        cout <<"Stack is empty. Cannot pop element." <<endl;
        return;
    }
    Element = s[top--]; // Decrement top and then retrieve the element
    length--;
}

// Find: Retrieve the element at a given position
template <class T>
bool Stack<T>::Find(int position, T &Element)
{
    if (position < 1 || position > length)
	{
        cout << "Invalid position."<<endl;
        return false;
    }
    Element = s[position - 1];
    return true;
}

// Search: Find the position of a given element in the stack
template <class T>
int Stack<T>::Search(T Element)
{
    for (int i = 0; i <= top; i++)
	{
        if(s[i] == Element)
		{
            return i+1; // Return position (index + 1) of the element
        }
    }
    return -1; // Return -1 if element not found
}

// Length: Get the current number of elements in the stack
template <class T>
int Stack<T>::Length()
{
    return length;
}

// isEmpty: Check if the stack is empty
template <class T>
bool Stack<T>::isEmpty()
{
    return top == -1; // returns true if top is -1, indicating an empty stack
}

// isFull: Check if the stack is full
template <class T>
bool Stack<T>::isFull()
{
    return top == size -1; // returns true if top is equal to the maximum index (size - 1)
}

// Display: Print all elements in the stack
template <class T>
void Stack<T>::Display()
{
    if (isEmpty())
	{
        cout <<"Stack is Empty."<<endl;
        return;    
    }
    cout<<"Stack Elements: "<<endl;
    for (int i = 0; i <= top; i++)
	{
        cout<<s[i]<<" "<<endl;
    }
}

int main() {
    // Test your stack implementation here
    Stack<int> stack(5);
    
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);

    // Check isEmpty
    if(stack.isEmpty())
    {
    	cout<<"Is Empty"<<endl;
	}
	else
	{
		cout<<"Is not empty."<<endl;
	}
	cout<<"--------------------"<<endl;
	//End isEmpty
	
	//IsFull
	if(stack.isFull())
	{
		cout<<"Is Full"<<endl;
	}
	else
	{
		cout<<"Is not full."<<endl;
	}
	cout<<"--------------------"<<endl;
	//End isFull
	
	// Length
	int len = stack.Length();
	cout <<"The length of the stack is: "<<len<<endl;
	cout<<"--------------------"<<endl;
	// End of length

	
	// Searching
	int element = stack.Search(3);
	cout<<"Element searched: "<<element<<endl;
	cout<<"--------------------"<<endl;
	// End of search

	
	// Find
	int elementfound;
	if(stack.Find(4,elementfound))
	{
		cout<<"Element found at given positon: "<<elementfound<<endl;
	}
	else
	{
		cout<<"Element not found!"<<endl;
	}
	cout<<"--------------------"<<endl;
	//End find
	
	
    stack.Display();
    
    // trying to push one more time, to give overflows message as well. 
    stack.Push(6);

    
    return 0;
}

