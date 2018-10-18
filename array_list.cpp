#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class ArrayList {
	private:
		int *data;
		int capacity;
		int growth_factor = 2;

	public:
		int size;

		ArrayList()  {
			size = 0;
			capacity = 1;
			data = new int[capacity];
		}

		ArrayList(vector<int> vect) {
			size = 0;
			capacity = 10;
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

int main() {
	ArrayList primes;
	for (int i=2; i<30; i++) {
		if (is_prime(i) == true) {
			primes.append(i);
		}
	}
	primes.print();
	ArrayList some_primes({2, 3, 5, 8, 11});
    some_primes.print();
    some_primes.insert(1, 5);
    some_primes.print();
    some_primes.remove(3);
    some_primes.print();
	return 0;
}