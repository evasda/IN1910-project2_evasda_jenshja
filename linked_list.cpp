#include <iostream>
using namespace std;

struct Node {
	int value;
	Node* next;
};


class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	int length() {
		Node* current = head;
		int count = 0;
		while (current != nullptr) {
			count++;
			current = current->next;
		}
		return count;	
	}

	void append(int val) {
		if (head==nullptr) {
			Node *n = new Node;
            n->value = val; 
            n->next = nullptr;
			head = n;
			tail = head;
			return;
		}

		else { 
			Node* current;
			current = tail;
			Node *n = new Node;
            n->value = val; 
            n->next = nullptr;
			current->next = n;
			tail = current->next;
			return; 
		}
	}

	void print() {
		Node* current = head;
		cout << "[";
		while (current->next !=nullptr) {
			cout << current->value;
			cout << ", ";
			current = current->next;
	    	}
		cout << current->value << "]" << endl;	
		}
};

int main() {
	LinkedList primes;
	primes.append(2);
	primes.append(3);
	primes.append(5);
	primes.append(7);
	cout << "primes = ";
	primes.print(); 
	cout << "length of primes: ";
	cout << primes.length() << endl;
	return 0;
}
