class DynamicArray {
private:
    int* arrayPtr; // The array pointer
    size_t size;    // Size of the array

public:
    // Regular Constructor
    DynamicArray(size_t s) : size(s) {
        arrayPtr = new int[size]; // Dynamic allocation
        // Initialize array elements...
    }

    // Destructor (Crucial for memory deallocation)
    ~DynamicArray() {
        delete[] arrayPtr;
    }

    // ? Deep Copy Constructor ?
    DynamicArray(const DynamicArray& other) : size(other.size) {
        // 1. Allocate new memory for the new object
        arrayPtr = new int[size];

        // 2. Copy the contents from the source array to the new array
        for (size_t i = 0; i < size; ++i) {
            arrayPtr[i] = other.arrayPtr[i];
        }
        // The new object now has its own unique copy of the data.
    }

    // Rule of Three/Five/Zero: When implementing a copy constructor, 
    // you often also need to implement the Copy Assignment Operator.
    // DynamicArray& operator=(const DynamicArray& other);
    // ...
};
