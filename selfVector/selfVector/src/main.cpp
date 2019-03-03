#include<iostream>
#include"../header/dynamicArray.h"

#define print(x) std::cout<<x<<std::endl
#define wait std::cin.get()

using namespace MyDynamicArray;

int main(void)
{
	
	DynamicArray::Documentation();

	#if 0
	//DynamicArray d_array(4,1,2,3,4);
	DynamicArray d_array(4);
	
	for (int i = 0; i < 4; i++)
		d_array[i] = i * i;

	d_array.display();

	d_array.push(14);
	d_array.display();

	d_array.pop();
	d_array.display();

	d_array.extend_array(5, 12, 13, 14, 15, 16);
	
	d_array.display();

	d_array.insert(3, -103);
	d_array.display();

	d_array.pop(4);
	d_array.display();

	d_array.clear();
	print("size");
	print(d_array.size_array());
	
	d_array.extend_array(5, 1, 2, 3, 4, 5);
	d_array.display();

	d_array.remove();
	print("size");
	print(d_array.size_array());
	d_array.display();
	
	#endif

	wait;
	return 0;
}