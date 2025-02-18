// TAArray.cc
#include "TAArray.h"
#include <iostream>
#include <algorithm>

// Constructor
TAArray::TAArray(int cap) : capacity(cap), size(0) {
    array = new TextArea*[capacity]();
}

// Destructor
TAArray::~TAArray() {
    clear();
    delete[] array;
}

// Add TextArea to the back
bool TAArray::add(TextArea* ta) {
    if (size >= capacity) return false; 
    array[size++] = ta;
    return true;
}

// Add TextArea at a specific index
bool TAArray::add(TextArea* ta, int index) {
    if (index < 0 || index > size || size >= capacity) return false;

    for (int i = size; i > index; --i) {
        array[i] = array[i - 1];
    }
    array[index] = ta;
    ++size;
    return true;
}

// Get TextArea by index
TextArea* TAArray::get(int index) const {
    if (index < 0 || index >= size) return nullptr;
    return array[index];
}

// Get TextArea by ID
TextArea* TAArray::get(const std::string& id) const {
    for (int i = 0; i < size; ++i) {
        if (array[i]->getId() == id) return array[i];
    }
    return nullptr;
}

// Remove TextArea by index
TextArea* TAArray::remove(int index) {
    if (index < 0 || index >= size) return nullptr;

    TextArea* removed = array[index];
    for (int i = index; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }
    --size;
    return removed;
}

// Remove TextArea by ID
TextArea* TAArray::remove(const std::string& id) {
    for (int i = 0; i < size; ++i) {
        if (array[i]->getId() == id) {
            return remove(i);
        }
    }
    return nullptr;
}

// Clear the array
void TAArray::clear() {
    for (int i = 0; i < size; ++i) {
        delete array[i];
    }
    size = 0;
}

// Get current size
int TAArray::getSize() const {
    return size;
}

// Get capacity
int TAArray::getCapacity() const {
    return capacity;
}

// Copy constructor
TAArray::TAArray(const TAArray& other) : capacity(other.capacity), size(other.size) {
    array = new TextArea*[capacity]();
    for (int i = 0; i < size; ++i) {
        array[i] = new TextArea(*other.array[i]);
    }
}

// Assignment operator
TAArray& TAArray::operator=(const TAArray& other) {
    if (this == &other) return *this;
    clear();
    delete[] array;
    
    capacity = other.capacity;
    size = other.size;
    array = new TextArea*[capacity]();
    for (int i = 0; i < size; ++i) {
        array[i] = new TextArea(*other.array[i]);
    }
    return *this;
}
