// TAArray.h
#ifndef TAARRAY_H
#define TAARRAY_H

#include "TextArea.h"

class TAArray {
private:
    TextArea** array;  // Dynamic array of TextArea pointers
    int size;          // Current number of elements
    int capacity;      // Maximum capacity

public:
    // Constructor & Destructor
    TAArray(int cap = 100);
    ~TAArray();

    // Methods
    bool add(TextArea* ta);                 // Add to back
    bool add(TextArea* ta, int index);      // Add at specific index
    TextArea* get(int index) const;         // Get by index
    TextArea* get(const std::string& id) const; // Get by ID
    TextArea* remove(int index);            // Remove by index
    TextArea* remove(const std::string& id);// Remove by ID
    int getSize() const;                    // Get current size
    int getCapacity() const;                // Get capacity
    void clear();                           // Clear all

    // Copy constructor and assignment operator (if needed)
    TAArray(const TAArray& other);
    TAArray& operator=(const TAArray& other);
};

#endif
