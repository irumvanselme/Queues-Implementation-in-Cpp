#include "Queue.h"

struct Student{
    string name;
    string gender;
};

int main (){
    Queue<Student> peopleWaitingToBeShaved(100);
    cout << "==== Welcome to the system of shaving ====" << endl;
    cout << "\t1. A new customer came" << endl;
    cout << "\t2. A new customer sits on the chair" << endl;
    cout << "\t3. The list of customers in the Queue" << endl;
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << ""
            break;
        case 2:
            break;
        case 3:
            peopleWaitingToBeShaved.displayQueue();
            break;
        default:
            return 0;
            break;
    }

    return 0;
}

