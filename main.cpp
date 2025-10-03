// comsc 210 | lab17 | Christian Molina
#include <iostream>
using namespace std;

const int SIZE = 7;  

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

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

   
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
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