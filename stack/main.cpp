//
//  main.cpp
//  stack
//
//  Created by Jedidiah Uchenna on 04.12.2022.
//

#include "stack/stack.hpp"
#include <iostream>


int main(int argc, const char * argv[])
{
    int a[100] {0};
    for(int i = 0; i < 100; i++) a[i] = (i * i) - (3 * i);
    Stack<int> test;
    //Arr::Stack<int> test;
    //LL::Stack<int> test;
    for(int i = 0; i < 100; i++) test.push(a[i]);
    std::cout << "1:\n";
    for(int i = 0; i < 100; i++) std::cout << test.pop() << ", ";
    for(int i = 0; i < 100; i++) test.push(a[i]);
    std::cout << "\n2:\n";
    for(int i = 0; i < 100; i++) std::cout << test.peek(i+1) << ", ";
    std::cout << "\n3:\n";
    for(int i = 0; i < 100; i++) std::cout << test.pop() << ", ";
    std::cout << "\n" << test.getSize() << "\n";
    
    return 0;
}
