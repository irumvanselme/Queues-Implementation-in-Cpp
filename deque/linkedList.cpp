/**
 * @author IRUMVA HABUMUGISHA Anselme
 * This is the implementation of the DeQue using a Linked List
 * */


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;

    static Node *getnode(int data) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = nullptr;
        return newNode;
    }
};

class Deque {
    Node *front;
    Node *rear;
    int Size;

public:
    Deque() {
        front = rear = nullptr;
        Size = 0;
    }

    void enQueue_on_front(int data) {
        Node *newNode = Node::getnode(data);

        if (newNode == nullptr) cout << "OverFlow\n";
        else {
            if (front == nullptr) rear = front = newNode;
            else {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }

            Size++;
        }
    };

    void enQueue_on_rear(int data) {
        Node *newNode = Node::getnode(data);

        if (newNode == nullptr) cout << "OverFlow\n";
        else {
            if (rear == nullptr) front = rear = newNode;
            else {
                newNode->prev = rear;
                rear->next = newNode;
                rear = newNode;
            }
            Size++;
        }
    };

    void deQueue_on_front() {
        if (isEmpty()) cout << "UnderFlow\n";
        else {
            Node *temp = front;
            front = front->next;

            if (front == nullptr) rear = nullptr;
            else front->prev = nullptr;

            free(temp);

            Size--;
        }
    };

    void deQueue_on_rear() {
        if (isEmpty()) cout << "UnderFlow\n";
        else {
            Node *temp = rear;
            rear = rear->prev;

            if (rear == nullptr) front = nullptr;
            else rear->next = nullptr;

            free(temp);

            Size--;
        }
    };

    bool isEmpty() { return (front == nullptr); };

    void display() {
        Node *start = front;
        cout << "Elements in the Queue are here :" << endl;
        while (start != nullptr) {
            cout << start->data << endl;
            start = start->next;
        }
    }
};

int main() {
    Deque dq;
    dq.enQueue_on_rear(5);
    dq.enQueue_on_rear(10);
    dq.enQueue_on_rear(11);
    dq.enQueue_on_rear(12);
    dq.enQueue_on_rear(14);
    dq.deQueue_on_rear();
    dq.enQueue_on_front(15);
    dq.deQueue_on_front();

    dq.display();

    return 0;
}