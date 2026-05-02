#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

template <typename T>
class Vector {
	T* data;
	std::size_t size;

public:
	Vector() : data(NULL), size(0) {}

	Vector(const Vector& other) : data(NULL), size(other.size) {
		if (size == 0) {
			return;
		}

		data = new T[size];
		for (std::size_t i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
	}

	std::size_t getSize() const {
		return size;
	}

	Vector& operator=(const Vector& other) {
		if (this == &other) {
			return *this;
		}

		delete[] data;
		size = other.size;

		if (size == 0) {
			data = NULL;
			return *this;
		}

		data = new T[size];
		for (std::size_t i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}

		return *this;
	}

	T& operator[](std::size_t idx) {
		return data[idx];
	}

	const T& operator[](std::size_t idx) const {
		return data[idx];
	}

	void push_back(const T& value) {
		T* newData = new T[size + 1];

		for (std::size_t i = 0; i < size; ++i) {
			newData[i] = data[i];
		}

		newData[size] = value;
		delete[] data;
		data = newData;
		++size;
	}

	void pop_back() {
		if (size == 0) {
			return;
		}

		T* newData = NULL;
		if (size > 1) {
			newData = new T[size - 1];
			for (std::size_t i = 0; i < size - 1; ++i) {
				newData[i] = data[i];
			}
		}

		delete[] data;
		data = newData;
		--size;
	}

	~Vector() {
		delete[] data;
	}
};

#endif
