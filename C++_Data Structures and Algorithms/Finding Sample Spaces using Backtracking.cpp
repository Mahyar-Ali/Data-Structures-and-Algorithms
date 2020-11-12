1/*
 Program to list all possible tuples of the sample
 space formed with replacement and without replacement
 using both conditions i.e., when order matters and when
 order doesn't matter.
 */
/*
- Linked List
- Maps
- Recursion
- Backtracking
*/

#include<map>
#include <iostream>
using namespace std;


//Node Class
class Node {
public:
	string value;
	Node* next;
};

//List Class
class Linkedlist {

public:
	Node* head;
	Node* tail;
	//initialie the head to null
	Linkedlist() {
		head = NULL;
	}

	//Inserting values at the head
	void InsertAtHead(string newvalue) {
		//Define a new Head
		Node* new_;
		new_ = new Node;
		new_->value = newvalue;
		if (!head) {
			head = new_;
			tail = new_;
			return;
		}
		tail->next = new_;
		tail = new_;
		new_->next = NULL;
	}

	void displayList() {
		Node* current = head;
		cout << "{ ";
		while (current) {
			cout << current->value << ", ";
			current = current->next;
		}
		cout << "}";
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

//Sample Space for s with replacement
void _mul(string s, int r, string pat, Linkedlist* list) {
	if (r == 0) {
		list->InsertAtHead(pat);
		return;
	}
	for (int i = 0; i < size(s); i++) {
		pat += s[i];
		cout << pat<<endl;
		_mul(s.substr(0, size(s)), r - 1, pat, list);
		pat = pat.substr(0, size(pat) - 1);
	}
}

//Sample Space for s without replacement and order matters
string per(string s,int r, string perm,Linkedlist* list) {

	if (size(perm) == r) {
		list->InsertAtHead(perm);
		return "	";
	}
	else {
		for (int i = 0; i < size(s); i++) {
			char temp = s[0];
			s[0] = s[i];
			s[i] = temp;
			perm = perm + string(1, s[0]);
			per(s.substr(1, size(s)), r, perm, list);
			perm = perm.substr(0,size(perm)-1);
			s[i] = s[0];
			s[0] = temp;
		}

		return "";
	}
}

//Sample space for s withour replacement and order doesn't matter
void order_n(string PERM, Linkedlist* list) {
	//PERM: ABCD in this case
	//list: pointer to the linked list in which permutations are stored
	map<char, int> dict = {{'A',0},{'B',1},{'C',2}, {'D',3},{'E',4},
							{'F',5},{'G',6} };
	map<int, string> comb;
	string perm = "";
	Node* current = list->head;
	while (current) {
		 perm = current->value;
		 current = current->next;
		 for (char i : perm) {
			 sum += dict[i];
		 }
		 if (comb.find(sum) == comb.end()){
			comb.insert(pair<int,string>(sum,perm));
			cout << perm << endl;
		 }
	}
}

int fact(int n) {
	if (n == 0)
		return 1;
	return fact(n - 1) * n;
}


int main(){

////-----> Sample Space for s with replacement

	/*
	Linkedlist list;
	int r = 3;
	string str = "ABCD";
	_mul(str, r, "", &list);
	list.displayList();
	cout << endl;
	cout << list.countList();*/

	cout << endl;


////-----> Sample Space for s without replacement and order matters
	
	Linkedlist list;
	string str = "ABCD";
	int r = 3; //should not be greater than size(str)
	int n = size(str);	
	per(str,r, "",&list);
	list.displayList();
	cout << endl;
	cout <<"Count: "<< list.countList() << endl;
	
	////Sample Space for s without replacement and order doesn't matter
	//order_n(str, &list);
}
