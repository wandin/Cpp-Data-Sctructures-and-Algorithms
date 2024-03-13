#include<iostream>

using namespace std;

class IllegalParamvalue
{
	// CLASS FOR THROWING AN ERROR MESSAGE IF WE WILL
	private:
		string message;
		public:
			IllegalParamvalue(string msg)
			{
				message = msg;
			}
			void outputMessage()
			{
				cout<<message<<endl;
			}
};

template<class T>
class ArrayADT
{
    private:
        T *A;
        int Capacity;
        int Size;
    public:
        ArrayADT(int initCap);			// CONSTRUCTOR
        ~ArrayADT();					// DESTRUCTOR
        void Insert(int pos,T elem);	// insert element at given position.
        void Delete(int pos,T& elem); 	// Delete element at given position
        bool Find(int pos,T& elem);		// Find an element in a given position
        int Search(T);					// Search for a given element in the Array
        int Length();					// Return the Size of the Array
        void Display();					// Display All values in the array (VALUES, NOT INDEX)
        bool IsEmpty();					// return if Array is empty
        bool IsFull();					// return if Array is full 
        T Get(int index);				// Get the value at current index
        void Set(int index,T);			// Set the value of the given index
        int indexOf(T);					// get index of current value - or return -1 if not finding element
        
        T FindMax();					// Find largest value
        T FindMin();  					// Find smallest value
        T SumOfArray(); 				// Sum all elements in array
        T Avg(); 						// Average value of array = SumofArray / Size of array
        void Append(T); 				// Append
        
        void LeftRotate_1x();			// Left Rotate 1x
        void LeftRotate(int k);			// Left Rotate N Times (input K)
        
		void RightRotate_1x();			// Right Rotate 1x
        void RightRotate(int k);		// Right Rotate N Times (input K)
        
        
        void Reverse();					// Reversing the order of elements in Array


};


template<class T>
ArrayADT<T>::ArrayADT(int initCap) 						// CONSTRUCTOR
{
    if(initCap < 1)
        throw IllegalParamvalue("Capacity cannot be Negative...");

    Capacity = initCap;
    Size = 0;
    A = new T [ Capacity];
    cout<<"Array got Created successfully ....."<<endl<<endl;
}

template<class T>
ArrayADT<T>::~ArrayADT() 								// DECONSTRUCTOR
{
    delete [] A;
    cout<<"Memory released by Destructor...."<<endl<<endl;
}

template<class T>
void ArrayADT<T>::Insert(int pos, T Element)
{
    if(pos < 1 || pos > Size+1)
        throw IllegalParamvalue("Invalid Position....");

    for(int i=Size-1; i>=pos-1;i--)
        A[i+1] = A[i];
    A[pos-1] = Element;
    Size++;

}
template<class T>
void ArrayADT<T>::Delete(int pos, T& Element)
{
   if(pos < 1 || pos > Size)
    throw IllegalParamvalue("Invalid Position to Delete the Element...");
    
   Element = A[pos - 1];
   for(int i=pos; i<Size;i++)
        A[i-1]=A[i];
   Size--;
}

template<class T>
bool ArrayADT<T>::Find(int pos, T& Element)
{
	if(pos < 1 || pos > Size)
	{
		return false;
		//throw IllegalParamvalue("Invalid Position to Find the Element...");
	}
    
    Element = A[pos -1];
    return true;
}

template<class T>
int ArrayADT<T>::Search(T Element)
{
	for(int i=0;i<Size;i++)
	{
		if(Element == A[i])
		{
			return i+1; // Successful search, returning the index +1, as we start counting from index 0.
		}
	}
	return -1;
}

template<class T>
int ArrayADT<T>::Length()
{
    return Size;
}

template<class T>
bool ArrayADT<T>::IsEmpty()
{
	if(Size == 0)
	{
		return true;
	}
	return false;
}

template<class T>
bool ArrayADT<T>::IsFull()
{
	if(Capacity == Size)
	{
		return true;
	}
	return false;
}

template<class T>
void ArrayADT<T>::Display()
{

    for(int i=0;i<Size;i++)
        cout<<A[i]<<" ";
}

template<class T>
T ArrayADT<T>::Get(int index)
{
	if(index < 0 or index > Size-1)
	{
		cout<<" Invalid Index"<<endl;
	}
	int result = A[index];
	return result;
}

template<class T>
void ArrayADT<T>::Set(int index,T element)
{
	if(index < 0 or index > Size-1)
	{
		cout<<" Invalid Index"<<endl;
	}
	A[index] = element;
}

template<class T>
int ArrayADT<T>::indexOf(T element)
{
	for (int i=0; i<Size-1;i++)
	{
		if(element == A[i])
		{
			int indexofelement = i;
			return indexofelement;
		}
	}
	return -1;
}

template<class T>
T ArrayADT<T>::FindMax()
{
	int MAX = 0;
	for(int i=0;i<Size-1;i++)
	{
		if(A[i] > MAX)
		{
			MAX = A[i];
		}
	}
	return MAX;
}

template<class T>
T ArrayADT<T>::FindMin()
{
	int MIN = A[0];
	for(int i=0;i<Size-1;i++)
	{
		if(A[i] < MIN)
		{
			MIN = A[i];
		}
	}
	return MIN;
}

template<class T>
T ArrayADT<T>::SumOfArray()
{
	T sum = 0;
	for(int i=0;i<Size;i++)
	{
		sum += A[i];
	}
	return sum;
}


template<class T>
T ArrayADT<T>::Avg()
{
	T sum = 0;
	T Average = 0;
	for(int i=0;i<Size;i++)
	{
		sum += A[i];
		Average = sum / Size;
	}
	return Average;
}

template<class T>
void ArrayADT<T>::Append(T Element)
{
	A[Size] = Element;
	Size++;
}



template<class T>
void ArrayADT<T>::LeftRotate_1x()
{
	int temp = A[0];
	for (int i = 0; i < Size-1; i++)
	{
		// <---------- Rotating to the left 
		A[i] = A[i+1];
	}
	A[Size-1] = temp;
}

template<class T>
void ArrayADT<T>::LeftRotate(int k)
{
	for (int i = 0; i < k; i++)
	{
		LeftRotate_1x();
	}
}

template<class T>
void ArrayADT<T>::RightRotate_1x()
{
	int temp = A[Size-1];
	for (int i = Size-1; i > 0; i--)
	{
		//  Rotating to the Right --------->
		A[i] = A[i-1];
	}
	A[0] = temp;
}

template<class T>
void ArrayADT<T>::RightRotate(int k)
{
	for (int i = Size-1; i > k; i--)
	{
		RightRotate_1x();
	}
}


template<class T>
void ArrayADT<T>::Reverse()
{
	int temp = A[0];
	for (int i=0, j=Size-1;i<=j; i++, j--)
	{
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}

int main()
{
		
  // Creating an object of the ArrayADT class with an initial capacity of 10 elements
    ArrayADT<int> a(10);
    int x, data;

    /* Inserting into Array */
    a.Insert(1, 10);    // Inserting value 10 at position 1
    a.Insert(2, 20);    // Inserting value 20 at position 2
    a.Insert(1, 30);    // Inserting value 30 at position 1
    a.Insert(1, 40);    // Inserting value 40 at position 1
    a.Insert(1, 50);    // Inserting value 50 at position 1
    a.Insert(3, 60);    // Inserting value 60 at position 3

    cout << "Array after insertion: ";
    a.Display();        // Displaying the array elements

    // Finding and displaying the maximum and minimum in the array
    cout << "Maximum Element is: " << a.FindMax() << endl;
    cout << "Minimum Element is: " << a.FindMin() << endl;

    // Calculating and displaying the sum and average of elements in the array
    cout << "Sum of Elements is: " << a.SumOfArray() << endl;
    cout << "Average value is: " << a.Avg() << endl;

    // Appending value 200 to the end of the array
    a.Append(200);

    cout << "\nArray after appending 200: ";
    a.Display();

    // Reversing the order of elements in the array
    cout << "\nReversed Array: ";
    a.Reverse();
    a.Display();

    // Performing a left rotation
    cout << "\nArray after left rotation: ";
    a.LeftRotate(2);
    a.Display();

    // Performing a right rotation
    cout << "\nArray after right rotation: ";
    a.RightRotate(2);
    a.Display();

    // Finding an element at position 3
    int pos = 3;
    if (a.Find(pos, x))
    {
        cout << "\nElement at position " << pos << " is: " << x << endl;
    }
    else
    {
        cout << "\nElement not found at position " << pos << endl;
    }

    // Searching for the position of element 60
    cout << "Position of element 60 is: " << a.Search(60) << endl;

    // Getting the length of the array
    cout << "Length of array: " << a.Length() << endl;

    // Checking if the array is empty
    if (a.IsEmpty())
    {
        cout << "The array is empty!" << endl;
    }
    else
    {
        cout << "The array is not empty!" << endl;
    }

    // Checking if the array is full
    if (a.IsFull())
    {
        cout << "The array is full!" << endl;
    }
    else
    {
        cout << "The array is not full!" << endl;
    }

    return 0;
       
}
