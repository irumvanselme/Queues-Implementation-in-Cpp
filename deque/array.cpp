/**
 * @author IRUMVA HABUMUGISHA Anselme
 * This is the implementation of the DeQue using an array
 * */


#include<iostream>
using namespace std;

class Deque {
    int *a, front, rear, size;
public:
    explicit Deque(int s) {
        front = -1;
        rear = -1;
        size = s;
        a = new int[s];
    };

    void enQueueAtFront(int item) {
        if (front == -1) {
            front = 0;
            a[++rear] = item;
        } else if (front != 0) a[--front] = item;
        else {
            cout << "Overflow!!!" << endl;
        }
    };

    void enQueueOnRear(int item) {
        if (rear >= size - 1) {
            cout << "Overflow!!!!" << endl;
        } else {
            if (front == -1) {
                front++;
                rear++;
            } else {
                rear = rear + 1;
            }
            a[rear] = item;
        }
    };

    void deQueueOnFront() {
        if (front == -1) {
            cout << "Underflow !" << endl;
            return;
        } else {
            if (front == rear) {
                front = rear = -1;
                return;
            } else
                front = front + 1;
        }
    };

    void deQueueOnRear() {
        if (front == -1) {
            cout << "Underflow !" << endl;
            return;
        } else {
            if (front == rear) {
                front = rear = -1;
            } else
                rear = rear - 1;
        }
    };

    void display() {
        cout << "Elements in the Queue are here :" << endl;
        if (front == -1) {
            cout << "Dequeue is empty" << endl;
        } else {
            for (int i = front; i <= rear; i++) {
                cout << a[i] << endl;
            }
        }
    };
};

int main() {
    Deque d1(10);
    d1.enQueueAtFront(10);
    d1.enQueueOnRear(20);
    d1.enQueueOnRear(21);
    d1.enQueueOnRear(22);
    d1.enQueueOnRear(23);
    d1.deQueueOnRear();
    d1.deQueueOnFront();

    d1.display();
}