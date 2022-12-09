//
//  stack.hpp
//  stack that combines both linked list and array
//
//  Created by Jedidiah Uchenna on 09.12.2022.
//

#ifndef STACK_HPP
#define STACK_HPP

#include <stdio.h>
#include "../stackLL/stack.hpp"
#include "../stackArr/stack.hpp"

template <class T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push(const T& );
    T pop();
    T peek(const int& ) const;
    T sTop();
    int getSize() const;
    bool isFull();
    bool isEmpty();

private:
    Arr::Stack<T>* stackArr;
    LL::Stack<T>* stackLL;
};

#endif /* stack_hpp */
