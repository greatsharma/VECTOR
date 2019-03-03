#ifndef __DYNAMICARRAY__
#define __DYNAMICARRAY__

#include<stdlib.h>
#include<stdarg.h>
#include<iostream>

namespace MyDynamicArray
{
	class DynamicArray
	{
	private:
		int m_size;
		int* base_ptr;
	public:
		DynamicArray();
		DynamicArray(int, ...);
		int size_array() const;
		void push(int);
		int pop();
		int pop(int);
		int get_element(int) const;
		int &operator[](int);
		void insert(int, int);
		void extend_array(int, ...);
		void display();
		void clear();
		void remove();
		static void Documentation()
		{
			std::cout << std::endl<<std::endl;
			std::cout << "Methods and their implementation -> " << std::endl<<std::endl;
			std::cout << "DynamicArray() -> constructor with no arguments, it initialises array with 0 size" << std::endl;
			std::cout << "DynamicArray(int, ...) -> first parameter is size and then variable no of data " << std::endl;
			std::cout << "size_array() -> returns the size of array " << std::endl;
			std::cout << "push(int data) -> push data at last index in array" << std::endl;
			std::cout << "pop() -> remove and returns last element of array" << std::endl;
			std::cout << "pop(int index) -> remove and returns element at index of array" << std::endl;
			std::cout << "get_element(int index) -> returns element without removing at index of array" << std::endl;
			std::cout << "insert(int index, int data) -> insert data at index" << std::endl;
			std::cout << "extend_array(int size, ...) -> increase array by size and takes variable no of data" << std::endl;
			std::cout << "display() -> display array in form [, , ... ,]" << std::endl;
			std::cout << "clear() -> clear the array and make it of size 0" << std::endl;
			std::cout << "remove() -> delete the array from memory" << std::endl;
			std::cout << "documentation() -> Docs of MyDynamicArray" << std::endl << std::endl;
		}
	};
}
#endif