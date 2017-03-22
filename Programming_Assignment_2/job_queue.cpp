#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;


class JobQueue {
private:
    
    int num_workers_;
    vector<int> jobs_;
    vector< pair<int, long long> > myPriorityQueue;

    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for(int i = 0; i < m; ++i){
            cin >> jobs_[i];
        }
        return;
    }
    
    void CreatePriorityQueue() {
        
        myPriorityQueue.clear();
        for (int i=0; i<num_workers_; i++){
            myPriorityQueue.push_back(make_pair(i, 0));
        }
        return;
    }
    
    void siftDown(int index){
        
        int minIndex = index;
        int leftChild = index*2 + 1;
        if (leftChild < (int)myPriorityQueue.size() && myPriorityQueue[leftChild].second <= myPriorityQueue[minIndex].second){
            
            if (myPriorityQueue[leftChild].second == myPriorityQueue[minIndex].second){
                if (myPriorityQueue[leftChild].first < myPriorityQueue[minIndex].first){
                    minIndex = leftChild;
                }
            }
            else {
                minIndex = leftChild;
            }
        }
        
        int rightChild = index*2 + 2;
        if (rightChild < (int)myPriorityQueue.size() && myPriorityQueue[rightChild].second <= myPriorityQueue[minIndex].second){
            
            if (myPriorityQueue[rightChild].second == myPriorityQueue[minIndex].second){
                if (myPriorityQueue[rightChild].first < myPriorityQueue[minIndex].first){
                    minIndex = rightChild;
                }
            }
            else {
                minIndex = rightChild;
            }
        }
        if (index != minIndex) {
            swap(myPriorityQueue[minIndex], myPriorityQueue[index]);
            siftDown(minIndex);
        }
        return;
    }
    
    void AssignJobs() {
        for (int i=0; i<(int)jobs_.size(); i++){
            cout << myPriorityQueue[0].first << " " << myPriorityQueue[0].second << std::endl;
            myPriorityQueue[0].second += jobs_[i];
            siftDown(0);
        }
    }
    
public:
    void Solve() {
        ReadData();
        CreatePriorityQueue();
        AssignJobs();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
