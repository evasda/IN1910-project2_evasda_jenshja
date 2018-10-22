#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Node {
	int value;
	Node* next;
};

class CircLinkedList {
private:
	Node* head;

	Node* get_node(int index) {
		if (head == nullptr) {
        	throw range_error("RangeError: Circular List is empty.");
        }
		int x = floor(index/length);
		int real_index = index - x*length;

    	Node* current = head;
    	for (int i=0; i<real_index; i++) {
        	current = current->next;
    	}
    	return current;
    }

public:
	int length;

	CircLinkedList() {
		head = nullptr;
		length = 0;
	}

	CircLinkedList(int n) {
		head = nullptr;
		length = 0;
		for (int i = 1; i<=n; i++) {
			append(i);
		}
	}

	void append(int val) {
		Node *n = new Node;
		n->value = val;
		if (head == nullptr) {
			n->next = n;
			head = n;
		}
		else {
			n->next = head;
			Node *current = head;
			while (current->next != head) {
				current = current->next;
			}
			current->next = n;
		}
		length += 1;
	}

	void print() {
		Node* current = head;
		cout << "[";
		while (current->next !=head) {
			cout << current->value;
			cout << ", ";
			current = current->next;
    	}
		cout << current->value << "]" << endl;	
	}

		int& operator[](int index) {
            return get_node(index)->value;
        }

    vector<int> josephus_sequence(int k) {
    	int count = 1;
    	vector<int> sequence;
    	while (length != 0) {
    		sequence.push_back(get_node(k-1)->value);
            remove_and_set_new_head(k-1);
            count ++;
    	}
    	return sequence;
    	
    }

        void remove_and_set_new_head(int index) {				//Can be made more efficient.
        	Node* current = get_node(index);
        	if (current->next == head) {
        		Node* temp = get_node(index-1);
        		temp->next = head;
        	}
        	else if (current == head) {
        		head = current->next;
        		current->next = nullptr;
        		get_node(length-2)->next = head;

        	}
        	else {
        		Node* temp = get_node(index-1);
        	    temp->next = current->next;
        	    head = current->next;
        	    current->next = nullptr;
            }
            length -= 1;
        }
};

int last_man_standing(int n, int k) {
	CircLinkedList josephus(n);
	vector<int> a = josephus.josephus_sequence(k);
	return a[n-1];
}

int main() {
	/*CircLinkedList primes;
	primes.append(2);
	primes.append(3);
	primes.append(5);
	primes.append(7);
	primes.append(11);
	primes.print();
	cout << primes[1] << endl; */
	int n = 68;
	int k = 7;
	int survivor = last_man_standing(n, k);
	cout << "The last survivor of the Josephus problem with n = " <<n;
	cout << " and k = " << k << " is " << survivor <<"." << endl;
	return 0;
}