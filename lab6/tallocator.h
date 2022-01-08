#ifndef LAB6__TALLOCATOR_H_
#define LAB6__TALLOCATOR_H_

#include "tlinked_list.h"

class TAllocator {
 public:
  TAllocator(size_t size, size_t count) {
    this->size = size;
    for (int i = 0; i < count; i++) {
      freeBlocks.pushBack(malloc(size));
    }
  }

  void* allocate(size_t size) {
    if (size != this->size) {
      std::cout << "Cant find such memory" << std::endl;
    }
    if (freeBlocks.size() != 0) {
      for (int i = 0; i < 5; i++) {
        freeBlocks.pushBack(malloc(size));
      }
    }

    void* temp = freeBlocks.getFirst()->getData();
    usedBlocks.pushBack(freeBlocks.getFirst()->getData());
    freeBlocks.erase(0);
    return temp;
  }

  void deallocate(void* ptr) {
    freeBlocks.pushBack(ptr);
  }

  ~TAllocator() {
    while (usedBlocks.size() != 0) {
      try {
        free(usedBlocks.getFirst()->getData());
        usedBlocks.erase(0);
      } catch(...) {
        usedBlocks.erase(0);
      }
    }
    while (freeBlocks.size() != 0) {
      try{
        free(freeBlocks.getFirst()->getData());
        freeBlocks.erase(0);
      } catch(...) {
        freeBlocks.erase(0);
      }
    }
  }

 private:
  size_t size;
  TLinkedList<void*> usedBlocks;
  TLinkedList<void*> freeBlocks;
};

#endif //LAB6__TALLOCATOR_H_
