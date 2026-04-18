// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
    T arr[size];
    int topIndex;

  public:
    TStack() : topIndex(-1) {}

    void push(T value) {
      arr[++topIndex] = value;
    }

    T pop() {
      return arr[topIndex--];
    }

    T top() const {
      return arr[topIndex];
    }

    bool isEmpty() const {
      return topIndex == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
