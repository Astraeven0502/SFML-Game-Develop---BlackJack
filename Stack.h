//
// Created by astraeven on 2021/5/18.
//

#ifndef SFML_GAME_PROJECT_STACK_H
#define SFML_GAME_PROJECT_STACK_H
#include "LinkedList.h"

template <class T>
class Stack : public LinkedList<T>{

public:
    Stack();
    void push(T item);// push back
    void pop();// remove the top from stack (tail)
    //T pop() // pop function can be a "T"
    T top();// return the top one (tail)
    bool Stack_empty();// check it empty or not
    int Stack_size();// return the size
};

#include "Stack.cpp"
#endif //SFML_GAME_PROJECT_STACK_H
