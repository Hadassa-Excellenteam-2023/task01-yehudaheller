#include "..\include\Vector.h"

//defult constractor
Vector::Vector(size_t size, int value) : m_size(size), m_capacity(size), m_data(new int[size])
{
	for (int i = 0; i < size; i++)
		m_data[i] = value;
}

//destractor
Vector::~Vector()
{
	delete[] m_data;
}

//copy constractor
Vector::Vector(const Vector& other): m_size(other.m_size), m_capacity(other.m_capacity), m_data(new int[m_capacity])
{
	for (int i = 0; i < m_size && i < m_capacity; i++) {
		m_data[i] = other.m_data[i];
	}
}

//moving constractor
Vector::Vector(Vector&& other) noexcept: m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data)
{
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_data = nullptr;
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		Vector tmp(other); 
		this->swap(tmp); 
	}
	return *this;

}


int& Vector::operator[](const int index)
{
	if (m_size <= index)
	{
		throw std::out_of_range("Invalid index: index out of range");
	}

	return m_data[index];
}

const int& Vector::operator[](const int index) const
{
	if (m_size <= index)
	{
		throw std::out_of_range("Invalid index: index out of range");
	}

	return m_data[index];
}

const bool& Vector::operator==(const Vector& other) const noexcept
{
	if (m_size != other.m_size)
		return false;
	
	for (int i = 0; i < m_size; i++)
		if (m_data[i] != other.m_data[i])
			return false;
	
	return true;

}

const bool& Vector::operator!=(const Vector& other) const noexcept
{
	return !( this->operator==(other));
}

std::strong_ordering Vector::operator<=>(const Vector& other) const noexcept
{
	// Check for object equality using the == operator
	if (*this == other) {
		return std::strong_ordering::equal; // If objects are equal, return equal
	}
	// If the sizes are different, return less or greater depending on which is smaller
	else if (m_size < other.m_size) {
		return std::strong_ordering::less; // If size is less, return less
	}
	else {
		return std::strong_ordering::greater; // Otherwise, return greater
	}
}


void Vector::swap(Vector& other) noexcept
{
	std::swap(m_size, other.m_size);
	std::swap(m_capacity, other.m_capacity);
	std::swap(m_data, other.m_data);
}

int* Vector::data() const
{
	return m_data;
}

bool Vector::empty() const
{
	return (m_size == 0) ? true : false;
}

int Vector::size() const
{
	return m_size;
}

int Vector::capacity() const
{
	return m_capacity;
}

void Vector::clear()
{
	m_size = 0;
	m_capacity = 0;
	m_data = nullptr;
}


void Vector::reserve(size_t capacity)
{
	if (capacity > m_capacity) {
		int* data = new int[capacity];
		for (size_t i = 0; i < m_size; ++i) {
			data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = data;
		m_capacity = capacity;
	}
}


void Vector::resize(int size, int value)
{
	if (size > m_size) {
		if (size > m_capacity) {
			reserve(size);
		}
		for (size_t i = m_size; i < size; ++i) {
			m_data[i] = value;
		}
	}
	m_size = size;
}

void Vector::push_back(int&& value)
{
	if (m_size == 0) 
		reserve(1);

	if (m_size == m_capacity)
		if (m_size < 128)
			reserve(m_capacity * 2);
		else
			reserve(m_capacity * 1.5);

	m_data[m_size++] = value;

}

void Vector::pop_back()
{
	if (m_size == 0)
		return;

	m_size--;


}

void Vector::insert(size_t index, int value)
{
	try {
		if (index > m_size) {
			throw std::out_of_range("Invalid index: index out of range");
		}

		if (m_size == m_capacity) {
			reserve(m_capacity * 2);
		}

		// Shift all elements after the index to the right
		for (int i = m_size - 1; i >= static_cast<int>(index); i--) {
			m_data[i + 1] = m_data[i];
		}

		// Insert the new value
		m_data[index] = value;

		m_size++;
	}
	catch (const std::out_of_range& e) {
		// Handle the exception
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}


void Vector::erase(int index)
{
	try {
		if (index >= m_size) {
			throw std::out_of_range("Invalid index: index out of range");
		}

		// Shift all elements after the index to the left
		for (int i = index; i < m_size - 1; i++) {
			m_data[i] = m_data[i + 1];
		}

		m_size--;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
}

