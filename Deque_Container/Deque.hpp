/*
 * Implement your functionality here without changing test.cpp
 */
#define Deque_DEFINE(type)                                                      \
typedef struct Deque_##type {                                                   \
 bool (*comparator)(const type &one, const type &two);                          \
 size_t (*size)(Deque_##type *deq);                                             \
 bool (*empty)(Deque_##type *deq);                                              \
 void (*push_back)(Deque_##type *deq, type t);                                  \
 size_t data_size = 0;                                                          \
 size_t capacity = 17;                                                          \
 type data[17];                                                                 \
 int front_ptr = 0;                                                             \
 int rear_ptr = 0;                                                              \
} Deque_##type;                                                                 \
size_t sizeOfDeque_##type(Deque_##type *deq) {                                  \
  return deq->data_size;                                                        \
}                                                                               \
bool emptyOfDeque_##type(Deque_##type *deq){                                    \
  return deq->size(deq) == 0;                                                   \
}                                                                               \
void pushBackOfDeque_##type(Deque_##type *deq, type t) {                        \
  deq->data[deq->rear_ptr] = t;                                                 \
  deq->rear_ptr++;                                                              \
  deq->data_size++;                                                             \
}                                                                               \
void Deque_##type##_ctor(struct Deque_##type *deq,                              \
                        bool (*comparator)(const type &one, const type &two)) { \
  deq->comparator = comparator;                                                 \
  deq->size = &sizeOfDeque_##type;                                              \
  deq->empty = &emptyOfDeque_##type;                                            \
  deq->push_back = &pushBackOfDeque_##type;                                     \
}
