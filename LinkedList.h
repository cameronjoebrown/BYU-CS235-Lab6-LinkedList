//
//  LinkedList.h
//  Lab6
//
//  Created by Cam on 11/12/18.
//  Copyright © 2018 Cameron Brown. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>
#include "LinkedListInterface.h"
//#include <stdexcept>

using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface <T> {
public:
    struct Node {
        T value;
        Node* next;
    };
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }
    ~LinkedList() {
        clear();
    }
    void insertHead(T value) {
        
    }
    void insertTail(T value) {
        
    }
    void insertAfter(T value, T insertionNode);
    void remove(T value);
    void clear();
    T at(int index);
    int size();
    string toString();
    Node* find(T value) {
        Node* temp;
        for(temp = head; temp != nullptr; temp=temp->next){
            if(temp->value == value) {
                return temp;
            }
            return nullptr;
        }
    }
protected:
    
    
private:
    Node* head;
    Node* tail;
    int listSize;
};

#endif /* LinkedList_h */
