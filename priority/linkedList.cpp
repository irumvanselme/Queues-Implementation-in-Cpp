/**
 * @author IRUMVA HABUMUGISHA Anselme
 * This is the implementation of the PriorityQue using a Linked list
 * */


#include <iostream>
using namespace std;

struct Node {
    int priority;
    int data;
    struct Node *next;
};

class Priority_Queue {
private:
    Node *front;

public:
    Priority_Queue() {
        front = nullptr;
    }

    void enQueue(int item, int priority) {
        Node *t, *q;
        t = new Node;
        t->data = item;
        t->priority = priority;
        if (front == nullptr || priority < front->priority) {
            t->next = front;
            front = t;
        } else {
            q = front;
            while (q->next != nullptr && q->next->priority <= priority)
                q = q->next;
            t->next = q->next;
            q->next = t;
        }
    }

    void deQueue() {
        Node *t;
        if (front == nullptr)
            cout << "Queue Underflow\n";
        else {
            t = front;
            cout << "Deleted item is: " << t->data << endl;
            front = front->next;
            free(t);
        }
    }

    void display() {
        Node *ptr;
        ptr = front;
        if (front == nullptr) cout << "Queue is empty\n";
        else {
            cout << "\n\nQueue is :\n";
            cout << "Item\tPriority\n";
            while (ptr != nullptr) {
                cout << ptr->data << "\t" << ptr->priority << endl;
                ptr = ptr->next;
            }
            cout << endl << endl;
        }
    }
};

int main() {
    Priority_Queue pq;
    pq.enQueue(10, 3);
    pq.enQueue(11, 2);
    pq.enQueue(16, 1);
    pq.enQueue(26, 5);
    pq.enQueue(61, 4);
    pq.deQueue();
    pq.display();

    return 0;
}