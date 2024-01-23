//
// Created by astraeven on 2021/5/18.
//

#ifndef SFML_GAME_PROJECT_LINKEDLIST_H
#define SFML_GAME_PROJECT_LINKEDLIST_H
#include "Node.h"
#include <iostream>

template <class T>
class LinkedList {

private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int _size = 0;
    void insertBefore(T item, Node<T>* node);
    void insertAfter(T item, Node<T>* node);
    void remove(Node<T>* node);
    Node<T>* search(T item);

public:
    LinkedList();
    LinkedList(const LinkedList& list);
    ~LinkedList();
    void insertBefore(T item, T before);
    void insertAfter(T item, T after);
    void remove(T item);
    void push_back(T item);
    void push_front(T item);
    int size();
    bool empty();

    void remove_tail();
    T getTail();

    template<class S>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list);

    void operator+=(T item);

    LinkedList& operator=(const LinkedList& list);
};

#include "LinkedList.cpp"
#endif //SFML_GAME_PROJECT_LINKEDLIST_H
