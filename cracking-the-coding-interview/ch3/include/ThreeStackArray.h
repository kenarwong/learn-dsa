#ifndef THREE_STACK_ARRAY_H
#define THREE_STACK_ARRAY_H

#include "headers.h"

const int DEFAULT_STACK_CAPACITY = 10;

template <class T>
class ThreeStackArray
{
public:
  ThreeStackArray();
  ThreeStackArray(int stackCapacity);
  ~ThreeStackArray();
  bool push(int stack, const T &item);
  bool pop(int stack);
  T peek(int stack);
  bool isEmpty(int stack);

private:
  int m_stackCapacity;
  T *arr;
  int top[3] = {0, 0, 0};

  void checkStack(int stack)
  {
    if (stack < 0 || stack >= 3)
    {
      throw std::invalid_argument("Invalid stack number");
    }
  }
};

template <class T>
inline ThreeStackArray<T>::ThreeStackArray()
{
  m_stackCapacity = DEFAULT_STACK_CAPACITY;
  arr = new T[m_stackCapacity * 3];

  for (int i = 0; i < 3; i++)
  {
    top[i] = i * m_stackCapacity;
  }
}

template <class T>
inline ThreeStackArray<T>::ThreeStackArray(int stackCapacity)
{
  m_stackCapacity = stackCapacity;
  arr = new T[m_stackCapacity * 3];

  for (int i = 0; i < 3; i++)
  {
    top[i] = i * m_stackCapacity;
  }
}

template <class T>
inline ThreeStackArray<T>::~ThreeStackArray()
{
  delete[] arr;
}

template <class T>
inline bool ThreeStackArray<T>::push(int stack, const T &item)
{
  checkStack(stack);

  if (top[stack] < ((stack + 1) * m_stackCapacity))
  {
    arr[top[stack]] = item;
    top[stack]++;
    return true;
  }

  return false;
}

template <class T>
inline bool ThreeStackArray<T>::pop(int stack)
{
  checkStack(stack);

  if (isEmpty(stack))
  {
    return false;
  }

  // T item = arr[top[stack]];
  top[stack]--;
  return true;
}

template <class T>
inline T ThreeStackArray<T>::peek(int stack)
{
  checkStack(stack);
  if (isEmpty(stack)) {
    throw std::invalid_argument("Stack is empty");
  }
  return arr[top[stack]-1];
}

template <class T>
inline bool ThreeStackArray<T>::isEmpty(int stack)
{
  checkStack(stack);

  return top[stack] == stack * m_stackCapacity;
}

#endif