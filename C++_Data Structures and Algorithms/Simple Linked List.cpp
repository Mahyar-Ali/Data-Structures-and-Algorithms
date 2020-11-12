#include <iostream>
using namespace std;


//Node Class
class Node {
public:
	int value;
	Node* next;
};

//List Class
class Linkedlist {

public:
	Node* head;
	//initialie the head to null
	Linkedlist() {
		head = NULL;
	}

	//Inserting values at the head
	void InsertAtHead(int newvalue) {
		//Define a new Head
		Node* new_head;
		new_head = new Node;
		new_head->value = newvalue;
		//Add the new head at the beginning.
		new_head->next = head;
		head = new_head;
	}

	void insertAtLocation(int location, int value) {
		Node* node;
		node = new Node;
		node->value = value;
		//Create a pointer to traverse through the linked list
		Node* current = head;
		if (location > 1) {
			int i = 1;
			//loop over the list until we reach at the required position
			while (i < (location - 1)) {
				current = current->next;
				i += 1;
			}
			node->next = current->next;
			current->next = node;
		}
		else {
			node->next = current;
			head = node;
		}
	}

	void _delete(int value) {
		//Create pointers to traverse through the list and to store
		//previous node in the list.
		Node* current = head;
		Node* prev = NULL;
		if (!head) {
			return; //If list is empty, do nothing
		}
		while (value != current->value && current->next) {
			prev = current;
			current = current->next;
		}
		//After the termination of the loop, we have to verify that whether 
		//the value is found in the list, or the loop just ended after traversing
		//through the whole List and didn't find the given value.

		if (current->value != value) {
			return;
		}

		if (prev) {
			prev->next = current->next;
			delete current;
		}
		//If the location is 1, there will be no previous node,
		//delete the head
		else if (!prev) {
			head = current->next;
			delete current;
		}

	}

	void displayList() {
		Node* current = head;
		while (current) {
			cout << "Node Pointer: Value = " << current->value << endl;
			current = current->next;
		}
	}

	//traverse over the list to count the number of nodes
	int countList() {
		int counter = 0;
		Node* current = head;
		while (current) {
			counter += 1;
			current = current->next;
		}
		return counter;
	}

};



int main() {
	Linkedlist linkedlist;
	linkedlist.InsertAtHead(4);
	linkedlist.InsertAtHead(5);
	linkedlist.InsertAtHead(6);

	linkedlist.insertAtLocation(4, 8);
	linkedlist._delete(4);
	linkedlist.displayList();

	int choice;
	bool quit = false;
	int temp;

	while (!quit) {
		cout << "\nCreate a Linked List" << endl;
		cout << "1. Insert Nodes at the Head" << endl;
		cout << "2. Insert Nodes at any location" << endl;
		cout << "3. Display the Linked List" << endl;
		cout << "4. Delete any Node from the List" << endl;
		cout << "5. Count the number of Nodes" << endl;
		cout << "6. Clear Screen" << endl;
		cout << "7. Quit" << endl;
		cin >> choice;
		if (choice == 6) { system("CLS"); continue; }
		if (choice == 7) break;
		switch (choice) {
		case 1:

			cout << "\nEnter an Integer Value: ";
			cin >> temp;
			linkedlist.InsertAtHead(temp);
			break;
		case 2:
			int pos;
			cout << "\nEnter the value and position: ";
			cin >> temp;
			cin >> pos;
			linkedlist.insertAtLocation(pos, temp);
			break;
		case 3:
			linkedlist.displayList();
			break;
		case 4:

			cout << "\nEnter the value of the node: ";
			cin >> temp;
			linkedlist._delete(temp);
			cout << "\n" << temp << " was deleted from the list";
			break;
		case 5:
			cout << "\nSize of linked List: " << linkedlist.countList();
			break;
		default:
			cout << "\nInvalid";
		}

	}


}
