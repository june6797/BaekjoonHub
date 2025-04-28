#include <string>
#include <vector>

using namespace std;

bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = true;
    bool a = x1 || x2;
    bool b = x3 || x4;
    answer = a && b;
    return answer;
}