#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

class TreeOrders {
  
public:
    int n;
    vector <int> key;
    vector <int> left;
    vector <int> right;

    void read() {
        cin >> n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> key[i] >> left[i] >> right[i];
        }
    }
    
    vector <int> in_order() {
        vector<int> result;
        inOrderTraversal(0);
        cout << std::endl;
        return result;
    }
    
    void inOrderTraversal(int x){
        if (x!=-1){
            inOrderTraversal(left[x]);
            cout << key[x] << " ";
            inOrderTraversal(right[x]);
        }
    }
  
    vector <int> pre_order() {
        vector<int> result;
        preOrderTraversal(0);
        cout << std::endl;
        return result;
    }
    
    void preOrderTraversal(int x){
        if (x!=-1){
            cout << key[x] << " ";
            preOrderTraversal(left[x]);
            preOrderTraversal(right[x]);
        }
    }

    vector <int> post_order() {
        vector<int> result;
        postOrderTraversal(0);
        cout << std::endl;
        return result;
    }
    
    void postOrderTraversal(int x){
        if (x!=-1){
            postOrderTraversal(left[x]);
            postOrderTraversal(right[x]);
            cout << key[x] << " ";
        }
    }
};



int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
    
  t.in_order();
  t.pre_order();
  t.post_order();
  return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
    
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}
