all: linked_list circular_linked_list array_list

linked_list:
	g++ -std=c++0x linked_list.cpp -o linked_list

circular_linked_list:
		g++ -std=c++0x circular_linked_list.cpp -o circular_linked_list

array_list:
				g++ -std=c++0x array_list.cpp -o array_list

clean:
		rm -f array_list
		rm -f linked_list
		rm -f circular_linked_list
