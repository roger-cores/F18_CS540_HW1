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
  A print utility
**/
void
MyClass_print(const MyClass *o) {
    printf("%d\n", o->id);
    printf("%s\n", o->name);
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
  deq.push_back(&deq, MyClass{3, "Doe"});
  Deque_MyClass_Iterator it = deq.begin(&deq);
  MyClass_print(&it.deref(&it));
  it.inc(&it);
  MyClass_print(&it.deref(&it));
  it.inc(&it);
  MyClass_print(&it.deref(&it));

	return 0;
}
