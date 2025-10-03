#include <iostream>
#include <algorithm>
#include <climits>

struct BinaryTree {
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int val) : value(val), left(nullptr), right(nullptr) {}
    ~BinaryTree() {
        delete left;
        delete right;
    }
};

struct doubleList {
    int data;
    doubleList* left;
    doubleList* right;
    doubleList(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};



BinaryTree* bstToListUtils(BinaryTree* root, BinaryTree* pPtr, BinaryTree* droot) {
    if (root == nullptr)
        return nullptr;

    if (root->left != nullptr) {
        bstToListUtils(root->left, root, droot);
        if (droot == nullptr) {
            droot = root->left;
            droot->right = pPtr;
        }
        else {
            //root->left = pPtr;
            root->right = bstToListUtils(root->right, root, droot);
        }
    }

    //if (root->right != nullptr) {
    //    bstToListUtils(root->right, root, droot);
    //}
}

    BinaryTree* bstToList(BinaryTree * root) {
        BinaryTree* dRoot = nullptr;
        bstToListUtils(root, nullptr, dRoot);
        return dRoot;
    }