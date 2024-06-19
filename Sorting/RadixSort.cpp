// Sorting technique using Radix Sort or Base Sort (Decimal - Base 10)
// For Binary (Base 2) use % 2, Octal (Base 8) use % 8, Hexadecimal (Base 16) use % 16

#include <iostream>

using namespace std;

// Function to get the maximum value in the array
int GetMax(int array[], int n)
{
    int m = array[0]; // Initialize the maximum value with the first element
    for (int i = 1; i < n; i++)
    {
        if (array[i] > m)
        {
            m = array[i]; // Update max if the current element is greater
        }
    }
    return m;
}

// Function to perform Counting Sort based on the digit represented by 'place'
void CountingSort(int array[], int size, int place)
{
    const int max = 10; // Since we are dealing with decimal numbers (0-9)
    int output[size];   // Output array to store sorted elements
    int Count[max];     // Array to store count of occurrences of digits

    // Initialize count array to 0
    for (int i = 0; i < max; i++)
    {
        Count[i] = 0;
    }

    // Store the count of occurrences of each digit
    for (int i = 0; i < size; i++)
    {
        Count[(array[i] / place) % 10]++;
    }

    // Change Count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < max; i++)
    {
        Count[i] += Count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[Count[(array[i] / place) % 10] - 1] = array[i];
        Count[(array[i] / place) % 10]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

// Function to perform Radix Sort on the array
void RadixSort(int array[], int size)
{
    int max = GetMax(array, size); // Get the maximum value in the array

    // Apply counting sort to sort elements based on place value.
    // Start with least significant digit and move towards most significant digit
    for (int place = 1; max / place > 0; place *= 10)
    {
        CountingSort(array, size, place);
    }
}

// Function to display the elements of the array
void Display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " "; // Print each element followed by a space
    }
    cout << endl;
}

int main()
{
    int array[] = {562, 62, 135, 0, 2, 1, 7, 56, 24}; // Initialize the array to be sorted
    int size = sizeof(array) / sizeof(array[0]);      // Calculate the size of the array

    cout << "\nBefore Sorting..." << endl;
    Display(array, size); // Display the array before sorting

    cout << "\nAfter Sorting..." << endl;
    RadixSort(array, size); // Sort the array using Radix Sort
    Display(array, size);   // Display the array after sorting

    return 0; // Return 0 to indicate successful execution
}
