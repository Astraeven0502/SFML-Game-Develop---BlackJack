//
// Created by astraeven on 2021/5/18.
//
#ifndef SFML_GAME_PROJECT_LINKEDLIST_CPP
#define SFML_GAME_PROJECT_LINKEDLIST_CPP
#include "LinkedList.h"

//private
template <class T>
void LinkedList<T>::insertBefore(T item, Node<T>* node)
{
    if (node != head)
    {
        _size++;
        Node<T> *n = new Node<T>;
        Node<T> *walker;
        walker = head;
        while (walker->next != node)
            walker = walker->next;
        n->next = node;
        walker->next = n;
        n->data = item;
    }
    else
        push_front(item);
}
template <class T>
void LinkedList<T>::insertAfter(T item, Node<T>* node)
{
    if (node != tail)
    {
        _size++;
        Node<T> *n = new Node<T>;
        Node<T> *walker;
        walker = head;
        while (walker != node)
            walker = walker->next;
        n->next = walker->next;
        walker->next = n;
        n->data = item;
    }
    else
        push_back(item);
}
template <class T>
void LinkedList<T>::remove(Node<T>* node)
{
    if (node == head && node == tail)
    {
        _size--;
        head = nullptr;
        tail = nullptr;
        delete node;
    }
    else if (node == head)
    {
        _size--;
        head = head->next;
        delete node;
    }
    else if (node == tail)
    {
        _size--;
        Node<T> *walker;
        walker = head;
        while (walker->next != node)
            walker = walker->next;
        tail = walker;
        tail->next = nullptr;
        delete node;
    }
    else if (node != nullptr)
    {
        _size--;
        Node<T> *prevNode, *nextNode;
        prevNode = head;
        nextNode = head;
        while (prevNode->next != node)
            prevNode = prevNode->next;
        nextNode = node->next;
        prevNode->next = nextNode;
        delete node;
    }
}
template <class T>
Node<T>* LinkedList<T>::search(T item)
{
    Node<T>* walker = head;
    while (walker != nullptr && walker->data != item)
    {
        walker = walker->next;
    }
    return walker;
}

//public
template <class T>
void LinkedList<T>::insertBefore(T item, T before)
{
    Node<T> *node = search(before);
    if (node == nullptr) // if there is no "before" in linked list
    {
        std::cout << "Error, Do not have " << before << " in Linked List" << std::endl;
    }
    else
    {
        insertBefore(item, node);
    }
}
template <class T>
void LinkedList<T>::insertAfter(T item, T after)
{
    Node<T> *node = search(after);
    if (node == nullptr) // if there is no "after" in linked list
    {
        std::cout << "Error, Do not have " << after << " in Linked List" << std::endl;
    }
    else
    {
        insertAfter(item, node);
    }
}
template <class T>
void LinkedList<T>::remove(T item)
{
    Node<T> *target = search(item);
    if (target != nullptr)
        remove(target);
}
template <class T>
void LinkedList<T>::push_back(T item)
{
    _size++;
    if (empty()) //if there is nothing
    {
        Node<T> *n = new Node<T>;
        n->next = nullptr;
        head = n;
        tail = n;
        n->data = item;
    }
    else
    {
        Node<T> *n = new Node<T>;
        n->next = nullptr;
        tail->next = n;
        tail = n;
        n->data = item;
    }
}
template <class T>
void LinkedList<T>::push_front(T item)
{
    _size++;
    if (empty())//if there is nothing
    {
        Node<T> *n = new Node<T>;
        n->next = nullptr;
        head = n;
        tail = n;
        n->data = item;
    }
    else
    {
        Node<T> *n = new Node<T>;
        n->next = head;
        head = n;
        n->data = item;
    }
}
template <class T>
int LinkedList<T>::size()
{
    return _size;
}
template <class T>
bool LinkedList<T>::empty()
{
    if(head == nullptr && tail == nullptr)
        return true;
    else
        return false;
}

template <class T>
void LinkedList<T>::remove_tail()
{
    if (!empty())
        remove(tail);
}

template <class T>
T LinkedList<T>::getTail()
{
    if (!empty())
        return tail->data;
}



//--------------------Operator---------------------------------------------------------//
template <class T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
{
    Node<T>* walker;
    int count = 1;
    walker = list.head;

    while(walker != nullptr)
    {
        out << "Node " << count << ": ";
        out << walker->data << std::endl;
        walker = walker->next;
        count++;
    }
    return out;
}

template <class T>
void LinkedList<T>::operator+=(T item)
{
    LinkedList::push_back(item);
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list)
{
    if (this == &list)
        return *this;
    this->~LinkedList();
    head = nullptr;
    tail = nullptr;


    Node<T> *temp = list.head;
    while (temp != nullptr)
    {
        this->push_back(temp->data);
        temp = temp->next;
    }
    return *this;

//    if(head != list.head)
//        this->~LinkedList<T>();
//    for(int i = 0; i < list.size(); i++)
//    {
//
//    }
    //delete data from the left side, only if it is not the same object as the right side
    //make sure head and tail are point to node pointer
    //copy all node data from the source to target
    //return a linked list
}
//--------------------Operator---------------------------------------------------------//


//--------------------Constructor------------------------------------------------------//
template <class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr)
{

}
template <class T>
LinkedList<T>::LinkedList(const LinkedList& list) : LinkedList()
{
    *this = list;
}
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *walker;
    walker = head;
    while (walker != nullptr)
    {
        walker = walker->next;
        delete head;
        head = walker;
    }
}
//--------------------Constructor------------------------------------------------------//

#endif //SFML_GAME_PROJECT_LINKEDLIST_CPP