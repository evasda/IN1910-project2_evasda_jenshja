#include <iostream>
#include <vector>
#include <stdexcept>
#include <math.h> 
#include <cassert>
using namespace std;

class ArrayList {
	private:
		int *data;
		int capacity;
		int growth_factor = 2;

	public:
		int size;
		int get_capacity() {
			return capacity;
		}

		ArrayList()  {
			size = 0;
			capacity = 1;
			data = new int[capacity];
		}

		ArrayList(vector<int> vect) {
			size = 0;
			capacity = 1;
			data = new int[capacity];
			for (int v:vect) {
				append(v);
			}
		}

		~ArrayList() {
			delete[] data;
		}		

		int length() {
			return size;
		}

		void append(int n) {
			if (size >= capacity) {
				resize(n);
			}
			data[size] = n;
			size += 1;
		}

		void resize(int n) {
			capacity *= growth_factor;
			int *tmp = new int[capacity];
			for (int i=0; i<size; i++) {
				tmp[i] = data[i];
			}
			delete[] data;
			data = tmp;
		}

		void print() {
			cout << "[";
			for (int i=0; i<(size-1); i++) {
				cout << data[i] << ",";
			}

			cout << data[size-1] << "]" << endl;	
		}


		int &operator[](int i) {
			if (0 <= i and i < size) {
				return data[i];
			} else {
				throw out_of_range("IndexError");
			}
		}

		void insert(int val, int index) {
			int *tmp = new int[capacity];
			if (index <= size) {
				for (int i=0; i<index; i++) {
					tmp[i] = data[i];
				}
				tmp[index] = val;
				for (int i=(index+1); i<=(size); i++) {
					tmp[i] = data[i-1];
				}
			} 
			else {
				throw out_of_range("IndexError");
			}
			delete[] data;
			data = tmp;
			size +=1;
		}


		void remove(int index) {
			int *tmp = new int[capacity];
			if (index <= size) {
				for (int i=0; i<index; i++) {
					tmp[i] = data[i];
				}
				for (int i=(index+1); i<(size); i++) {
					tmp[i-1] = data[i];
				}
			} 
			else {
				throw out_of_range("IndexError");
			}
			delete[] data;
			data = tmp;
			size -=1;
			if (size < 0.25 * capacity) {
				shrink_to_fit();
			}
		}

		int pop(int index) {
			int pop_val = data[index];
			remove(index);
			return pop_val;
		}

		int pop() {
			int pop_val = data[size-1];
			remove(size);
			return pop_val;
		}

		void shrink_to_fit() {
			if(size == 0 || size == 1) {
				capacity = 1;
			}
			else {
				int n; 
				n = ceil(log(size)/log(2));
				capacity = pow(2,n);
		    }
		}
};

bool is_prime(int n) {
	int i = 2;
	bool val;
	while (i < n) {
		if (n % i == 0) {
			val = false;
			break;
		}
		else {
			val = true;
		}	
		i += 1;
	}
	return val;	
}

void test_ArrayList() {
	ArrayList vec;
	for (int i=0; i<=513; i++) {
		vec.append(i);
	}
	int cap = vec.get_capacity();
	assert(cap == 1024);
	for (int i=0; i<=257; i++) {
		vec.remove(i);
	}
	vec.shrink_to_fit();
	int new_cap = vec.get_capacity();
	assert(new_cap == 256);
}

int main() {
	ArrayList primes;
	for (int i=2; i<30; i++) {
		if (is_prime(i) == true) {
			primes.append(i);
		}
	}
	primes.print();
	
    test_ArrayList();
	return 0;
}