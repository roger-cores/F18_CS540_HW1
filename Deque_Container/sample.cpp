#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Deque.hpp"

/**
  Type of data
**/
struct MyClass;
struct MyClass {
    int id;
    char name[10];
    int (*getId)(MyClass *mcl);
};

int getIdForMcl(MyClass *mcl) {
  return mcl->id;
}

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
    printf("%d\t", o->id);
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
  for (Deque_MyClass_Iterator it = deq.begin(&deq);
       !Deque_MyClass_Iterator_equal(it, deq.end(&deq)); it.inc(&it)) {
      MyClass_print(&it.deref(&it));
  }
  Deque_MyClass_reallocate(&deq);
  for (Deque_MyClass_Iterator it = deq.begin(&deq);
       !Deque_MyClass_Iterator_equal(it, deq.end(&deq)); it.inc(&it)) {
      MyClass_print(&it.deref(&it));
  }

  // MyClass *deq = (MyClass*) calloc(10, sizeof(MyClass));
  // deq[0] = MyClass{1, "Joe"};
  // deq[0].getId = &getIdForMcl;
  // deq[1] = MyClass{2, "Trivedi"};
  // deq[0].getId = &getIdForMcl;
  // deq[2] = MyClass{3, "Doe"};
  // deq[0].getId = &getIdForMcl;
  //
  // for(int i=0; i<3; i++){
  //   MyClass_print(&deq[i]);
  // }

	return 0;
}
