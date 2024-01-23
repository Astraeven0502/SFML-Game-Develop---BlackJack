//
// Created by astraeven on 2021/5/18.
//
#ifndef SFML_GAME_PROJECT_STACK_CPP
#define SFML_GAME_PROJECT_STACK_CPP
#include "Stack.h"

template <class T>
Stack<T>::Stack()
{

}

template <class T>
void Stack<T>::push(T item)
{
    this->push_back(item);
}

template <class T>
void Stack<T>::pop()
{
    this->remove_tail();
}

template <class T>
T Stack<T>::top()
{
    return this->getTail();
}

template <class T>
bool Stack<T>::Stack_empty()
{
    return this->empty();
}

template <class T>
int Stack<T>::Stack_size()
{
    return this->size();
}

#endif //SFML_GAME_PROJECT_STACK_CPP