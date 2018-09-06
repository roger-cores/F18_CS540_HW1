/*
 * Implement your functionality here without changing test.cpp
 */

int mask(int value, size_t capacity, int operation) {
  if(operation == 1) {  // Opearation Increment
    if(value == capacity-1) return 0;
    else return ++value;
  } else {              // Opearation Decrement
    if(value == 0) return capacity-1;
    else return --value;
  }
}

#define Deque_DEFINE(type)                                                      \
                                                                                \
struct Deque_##type;                                                            \
typedef struct Deque_##type##_Iterator {                                        \
  int index;                                                                    \
  Deque_##type *deq;                                                            \
  type& (*deref)(Deque_##type##_Iterator *it);                                  \
  void (*inc)(Deque_##type##_Iterator *it);                                     \
  void (*dec)(Deque_##type##_Iterator *it);                                     \
} Deque_##type##_Iterator;                                                      \
                                                                                \
typedef struct Deque_##type {                                                   \
 bool (*comparator)(const type &one, const type &two);                          \
 size_t (*size)(Deque_##type *deq);                                             \
 bool (*empty)(Deque_##type *deq);                                              \
 void (*push_back)(Deque_##type *deq, type t);                                  \
 type (*at)(Deque_##type *deq, int index);                                      \
 Deque_##type##_Iterator (*begin)(Deque_##type *deq);                           \
 Deque_##type##_Iterator (*end)(Deque_##type *deq);                             \
 size_t data_size = 0;                                                          \
 size_t capacity = 17;                                                          \
 type data[17];                                                                 \
 int front_ptr = 0;                                                             \
 int rear_ptr = 0;                                                              \
} Deque_##type;                                                                 \
                                                                                \
size_t sizeOfDeque_##type(Deque_##type *deq) {                                  \
  return deq->data_size;                                                        \
}                                                                               \
                                                                                \
bool emptyOfDeque_##type(Deque_##type *deq){                                    \
  return deq->size(deq) == 0;                                                   \
}                                                                               \
                                                                                \
void pushBackOfDeque_##type(Deque_##type *deq, type t) {                        \
  deq->data[deq->rear_ptr] = t;                                                 \
  deq->rear_ptr++;                                                              \
  deq->data_size++;                                                             \
}                                                                               \
                                                                                \
type atOfDeque_##type(Deque_##type *deq, int index) {                           \
  return deq->data[index];                                                      \
}                                                                               \
                                                                                \
type& derefOf_##type(Deque_##type##_Iterator *it) {                             \
return it->deq->data[it->index];                                                \
}                                                                               \
                                                                                \
void incOf_##type(Deque_##type##_Iterator *it) {                                \
it->index = mask(it->index, it->deq->capacity, 1);                              \
}                                                                               \
                                                                                \
void decOf_##type(Deque_##type##_Iterator *it) {                                \
it->index = mask(it->index, it->deq->capacity, 0);                              \
}                                                                               \
                                                                                \
Deque_##type##_Iterator endOf_##type(Deque_##type *deq) {                       \
  Deque_##type##_Iterator it;                                                   \
  it.deq = deq;                                                                 \
  it.index = deq->rear_ptr;                                                     \
  it.deref = &derefOf_##type;                                                   \
  it.inc = &incOf_##type;                                                       \
  it.dec = &decOf_##type;                                                       \
  return it;                                                                    \
}                                                                               \
                                                                                \
Deque_##type##_Iterator beginOf_##type(Deque_##type *deq) {                     \
  Deque_##type##_Iterator it;                                                   \
  it.deq = deq;                                                                 \
  it.index = deq->front_ptr;                                                    \
  it.deref = &derefOf_##type;                                                   \
  it.inc = &incOf_##type;                                                       \
  it.dec = &decOf_##type;                                                       \
  return it;                                                                    \
}                                                                               \
                                                                                \
void Deque_##type##_ctor(struct Deque_##type *deq,                              \
                        bool (*comparator)(const type &one, const type &two)) { \
  deq->comparator = comparator;                                                 \
  deq->size = &sizeOfDeque_##type;                                              \
  deq->empty = &emptyOfDeque_##type;                                            \
  deq->push_back = &pushBackOfDeque_##type;                                     \
  deq->at = &atOfDeque_##type;                                                  \
  deq->end = &endOf_##type;                                                     \
  deq->begin = &beginOf_##type;                                                 \
}
