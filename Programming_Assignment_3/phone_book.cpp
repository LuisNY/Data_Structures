#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    
    return queries;
}


void poulateTable(vector<string> &hashTable, vector<Query> allQueries){
    
    for (size_t i=0; i<allQueries.size(); i++){
        
        if (allQueries[i].type == "add") {
            hashTable[allQueries[i].number] = allQueries[i].name;
        }
        else if (allQueries[i].type == "del") {
            hashTable[allQueries[i].number] = "";
        }
        else {
            if (hashTable[allQueries[i].number] != "")
                cout << hashTable[allQueries[i].number] << endl;
            else
                cout << "not found" << endl;
        }
    }
    return;
}

int main() {
    
    vector<Query> allQueries = read_queries();
    vector<string> myHashTable(10000000);
    poulateTable(myHashTable, allQueries);
    
    return 0;
}
