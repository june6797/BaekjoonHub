#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    if(a == b && b ==c) {
        
        return(a + b + c) * (a * a + b * b +c* c) * (a*a*a + b*b*b + c*c*c);
    }
    else if( a== b) {
        
        return(a + b + c) * (a * a + b * b +c* c);
    }
    else if( a== c) {
        
        return(a + b + c) * (a * a + b * b +c* c);
    }
    else if(b ==c) {
        return(a + b + c) * (a * a + b * b +c* c);
    }
    else {
        return a + b +c;
    }
    return answer;
}