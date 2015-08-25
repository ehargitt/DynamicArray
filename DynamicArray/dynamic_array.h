#ifndef DYNAMICARRAY_DYNAMICARRAY_H_
#define DYNAMICARRAY_DYNAMICARRAY_H_
#include <iostream>

template <typename T>
class DynamicArray {
  public:
    static const int kDefaultInitCapacity = 10;
    DynamicArray<T>(int initial_capacity);
    DynamicArray<T>() : DynamicArray<T>(kDefaultInitCapacity) {}
    ~DynamicArray<T>();
    T getItemAt(int index);
    int getCapacity() { return capacity; }
    int getNumElements() { return num_elements; }
    void set(int index, T input);

  private:
    int num_elements = 0;
    int capacity;
    T * storage;
};

template <typename T>
DynamicArray<T>::DynamicArray(int initial_capacity) {
  capacity = initial_capacity;
  storage = new T[capacity];
  for (int i = 0; i < capacity; ++i) {
    storage[i] = NULL;
  }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
  delete[] storage;
}

template <typename T>
T DynamicArray<T>::getItemAt(int index) {
  if (index > capacity - 1) {
    return NULL;
  }
  return storage[index];
}

template <typename T>
void DynamicArray<T>::set(int index, T input) {
  if (storage[index] == NULL && input != NULL) {
    ++num_elements;
    if (num_elements * 2 >= capacity) {
      capacity *= 2;
      T *temp = new T[capacity];
      for (int i = 0; i < capacity; ++i) {
        temp[i] = NULL;
      }

      for (int i = 0; i < num_elements; ++i) {
        temp[i] = storage[i];
      }
      delete[] storage;
      storage = temp;
    }
  }
  else if (storage[index] != NULL && input == NULL) {
    --num_elements;
  }

  storage[index] = input;
}

#endif