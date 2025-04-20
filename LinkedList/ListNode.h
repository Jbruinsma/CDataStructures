//
// Created by justi on 4/20/2025.
//

#ifndef LISTNODE_H
#define LISTNODE_H


template<typename T>
class ListNode {
private:
    T val;
    ListNode<T>* prev;
    ListNode<T>* next;
public:
    ListNode(T value) {
        val = value;
        this->prev = nullptr;
        this->next = nullptr;
    }

    T getVal() const {
        return val;
    }

    ListNode<T>* getPrev() const {
        return prev;
    }

    ListNode<T>* getNext() const {
        return next;
    }

    void setVal(T value) {
        val = value;
    }

    void setPrev(ListNode<T>* previous_node) {
        prev = previous_node;
    }

    void setNext(ListNode<T>* next_node) {
        next = next_node;
    }

};



    #endif //LISTNODE_H
