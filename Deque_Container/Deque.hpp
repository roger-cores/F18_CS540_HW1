/*
 * Implement your functionality here without changing test.cpp
 */
#define Deque_DEFINE(type)                                                      \
struct Deque_##type {                                                           \
 int data;                                                                      \
 bool (*comparator)(const type &one, const type &two);                          \
};                                    \
void Deque_##type##_ctor(Deque_##type *deq, bool (*comparator)(const type &one, const type &two)) { \
  deq = (Deque_##type *) malloc(sizeof(Deque_##type));                          \
  deq->comparator = comparator;                                                 \
}
