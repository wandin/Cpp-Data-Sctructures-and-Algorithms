// Heap using Heapify technique
#include <iostream>
using namespace std;

// Template class for Heap
template<class T>
class Heap {
private:
    T *a; // Array to store heap elements
    int n; // Number of elements in the heap

public:
    // Constructor to initialize heap with a given size
    Heap(int size);

    // Function to display the elements of the heap
    void Display();

    // Function to heapify the array
    void Heapfy(int n);

    // Function to delete the maximum element (root) from the heap
    void DelMax(int n, T &x);

    // Function to adjust the heap to maintain the heap property
    void Adjust(int i, int n);

    // Function to perform heap sort
    void HeapSort();

    // Destructor to deallocate the heap array
    ~Heap() { delete [] a; }
};

// Constructor definition
template<class T>
Heap<T>::Heap(int size) {
    if (size < 0) {
        throw "size must be greater than zero";
    }
    n = size;
    a = new T[n + 1]; // Allocate array with size n+1
    for (int i = 1; i <= n; i++) {
        cout << "Enter an element: " << i << endl;
        cin >> a[i];
    }
}

// Display function definition
template<class T>
void Heap<T>::Display() {
    cout << "The array elements are: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Heapify function definition
template<class T>
void Heap<T>::Heapfy(int n) {
    for (int i = n / 2; i >= 1; i--) {
        Adjust(i, n);
    }
}

// Delete maximum element function definition
template<class T>
void Heap<T>::DelMax(int n, T &x) {
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
void Heap<T>::Adjust(int i, int n) {
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

// Heap sort function definition
template<class T>
void Heap<T>::HeapSort() {
    T x;
    Heapfy(n); // Build the heap
    for (int i = n; i >= 1; i--) {
        DelMax(i, x); // Delete the maximum element
        a[i] = x; // Place it at the end of the array
    }
}

// Main function
int main() {
    try {
        Heap<int> h(8); // Create a heap with 8 elements
        cout << "\n Before Sorting..." << endl;
        h.Display(); // Display elements before sorting

        h.HeapSort(); // Perform heap sort
        cout << "\n After Sorting..." << endl;
        h.Display(); // Display elements after sorting
    } catch (char* c) {
        cout << c; // Catch and display exceptions
    }
    return 0;
}

