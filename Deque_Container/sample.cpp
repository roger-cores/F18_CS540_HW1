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
  deq.push_back(&deq, MyClass{2, "Trivedi"});
  deq.push_back(&deq, MyClass{3, "Doe"});
  deq.pop_front(&deq);
  deq.pop_back(&deq);
  for (Deque_MyClass_Iterator it = deq.begin(&deq);
       !Deque_MyClass_Iterator_equal(it, deq.end(&deq)); it.inc(&it)) {
      MyClass_print(&it.deref(&it));
  }

	return 0;
}
