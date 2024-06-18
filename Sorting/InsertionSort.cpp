// Sorting technique using Insertion Sort

#include <iostream>

using namespace std;

// Template class for Insertion Sort
template<class T>
class InsertionSort
{
private:
    T *array;  // Pointer to the array
    int n;     // Number of elements in the array
    
public:
    // Constructor to initialize the array with the given size
    InsertionSort(int c)
    {
        if (c < 1)
        {
            throw "invalid size input...";  // Throw an error if size is less than 1
        }
        n = c;
        array = new T[n + 1];  				// Allocate memory for the array
    }
    
    // Method to read elements into the array
    void ReadArray()
    {
        cout << "\nEnter the elements into the array:" << endl;
        for (int i = 1; i <= n; i++)
        {
            cin >> array[i];  // Read each element from the user
        }
    }
    
    // Method to insert an element into the sorted part of the array
    void Insert(T e, int i)
    {
        array[0] = e;  					// Sentinel value to stop the while loop
        while (e < array[i])  			// While the element to insert is less than the current element
        {
            array[i + 1] = array[i];  	// Shift the current element one position to the right
            i--;
        }
        array[i + 1] = e;  				// Insert the element in the correct position
    }
    
    // Method to perform Insertion Sort
    void ISort()
    {
        for (int j = 2; j <= n; j++)  	// Iterate through the array starting from the second element
        {
            T temp = array[j];  		// Store the current element
            Insert(temp, j - 1);  		// Insert it into the sorted part of the array
        }
    }
    
    // Method to display the array
    void Display()
    {
        for (int i = 1; i <= n; i++)  	// Iterate through the array
        {
            cout << array[i] << " ";  	// Print each element
        }
        cout << endl;  					// Print a new line at the end
    }
};

int main()
{
    try
    {
        // Create an InsertionSort object with 5 elements
        InsertionSort<int> i(5);
        i.ReadArray();  								// Read the array elements from the user
        cout << "\nArray Before Sorting is:" << endl;
        i.Display();  									// Display the array before sorting
        i.ISort();  									// Sort the array using Insertion Sort
        cout << "\nArray After Sorting is:" << endl;
        i.Display();  									// Display the array after sorting
    }
    catch (char *c)
    {
        cout << c << endl;  // Catch and display any errors
    }
    return 0;  // Return 0 to indicate successful execution
}

