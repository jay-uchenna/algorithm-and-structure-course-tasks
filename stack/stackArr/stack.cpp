//
//  stack.cpp
//  stack implementation using Array
//
//  Created by Jedidiah Uchenna on 09.12.2022.
//

#include "stack.hpp"
#include <iostream>

template <class T> Arr::Stack<T>::Stack():size(50),top(-1)
{
    arr = new T[size];
}
template <class T> Arr::Stack<T>::~Stack()
{
    delete [] arr;
}
//add value to stack from top
template <class T> void Arr::Stack<T>::push(const T& val)
{
    if(top+1 >= size) throw std::runtime_error("stack is full\n");
    else  arr[++top] = val;
}
//last out: return last value added to stack and remove it from stack
template <class T> T Arr::Stack<T>::pop()
{
    if(top == -1) throw std::runtime_error("stack is empty\n");
    return arr[top--];
}
template <class T> T Arr::Stack<T>::peek(const int& pos) const
{
    if(pos < 1) throw std::runtime_error("error: input should be greater than 0\n");
    if(top == -1) throw std::runtime_error("stack is empty\n");
    if(pos > top+1) throw std::runtime_error("error: input exceeds stack\n");
    return arr[top+1-pos];
}
template <class T> T Arr::Stack<T>::sTop()
{
    if(top == -1) throw std::runtime_error("stack is empty\n");
    return arr[top];
}
template <class T> int Arr::Stack<T>::getSize() const
{
    return top+1;
}

template <class T> bool Arr::Stack<T>::isFull()
{
    if(top+1 == size) return true;
    return false;
}
template <class T> bool Arr::Stack<T>::isEmpty()
{
    //std::cout << "\ntop: " << top << "\n";
    if(top == -1) return true;
    return false;
}
// explicit instantiation for template class
template class Arr::Stack<int>;

