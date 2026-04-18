// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
  static const int kSize = size;
  T arr[kSize];
  int topIndex;

 public:
  TStack() : topIndex(-1) {}

  void push(T value) {
    if (topIndex < ksize - 1) {
      arr[++topIndex] = value;
    }
  }

  T pop() {
    if (!isEmpty()) {
      return arr[topIndex--];
    }
    return T();
  }

  T top() {
    return arr[topIndex];
  }

  bool isEmpty() const {
    return topIndex == -1;
  }
};

#endif  // INCLUDE_TSTACK_H_
