// Heap - Sorting

#include <iostream>

using namespace std;

// Template class for Heap
template<class T>
class MaxHeap {
private:
    T *a; // Array to store heap elements
    int n; // Number of elements in the heap

public:
    // Constructor to initialize heap with a given size
    MaxHeap(int size);

    // Function to display the elements of the heap
    void Display();

    // Function to insert an element into the heap
    void Insert(int n);

    // Function to delete the maximum element (root) from the heap
    void DelMax(int n, T &x);

    // Function to adjust the heap to maintain the heap property
    void Adjust(int i, int n);

    // Function to perform heap sort
    void Sort();
};

// Constructor definition
template<class T>
MaxHeap<T>::MaxHeap(int size) {
    if (size < 0) {
        throw "size must be greater than zero";
    }
    n = size;
    a = new T[n + 1]; // Allocate array with size n+1
    for (int i = 1; i <= n; i++) {
        cout << "\nEnter the element " << i << "\n";
        cin >> a[i];
    }
}

// Display function definition
template<class T>
void MaxHeap<T>::Display() {
    cout << "\nThe Array elements are: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

// Insert function definition
template<class T>
void MaxHeap<T>::Insert(int n) {
    int i = n;
    T item = a[n];
    // Traverse up and fix the heap property
    while ((i > 1) && (a[i / 2] < item)) {
        a[i] = a[i / 2]; // Move parent down
        i = i / 2; // Move up to the parent
    }
    a[i] = item; // Place the new item in the correct position
}

// Delete maximum element function definition
template<class T>
void MaxHeap<T>::DelMax(int n, T &x) {
    if (n == 0) {
        cout << "Heap is empty!" << endl;
    } else {
        x = a[1]; // Store the maximum element
        a[1] = a[n]; // Replace the root with the last element
        Adjust(1, n - 1); // Adjust the heap
    }
}

// Adjust function definition
template<class T>
void MaxHeap<T>::Adjust(int i, int n) {
    int j = 2 * i; // Left child index
    T item = a[i]; // Store the item to be adjusted

    while (j <= n) {
        if ((j < n) && (a[j] < a[j + 1])) {
            j = j + 1; // Right child is larger
        }
        if (item >= a[j]) break; // If item is larger, break
        a[j / 2] = a[j]; // Move child up
        j = 2 * j; // Move to the next level
    }
    a[j / 2] = item; // Place the item in the correct position
}

// Sort function definition
template<class T>
void MaxHeap<T>::Sort() {
    T x;
    // Build the heap
    for (int i = 1; i <= n; i++) {
        Insert(i);
    }
    // Perform heap sort
    for (int i = n; i >= 1; i--) {
        DelMax(i, x); // Delete the maximum element
        cout << "\nSort, value of x is: " << x << endl;
        a[i] = x; // Place it at the end of the array
    }
}

// Main function
int main() {
    try {
        MaxHeap<int> h(5); // Create a heap with 5 elements
        cout << "\nBefore Sorting..." << endl;
        h.Display(); // Display elements before sorting

        cout << "\nAfter Sorting..." << endl;
        h.Sort(); // Perform heap sort
        h.Display(); // Display elements after sorting
    } catch (char* c) {
        cout << c; // Catch and display exceptions
    }
    return 0;
}

