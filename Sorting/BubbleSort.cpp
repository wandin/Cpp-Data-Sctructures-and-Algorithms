//Sorting Technique using Bubble Sort

#include <iostream>

using namespace std;

int main()
{
	
	int i, j, temp, numOfElements, a[20]; // i and j for loops, temp for swapping, number of elements, a[20] for the array
	
    // Prompt user for the number of elements
	cout<<"Enter the number of elements."<<endl;
	cin>>numOfElements;
	
	// Prompt user to enter the elements
	cout<<"Enter the Elements"<<endl<<endl;
	for(int i = 0; i < numOfElements; i++)
	{
		cin>>a[i];
	}
	
    // Bubble Sort algorithm
	for(i = 0; i < numOfElements; i++)			// Outer loop iterates over the entire array
	{
		for(j = i + 1; j < numOfElements; j++) 	// Inner loop compares adjacent elements
		{
			if(a[i] > a[j])						// If the current element is greater than the next element
			{
               	// Swap the elements
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
    // Output the sorted array
	cout<<"Bubble sort is: "<<endl<<endl;
	for(i = 0; i < numOfElements; i++)
	{
		cout<<a[i]<<endl;
	}
}
