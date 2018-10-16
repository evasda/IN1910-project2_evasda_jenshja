#include <iostream>
#include <vector>
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
	return 0;
}