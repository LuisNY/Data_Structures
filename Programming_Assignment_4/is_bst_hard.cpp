#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
    int key;
    int left;
    int right;
};

class Tree {
    
    int nodes;
    vector<int> key;
    vector<int> left;
    vector<int> right;
    vector<Node> tempKey;
    int flag = 0;
    
public:
    
    Tree(int nodes) {
        this->nodes = nodes;
        this->key.resize(nodes);
        this->left.resize(nodes);
        this->right.resize(nodes);
    }
    
    void read() {
        for (int i = 0; i < nodes; ++i) {
            int key, left, right;
            cin >> key;
            this->key[i] = key;
            cin >> left;
            this->left[i] = left;
            cin >> right;
            this->right[i] = right;
        }
    }
    
    bool IsBinarySearchTree() {
        
        if (nodes>0)
            inOrderTraversal(0);
        
        if (flag == 1){
            return false;
        }
        
        return true;
    }
    
    int inOrderTraversal(int x){
        
        if (x==-1)
            return -1;
        
        inOrderTraversal(left[x]);
        
        Node myNode;
        myNode.key = key[x];
        myNode.left = left[x];
        myNode.right = right[x];
        
        tempKey.push_back(myNode);
        if (tempKey.size()>1) {
            if(tempKey[tempKey.size()-2].key > tempKey[tempKey.size()-1].key) {
                flag=1;
                return -1;
            }
            else if (tempKey[tempKey.size()-2].key == tempKey[tempKey.size()-1].key){
                if (this->key[tempKey[tempKey.size()-1].left] == tempKey[tempKey.size()-2].key) {
                    flag=1;
                    return -1;
                }
            }
        }
        
        inOrderTraversal(right[x]);
        
        return 0;
    }
};


int main() {
    int nodes;
    cin >> nodes;
    Tree tree(nodes);
    tree.read();
    
    if (tree.IsBinarySearchTree()) {
        cout << "CORRECT" << endl;
    } else {
        cout << "INCORRECT" << endl;
    }
    return 0;
}
