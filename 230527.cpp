//https://school.programmers.co.kr/learn/courses/30/lessons/172927
#include <iostream>
#include <string>
#include <vector>
#include <map>

std::map<std::string, int> m[4];


int solution(std::vector<int> picks, std::vector<std::string> minerals) {
	m[0]["diamond"] = 1, m[0]["iron"] = 1, m[0]["stone"] = 1;
	m[1]["diamond"] = 5, m[1]["iron"] = 1, m[1]["stone"] = 1;
	m[2]["diamond"] = 25, m[2]["iron"] = 5, m[2]["stone"] = 1;


	std::vector<int> tools = {};
	for (int i = 0; i < picks.size(); i++) {
		if (picks[i] == 0) {
			continue;
		}

		for (int j = 0; j < picks[i] * 5; j++) {
			tools.push_back(i);
		}
	}

	int answer = 0;
	int toolSize = tools.size();
	std::cout << toolSize << std::endl;
	for (int i = 0; i < minerals.size(); i++) {
		if (i > toolSize - 1) {
			break;
		}

		std::cout << m[tools[i]][minerals[i]] << ", ";
		answer += m[tools[i]][minerals[i]];
	}
	return answer;

}
