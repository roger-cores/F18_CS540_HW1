/*
 * Implement your functionality here without changing test.cpp
 */
#define Deque_DEFINE(type)                                                      \
typedef struct Deque_##type {                                                   \
 bool (*comparator)(const type &one, const type &two);                          \
 size_t (*size)(Deque_##type *type);                                            \
} Deque_##type;                                                                 \
size_t sizeOfDeque_##type(Deque_##type *deq) {                                  \
  return 0;                                                                     \
}                                                                               \
void Deque_##type##_ctor(struct Deque_##type *deq, bool (*comparator)(const type &one, const type &two)) { \
  deq->comparator = comparator;                                                 \
  deq->size = &sizeOfDeque_##type;                                              \
}
