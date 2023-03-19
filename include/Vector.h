#pragma once
#include <iostream>
#include <compare>
#include <stdexcept>


class Vector {
public:
	explicit Vector(size_t size = 0, int value = 0);
	~Vector();
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;
	Vector& operator=(const Vector& other);
	std::strong_ordering operator<=>(const Vector& other) const noexcept;
	int& operator[](const int index);
	const int& operator[](const int index) const;
	const bool& operator==(const Vector& other) const noexcept;
	void swap(Vector& other) noexcept;
	int* data() const;
	bool empty() const;
	int size() const;
	int capacity() const;
	void clear();
	void reserve(size_t capacity);
	void resize(int size, int value);
	void push_back(int&& value);
	void pop_back();
	void insert(size_t index, int value);
	void erase(int index);

private:
	int m_size;
	int m_capacity;
	int* m_data;
};
