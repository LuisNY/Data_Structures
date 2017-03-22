#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using std::string;
using std::vector;
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::iterator;

struct Query {
    string type, str;
    size_t index;
};

class QueryProcessor {
    
    int bucketCount;
    vector<list<string>> hashTable;
    vector<Query> queries;
    
    size_t hash_func(const string &s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucketCount;
    }

public:
    
    QueryProcessor(int bucketCount, const vector<list<string>> &hashTable, const vector<Query> &queries) {
        this->bucketCount = bucketCount;
        this->hashTable = hashTable;
        this->queries = queries;
    }
    
    void processQueries() {
        
        for (size_t i=0; i<queries.size(); i++) {
            
            bool found = false;
            if (queries[i].type == "add"){
                
                size_t index = hash_func(queries[i].str);
                for (std::list<string>::iterator it = hashTable[index].begin(); it != hashTable[index].end(); it++){
                    
                    if (*it == queries[i].str){
                        found = true;
                    }
                }
                if (!found)
                    hashTable[index].push_front(queries[i].str);
            }
            
            else if (queries[i].type == "del"){
                
                size_t index = hash_func(queries[i].str);
                hashTable[index].remove(queries[i].str);
            }
            
            else if (queries[i].type == "find"){
                size_t index = hash_func(queries[i].str);
                for (std::list<string>::iterator it = hashTable[index].begin(); it != hashTable[index].end(); it++){
                    
                    if (*it == queries[i].str){
                        found = true;
                    }
                }
                if (found)
                    cout << "yes" << endl;
                else
                    cout << "no" << endl;
            }
            
            else {
                
                int index = (int)queries[i].index;
                
                if (hashTable[index].empty())
                    cout << endl;
                else {
                    for (std::list<string>::iterator it = hashTable[index].begin(); it != hashTable[index].end(); it++){
                        cout << *it << " ";
                    }
                    cout << endl;
                }
            }
        }
        
        return;
    }
};


vector<Query> readQueries() {
    int n;
    cin >> n;
    vector<Query> myQueries(n);
    for (int i = 0; i < n; i++){
        cin >> myQueries[i].type;
        if (myQueries[i].type != "check") {
            cin >> myQueries[i].str;
        } else {
            cin >> myQueries[i].index;
        }
    }
    return myQueries;
}


int main() {
    
    int bucket_count;
    cin >> bucket_count;
    
    vector<list<string>> myHashTable(bucket_count);
    vector<Query> myQueries = readQueries();
    QueryProcessor myProcessor(bucket_count, myHashTable, myQueries);
    myProcessor.processQueries();

    return 0;
}
