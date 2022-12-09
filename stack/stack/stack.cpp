//
//  stack.cpp
//  stack that combines both linked list and array
//
//  Created by Jedidiah Uchenna on 09.12.2022.
//

#include "stack.hpp"
#include <iostream>

//default constructor: assign NULL to topNode to show the stack is empty
template <class T> Stack<T>::Stack() : stackLL(NULL)
{
    stackArr = new Arr::Stack<T>;
}
template <class T> Stack<T>::~Stack()
{
    delete stackArr;
    if(stackLL) delete stackLL;
}
//add value to stack from top
template <class T> void Stack<T>::push(const T& val)
{
    if(stackArr->isFull())
    {
        if(stackLL == NULL) stackLL = new LL::Stack<T>;
        stackLL->push(val);
    }
    else stackArr->push(val);
}
//last out: return last value added to stack and remove it from stack
template <class T> T Stack<T>::pop()
{
    if(stackLL)
    {
        T temp = stackLL->pop();
        if(stackLL->isEmpty())
        {
            delete stackLL;
            stackLL = NULL;
        }
        return temp;
    }
    else return stackArr->pop();
}
template <class T> T Stack<T>::peek(const int& pos) const
{
    int tempPos = pos;
    if(stackLL && pos <= stackLL->getSize()) return stackLL->peek(pos);
    if(stackLL && pos > stackLL->getSize()) tempPos = pos - stackLL->getSize();
    return stackArr->peek(tempPos);
}
template <class T> T Stack<T>::sTop()
{
    if(stackLL) return stackLL->sTop();
    return stackArr->sTop();
}
template <class T> int Stack<T>::getSize() const
{
    int size = 0;
    if(stackLL) size = stackLL->getSize();
    return stackArr->getSize() + size;
}

template <class T> bool Stack<T>::isFull()
{
    if(stackLL->isFull()) return true;
    return false;
}
template <class T> bool Stack<T>::isEmpty()
{
    if(stackArr->isEmpty()) return true;
    return false;
}
// explicit instantiation for template class
template class Stack<int>;

