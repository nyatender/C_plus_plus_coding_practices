//#include <stdio.h>
//#include <climits>
//#include <iostream>
//#include <vector>
//#include<queue>
//#include "..\BST\treeNode.h"
//
//
//using namespace std;
//
//
//
//// ======================================================================
//// Helper function to check if a tree is BST within a given range
//bool isBSTUtil(Node* node, int min, int max) {
//    if (node == nullptr)
//        return true;
//
//    // If the current node's data 
//    // is not in the valid range, return false
//    if (node->data < min || node->data >= max)
//        return false;
//
//    if (node->left != nullptr && !isBSTUtil(node->left, node->data, min))
//        return false;
//
//    if (node->right != nullptr && !isBSTUtil(node->right, max, node->data))
//        return false;
//
//    return true;
//}
//
//// Function to check if the entire binary tree is a BST
//bool isBST(Node* root) {
//    return isBSTUtil(root, INT_MIN, INT_MAX);
//}
//// ======================================================================
//
//
//// ======================================================================
//// Recursive function to construct BST
//Node* sortedArrayToBSTRecur(vector<int>& arr,
//    int start, int end) {
//    if (start > end) return nullptr;
//
//    // Find the middle element
//    int mid = start + (end - start) / 2;
//
//    // Create root node
//    Node* root = new Node(arr[mid]);
//
//    // Create left subtree
//    root->left = sortedArrayToBSTRecur(arr, start,
//        mid - 1);
//
//    // Create right subtree
//    root->right = sortedArrayToBSTRecur(arr, mid + 1,
//        end);
//    return root;
//}
//
//Node* sortedArrayToBST(vector<int>& arr) {
//    int n = arr.size();
//    return sortedArrayToBSTRecur(arr, 0, n - 1);
//}
//
//void preOrder(Node* root) {
//    if (root == nullptr) return;
//    cout << root->data << " ";
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//int main1() {
//
//    vector<int> arr = { 1, 2, 3, 4 };
//    Node* root = sortedArrayToBST(arr);
//    preOrder(root);
//
//    return 0;
//}
//
//
//// ======================================================================
//
//// function to return the root of inverted tree
//void mirror(Node* root) {
//    if (root == nullptr)
//        return;
//
//    // Invert the left and right subtree
//    mirror(root->left);
//    mirror(root->right);
//
//    // Swap the left and right subtree
//    swap(root->left, root->right);
//}
//
//// Print tree as level order
//void levelOrder(Node* root) {
//    if (root == nullptr) {
//        cout << "N ";
//        return;
//    }
//
//    queue<Node*> qq;
//    qq.push(root);
//
//    while (!qq.empty()) {
//        Node* curr = qq.front();
//        qq.pop();
//
//        if (curr == nullptr) {
//            cout << "N ";
//            continue;
//        }
//        cout << (curr->data) << " ";
//        qq.push(curr->left);
//        qq.push(curr->right);
//    }
//}
//
//// BST Diameter and max Path Sum
//// ======================================================================
//
//
//// BST kthsSmallestNode
//// ======================================================================
//void findKthSmallest(Node* root, int i, int k, Node* result) {
//    if (root == nullptr || result != nullptr)
//        return;
//
//    findKthSmallest(root->left, i, k, result);
//    i++;
//    if (i == k) {
//        result = root;
//    }
//    findKthSmallest(root->right, i, k, result);
//}
//
//int kthSmallestElement(Node* root, int k) {
//    Node* result = nullptr;
//    //findKthSmallest(root, 0, 4, )
//    return 0;
//}