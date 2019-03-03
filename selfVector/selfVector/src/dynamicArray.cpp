#include "../header/dynamicArray.h"

using namespace MyDynamicArray;

DynamicArray::DynamicArray() : m_size(0) { base_ptr = (int*)calloc(0, sizeof(int)); }

DynamicArray::DynamicArray(int size, ...) : m_size(size)
{
	base_ptr = (int*)calloc(m_size, sizeof(int));

	va_list va_l;
	va_start(va_l, size);
	for (int i = 0; i < size; i++)
		*(base_ptr + i) = va_arg(va_l, int);

	va_end(va_l);
}

int DynamicArray::size_array() const { return m_size; }

void DynamicArray::push(int data)
{
	m_size += 1;
	base_ptr = (int*)realloc(base_ptr, sizeof(int)*(m_size));
	*(base_ptr + m_size-1) = data;

	return;
}

int DynamicArray::pop() 
{
	int element;
	if (m_size > 0)
	{
		element = *(base_ptr + m_size - 1);
		m_size -= 1;
		base_ptr = (int*)realloc(base_ptr, sizeof(int)*m_size);
	}
	else std::cout << "cannot pop element array is empty...";

	return element;
}

int DynamicArray::pop(int index)
{
	int element;
	if (m_size > 0 && index < m_size)
	{
		int var = *(base_ptr + m_size - 1);
		m_size -= 1;
		base_ptr = (int*)realloc(base_ptr, sizeof(int)*m_size);

		element = *(base_ptr + index);

		for (int i = index; i < m_size - 1; i++)
			*(base_ptr + i) = *(base_ptr + i + 1);

		*(base_ptr + m_size - 1) = var;
	}
	else if (index < 0 || index >= m_size) std::cout << "Invalid index" << std::endl;
	else std::cout << "cannot pop array is empty..." << std::endl;
	
	return element;
}

int DynamicArray::get_element(int index) const
{
	return *(base_ptr + index);
}

int &DynamicArray::operator[](int index)
{
	return *(base_ptr + index);
}

void DynamicArray::insert(int index, int data)
{
	int* temp_ptr = base_ptr;
	m_size += 1;

	base_ptr = (int*)realloc(base_ptr, sizeof(int)*m_size);
	int var = *(base_ptr + index);
	*(base_ptr + index) = data;

	for (int j = index + 1, i = j; j < m_size; j++, i++)
		*(base_ptr + i) = *(temp_ptr + j);

	for (int j = m_size - 2; j > index; j--)
		*(base_ptr + j + 1) = *(base_ptr + j);

	*(base_ptr + index + 1) = var;

	return;
}

void DynamicArray::extend_array(int arg_count,...)
{
	base_ptr = (int*)realloc(base_ptr, sizeof(int)*(m_size + arg_count));

	va_list va_l;
	va_start(va_l, arg_count);
	for (int i = 0; i < arg_count; i++)
		*(base_ptr + m_size + i) = va_arg(va_l, int);
	va_end(va_l);
	m_size += arg_count;

	return;
}

void DynamicArray::display()
{
	if (base_ptr)
	{
		std::cout << std::endl << " [ ";
		for (int i = 0; i < m_size; i++)
		{
			std::cout << *(base_ptr + i);
			if (i < m_size - 1) std::cout << " , ";
		}
		std::cout << " ] " << std::endl;
	}
	else std::cout << "accessing memory which is no more available..."<<std::endl;
	
	return;
}

void DynamicArray::clear()
{
	m_size = 0;
	base_ptr = 0;
}

void DynamicArray::remove()
{
	m_size = 0;
	base_ptr = 0;
	delete base_ptr;
	//delete this;
}