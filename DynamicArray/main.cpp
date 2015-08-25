#include "dynamic_array.h"
#include <iostream>
int main() {
  DynamicArray<char> arr0 = DynamicArray<char>();
  for (int i = 0; i < 40; ++i) {
    arr0.set(i, i + 97);
    std::cout << "i = " << i << ", arr0[i] = " << arr0.getItemAt(i) << ", capacity = " << arr0.getCapacity() << std::endl;
  }
  return 0;
}