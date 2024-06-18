// Sorting Technique using Shell Sorting

#include <iostream>

using namespace std;

// Function to perform Shell Sort on array a[] with specified increments b[]
void ShellSort(int a[], int b[], int d, int x)
{
	int j, k, l, y, span;
	for (j = 0; j < x; j++)
	{
		span = b[j]; // Set the span (increment) for this iteration
		for (k = span; k < d; k++)
		{
			y = a[k]; // Store the current element to be inserted in its correct position
			// Insertion sort using the current span
			for (l = k - span; l >= 0 && y < a[l]; l -= span)
			{
				a[l + span] = a[l]; // Shift elements to the right within the span
			}
			a[l + span] = y; // Place the stored element in its correct position
		}
	}

	// Output the sorted array
	cout << "\n After Sorting Array is: " << endl;
	for (j = 0; j < d; j++)
	{
		cout << a[j] << "\t"; // Print each element of the sorted array
	}
	cout << endl;
}

// Main function to take user input and initiate Shell Sort
int main()
{
	int i, dim, x, a[20], b[5];

	// Input the dimension of the array
	cout << " \n Enter Dimension For Array : ";
	cin >> dim;

	// Input the elements of the array
	cout << " \n Enter " << dim << " Values For Array : ";
	for (i = 0; i < dim; i++)
	{
		cin >> a[i];
	}

	// Input the number of increments
	cout << " \n Enter Number Of Increments : ";
	cin >> x;

	// Input the increments
	cout << " \n Enter Increments Last 1 : ";
	for (i = 0; i < x; i++)
	{
		cin >> b[i];
	}

	// Display the entered values of the array
	cout << " \n Entered Values Of Array Are : " << endl;
	for (i = 0; i < dim; i++)
	{
		cout << a[i] << "\t";
	}

	// Display the increments
	cout << " \n Increments Are : " << endl;
	for (i = 0; i < x; i++)
	{
		cout << b[i] << "\t";
	}

	// Call the ShellSort function to sort the array with specified increments
	ShellSort(a, b, dim, x);

	return 0;
}

