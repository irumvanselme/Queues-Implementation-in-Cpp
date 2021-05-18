/**
 * @author IRUMVA HABUMUGISHA Anselme
 * This is the implementation of the Circular Que using an array
 * */


#include<iostream>
using namespace std;

struct Queue {
    int rear, front;

    int size;
    int *arr;

    explicit Queue(int s) {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value) {
        /**
         * @do this
         * Check underflow
         * */

        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "\nOverflow !";
            return;
        }
        // do this if the que is empty
        if (front == -1) front = rear = 0;

        // else do this
        else rear = (rear+1) % size;

        arr[rear] = value;
    };

    int deQueue() {
        // check underflow
        if (front == -1) {
            cout << "\nUnderflow !";
            return INT_MIN;
        }

        // store and delete the element
        int data = arr[front];
        arr[front] = -1;

        // do this if we are remainig with one element
        if (front == rear) front = rear = -1;

        // and do this in any other case
        else front = (front+1) % size ;

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
};

int main() {
    Queue q(5);

    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();

    q.displayQueue();
    return 0;
}
