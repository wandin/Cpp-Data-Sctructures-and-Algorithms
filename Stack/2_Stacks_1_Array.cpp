// Implementing 2 stacks using a single array. 

#include <iostream>

using namespace std;


template <class T>
class Stack
{
private:
	T *S;
	int top1;
	int top2;
	int length;
	int Size;

public:
	Stack(int);
	~Stack();
	void Push1(T);
	void Push2(T);
	void Pop1(T&);
	void Pop2(T&);
	void Display1();
	void Display2();
	T TopMost1();
	T TopMost2();
};

// Constructor
template <class T>
Stack<T>::Stack(int sz)
{
	Size = sz;
	S = new T[Size];
	top1 = -1;
	top2 = Size;
	length = 0;
}

//Destructor
template <class T>
Stack<T>::~Stack()
{
	delete [] S;
}

// Push1
template <class T>
void Stack<T>::Push1(T Element)
{
	if(top1 < top2-1)
	{
		S[++top1] = Element;
		length++;
	}
	else
	{
		cout<<"Stack #1 is FULL."<<endl;
		return;
	}
}

// Push2
template <class T>
void Stack<T>::Push2(T Element)
{
		if(top1 < top2-1)
	{
		S[--top2] = Element;
		length++;
	}
	else
	{
		cout<<"Stack #2 is FULL."<<endl;
		return;
	}
}


// Pop1
template <class T>
void Stack<T>::Pop1(T &Element)
{
	if(top1 == -1)
	{
		cout<<"Stack #1 is Empty."<<endl;
		return;
	}
	Element = S[top1];
	top1--;
	length--;
}

// Pop2
template <class T>
void Stack<T>::Pop2(T &Element)
{
	if(top2 == Size - 1)
	{
		cout<<"Stack #1 is Empty."<<endl;
		return;
	}
	Element = S[top2];
	top2++;
	length--;
}

//Display1
template <class T>
void Stack<T>::Display1()
{
	cout<<"\nStack #1 contains : "<<endl;
	for(int i = 0; i <= top1; i++)
	{
		cout<<S[i]<<" "<<endl;
	}
}

//Display2
template <class T>
void Stack<T>::Display2()
{
	cout<<"\nStack #2 contains : "<<endl;
	for(int i = Size - 1; i >= top2; i--)
	{
		cout<<S[i]<<" "<<endl;
	}
}

//TopMost1
template <class T>
T Stack<T>::TopMost1()
{
	return S[top1];
}

//TopMost2
template <class T>
T Stack<T>::TopMost2()
{
	return S[top2];
}


int main()
{
	Stack<int> stack(10);
	int x;
	
	stack.Push1(1);
	stack.Push1(2);
	stack.Push1(3);
	
	stack.Push2(40);
	stack.Push2(50);
	stack.Push2(60);
	stack.Push2(70);
	stack.Push2(80);
	stack.Push2(90);
	
	stack.Push1(4);
	
	
	stack.Display1();
    cout<<"--------------------------"<<endl;
	stack.Display2();
    cout<<"--------------------------"<<endl;


	//TopMost
    cout<<"\nTopMost element in Stack#1 is.."<<stack.TopMost1()<<endl;
    cout<<"\nTopMost element in Stack#2 is.."<<stack.TopMost2()<<endl;
    cout<<"--------------------------"<<endl;
    //End topmost

	//Pop
    stack.Pop1(x);
    cout<<"\nElement "<<x<<" from Stack#1 Deleted"<<endl;

    stack.Pop2(x);
    cout<<"\nElement "<<x<<" from Stack#2 Deleted"<<endl;
    cout<<"--------------------------"<<endl;
    //End pop
    
    	
	stack.Display1();
	stack.Display2();
	
	//TopMost
    cout<<"\nTopMost element in Stack#1 after popping is.."<<stack.TopMost1()<<endl;
    cout<<"\nTopMost element in Stack#2 after popping is.."<<stack.TopMost2()<<endl;
    cout<<"--------------------------"<<endl;
    //End topmost
	
	return 0;
}
