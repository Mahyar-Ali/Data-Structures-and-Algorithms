/*
Postfix Expression Solver
- Convert Arithmetic Expression to Postfix Notation
- Solve the Postfix Expression

Solution is Implemented Using Queues

Note: For now the solution only works for 
expression that evaluate to an Integer value
as result. Double and Float can be handled
in the same way.
*/

#include<iostream>
#include<map>
#include<string>
#include<cmath>
using namespace std;
struct block {
public:
	string i;
	block* next;
};
struct Que {
public:
	int SIZE;
	block* head;
	Que() {
		head = NULL;
		SIZE = 20;
	}

	int getStackSize() {
		int counter = 0;
		block* pointer;
		pointer = head;
		while (pointer) {
			counter++;
			pointer = pointer->next;
		}
		return counter;
	}
	bool IsFull() {
		if (getStackSize() == SIZE) {
			return true;
		}
		return false;

	}
	bool IsEmpty() {
		if (head == NULL)
			return true;
		return false;
	}

	void Push(string val) {
		if (!IsFull()) {
			block* new_head;
			new_head = new block;
			new_head->i = val;
			new_head->next = head;
			head = new_head;
		}
		else {
			cout << "Stack is Full" << endl;
		}
	}
	string pop() {
		if (!IsEmpty()) {
			block* temp;
			temp = head;
			string i = head->i;
			head = head->next;
			delete (temp);
			return i;
		}
		else {
			return "E";
		}
	}

	string r_head() {
		if (!IsEmpty()) return head->i;
		else return "E";
	}
	void display() {
		block* pointer = head;
		while (pointer) {
			cout << pointer->i << endl;
			pointer = pointer->next;
		}
	}
};

int convert_int(string temp) {
	if (temp.size() == 1) {
		return int(temp[0]) - 48;
	}
	return convert_int(temp.substr(0, temp.size() - 1)) * 10 + int(temp[temp.size() - 1]) - 48;
}

int main() {
	Que q1;
	string postfix = "";
	map<char, int> operators_pre = { {'+',1},{'-',1},
		{'*',2},{'/',2},{'^',3},{'(',4},{')',5} };

	string exp = "(1*2/3)+(4/5*2)/6"; //623+-382/+*2^3+

	for (char c : exp) {
		cout << "pos " << postfix << endl;
		if (int(c) >= 48 && int(c) <= 57) {
			postfix.append(1, c);
		}
		else if (operators_pre[c] == 5) {
			while (q1.r_head()[0] != '(') {
				postfix += q1.pop();
			}
			q1.pop();
		}
		else if (operators_pre[c] == 4) {
			q1.Push(string(1, c));
		}
		else if (operators_pre[c] <= operators_pre[q1.r_head()[0]]
			&& operators_pre[q1.r_head()[0]] != 4) {
			postfix += q1.pop();
			q1.Push(string(1, c));
		}
		else {
			q1.Push(string(1, c));
		}
	}
	while (operators_pre[q1.r_head()[0]]) {
		postfix += q1.pop();
	}
	cout << postfix;

	Que q2;
	int result;
	int a, b;
	for (char c : postfix) {
		cout << "---------" << endl;
		cout << c << endl;
		cout << q2.r_head() << endl;

		if (int(c) >= 48 && int(c) <= 57) {
			q2.Push(string(1, c));
			continue;
		}

		switch (c) {
		case '+':

			a = convert_int(q2.pop());
			b = convert_int(q2.pop());
			result = b + a;
			q2.Push(to_string(result));
			break;
		case '-':
			a = convert_int(q2.pop());
			b = convert_int(q2.pop());
			result = b - a;
			q2.Push(to_string(result));
			break;
		case '*':
			a = convert_int(q2.pop());
			b = convert_int(q2.pop());
			result = b * a;
			q2.Push(to_string(result));
			break;
		case '/':
			a = convert_int(q2.pop());
			b = convert_int(q2.pop());
			result = b / a;
			q2.Push(to_string(result));
			break;
		case '^':
			a = convert_int(q2.pop());
			b = convert_int(q2.pop());
			result = pow(b, a);
			q2.Push(to_string(result));
			break;
		default:
			cout << "Invalid" << endl;
		}
	}
	cout << q2.r_head() << endl;
}