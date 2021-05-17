/**
 * @author IRUMVA HABUMUGISHA Anselme
 * This is the implementation of the PriorityQue using an array
 * */

#include<iostream>
using namespace std;

class PriorityQueue {
    int *elements, *priorities;
    int rear, front, size;

public:
    explicit PriorityQueue(int s) {
        elements = new int[s];
        priorities = new int[s];
        size = s;
        front = -1;
        rear = -1;
    }

    void enqueue(int data, int p) {
        int i;
        if ((front == 0) && (rear == size - 1)) cout << "Overflow !";
        else {
            if (front == -1) {
                front = rear = 0;
                elements[rear] = data;
                priorities[rear] = p;
            } else if (rear == size - 1) {
                for (i = front; i <= rear; i++) {
                    elements[i - front] = elements[i];
                    priorities[i - front] = priorities[i];
                    rear = rear - front;
                    front = 0;
                    for (i = rear; i > front; i--) {
                        if (p > priorities[i]) {
                            elements[i + 1] = elements[i];
                            priorities[i + 1] = priorities[i];
                        } else break;
                        elements[i + 1] = data;
                        priorities[i + 1] = p;
                        rear++;
                    }
                }
            } else {
                for (i = rear; i >= front; i--) {
                    if (p > priorities[i]) {
                        elements[i + 1] = elements[i];
                        priorities[i + 1] = priorities[i];
                    } else break;
                }
                elements[i + 1] = data;
                priorities[i + 1] = p;
                rear++;
            }
        }
    }

    void display() {
        int i;
        cout << "Item \tPriority\n";
        for (i = rear; i >= front; i--)
            cout << elements[i] << "\t" << priorities[i] << endl;
    }

    void dequeue() {
        if (front == -1) cout << "Queue is Empty";
        else {
            if (front == rear) front = rear = -1;
            else front++;
        }
    }
};

int main() {
    PriorityQueue pq(10);
    pq.enqueue(20, 5);
    pq.enqueue(21, 6);
    pq.enqueue(41, 2);
    pq.enqueue(1, 4);
    pq.dequeue();
    pq.display();
    return 0;
}