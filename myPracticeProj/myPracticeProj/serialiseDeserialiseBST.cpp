//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//// Definition of TreeNode
//template<typename T>
//struct TreeNode {
//    T data;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
//};
//
//class SerializeDeserialize {
//private:
//    static constexpr const char* MARKER = "M";
//    static int m;
//
//    static void serializeRec(TreeNode<int>* node, vector<string>& stream) {
//        if (node == nullptr) {
//            string s = to_string(m);
//            stream.push_back(string(MARKER) + s);
//            m = m + 1;
//            return;
//        }
//
//        stream.push_back(to_string(node->data));
//
//        serializeRec(node->left, stream);
//        serializeRec(node->right, stream);
//    }
//
//    static TreeNode<int>* deserializeHelper(vector<string>& stream) {
//        if (stream.empty()) return nullptr;
//
//        string val = stream.front();
//        stream.pop_back();
//
//        if (val[0] == MARKER[0]) {
//            return nullptr;
//        }
//
//        TreeNode<int>* node = new TreeNode<int>(stoi(val));
//        node->left = deserializeHelper(stream);
//        node->right = deserializeHelper(stream);
//
//        return node;
//    }
//
//public:
//    static vector<string> serialize(TreeNode<int>* root) {
//        vector<string> stream;
//        serializeRec(root, stream);
//        return stream;
//    }
//
//    static TreeNode<int>* deserialize(vector<string> stream) {
//        reverse(stream.begin(), stream.end());
//        return deserializeHelper(stream);
//    }
//};
//
//// Initialize static variable
//int SerializeDeserialize::m = 1;
//
//
//// Example usage
//int main() {
//    // Constructing a small test tree
//    TreeNode<int>* root = new TreeNode<int>(10);
//    root->left = new TreeNode<int>(20);
//    root->right = new TreeNode<int>(30);
//    root->left->left = new TreeNode<int>(40);
//    root->right->left = new TreeNode<int>(50);
//
//    vector<string> serialized = SerializeDeserialize::serialize(root);
//
//    cout << "Serialized Tree: ";
//    for (auto& s : serialized) {
//        cout << s << " ";
//    }
//    cout << endl;
//
//    TreeNode<int>* deserializedRoot = SerializeDeserialize::deserialize(serialized);
//
//    cout << "Deserialized Root Value: " << deserializedRoot->data << endl;
//
//    
//    return 0;
//}
