#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Node {
	int value;
	Node* next;
};


class LinkedList {
private:
	Node* head;
	Node* tail;

	Node* get_node(int index) {
    	if (index < 0 || index >= length()) {
        	throw range_error("IndexError: Index out of range");
    	}

    	Node* current = head;
    	for (int i=0; i<index; i++) {
        	current = current->next;
    	}
    	return current;
    }

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	LinkedList(vector<int> vec) {
		head = nullptr;
		tail = nullptr;
		for (int v:vec) {
			append(v);
		}
	}

	~LinkedList() {
    Node* current;
    Node* next;

    current = head;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    	}
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

		int& operator[](int index) {
            return get_node(index)->value;
        }

        void insert(int val, int index) {
        	Node* current = get_node(index-1);
        	Node* n = new Node;
        	n->value = val;
        	n->next = current->next;
        	current->next = n; 
        }

        void remove(int index) {				//Can be made more efficient.
        	Node* current = get_node(index);
        	if (current->next == nullptr) {
        		Node* temp = get_node(index-1);
        		temp->next = nullptr;
        		tail = temp;
        	}
        	else if (current == head) {
        		head = current->next;
        		current->next = nullptr;
        	}

        	else {
        		Node* temp = get_node(index-1);
        	    temp->next = current->next;
        	    current->next = nullptr;
            }
        }
        int pop(int index) {
        	Node* temp = get_node(index);
        	int pop_val = temp->value;
        	remove(index);
        	return pop_val;
        }

        int pop() {
        	int pop_val = tail->value;
        	remove(length()-1);
        	return pop_val;
        }
};

void test_LinkedList() {
	// Testing append
	LinkedList primes;
	primes.append(2);
	primes.append(3);
	primes.append(5);
	primes.append(11);
	// Testing print
	primes.print(); 
    // Testing []
	assert(3 == primes[1]);
    // Testing insert 
    primes.insert(7,3);
    assert(7 == primes[3]);
    // Testing remove
    primes.remove(3);
    assert(7 != primes[3]);
    // Testing pop(int) 
    int pop_val = primes.pop(0);
    assert(2 == pop_val);
    // Testing pop()
    int pop_val2 = primes.pop();
    assert(11 == pop_val2);
    // Testing LinkedList(vector<int>)
	LinkedList primes_2({2,3,5,11});
	primes_2.print();
}

int main() {
	test_LinkedList();
	return 0;
}
