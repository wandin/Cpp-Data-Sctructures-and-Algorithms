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



## Bubble Sort (BubbleSort.cpp Within Sorting folder)
### Description
This program implements the Bubble Sort algorithm in C++ (located in the Sorting folder).</br>
It provides a simple method to sort an array of integers using the Bubble Sort technique.

Operations on BubbleSort

1. **Main Function:** Executes the Bubble Sort algorithm.
2. **User Input:** Prompts the user to enter the number of elements and the elements themselves.
3. **BubbleSort:** Performs Bubble Sort on the array.
4. **Output:** Displays the sorted array.

### Main Function
The main function is the entry point of the program. It performs the following steps:
- Prompts the user to enter the number of elements to be sorted.
- Prompts the user to enter the elements of the array.
- Executes the Bubble Sort algorithm to sort the array.
- Displays the sorted array.

### User Input
The program uses `cin` to take input from the user:
- The number of elements (`numOfElements`).
- The elements of the array (`a[20]`).

### BubbleSort
The Bubble Sort algorithm sorts the array in ascending order. It works by repeatedly swapping adjacent elements if they are in the wrong order:
- Outer loop iterates over the entire array.
- Inner loop compares adjacent elements and swaps them if necessary.

### Output
The program outputs the sorted array using `cout`.




## Insertion Sort (InsertionSort.cpp Within Sorting folder)
### Description
This program implements the Insertion Sort algorithm in C++ (located in the Sorting folder).</br>
It provides a method to sort an array of elements using the Insertion Sort technique.

Operations on InsertionSort

1. **Main Function:** Executes the Insertion Sort algorithm.
2. **User Input:** Prompts the user to enter the elements of the array.
3. **InsertionSort:** Performs Insertion Sort on the array.
4. **Output:** Displays the array before and after sorting.

### Main Function
The main function is the entry point of the program. It performs the following steps:
- Creates an `InsertionSort` object with a given number of elements.
- Prompts the user to enter the elements of the array.
- Displays the array before sorting.
- Executes the Insertion Sort algorithm to sort the array.
- Displays the array after sorting.

### User Input
The program uses `cin` to take input from the user:
- The elements of the array.

### InsertionSort
The Insertion Sort algorithm sorts the array in ascending order. It works by repeatedly inserting an element into the sorted part of the array:
- Reads the elements into the array.
- Inserts each element into its correct position in the sorted part of the array.
- Displays the sorted array.

### Output
The program outputs the array before and after sorting using `cout`.



## Selection Sort (SelectionSort.cpp Within Sorting folder)
### Description
This program implements the Selection Sort algorithm in C++ (located in the Sorting folder).</br>
It provides a method to sort an array of integers using the Selection Sort technique.

Operations on SelectionSort

1. **Main Function:** Executes the Selection Sort algorithm.
2. **User Input:** The array is predefined in the code.
3. **SelectionSort:** Performs Selection Sort on the array.
4. **Output:** Displays the original and sorted arrays.

### Main Function
The main function is the entry point of the program. It performs the following steps:
- Defines an array of integers to be sorted.
- Prints the original array.
- Executes the Selection Sort algorithm to sort the array.
- Prints the sorted array.

### User Input
The array to be sorted is predefined within the code. There is no user input for the array elements.

### SelectionSort
The Selection Sort algorithm sorts the array in ascending order. It works by repeatedly finding the minimum element from the unsorted part of the array and swapping it with the first unsorted element:
- Finds the minimum element in the unsorted part of the array.
- Swaps it with the first element of the unsorted part.
- Repeats the process for the remaining unsorted part of the array.

### Output
The program outputs the array before and after sorting using `cout`.


## Merge Sort (MergeSort.cpp Within Sorting folder)
### Description
This program implements the Merge Sort algorithm in C++ (located in the Sorting folder).</br>
It provides a method to sort an array of integers using the Merge Sort technique.

### Operations on Merge Sort

1. **Main Function:** Executes the Merge Sort algorithm.
2. **User Input:** The array size and elements are entered by the user.
3. **Merge Sort Functionality:** Performs Merge Sort on the array.
4. **Output:** Displays the original and sorted arrays.

### Main Function
The main function is the entry point of the program. It performs the following steps:
- Prompts the user to enter the size of the array and its elements.
- Prints the original array.
- Executes the Merge Sort algorithm to sort the array.
- Prints the sorted array.

### User Input
The user is prompted to enter:
- The size of the array.
- The elements of the array.

### Merge Sort Functionality
The Merge Sort algorithm sorts the array in ascending order by:
- Dividing the array into two halves recursively.
- Sorting each half recursively using Merge Sort.
- Merging the sorted halves to produce the sorted array.

### Output
The program outputs the array before and after sorting using `cout`.



## Quick Sort (QuickSort.cpp Within Sorting folder)

### Description
This program implements the Quick Sort algorithm in C++ (located in the Sorting folder). It provides a method to sort an array of integers using the Quick Sort technique.

### Operations on Quick Sort

1. **swap Function:** 
   - Description: Swaps two elements of type T using pointers.
   - Implementation: Defined as a template function that takes pointers to elements and swaps their values.

2. **Partition Function:** 
   - Description: Partitions the array A[] based on a pivot element.
   - Parameters: 
     - `A[]`: Array to be partitioned.
     - `low`: Lower index of the array or sub-array to be partitioned.
     - `high`: Higher index of the array or sub-array to be partitioned.
   - Returns: Index of the pivot element after partitioning.

3. **QuickSort Function:** 
   - Description: Recursively sorts the array A[] using the Quick Sort algorithm.
   - Parameters: 
     - `A[]`: Array to be sorted.
     - `low`: Starting index of the array or sub-array to be sorted.
     - `high`: Ending index of the array or sub-array to be sorted.

4. **Display Function:** 
   - Description: Displays the elements of array A[].
   - Parameters: 
     - `A[]`: Array to be displayed.
     - `n`: Number of elements in the array.

### Main Function
The main function is the entry point of the program. It performs the following steps:
- Initializes an array of integers with predefined values.
- Prints the original array before sorting.
- Executes the Quick Sort algorithm to sort the array.
- Prints the sorted array after sorting.


## Shell Sort (ShellSort.cpp Within Sorting folder)

### Description
This program implements the Shell Sort algorithm in C++ (located in the Sorting folder). It provides a method to sort an array of integers using the Shell Sort technique.

### Operations on Shell Sort

1. **ShellSort Function:** 
   - Description: Sorts the array a[] using Shell Sort with specified increments b[].
   - Parameters: 
     - `a[]`: Array to be sorted.
     - `b[]`: Array of increments for Shell Sort.
     - `d`: Number of elements in array `a[]`.
     - `x`: Number of elements in array `b[]`.

### Main Function
The main function is the entry point of the program. It performs the following steps:
- Prompts the user to enter the dimension of the array and its elements.
- Prompts the user to enter the number of increments and the increments themselves.
- Prints the original array before sorting.
- Executes the Shell Sort algorithm to sort the array.
- Prints the sorted array after sorting.


# Counting Sort (CountingSort.cpp Within Sorting Folder)

## Description
This program implements the Counting Sort algorithm in C++ (located in the Sorting folder). It provides a method to sort an array of integers using the Counting Sort technique.

## Operations on Counting Sort

### Display Function
- **Description:** Displays the elements of the array.
- **Parameters:**
    - `A[]`: Array whose elements are to be displayed.
    - `n`: Number of elements in the array `A[]`.

### GetMax Function
- **Description:** Finds the maximum value in the array.
- **Parameters:**
    - `A[]`: Array whose maximum value is to be found.
    - `n`: Number of elements in the array `A[]`.
- **Returns:** The maximum value in the array `A[]`.

### CountSort Function
- **Description:** Sorts the array `A[]` using the Counting Sort algorithm.
- **Parameters:**
    - `A[]`: Array to be sorted.
    - `n`: Number of elements in the array `A[]`.

## Main Function
The main function is the entry point of the program. It performs the following steps:
- Initializes the array `A[]` with predefined elements.
- Calculates the size of the array `A[]`.
- Prints the original array before sorting.
- Executes the Counting Sort algorithm to sort the array.
- Prints the sorted array after sorting.


# Bucket Sort (BucketSort.cpp Within Sorting Folder)

## Description
This program implements the Bucket Sort algorithm in C++ (located in the Sorting folder). It provides a method to sort an array of integers using the Bucket Sort technique.

## Operations on Bucket Sort

### Display Function
- **Description:** Displays the elements of the array.
- **Parameters:**
    - `A[]`: Array whose elements are to be displayed.
    - `n`: Number of elements in the array `A[]`.

### GetMax Function
- **Description:** Finds the maximum value in the array.
- **Parameters:**
    - `A[]`: Array whose maximum value is to be found.
    - `n`: Number of elements in the array `A[]`.
- **Returns:** The maximum value in the array `A[]`.

### Insert Function
- **Description:** Inserts a value into the bucket at the specified index.
- **Parameters:**
    - `ptrBucket`: Array of bucket pointers.
    - `index`: Index at which the value should be inserted.

### Delete Function
- **Description:** Deletes a value from the bucket at the specified index and returns the deleted value.
- **Parameters:**
    - `ptrBucket`: Array of bucket pointers.
    - `index`: Index at which the value should be deleted.
- **Returns:** The deleted value.

### BucketSort Function
- **Description:** Sorts the array `A[]` using the Bucket Sort algorithm.
- **Parameters:**
    - `A[]`: Array to be sorted.
    - `n`: Number of elements in the array `A[]`.

## Main Function
The main function is the entry point of the program. It performs the following steps:
- Initializes the array `A[]` with predefined elements.
- Calculates the size of the array `A[]`.
- Prints the original array before sorting.
- Executes the Bucket Sort algorithm to sort the array.
- Prints the sorted array after sorting.


# Radix Sort (RadixSort.cpp Within Sorting Folder)

## Description
This program implements the Radix Sort algorithm in C++ (located in the Sorting folder). It provides a method to sort an array of integers using the Radix Sort technique, primarily focusing on sorting based on decimal digits.

## Operations on Radix Sort

### GetMax Function
- **Description:** Finds the maximum value in the array.
- **Parameters:**
    - `array[]`: Array whose maximum value is to be found.
    - `n`: Number of elements in the array `array[]`.
- **Returns:** The maximum value in the array `array[]`.

### CountingSort Function
- **Description:** Sorts the array `array[]` using the Counting Sort algorithm based on the digit represented by `place`.
- **Parameters:**
    - `array[]`: Array to be sorted.
    - `size`: Number of elements in the array `array[]`.
    - `place`: Represents the digit place value (1 for units, 10 for tens, 100 for hundreds, etc.).

### RadixSort Function
- **Description:** Performs Radix Sort on the array `array[]`.
- **Parameters:**
    - `array[]`: Array to be sorted.
    - `size`: Number of elements in the array `array[]`.

### Display Function
- **Description:** Displays the elements of the array.
- **Parameters:**
    - `array[]`: Array whose elements are to be displayed.
    - `size`: Number of elements in the array `array[]`.

## Main Function
The main function is the entry point of the program. It performs the following steps:
- Initializes the array `array[]` with predefined elements.
- Calculates the size of the array `array[]`.
- Prints the original array before sorting.
- Executes the Radix Sort algorithm to sort the array based on decimal digits.
- Prints the sorted array after sorting.

## Usage
To use this program:
1. Compile the `RadixSort.cpp` file.
2. Run the executable.
3. The program will display the array before and after sorting using Radix Sort.

## Notes
- The Radix Sort implemented in this program focuses on sorting based on decimal digits (base 10). For other bases such as binary, octal, or hexadecimal, modify the `CountingSort` function by adjusting the modulus operation accordingly.



# Hashing (Hashing.cpp Within Sorting Folder)

## Description
This program implements a Hashing technique with linear probing in C++ (located in the Sorting folder). It provides methods to insert, delete, search, and display elements in a hash table using linear probing to handle collisions.

## Operations on Hashing

### HashFunction
- **Description:** Computes the hash index for a given key using the modulus operator.
- **Parameters:**
    - `k`: Key for which the hash index is to be computed.
- **Returns:** The hash index for the key `k`.

### Insert Function
- **Description:** Inserts an element into the hash table.
- **Parameters:**
    - `e`: Element to be inserted into the hash table.
- **Returns:** The current hash table object after insertion.

### Delete Function
- **Description:** Deletes an element from the hash table.
- **Parameters:**
    - `e`: Element to be deleted from the hash table.

### Search Function
- **Description:** Searches for an element in the hash table.
- **Parameters:**
    - `k`: Key to be searched in the hash table.
    - `e`: Element found at the hash index.
- **Returns:** 1 if the element is found, 0 otherwise.

### Display Function
- **Description:** Displays the elements of the hash table.
- **Parameters:**
    - None

## Main Function
The main function is the entry point of the program. It performs the following steps:
- Initializes the hash table with a given size.
- Inserts predefined elements into the hash table.
- Displays the hash table after each operation (insertion, deletion).
- Attempts to delete a non-existent element to demonstrate the handling of such cases.
- Inserts additional elements to show the process of handling collisions and the use of linear probing.
- Displays the hash table after all operations.

## Usage
To use this program:
1. Compile the `Hashing.cpp` file.
2. Run the executable.
3. The program will display the hash table after various operations such as insertion, deletion, and search.

## Notes
- This implementation uses linear probing to handle collisions. When the computed hash index is already occupied, the program linearly probes the next indices to find an empty slot.
- The hash table size is set to 11 by default, but it can be adjusted as needed. The hash function uses the modulus operator to compute the hash index.

# Hashing with Chaining (HashingChaining.cpp Within Sorting Folder)

## Description
This program implements the Hashing with Chaining technique in C++ (located in the Sorting folder). It provides a method to manage a hash table where collisions are handled using linked lists (chaining).

## Operations on Hashing with Chaining

### Node Structure
- **Description:** Represents a key-value pair in the hash table.
- **Members:**
    - `key`: The key of the node.
    - `value`: The value associated with the key.
    - `next`: Pointer to the next node in the linked list.

### HashTable Class
- **Description:** Implements a hash table using the chaining technique for collision handling.
- **Members:**
    - `table`: A vector of pointers to `Node`, representing the hash table.
    - `size`: The size of the hash table.
    - `Hash(int key)`: A private method that calculates the hash index for a given key.

### HashTable Constructor
- **Description:** Initializes the hash table with a given size.
- **Parameters:**
    - `sz`: The size of the hash table.

### HashTable Destructor
- **Description:** Cleans up the dynamically allocated memory for the hash table.

### Insert Function
- **Description:** Inserts a key-value pair into the hash table.
- **Parameters:**
    - `key`: The key to be inserted.
    - `value`: The value associated with the key.

### Search Function
- **Description:** Searches for a key in the hash table and returns its value.
- **Parameters:**
    - `key`: The key to be searched.
- **Returns:** The value associated with the key if found, otherwise returns `-1`.

### Remove Function
- **Description:** Removes a key from the hash table.
- **Parameters:**
    - `key`: The key to be removed.

### Main Function
The main function is the entry point of the program. It performs the following steps:
- Creates a hash table with a predefined size.
- Inserts some key-value pairs into the hash table.
- Searches for a key and displays its value if found.
- Removes a key from the hash table.
- Searches for the key again after removal to verify it has been deleted.
- Displays appropriate messages based on the search results.

## Usage
To use this program:
1. Compile the `HashingChaining.cpp` file.
2. Run the executable.
3. The program will insert, search, and remove keys in the hash table, displaying the results of these operations.

## Notes
- This implementation uses chaining to handle collisions in the hash table. Each index in the hash table's array points to the head of a linked list containing all key-value pairs that hash to that index.
- Ensure to delete the dynamically allocated memory in the destructor to avoid memory leaks.
