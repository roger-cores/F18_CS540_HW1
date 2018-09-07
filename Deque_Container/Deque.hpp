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
void Deque_##type##_reallocate(Deque_##type *deq);                              \
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
 void (*push_front)(Deque_##type *deq, type t);                                 \
 void (*pop_front)(Deque_##type *deq);                                          \
 void (*pop_back)(Deque_##type *deq);                                           \
 void (*clear)(Deque_##type *deq);                                              \
 void (*dtor)(Deque_##type *deq);                                                \
 type& (*at)(Deque_##type *deq, int index);                                     \
 type& (*front)(Deque_##type *deq);                                             \
 type& (*back)(Deque_##type *deq);                                              \
 Deque_##type##_Iterator (*begin)(Deque_##type *deq);                           \
 Deque_##type##_Iterator (*end)(Deque_##type *deq);                             \
 size_t data_size = 0;                                                          \
 size_t capacity = 17;                                                          \
 type *data;                                                                    \
 int front_ptr = 0;                                                             \
 int rear_ptr = 0;                                                              \
 char *type_name;                                                               \
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
  if(deq->data_size == deq->capacity-1) {                                       \
    Deque_##type##_reallocate(deq);                                             \
  }                                                                             \
  deq->data[deq->rear_ptr] = t;                                                 \
  deq->rear_ptr = mask(deq->rear_ptr, deq->capacity, 1);                        \
  deq->data_size++;                                                             \
}                                                                               \
                                                                                \
void pushFrontOfDeque_##type(Deque_##type *deq, type t) {                       \
  if(deq->data_size == deq->capacity-1) {                                       \
    Deque_##type##_reallocate(deq);                                             \
  }                                                                             \
  deq->front_ptr = mask(deq->front_ptr, deq->capacity, 0);                      \
  deq->data[deq->front_ptr] = t;                                                \
  deq->data_size++;                                                             \
}                                                                               \
                                                                                \
void popBackOfDeque_##type(Deque_##type *deq) {                                 \
  if(deq->empty(deq) == 1) {                                                    \
    return;                                                                     \
  } else {                                                                      \
    deq->rear_ptr = mask(deq->rear_ptr, deq->capacity, 0);                      \
    deq->data_size--;                                                           \
  }                                                                             \
}                                                                               \
                                                                                \
void popFrontOfDeque_##type(Deque_##type *deq) {                                \
  if(deq->empty(deq) == 1) {                                                    \
    return;                                                                     \
  } else {                                                                      \
    deq->front_ptr = mask(deq->front_ptr, deq->capacity, 1);                    \
    deq->data_size--;                                                           \
  }                                                                             \
}                                                                               \
                                                                                \
type& atOfDeque_##type(Deque_##type *deq, int index) {                          \
  int start = deq->front_ptr;                                                   \
  start += index;                                                               \
  if(start > deq->capacity-1) {                                                 \
    start = start - deq->capacity;                                              \
  }                                                                             \
  return deq->data[start];                                                      \
}                                                                               \
                                                                                \
type& backOfDeque_##type(Deque_##type *deq) {                                    \
  return deq->data[mask(deq->rear_ptr, deq->capacity, 0)];                      \
}                                                                               \
                                                                                \
type& frontOfDeque_##type(Deque_##type *deq) {                                   \
  return deq->data[deq->front_ptr];                                             \
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
void clearFor_##type(Deque_##type *deq) {                                       \
  deq->capacity = 17;                                                           \
  deq->data_size = 0;                                                           \
  deq->front_ptr = 0;                                                           \
  deq->rear_ptr = 0;                                                            \
}                                                                               \
                                                                                \
void dtorFor_##type(Deque_##type *deq) {                                        \
  deq->clear(deq);                                                              \
  free(deq->data);                                                              \
  deq->data = (type*) calloc(deq->capacity, sizeof(type));                      \
}                                                                               \
                                                                                \
void Deque_##type##_ctor(struct Deque_##type *deq,                              \
                        bool (*comparator)(const type &one, const type &two)) { \
  deq->data = (type*) calloc(deq->capacity, sizeof(type));                      \
  deq->comparator = comparator;                                                 \
  deq->size = &sizeOfDeque_##type;                                              \
  deq->empty = &emptyOfDeque_##type;                                            \
  deq->push_back = &pushBackOfDeque_##type;                                     \
  deq->push_front = &pushFrontOfDeque_##type;                                   \
  deq->at = &atOfDeque_##type;                                                  \
  deq->end = &endOf_##type;                                                     \
  deq->begin = &beginOf_##type;                                                 \
  deq->front = &frontOfDeque_##type;                                            \
  deq->back = &backOfDeque_##type;                                              \
  deq->pop_back = &popBackOfDeque_##type;                                       \
  deq->clear = &clearFor_##type;                                                \
  deq->dtor = &dtorFor_##type;                                                  \
  deq->pop_front = &popFrontOfDeque_##type;                                     \
  char deque_prefix[7] = "Deque_";                                              \
  deq->type_name = (char *) malloc(sizeof(#type) + sizeof(deque_prefix) + 1);   \
  deq->type_name[0] = '\0';                                                     \
  strcat(deq->type_name, deque_prefix);                                         \
  strcat(deq->type_name, #type);                                                \
}                                                                               \
                                                                                \
bool Deque_##type##_Iterator_equal(Deque_##type##_Iterator it_current,          \
                                   Deque_##type##_Iterator it_end) {            \
  return &it_current.deref(&it_current) == &it_end.deref(&it_end);              \
}                                                                               \
                                                                                \
void Deque_##type##_reallocate(Deque_##type *deq) {                             \
  deq->capacity = ((deq->capacity-1) * 2) + 1;                                  \
  type *data = (type*) calloc(deq->capacity, sizeof(type));                     \
  int i = 0;                                                                    \
  for (Deque_##type##_Iterator it = deq->begin(deq);                            \
       !Deque_##type##_Iterator_equal(it, deq->end(deq)); it.inc(&it)) {        \
      data[i] = it.deref(&it);                                                  \
      i++;                                                                      \
  }                                                                             \
  deq->front_ptr = 0;                                                           \
  deq->rear_ptr = i;                                                            \
                                                                                \
  free(deq->data);                                                              \
  deq->data = data;                                                             \
}                                                                               \
                                                                                \
bool Deque_##type##_equal(Deque_##type deq1, Deque_##type deq2) {               \
  bool result = true;                                                           \
  result = result && (deq1.comparator == deq2.comparator);                      \
  result = result && (deq1.size(&deq1) == deq2.size(&deq2));                    \
  Deque_##type##_Iterator it1;                                                  \
  Deque_##type##_Iterator it2;                                                  \
  for(it1 = deq1.begin(&deq1), it2 = deq2.begin(&deq2);                         \
      !Deque_##type##_Iterator_equal(it1, deq1.end(&deq1)) &&                   \
      !Deque_##type##_Iterator_equal(it2, deq2.end(&deq2));                     \
      it1.inc(&it1), it2.inc(&it2)) {                                           \
        result = result &&                                                      \
        (deq1.comparator(it1.deref(&it1), it2.deref(&it2))                      \
        == deq2.comparator(it2.deref(&it2), it1.deref(&it1)));                  \
  }                                                                             \
  return result;                                                                \
}
