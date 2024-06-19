#include <iostream>

using namespace std;

// Function to display the elements of the array
void Display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

// Function to get the maximum value in the array
int GetMax(int A[], int n)
{
    int m = -32768; // Initialize to a very small number (16-bit signed integer minimum value)
    for (int i = 0; i < n; i++)
    {
        if (A[i] > m)
        {
            m = A[i]; // Update max if the current element is greater
        }
    }
    return m;
}

// Function to perform Counting Sort on the array
void CountSort(int A[], int n)
{
    // Get the maximum value in the array to determine the range of the Count array
    int Max = GetMax(A, n);
    
    // Create a Count array of size Max + 1 and initialize all elements to 0
    int Count[Max + 1];
    for (int i = 0; i < Max + 1; i++)
    {
        Count[i] = 0;
    }
    
    // Count the occurrences of each element in the array
    for (int i = 0; i < n; i++)
    {
        Count[A[i]]++;
    }
    
    // Reconstruct the sorted array using the Count array
    for (int i = 0, j = 0; j < Max + 1;)
    {
        if (Count[j] > 0)
        {
            A[i++] = j; // Place the element in the original array
            Count[j]--; // Decrease the count for this element
        }
        else
        {
            j++; // Move to the next element in the Count array
        }
    }
}

int main()
{
    // Initialize the array to be sorted
    int A[] = {32, 15, 4, 2, 5, 9, 8, 10};
    int size = sizeof(A) / sizeof(A[0]); // Calculate the size of the array
    
    cout << "\nDisplaying before sort" << endl;
    Display(A, size); // Display the array before sorting
    
    cout << "\n\nDisplaying after sort" << endl;
    
    CountSort(A, size); // Sort the array using Counting Sort
    Display(A, size); // Display the array after sorting
    
    return 0; // Return 0 to indicate successful execution
}

