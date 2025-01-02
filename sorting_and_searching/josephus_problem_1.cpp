#include <iostream>

using namespace std;

// implementation of singly linked list. 
class Node {
    public:
    int value;
    Node* next;
};

int main() {
    int n{};
    cin >> n;

    // Idea 1: use linked list
    Node* head = new Node();
    head->value = n;
    head->next = NULL;

    // creating a linked list from 1 to n by inserting in the beginning.
    for (int i = n - 1; i >= 1; i--) {
        Node* temp = new Node();
        temp->value = i;
        temp->next = head;
        head = temp;
    }
    
    // print the children removed and update the linked list accordingly.
    Node* current = head;
    while (current->next != NULL) {

        // move one over and remember the previous node, print the current node
        // 1  2  3  4  5  6  7 
        // *->*
        Node* prev = current;
        current = current->next;
        cout << current->value << " ";

        if (current->next != NULL) {

            // if there is a node after the current, connect the previous node 
            // to it, deleting the just printed node
            // 1  x  3  4  5  6  7 
            // |_____*
            current = current->next;
            prev->next = current;

            // if the node after that is NULL, then we must return back to the
            // beginning. print the beginning node and start the process from 
            // the node after the beginning node
            // 1  x  3  x  5  x  7 
            // |_____|_____|_____*->NULL
            //
            // 1  x  3  x  5  x  7 
            // p     *<----------*
            if (current->next == NULL) {
                cout << head->value << " ";
                current = head->next;
                head = head->next;
            }
        }

        // if the next node is NULL after printing the current node, that means 
        // we must skip the beginning node and print the second node.
        // 1  2  3  4  5  6  
        // |_____|_____|  *->NULL
        else {
            prev->next = NULL;
            current = head;
        }
    } 

    // because we check if current->next == NULL, there is always the last node
    // that is not printed.
    cout << head->value;

    return 0;
}

// Ideal Solution:
    int n;
    cin >> n;
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    bool need_to_remove = false;
    while (!q.empty()) {
        int val = q.front();
        q.pop();
        if (need_to_remove) {
            cout << val << " ";
        }
        else {
            q.push(val);
        }

        need_to_remove = !need_to_remove;
    }
