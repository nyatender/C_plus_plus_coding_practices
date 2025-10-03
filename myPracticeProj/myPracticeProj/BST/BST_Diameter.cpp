//#include <iostream>
//#include <algorithm>
//#include <climits>
//
//struct BinaryTree {
//    int value;
//    BinaryTree* left;
//    BinaryTree* right;
//
//    BinaryTree(int val) : value(val), left(nullptr), right(nullptr) {}
//    ~BinaryTree() {
//        delete left;
//        delete right;
//    }
//};
//
//struct TreeInfo {
//    int diameter;
//    int height;
//    TreeInfo(int d, int h) : diameter(d), height(h) {}
//};
//
//TreeInfo getTreeInfo(BinaryTree* tree) {
//    if (!tree) return TreeInfo(0, 0);
//
//    TreeInfo leftInfo = getTreeInfo(tree->left);
//    TreeInfo rightInfo = getTreeInfo(tree->right);
//
//    int longestPathThroughRoot = leftInfo.height + rightInfo.height;
//    int maxDiameterSoFar = std::max(leftInfo.diameter, rightInfo.diameter);
//    int currentDiameter = std::max(longestPathThroughRoot, maxDiameterSoFar);
//    int currentHeight = 1 + std::max(leftInfo.height, rightInfo.height);
//
//    return TreeInfo(currentDiameter, currentHeight);
//}
//
//int binaryTreeDiameter(BinaryTree* tree) {
//    return getTreeInfo(tree).diameter;
//}
//
//struct NodeInfo {
//    int maxPathSoFar;
//    int maxPathSumSoFar;
//    NodeInfo(int msf, int mpssf) : maxPathSoFar(msf), maxPathSumSoFar(mpssf) {}
//};
//
//NodeInfo maxPathSumCal(BinaryTree* tree) {
//    if (!tree) return NodeInfo(0, INT_MIN);
//
//    NodeInfo left = maxPathSumCal(tree->left);
//    NodeInfo right = maxPathSumCal(tree->right);
//
//    int maxChild = std::max(left.maxPathSoFar, right.maxPathSoFar);
//    int currMaxPathFromNode = std::max(tree->value + maxChild, tree->value);
//
//    int maxPathIncludingNode = std::max(currMaxPathFromNode,
//        tree->value + left.maxPathSoFar + right.maxPathSoFar);
//    maxPathIncludingNode = std::max(maxPathIncludingNode,
//        std::max(left.maxPathSumSoFar, right.maxPathSumSoFar));
//
//    return NodeInfo(currMaxPathFromNode, maxPathIncludingNode);
//}
//
//int maxPathSum(BinaryTree* tree) {
//    return maxPathSumCal(tree).maxPathSumSoFar;
//}
//
//int main2() {
//    BinaryTree* root = new BinaryTree(1);
//    root->left = new BinaryTree(3);
//    root->right = new BinaryTree(2);
//    root->left->left = new BinaryTree(7);
//    root->left->left->left = new BinaryTree(8);
//    root->left->left->left->left = new BinaryTree(9);
//    root->left->right = new BinaryTree(4);
//    root->left->right->right = new BinaryTree(5);
//    root->left->right->right->right = new BinaryTree(6);
//
//    std::cout << binaryTreeDiameter(root) << std::endl;
//    std::cout << maxPathSum(root) << std::endl;
//
//    delete root; // This will recursively delete all nodes
//
//    return 0;
//}
