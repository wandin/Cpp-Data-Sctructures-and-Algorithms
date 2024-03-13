# LinkedLists

This repository contains the implementation of a linked list (LinkedList) in C++ as an Abstract Data Type (ADT). Below are the operations performed on the LinkedList:

## Operations on LinkedList

1. **Insert:** Inserts an element at a specific position in the linked list.
2. **Delete:** Deletes an element from a specific position in the linked list.
3. **Find:** Finds an element at a specific position in the linked list.
4. **Search:** Searches for an element in the linked list and returns its position.
5. **Display:** Displays all elements of the linked list.
6. **IsEmpty:** Checks if the linked list is empty.
7. **Concat:** Concatenates two linked lists.

## Example Usage

Here's a simple example of using the LinkedList:

```cpp
LinkedList<int> SLL;

// Inserting elements
SLL.Insert(1, 10);
SLL.Insert(2, 20);
SLL.Insert(3, 30);

// Displaying elements
SLL.Display();

// Deleting elements
SLL.Delete(1, x);
SLL.Delete(1, x);

// Finding elements
if(SLL.Find(1, x)) {
    cout << "Element found: " << x << endl;
} else {
    cout << "Element not found!" << endl;
}

// Searching elements
cout << "Element found at position: " << SLL.Search(30) << endl;

// Checking if the list is empty
if(SLL.IsEmpty()) {
    cout << "The list is empty!" << endl;
} else {
    cout << "The list is not empty!" << endl;
}

// Concatenating lists
LinkedList<int> a, b, c;
a.Insert(1, 1);
b.Insert(1, 6);
c.Concat(&a, &b);
