//
//  stack.hpp
//  stack implementation using Array
//
//  Created by Jedidiah Uchenna on 09.12.2022.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>

namespace Arr
{
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
        int size;
        int top;
        T * arr;
    };
}

#endif /* stack_hpp */
