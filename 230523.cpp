#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::vector<int> l, std::vector<int> r) {
    return l[1] < r[1];
}

int solution(std::vector<std::vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), compare);

    int end = targets[0][1];
    for (int i = 1; i < targets.size(); i++) {
        if (targets[i][0] >= end) {
            end = targets[i][1];
            answer++;
        }
    }

    return answer;
}

//int main()
//{
//    vector<vector<int>> targets = { {4,5}, {4,3}, {10,14}, {11,13}, {5,12}, {3,7} };
//    solution(targets);
//}
