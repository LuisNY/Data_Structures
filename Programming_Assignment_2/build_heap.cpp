#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
    vector<int> data_;
    vector< pair<int, int> > swaps_;
  
    void WriteResponse() const {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i) {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }
    
    void ReadData() {
        int n;
        cin >> n;
        data_.resize(n);
        for(int i = 0; i < n; ++i)
            cin >> data_[i];
    }
    
    void GenerateSwaps() {
      
        swaps_.clear();
        int N = (int)data_.size();
        for (int i=floor(N/2); i>=0; i--) {
            siftDown(i);
        }
    }
    
    void siftDown(int index){
        
        int minIndex = index;
        int leftChild = index*2 + 1;
        if (leftChild < (int)data_.size() && data_[leftChild] < data_[minIndex])
            minIndex = leftChild;
        
        int rightChild = index*2 + 2;
        if (rightChild < (int)data_.size() && data_[rightChild] < data_[minIndex])
            minIndex = rightChild;
        
        if (index != minIndex) {
            swap(data_[minIndex], data_[index]);
            swaps_.push_back(make_pair(index, minIndex));
            siftDown(minIndex);
        }
        return;
    }

 
public:
    void Solve() {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
