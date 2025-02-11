//CPP program to implement a hashmap

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> createMap(vector<string> &keys, vector<int> &values){
    unordered_map<string, int> hashMap;

    if(keys.size() != values.size()){
        throw invalid_argument("Keys and Values must have same size");
    }

    for(int i=0; i<keys.size(); i++){
        hashMap[keys[i]] = values[i]; 
    }
    return hashMap;
}

int main(){
    vector<string> keys = {"one", "two", "three"};
    vector<int> values = {1, 2, 3};

    unordered_map<string, int> hashMap = createMap(keys, values);

    for(const auto &pair: hashMap){
        cout << pair.first << ": "<< pair.second << endl;
    }

    /*
        three: 3
        two: 2  
        one: 1
    */

    return 0;
}