#include<list>
#ifndef ONE_H
#define ONE_H
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int) {
        this->left = nullptr;
        this->right = nullptr;
    }
}; 

//class NestedInteger {
//public:
//    virtual bool isInteger() = 0;
//    virtual list<NestedInteger>& getList() = 0;
//    virtual int getIntegerValue() = 0;
//};
#endif
#pragma once
