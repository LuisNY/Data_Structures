#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Tree {
    
    int nodes;
    vector<int> key;
    vector<int> left;
    vector<int> right;
    vector<int> tempKey;
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
        
        tempKey.push_back(key[x]);
        if (tempKey.size()>1) {
            if(tempKey[tempKey.size()-2] > tempKey[tempKey.size()-1]) {
                flag=1;
                return -1;
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
