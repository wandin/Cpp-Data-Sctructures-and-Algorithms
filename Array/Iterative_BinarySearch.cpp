// Program to implement ITERATIVE Binary Search

#include <iostream>

using namespace std;


template<class T>
class BinarySearch
{
	
private:
		
	T *A;
	int n;
		
public:
	
	BinarySearch(int);
	int BSearch(int, int, T); // low value, high value, where to search, in this case an Array templated from T.
	
};

template<class T>
BinarySearch<T>::BinarySearch(int n)
{
	A = new T[n];
	
	cout<<"\nEnter "<<n<<" Elements in Ascending Order"<<endl;
	
	
	for(int i=0; i<n;i++)
	{
		cin>>A[i];
	}
}



template<class T>
int BinarySearch<T>::BSearch(int low, int high, T key)
{
	// Divide and Conquer!
	if(low == high)
	{
		if( key == A[low])
		{
			return high + 1; // low + 1 would work too, as  they are equal...
		}
		else
		{
			return -1;
		}
	}		
	else
	{	
		while(low <= high)
		{
			int mid = (low + high) / 2;
		
			if(key == A[mid])
			{
				return A[mid]; // return the index + 1, to give us the position, as the array starts from 0 (index 0 = 1st position); // SUCCESSFUL SEARCH
			}
			else if(key < A[mid])
			{
				high = mid - 1; // we move the high position to where the mid position was, SUBTRACTING 1, so if mid was at position five, high should be at 4, we move to the left 
			}
			else if(key > A[mid])
			{
				low = mid + 1; // we move the low position to where the mid position was, ADDING 1, so if mid was at position five, low should be at 6, we move to the right
			}
		}
		
	}
	return -1; //Unsuccessful search
}

int main()
{
	int n;
	int low = 0;
	int key;
	cout<<"Enter number of Data Elements"<<endl;
	cin>>n;
	int high = n-1;
	
	BinarySearch<int> BS(n);

	cout<<"Enter the Element to search"<<endl;
	cin>>key;

	int index = BS.BSearch(low, high, key);
	if(index == -1)
	{
		cout<<"\n NOT Found element "<<endl;

	}
	else
	{
		cout<<"\nFound element "<<key<<" at Position "<<index<<endl;

	}
	return 0;
}
