#include "Tree.h"
#include <limits>
#include <vector>

template <class T> class MaxHeap {
private:
  int maxSize;
  int size;
public:
  T *H;
  MaxHeap(int size) {
    this->maxSize = size;
    this->size = 0;
    T array[size+1];
    H = array;
  }
  int parent(int index) { return index / 2; }
  int leftChild(int index) { return index * 2; }
  int rightChild(int index) { return index * 2 + 1; }
  void SiftUp(int index) {
    while (index > 1 and H[parent(index)] < H[index]) {
      T temp = H[index];
      H[index] = H[parent(index)];
      H[parent(index)] = temp;
      index = parent(index);
    }
  }
  void SiftDown(int index) {
    auto maxIndex = index;
    auto left = leftChild(index);
    if (left <= this->size && H[left] < H[maxIndex]) {
      maxIndex = left;
    }
    auto right = rightChild(index);
    if (right <= this->size && H[right] < H[maxIndex]) {
      maxIndex = right;
    }
    if (index == maxIndex) {
      auto temp = H[index];
      H[index] = H[maxIndex];
      H[maxIndex] = temp;
      SiftDown(maxIndex);
    }
  }
  void Insert(T dato) {
    if (this->size == this->maxSize) {
      throw std::runtime_error("Lleno");
    }
    this->size += 1;
    H[this->size] = dato;
    SiftUp(this->size);
  }
  T ExtractMax() {
    auto result = H[1];
    H[1] = H[this->size];
    this->size -= 1;
    SiftDown(1);
    return result;
  }
  void Remove(int index) {
    H[index] = std::numeric_limits<int>::max();
    SiftUp(index);
    ExtractMax();
  }
  void ChagePriotiry(int index, T dato) {
    auto oldp = H[index];
    H[index] = dato;
    if (dato > oldp) {
      SiftUp(index);
    } else {
      SiftDown(index);
    }
  }
  void Display() {
    for (int i = 1; i < this->size; i++) {
      std::cout << H[i] << " ";
    }
    std::cout<<'\n';
  }
};