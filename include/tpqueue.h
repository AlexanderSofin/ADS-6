// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T, int size>
class TPQueue {
 private:
    T arr[10];
    int begin, end;
 public:
    TPQueue() : begin(0), end(0) { }
    void push(T item) {
        int i = end++;
        for (i; (--i >= begin) && (arr[i % size].prior < item.prior);) {
            arr[(i + 1) % size] = arr[i % size];
        }
        arr[(i + 1) % size] = item;
    }
    T pop() {
        return arr[(begin++) % size];
    }
};
struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
