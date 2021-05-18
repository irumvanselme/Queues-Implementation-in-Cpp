/**
 * @author IRUMVA HABUMUGISHA Anselme
 * This is the implementation of the Circular Que using a Linked List
 * */


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class CircularQueue {
    Node *front = nullptr;
    Node *rear = nullptr;

public:
    void enQueue(int data) {
        Node *temp = new Node;
        temp->data = data;
        if (front == nullptr && rear == nullptr) front = rear = temp;
        else rear->next = temp;

        rear = temp;
        rear->next = front;
    }

    void deQueue() {
        if (front == nullptr) {
            cout << "Que is empty ";
        } else if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    void display() {
        cout << "Elements of the Queue is :" << endl;
        Node *temp = front;
        while (temp->next != front) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};

int main() {
    CircularQueue queue;
    queue.enQueue(10);
    queue.enQueue(101);
    queue.enQueue(15);
    queue.enQueue(24);
    queue.deQueue();

    queue.display();
    return 0;
}
