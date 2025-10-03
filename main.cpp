// comsc 210 | lab17 | Christian Molina
#include <iostream>
using namespace std;

const int SIZE = 7;  
// I gotta say i dont really understand the purpose of this project
// but I guess its good practice for linked lists
struct Node {
    float value;
    Node *next;
};

void output(Node *head);// prototype
void addFront(Node * &head, float val);
void addTail(Node * &head, float val);

void deleteNode(Node * &head, int position);
void insertNode(Node * &head, int position, float val);
void deleteList(Node * &head);

int main() {
    Node *head = nullptr;
    
    // adding nodes to the linked list
    for (int i = 0; i < SIZE; i++){
        addFront(head, rand() % 100);
    }

    cout << "Initial list:" << endl;
    output(head);

    // deleting a node
    int entry;
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry);
    cout << "After deletion:" << endl;
    output(head);

    // insert node after a chosen node...
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    cout << "After insertion:" << endl;
    output(head);

    //add a node to the tail
    addTail(head, 9999);
    cout << "After adding 9999 to the tail:" << endl;
    output(head);

    //Lastly delete the entire list
    deleteList(head);
    cout << "After deleting the entire list:" << endl;
    output(head);

    

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addFront(Node * &hd, float val) {
    Node * newNode = new Node;
    newNode->value = val;
    newNode->next = hd;
    hd = newNode;
}

void addTail(Node * &hd, float val) {
    Node * newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    if (!hd) { // if the list were to be empty
        hd = newNode;
        return;
    }

    Node * current = hd;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

//for inserting a node at a given position
void insertNode(Node * &hd, int position, float val) {
    if (position < 0) {
        cout << "Invalid position.\n";
        return;
    }
    Node *current = hd;
    Node *previous = nullptr;
    for (int i = 0; i < position && current; ++i) {
        previous = current;
        current = current->next;
    }
    Node *newNode = new Node;
    newNode->value = val;
    newNode->next = current;
    if (previous) {
        previous->next = newNode;
    } else {
        hd = newNode; // inserting at the head
    }
}

//for deleting a node at a given position

void deleteNode(Node * &hd, int position) {
    if (!hd || position < 1) {
        cout << "Invalid position or empty list.\n";
        return;
    }
    Node * current = hd;
    Node * previous = nullptr;
    for (int i = 1; i < position && current; i++) {
        previous = current;
        current = current->next;
    }
    if (!current) return; // position out of bounds
    if (!previous) { // deleting the head
        hd = current->next;
    } else {
        previous->next = current->next;
    }
    delete current;

}

void deleteList(Node * &hd) {
    Node * current = hd;
    while (current) {
        Node * temp = current;
        current = current->next;
        delete temp;
    }
    hd = nullptr;
}