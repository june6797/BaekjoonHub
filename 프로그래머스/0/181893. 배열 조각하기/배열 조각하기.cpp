#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    for(int i = 0; i< query.size(); i++) {
        int temp = query[i];
        
        if(i % 2 == 0) {
            for(int j = 0; j < temp + 1;j++) {
                
                    answer.push_back(arr[j]);
                
            }
        }
        else {
            for(int j = temp; j < arr.size();j++) {
                
                    answer.push_back(arr[j]);
                
            }
        }
        arr.clear();
        for(int j = 0; j < answer.size(); j++) {
            arr.push_back(answer[j]);
        }
        answer.clear();
    }
    return arr;
}