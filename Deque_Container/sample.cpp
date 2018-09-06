#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Deque.hpp"

/**
  Type of data
**/
struct MyClass {
    int id;
    char name[10];
};

/**
  A comparator
**/
bool
MyClass_less_by_id(const MyClass &o1, const MyClass &o2) {
    return o1.id < o2.id;
}

/**
  expands code for MyClass type
**/
Deque_DEFINE(MyClass)

int main() {
	Deque_MyClass deq;
  Deque_MyClass_ctor(&deq, MyClass_less_by_id);
  deq.push_back(&deq, MyClass{1, "Joe"});
  deq.push_back(&deq, MyClass{2, "Mary"});
  printf("%d", deq.size(&deq));
	return 0;
}
