#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <typeinfo>
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
	// Deque_MyClass deq;
  // Deque_MyClass_ctor(&deq, MyClass_less_by_id);
  // deq.push_back(&deq, MyClass{1, "Joe"});
  // deq.push_back(&deq, MyClass{2, "Trivedi"});
  // deq.push_back(&deq, MyClass{3, "Doe"});
  // deq.pop_front(&deq);
  // for (Deque_MyClass_Iterator it = deq.begin(&deq);
  //      !Deque_MyClass_Iterator_equal(it, deq.end(&deq)); it.inc(&it)) {
  //     MyClass_print(&it.deref(&it));
  // }
  // Deque_MyClass_reallocate(&deq);
  // for (Deque_MyClass_Iterator it = deq.begin(&deq);
  //      !Deque_MyClass_Iterator_equal(it, deq.end(&deq)); it.inc(&it)) {
  //     MyClass_print(&it.deref(&it));
  // }

  Deque_MyClass deq;
  Deque_MyClass_ctor(&deq, MyClass_less_by_id);

  assert(deq.size(&deq) == 0);
  // size() should return a size_t.
  assert(typeid(std::size_t) == typeid(decltype(deq.size(&deq))));
  assert(deq.empty(&deq));
  //
  // // Should print "---- Deque_MyClass, 14".
  printf("---- %s, %d\n", deq.type_name, sizeof deq.type_name);
  // // std::cout << "---- " << deq.type_name << ", " << sizeof(deq.type_name) << std::endl;
  assert(sizeof deq.type_name == 14); // TODO Fails
  //
  deq.push_back(&deq, MyClass{1, "Joe"});
  deq.push_back(&deq, MyClass{2, "Mary"});
  deq.push_back(&deq, MyClass{3, "Tom"});
  deq.push_front(&deq, MyClass{0, "Mike"});
  deq.push_front(&deq, MyClass{-1, "Mary"});
  printf("\n");
  for (Deque_MyClass_Iterator it = deq.begin(&deq);
       !Deque_MyClass_Iterator_equal(it, deq.end(&deq)); it.inc(&it)) {
      MyClass_print(&it.deref(&it));
  }
  printf("\n");

  MyClass_print(&deq.front(&deq));
  MyClass_print(&deq.back(&deq));
  printf("\n");
  assert(deq.front(&deq).id == -1);
  assert(deq.back(&deq).id == 3);

  deq.pop_front(&deq);
  deq.pop_back(&deq);
  assert(deq.front(&deq).id == 0);
  assert(deq.back(&deq).id == 2);

  assert(deq.size(&deq) == 3);

  for (Deque_MyClass_Iterator it = deq.begin(&deq);
       !Deque_MyClass_Iterator_equal(it, deq.end(&deq)); it.inc(&it)) {
      MyClass_print(&it.deref(&it));
  }




	return 0;
}
