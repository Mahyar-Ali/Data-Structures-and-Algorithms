/* C++ Program to Implement Circular Doubly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

/*
 * Class Declaration
 */
class DoubleCircularList
{
public:
	int counter = 0;

	/*
	 * Node Declaration
	 */
   struct node {
		int info;
		struct node* next;
		struct node* prev;
	}*start, * last;

   DoubleCircularList() {
		start = NULL;
		last = NULL;
	}

	/*
	 *CREATE NODE AND ALLOCATE MEMORY DYNAMICALLY
	 */
   node* createNode(int value) {
		struct node* temp;
		temp = new node;
		temp->info = value;
		return temp;
	}

   bool isEmpty() {
		return start == NULL && start==last;
	}
	/*
	 *INSERTS ELEMENT AT BEGINNING
	 */
   void insertAtStart() {
		int value;
		cout << endl << "Enter the element to be inserted: ";
		cin >> value;
		cout << endl;
		node* temp = createNode(value);
		//If list is empty
		if (isEmpty()) {
			start = temp;
			start->next = start;
			start->prev = start;
			last = start;
			return;
		}

		start->prev = temp;
		last->next = temp;
		temp->next = start;
		temp->prev = last;
		start = temp;
	}

	/*
	 *INSERTS ELEMNET AT LAST
	 */
   void insertLast(int value) {
		node* temp = createNode(value);

		//If list is empty, Inser the value at head
		if (isEmpty()) {
			start = temp;
			start->next = start;
			start->prev = start;
			last = start;
			return;
		}

		last->next = temp;
		start->prev = temp;
		temp->prev = last;
		temp->next = start;
		last = temp;
	}
	/*
	 *INSERTS ELEMENT AT POSITION
	 */
   void insertAtPos() {
		int value, pos;
		cout << endl << "Enter the postion of element inserted: ";
		cout << endl;
		cin >> pos;
		cout << endl;
		//If the list is empty or the position is the head
		if (isEmpty() || pos == 0) {
			//List is empty, Inserting at the head.
			cout << endl << "Inserting at the head.";
			insertAtStart();
			cout << endl;
			return;
		}

		//If position is not the head
		cout << endl << "Enter the element to be inserted: ";
		cin >> value;
		cout << endl;
		node* current = new node;
		current = start;
		int _temp = 0;
		//Traverse throug the list until we either find the location
		//or we reached the tail
		while (_temp < pos && current!=last) {
			current = current->next;      
			_temp += 1;
		}

		//If the position is the tail
		if (current == last && _temp==(pos-1) ) {
			insertLast(value);
			return;
		}
		//If we traversed through the whole list but could not
		//find the position
		else if (current == last && _temp != pos-1) {
			cout << "Location not found!" << endl;
			cout << "Appending the value at the end" << endl;
			insertLast(value);
			return;
		}

		node* temp = createNode(value);
		temp->next = current;
		temp->prev = current->prev;
		current->prev->next = temp;
		current->prev= temp;
	}
	/*
	 * Delete Node at Particular Position
	 */
   void deleteAtPos()
	{
		int pos;
		if (isEmpty())
		{
			cout <<endl<< "List is empty, nothing to delete" << endl;
			return;
		}

		cout << endl << "Enter the postion of element to be deleted: ";
		cin >> pos;

		//If position is the head
		if (pos == 0) {
			last->next = start->next;
			delete start;
			start = last->next;
			start->prev = last;		
			return;
		}

		//If position is not head
		node* current = start;
		int _temp = 0;
		//Traverse throug the list until we either find the location
		//or we reached the tail
		while (_temp < pos && current != last) {
			current = current->next;
			_temp += 1;
		}
		//If the position is the tail
		if (current == last && _temp == pos) {
			last = current->prev;
			last->next = start;
			start->prev = last;
			delete(current);
			return;
		}
		//If we traversed through the whole list but could not
		//find the position
		if (current == last && _temp != pos) {
			cout << "Position not found!" << endl;
			return;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete(current);
		cout << endl;
	}
	/*
	 * Display Elements of the List
	 */
   void display() {
		node* current = start;
		while (current && current!=last) {
			cout << endl << "Node ptr, Value--> " << current->info;
			current = current->next;
		}
		//Because we terminated the loop when the pointer reached the last
		//node, by default the last node will not be printed. So, we have
		//to print it explicitly.
		cout<< endl << "Node ptr, Value--> " << current->info;
		cout << endl;
	}
};

/*
 * Main: Contains Menu
 */
int main() {
	int userChoice;
	DoubleCircularList cdl;

	while (1) {
		cout << "\n-------------------------------" << endl;
		cout << "Operations on Doubly Circular linked list" << endl;
		cout << "\n-------------------------------" << endl;
		cout << "1.Insert at Beginning" << endl;
		cout << "2.Insert at Last" << endl;
		cout << "3.Insert at Specific Position" << endl;
		cout << "4.Delete at Specific Position" << endl;
		cout << "5.Display List" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter your choice : ";
		cin >> userChoice;
		switch (userChoice) {
		case 1:
			cdl.insertAtStart();
			break;
		case 2:
			/*I just made a small change to the insert at last funvtion
			* because we were calling this functionin in the delete and
			* insertAtLocation depending on certain condition. The original
			* implementation could have become a bit repetitive.*/
			int value;
			cout << endl << "Enter the element to be inserted: ";
			cin >> value;
			cdl.insertLast(value);
			break;
		case 3:
			cdl.insertAtPos();
			break;
		case 4:
			cdl.deleteAtPos();
			break;
		case 5:
			cdl.display();
			break;
		case 6:
			exit(1);
		default:
			cout << "Wrong choice" << endl;
		}
	}
	return 0;
}
