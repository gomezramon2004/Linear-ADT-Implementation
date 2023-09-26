#pragma once

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
        void insertAtFront(T data);
        void insertAtEnd(T data);
        ~LinkedList();
};