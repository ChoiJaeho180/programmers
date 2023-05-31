//https://school.programmers.co.kr/learn/courses/30/lessons/178870

#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int>sequence, int k) {
	std::vector<int> answer = { 0, 0 };
	int start = 0;
	int end = 0;
	int sum = sequence[0];
	int temp = sequence.size() + 1;

	while (start <= end && end < sequence.size()) {
		if (sum < k) {
			sum += sequence[++end];
		}
		else if (sum == k) {
			if (end - start + 1 < temp) {
				temp = end - start + 1;
				answer[0] = start;
				answer[1] = end;
			}
			else if (end - start + 1 == temp) {
				if (answer[0] > start) {
					answer[0] = start;
					answer[1] = end;
				}
				sum -= sequence[start++];
			}
		}
		else {
			sum -= sequence[start++];
		}

	}

	return answer;
}
