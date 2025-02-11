//CPP program to store vectors as values in hashmaps

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, vector<int>> createMapWithVectorsAsValues(vector<int> &values){
    unordered_map<string, vector<int>> hashMap;

    for(int i=0; i<values.size(); i++){
        if(values[i] % 2 == 0){
            hashMap["Even"].push_back(values[i]);
        }else{
            hashMap["Odd"].push_back(values[i]);
        }
    }
    return hashMap;
}



int main(){
    vector<int> values = {0,1,2,3,4,5,6,7,8,9};

    unordered_map<string, vector<int>> hashMap = createMapWithVectorsAsValues(values);

    for(const auto &pair: hashMap){
        cout<<pair.first<<": ";
        for(int num: pair.second){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}