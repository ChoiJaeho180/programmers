//https://school.programmers.co.kr/learn/courses/30/lessons/181187
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int i = 1; i <= r2; i++) {
        for (int j = 0; j <= r2; j++) {
            float dis = sqrt(pow(i, 2) + pow(j, 2));
            if (r2 >= dis && dis >= r1) {
                answer += 1;
            }
        }
    }
    return answer * 4;
}