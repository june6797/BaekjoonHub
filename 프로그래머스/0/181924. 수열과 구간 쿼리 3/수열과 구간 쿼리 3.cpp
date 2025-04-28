#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(int i = 0; i< queries.size();i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int x = arr[a];
        int y = arr[b];
        arr[a] = y;
        arr[b] = x;
    }
    answer = arr;
    return answer;
}