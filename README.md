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



**@TODO:** - more data structures to be added. 
