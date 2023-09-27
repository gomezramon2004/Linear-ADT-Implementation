#pragma once
#include <stdexcept>

template <class T>
class Node {
    private:
        T data;
        Node<T>* next;
    public:
        Node(T data);
        T getData();
        Node<T>* getNext();
        void setData(T data);
        void setNext(Node<T>* next);
};

template <class T>
class LinkedList {
    private:
        int size;
        Node<T>* head;
    public:
        LinkedList();
        int getSize();
        Node<T>* getHead();
        void create(T data);
        T read(T data);
        bool update(T update, T data);
        bool del(T data);
        ~LinkedList();
};