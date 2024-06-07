//Queue for use in GraphBreathFirstSearch.cpp


#include <iostream>
using namespace std;


template <class T>
class Queue {
    private:
        T *arr;
        int frontIndex;
        int rear;
        int size;
        int capacity;

    public:
        Queue(int capacity) {
            this->capacity = capacity;
            arr = new T[capacity];
            frontIndex = 0;
            size = 0;
            rear = capacity - 1;
        }

        ~Queue() {
            delete[] arr;
        }

        bool isEmpty() {
            return (size == 0);
        }

        bool isFull() {
            return (size == capacity);
        }

        void push(T value) {
            if (isFull()) {
                cout << "Queue is full\n";
                return;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            size++;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
            frontIndex = (frontIndex + 1) % capacity;
            size--;
        }

        T front() {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return -1;  // This assumes T is an integer type. For a generic implementation, we might handle this differently.
            }
            return arr[frontIndex];
        }
};
