# Arrays and LinkedLists

This repository contains the implementation of DataStructures in C++ as Abstract Data Types (ADTs). Below are the operations performed on Arrays:

## Arrays (Array folder)

### Operations on Arrays

1. **Insert:** Inserts an element at a specific position in the array.
2. **Delete:** Deletes an element from a specific position in the array.
3. **Find:** Finds an element at a specific position in the array.
4. **Search:** Searches for an element in the array and returns its position.
5. **Length:** Returns the size of the array.
6. **Display:** Displays all elements of the array.
7. **IsEmpty:** Checks if the array is empty.
8. **IsFull:** Checks if the array is full.
9. **Get:** Retrieves the value at a given index in the array.
10. **Set:** Sets the value at a given index in the array.
11. **IndexOf:** Finds the index of a given element in the array.
12. **FindMax:** Finds the largest value in the array.
13. **FindMin:** Finds the smallest value in the array.
14. **SumOfArray:** Computes the sum of all elements in the array.
15. **Avg:** Computes the average value of all elements in the array.
16. **Append:** Appends an element to the end of the array.
17. **LeftRotate:** Performs a left rotation on the array.
18. **RightRotate:** Performs a right rotation on the array.
19. **Reverse:** Reverses the order of elements in the array.

### Binary Search (Within Array folder)

#### Description
This class implements iterative binary search on an array in C++.

#### Constructor
- **BinarySearch(int n):** Initializes a BinarySearch object with an array of size `n` and prompts the user to enter `n` elements in ascending order.

#### Methods
- **int BSearch(int low, int high, T key):** Performs iterative binary search on the array to find the position of the element `key`. Returns the position of the element if found, or -1 if not found.

#### Usage Example
```cpp
int main() {
    int n;
    int low = 0;
    int key;
    cout << "Enter number of data elements: " << endl;
    cin >> n;
    int high = n - 1;
    
    BinarySearch<int> BS(n);

    cout << "Enter the element to search: " << endl;
    cin >> key;

    int index = BS.BSearch(low, high, key);
    if (index == -1) {
        cout << "\nElement not found." << endl;
    } else {
        cout << "\nFound element " << key << " at position " << index << endl;
    }
    return 0;
}
```

### Class MinMerges.cpp (Within Array folder)

#### Description
This class implements a function to find the minimum number of operations required to make the elements of the array a palindrome.
[i.e: { 1, 6, 3, 4 }], after 2 operations the array will be {7,7} and will print The minimum number of operations required is 2.

### Class PrintAllSubArrays.cpp (Within Array folder)

#### Description
This class implements a function to find and print all subarrays of an array, that indexes when summed up are equal to zero.
[i.e: {1, -1}] will print Sub-Array indexes [0 to 1] and the values of each index [1, -1]

### Class SmallestPosNum.cpp (Within Array folder)

#### Description
This class implements a function to find the smallest positive missing number.
[i.e: {1, 2, 3, 4, 5, 6}] output-> "The smallest positive missing number is 7"


## LinkedLists (LinkedList folder)

Below are the operations performed on the LinkedList:

### Operations on LinkedList

1. **Insert:** Inserts an element at a specific position in the linked list.
2. **Delete:** Deletes an element from a specific position in the linked list.
3. **Find:** Finds an element at a specific position in the linked list.
4. **Search:** Searches for an element in the linked list and returns its position.
5. **Display:** Displays all elements of the linked list.
6. **IsEmpty:** Checks if the linked list is empty.
7. **Concat:** Concatenates two linked lists.
8. **Merge:** Merges two linkedList by rearranging Node pointers.
9. **Reverse a LinkedList using a Temp Array** Self explanatory 😂
10. **Reverse a LinkedList:** Reverses a LinkedList by rearranging Node pointers.


## Circular LinkedLists (LinkedList folder)

Below are the operations performed on the Circular LinkedList:

1. **Constructor**.
2. **Destructor**.
3. **Insert** Inserts an element at a specific position in the Circular linked list.
4. **Delete** Deletes an element from a specific position in the Circular Linked List.
5. **Find** Finds an element at a specific position in the Circular Linked List.
6. **Search** Searches for an element in the Circular Linked List and returns its position.
7. **Display** Displays all elements of the Circular Linked List.
8. **Display Using Recursion**. Displays all elements of the Circular Linked List using recursion.
9. **Length** Returns the length of the Circular Linked List.
10. **IsEmpty** Checks if the Circular Linked List is empty, returns a bool.


## Doubly LinkedLists (LinkedList folder)

Below are the operations performed on the Doubly LinkedList:

1. **Constructor**.
2. **Destructor**.
3. **Insert** Inserts an element at a specific position in the Doubly linked list.
4. **Delete** Deletes an element from a specific position in the Doubly Linked List.
5. **Find** Finds an element at a specific position in the Doubly Linked List.
6. **Search** Searches for an element in the Doubly Linked List and returns its position.
7. **Length** Returns the length of the Doubly Linked List.
8. **IsEmpty** Checks if the Doubly Linked List is empty, returns a bool.
9. **Display** Displays all elements of the Doubly Linked List.


## Stack using Array Representation (Stack folder)

Below are the operations performed on the Stack using an Array Implementation:

1. **Constructor**.
2. **Destructor**.
3. **Push** Inserts an element at the Stack.
4. **Pop** Deletes an element from the Stack.
5. **Find** Retrieve the element at a given position in the Stack.
6. **Search** Find the position of a given element in the stack.
7. **Length** Returns the length of the Stack.
8. **IsEmpty** Checks if the Stack is empty, returns a bool.
9. **IsFull** Checks if the Stack is full, returns a bool.
10. **Display** Displays all elements of the Stack.

## 2 Stacks using a single Array (Stack folder - 2_Stacks_1_Array.cpp)

Simple demonstration of using 2 stacks with a single array.
1. **Push** Inserts an element at each Stack.
2. **Pop** Deletes an element from each Stack.
3. **Display** Displays all elements of each Stack.
4. **TopMost** Returns the element at top position in each stack.

## Stack using Linked Representation (LinkedList) (Stack folder)
Below are the operations performed on the Stack using a Linked Implementation:

1. **Constructor**.
2. **Destructor**.
3. **Push** Inserts an element at the Stack.
4. **Pop** Deletes an element from the Stack.
5. **Find** Retrieve the element at a given position in the Stack.
6. **Search** Find the position of a given element in the stack.
7. **Length** Returns the length of the Stack.
8. **IsEmpty** Checks if the Stack is empty, returns a bool.
9. **IsFull** Checks if the Stack is full, returns a bool.
10. **Display** Displays all elements of the Stack.

## Queue (Queue folder)
Below are the operations performed on a Queue:

1. **Constructor**.
2. **Destructor**.
3. **EnQueue** Inserts an element at the Queue.
4. **DeQueue** Deletes an element from the Queue.
5. **Find** Retrieve the element at a given position in the Queue.
6. **Search** Find the position of a given element in the Queue.
7. **Length** Returns the length of the Queue.
8. **IsEmpty** Checks if the Queue is empty, returns a bool.
9. **IsFull** Checks if the Queue is full, returns a bool.
10. **Display** Displays all elements of the Queue.

## CircularQueue (Queue folder)
Below are the operations performed on a CircularQueue:

1. **Constructor**.
2. **Destructor**.
3. **EnQueue** Inserts an element at the Queue.
4. **DeQueue** Deletes an element from the Queue.
5. **FrontElement** Retrieve the Front element, index 0.
6. **RearElement** Retrieve the Rear element, last element inserted.
7. **Length** Returns the length of the Queue.
8. **IsEmpty** Checks if the Queue is empty, returns a bool.
9. **IsFull** Checks if the Queue is full, returns a bool.
10. **Display** Displays all elements of the Queue.

## LinkedQueue (Queue folder)
Below are the operations performed on a Linked Queue:

1. **Constructor**.
2. **Destructor**.
3. **EnQueue** Inserts an element at the Queue.
4. **DeQueue** Deletes an element from the Queue.
5. **FrontMost** Retrieve the Front element, index 0.
6. **RearMost** Retrieve the Rear element, last element inserted.
7. **Length** Returns the length of the Queue.
8. **IsEmpty** Checks if the Queue is empty, returns a bool.
10. **Display** Displays all elements of the Queue.


## DoubleEndedQueue (Queue folder)
Below are the operations performed on a DoubleEnded Queue:

1. **Constructor**.
2. **Destructor**.
3. **InsertFromFront** Inserts an element at the Queue.
4. **InsertFromRear** Deletes an element from the Queue.
5. **DeleteFromFront** Deletes an element from the Front indicator in the Queue.
6. **DeleteFromRear** Deletes an element from the Rear indicator in the Queue.
7. **getFront** Retrieve the Front element, index 0.
8. **getRear** Retrieve the Rear element, last element inserted.
9. **isFull** Checks if the Queue is Full, returns a bool.
10. **IsEmpty** Checks if the Queue is empty, returns a bool.
11. **Display** Displays all elements of the Queue.


## QueueUsingStack (Queue folder)
Below are the operations performed on a QueueUsingStack:

-- Two Stacks used to manipulate data.

1. **Constructor**.
2. **Enqueue** Enqueues using 2 stacks to operate
3. **DeQueue** Dequeues using 2 stacks to operate



 ## Binary Tree using Stack (BinaryTree folder)
These are the basic properties of Binary Trees

Lets consider:
(*n*) as the number of nodes in the tree.
(*h*) the height of the Tree.

1. For any given Tree(*T*) with *n* nodes there is exactly  (*n-1*) edges
2. For any given Tree(*T*) with Height *h* there are at least (*h+1*) nodes, and atmost $2^{(h+1)}$ -1 nodes
3. For any given Tree(*T*) with *n* nodes the minimum heigh is -> $\log_2^{(n+1)}$ - 1 and maximum height(*h*) of -> (*n-1*)

4.**Only for Complete Binary Trees**

4.1. Let (*i*) be the position for any node(Element) in an Array then
	a node's Left-child exists at 2x*i* position and if 2x*i* > n, then no Left-child exists for that Node
4.2. A node's Right-Child exists at 2x*i*+1 position and if 2x*i*+1 > *n* then no Right-Child exists for that node.
4.3. A node's parent exists at (*i*/2) position and if *i* then no parent exists (it's the Root node)

5. At each Height the max number of Nodes(*n*) is equals to -> $2^{\text{(h))}}-1$ -->

Below are the operations performed on a Binary Tree:
-- **We are using a Stack to perform Iterative Methods**

1. **Constructor**. Constructing the BinaryTree - setting the Root as NULL
2. **newNode**. Set the Root Node and child Nodes
3. **TraverseInOrder**. We Traverse the Tree in the order: LeftSubTree->Root->RightSubTree in a Recursive Method
3.1. **IterativeTraverseInOrder**. We Traverse the Tree in the order: LeftSubTree->Root->RightSubTree but using an iterative method instead of Recursive
4. **TraversePreOrder**. We Traverse the Tree in the order: Root->LeftSubTree->RightSubTree in a Recursive Method
4.1. **IterativePreOrder**. Traverse the Tree in the order: Root->LeftSubTree->RightSubTree but using an iterative method instead of Recursive
5. **TraversePostOrder**. We Traverse the Tree in the order: LeftSubTree->RightSubTree->Root in a Recursive Method
6. **getHeight**. We print the Height of Tree, Height is also known as Depth.


## Binary Tree using Queue (BinaryTree folder)
Below are the operations performed on a Binary Tree:
-- **We are using a Queue to perform Iterative Methods**


1. **Constructor**. Constructing the BinaryTree - setting the Root as nullptr
2. **CreateTree**.
3. **TraverseInOrder**. We Traverse the Tree in the order: LeftSubTree->Root->RightSubTree in a Recursive Method
4. **TraversePreOrder**. We Traverse the Tree in the order: Root->LeftSubTree->RightSubTree in a Recursive Method
5. **TraversePostOrder**. We Traverse the Tree in the order: LeftSubTree->RightSubTree->Root in a Recursive Method
6. **TraverseLevelOrder**. We Traverse the Tree in a Level Order also known as (breadth-first traversal)
7. **getHeight**. We print the Height of Tree, Height is also known as Depth.
8. **Node Count**. Return the amount of nodes in the Tree.
9. **getRoot**. Return the Root value


## Binary Search Tree (SearchTree folder)
Below are the operations performed on a Binary Search Tree:
**A basic Dictionary approach, Insert, Delete, Search. Using a binary Tree**

1. **Constructor**. initializes Root to nullptr
2. **GetRootElement**. Getter for Root element
3. **Insert**. Function to insert a key into the tree
4. **InOrder**. Function to perform in-order traversal
5. **Search**. Function to search for a key in the tree
6. **Delete**. Function to delete a key from the tree
7. **InOrderPred**. Function to find the in-order predecessor of a node
8. **InOrderSucc**. Function to find the in-order successor of a node
9. **getHeight**. Function to get the height of the tree


## AVL Tree (AVL_Tree folder)
Below are the operations performed on the AVL Tree:
**Auto Balancing/Rotating Tree**

1. **Constructor**. initializes Root to nullptr
2. **getRoot**. Getter for Root element
3. **Insert**. Function to insert a key into the tree
4. **InOrder**. Function to perform in-order traversal
9. **getHeight**. Function to get the height of the tree
10. **LLRotation**. Left-Left Rotation function for balancing the Tree while Inserting Elements
11. **RRRotation**. Right-Right Rotation function for balancing the Tree while Inserting Elements
12. **LRRotation**. Left-Right Rotation function for balancing the Tree while Inserting Elements
13.	**RLRotation**. Right-Left Rotation function for balancing the Tree while Inserting Elements



## MaxHeap (Heap folder)

A Heap is a complete binary tree that can be a Max-Heap or Min-Heap. In a Max-Heap, each node is greater than or equal to its children, ensuring that the largest element is at the root. This structure is useful for implementing priority queues and the Heap Sort algorithm.

Below are the operations performed on a Max Binary Heap:

1. **Constructor:** Initializes the heap with a specific size and inserts the elements.
2. **Display:** Displays all elements of the heap.
3. **Insert:** Inserts an element into the heap and adjusts to maintain the heap property.
4. **DelMax:** Removes and returns the largest element from the heap (the root) and adjusts the heap structure.
5. **Adjust:** Adjusts the position of an element to maintain the heap property.
6. **Sort:** Sorts the elements of the heap using the Heap Sort algorithm.

### Usage Example
```cpp
int main() {
    try {
        MaxHeap<int> h(5); // Creates a heap with 5 elements
        cout << "\nBefore Sorting..." << endl;
        h.Display(); // Displays the elements before sorting

        cout << "\nAfter Sorting..." << endl;
        h.Sort(); // Performs heap sort
        h.Display(); // Displays the elements after sorting
    } catch (char* c) {
        cout << c; // Catches and displays exceptions
    }
    return 0;
}
```


## Heap Sort Using Heapify (Heap Folder)

### Description
The `HeapifyTechnique.cpp` class implements heap sort using the heapify technique. This technique builds the heap in a bottom-up manner, ensuring the max-heap property is maintained. The class allows for sorting an array of elements by first transforming it into a max-heap and then repeatedly extracting the maximum element.


Below are the operations performed on a Max Binary Heap using the Heapify technique:

1. **Constructor:** Initializes the heap with a specific size and inserts the elements.
2. **Display:** Displays all elements of the heap.
3. **Heapifying:** Transforms the array into a max-heap.
4. **DelMax:** Removes and returns the largest element from the heap (the root) and adjusts the heap structure.
5. **Adjust:** Adjusts the position of an element to maintain the heap property.
6. **Sort:** Sorts the elements of the heap using the Heap Sort algorithm.



## Graphs (Graph folder) GraphADT.cpp (Within Graph folder)
### Description
This class implements a graph using an adjacency matrix in C++. It provides various methods to manipulate and query the graph.

Operations on GraphADT

1. **Constructor:** Initializes the graph with a given number of vertices and edges.
2. **Destructor:** Cleans up the allocated memory for the adjacency matrix.
3. **isEmpty:** Checks if the graph is empty.
4. **NumberOfVertices:** Returns the number of vertices in the graph.
5. **NumberOfEdges:** Returns the number of edges in the graph.
6. **Degree:** Calculates the degree of a given vertex.
7. **EdgeExists:** Checks if an edge exists between two given vertices.
8. **InsertEdge:** Inserts an edge between two given vertices.
9. **DeleteEdge:** Deletes an edge between two given vertices.
10. **DisplayAdjMatrix:** Displays the adjacency matrix of the graph.


## Graph Breath First Search (GraphBFS.cpp Within Graph folder)
### Description
This class extends the graph implementation to include Breadth-First Search (BFS) using a queue in C++(located in graph folder as well).</br>
It provides methods to perform BFS traversal of the graph.

Operations on GraphBFS

1. **Constructor:** Initializes the graph with a given number of vertices and edges.
2. **Destructor:** Cleans up the allocated memory for the adjacency matrix and the visited array.
3. **isEmpty:** Checks if the graph is empty.
4. **NumberOfVertices:** Returns the number of vertices in the graph.
5. **NumberOfEdges:** Returns the number of edges in the graph.
6. **Degree:** Calculates the degree of a given vertex.
7. **EdgeExists:** Checks if an edge exists between two given vertices.
8. **InsertEdge:** Inserts an edge between two given vertices.
9. **DeleteEdge:** Deletes an edge between two given vertices.
10. **DisplayAdjMatrix:** Displays the adjacency matrix of the graph.
11. **BFS:** Performs Breadth-First Search traversal starting from a given vertex.



## Graph Depth First Search (GraphDFS.cpp Within Graph folder)
### Description
This class extends the graph implementation to include Depth-First Search (DFS) in C++ (located in the graph folder as well).</br>
It provides methods to perform DFS traversal of the graph.

Operations on GraphDFS

1. **Constructor:** Initializes the graph with a given number of vertices and edges.
2. **Destructor:** Cleans up the allocated memory for the adjacency matrix and the visited array.
3. **isEmpty:** Checks if the graph is empty.
4. **NumberOfVertices:** Returns the number of vertices in the graph.
5. **NumberOfEdges:** Returns the number of edges in the graph.
6. **Degree:** Calculates the degree of a given vertex.
7. **EdgeExists:** Checks if an edge exists between two given vertices.
8. **InsertEdge:** Inserts an edge between two given vertices.
9. **DeleteEdge:** Deletes an edge between two given vertices.
10. **DisplayAdjMatrix:** Displays the adjacency matrix of the graph.
11. **DFS:** Performs Depth-First Search traversal starting from a given vertex.









**@TODO:** - more data structures to be added 
