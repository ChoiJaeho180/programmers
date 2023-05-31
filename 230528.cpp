// https://school.programmers.co.kr/learn/courses/30/lessons/169199
#include <vector>
#include <string>
#include <queue>

int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
int map[101][101];
int visited[101][101];

struct Node {
    int row, col, dist;
    Node(int a, int b, int c) {
        row = a;
        col = b;
        dist = c;
    }
};

int solution(std::vector<std::string> board) {
    int answer = 0;
    std::queue<Node> q;
    int rowMax = board.size();
    int colMax = board[0].size();

    // MAP 생성
    for (int i = 0; i < rowMax; i++) {
        for (int j = 0; j < colMax; j++) {
            if (board[i][j] == '.') map[i + 1][j + 1] = 0;
            else if (board[i][j] == 'D') map[i + 1][j + 1] = 1;
            else if (board[i][j] == 'R') {
                q.push(Node(i + 1, j + 1, 0));
                map[i + 1][j + 1] = 0;
                visited[i + 1][j + 1] = 1;
            }
            else map[i + 1][j + 1] = 2;
        }
    }

    // BFS
    while (!q.empty()) {
        Node v = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = v.row + dr[i];
            int nc = v.col + dc[i];
            while (true) {
                // 벽이거나 맵을 벗어나거나 체크
                if (map[nr][nc] == 1 || nr < 1 || nr > rowMax || nc < 1 || nc > colMax) {
                    break;
                }

                nr += dr[i];
                nc += dc[i];
            }
            
            // 벽 이전 점, 맵 끝 반환
            nr -= dr[i];
            nc -= dc[i];

            if (map[nr][nc] == 2) {
                return v.dist + 1;
            }

            // 방문체크
            if (visited[nr][nc] != 1) {
                visited[nr][nc] = 1;
                q.push(Node(nr, nc, v.dist + 1));
            }
        }
    }

    return -1;
}