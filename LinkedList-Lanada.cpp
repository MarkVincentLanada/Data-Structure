#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* link;
};

// Function to create a new node
Node* createNode(int num) {
    Node* temp = new Node();
    temp->data = num;
    temp->link = nullptr;
    return temp;
}

// Function to insert a node
void insertAtEnd(Node*& p, int num) {
    Node* temp = createNode(num);
    if (p == nullptr) {
        p = temp; // If the list is empty, make the new node the head
        return;
    }
    Node* current = p;
    while (current->link != nullptr) {
        current = current->link; // Traverse to the last node
    }
    current->link = temp; // Link the new node at the end
}

// Function to display the linked list
void displayList(Node* p) {
    if (p == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* q = p;
    while (q != nullptr) {
        cout << q->data << " -> ";
        q = q->link;
    }
    cout << "nullptr" << endl;
}

// Function to delete a node with a specific value
void deleteNode(Node*& p, int target) {
    Node* current = p;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == target) {
            // Found the node to delete
            if (prev == nullptr) {
                // Node to delete is the first node
                p = current->link;
            } else {
                prev->link = current->link;
            }
            delete current;
            return; // Exit the function
        }
        prev = current;
        current = current->link;
    }

    cout << "Node with value " << target << " not found." << endl;
}

// Function to search for a value in the linked list and return its position
int searchNodePosition(Node* p, int target) {
    Node* current = p;
    int position = 1; // Initialize position to 1 (assuming the first node)

    while (current != nullptr) {
        if (current->data == target) {
            return position; // Found the node; return its position
        }
        current = current->link;
        position++;
    }

    return -1; // Value not found
}

// Function to reverse the linked list
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->link; // Store the next node
        current->link = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to next node
    }
    head = prev; // Update head to the new front
}

prev = 10
current = 5
current.link = null
next = 5

// Function to sort the linked list using Bubble Sort
void sortList(Node*& head) {
    if (head == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->link != nullptr) {
            if (current->data > current->link->data) {
                // Swap the data
                swap(current->data, current->link->data);
                swapped = true;
            }
            current = current->link;
        }
    } while (swapped);
}

int main() {
    Node* p = nullptr; // Initialize p to point to the first node
    int choice, num;
	
    do {
        // Display the menu
        cout << "\n--- Linked List Menu ---" << endl;
        cout << "1. Insert A Value" << endl;
        cout << "2. Count All Items In List" << endl;
        cout << "3. Display All Items In List" << endl;
        cout << "4. Remove A Value" << endl;
        cout << "5. Search A Value" << endl;
        cout << "6. Reverse The List" << endl;
        cout << "7. Sort The List" << endl;
        cout << "8. Exit Program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
		
        switch (choice) {
            case 1:
                cout << "Enter values to insert (enter -1 to stop): " << endl;
                while (true) {
                    cout << "Enter a value: ";
                    cin >> num;
                    if (num == -1) break; // Stop if user inputs -1
                    insertAtBeginning(p, num);
                }
                break;
				
            case 2:
                {
                    int count = 0;
                    Node* temp = p;
                    while (temp != nullptr) {
                        count++;
                        temp = temp->link;
                    }
                    cout << "Total number of nodes: " << count << endl;
                }
                break;
				
            case 3:
                cout << "All items in the list: ";
                displayList(p); // Call the display function
                break;
				
            case 4:
                cout << "Enter a value to remove: ";
                cin >> num;
                deleteNode(p, num);
                break;
				
            case 5:
                cout << "Enter a value to search: ";
                cin >> num;
                int position;
                position = searchNodePosition(p, num);
                if (position != -1) {
                    cout << "Value " << num << " found at position " << position << " in the linked list." << endl;
                } else {
                    cout << "Value " << num << " not found in the linked list." << endl;
                }
                break;
				
            case 6:
                reverseList(p);
                cout << "Linked list after reversal: ";
                displayList(p);
                break;
				
            case 7:
                sortList(p);
                cout << "Linked list after sorting: ";
                displayList(p);
                break;
				
            case 8:
                cout << "Exiting program." << endl;
                break;
				
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 8);
	
    return 0;
}
