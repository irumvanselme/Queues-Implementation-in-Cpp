#include<iostream>
using namespace std;

template<typename T>
class Queue {
private:
    int rear, front;

    int size;
    T *arr;

public:
    void enQueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "\nOverflow !";
            return;
        } else if (front == -1) {
            front = rear = 0;
            arr[rear] = value;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = value;
        } else {
            rear++;
            arr[rear] = value;
        }
    };

    T deQueue() {
        if (front == -1) {
            cout << "\nUnderflow !";
            return INT_MIN;
        }

        T data = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1) front = 0;
        else front++;

        return data;
    };

    void displayQueue() const {
        if (front == -1) {
            cout << "\nQueue is Empty";
            return;
        }

        cout << "\nElements in Circular Queue are:" << endl;
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << endl;
        } else {
            for (int i = front; i < size; i++)
                cout << arr[i] << endl;

            for (int i = 0; i <= rear; i++)
                cout << arr[i] << endl;
        }
    };
public:
    explicit Queue(int s) {
        front = rear = -1;
        size = s;
        arr = new T[s];
    }
};