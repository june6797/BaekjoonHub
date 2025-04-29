#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> v;
    for(int i = 0; i < arr.size(); i++) {
        v.push_back(arr[i]);
    }
    while(true) {
        for(int i = 0; i < arr.size(); i++) {
            if((arr[i] >= 50) && (arr[i] % 2==0)) {
            arr[i] = arr[i] / 2;
        }
        else if(arr[i] < 50 && arr[i] % 2 == 1) {
            arr[i] *= 2;
            arr[i]++;
        }
        }
        answer++;
        bool check = true;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != v[i])
            {
                check = false;
                break;
            }
        }
        if(check) {
            return answer - 1;
        }
        v.clear();
        for(int i = 0; i < arr.size(); i++) {
        v.push_back(arr[i]);
    }
    }
    return answer;
}