#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<char> BFS(vector<vector<char>>& maze, pair<int, int> start, pair<int, int> finish) {
    vector<char> path;
    int length = maze.size();
    int width = maze[0].size();
    int changesX[4] = { -1, 1, 0, 0 };
    int changesY[4] = { 0, 0, -1, 1 };
    vector<vector<bool>> visited(length, vector<bool>(width, false));
    vector<vector<pair<int, int>>> previos(length, vector<pair<int, int>>(width, { -1, -1 }));
    queue<pair<int, int>> queuq;
    queuq.push(start);
    visited[start.first][start.second] = true;
    while (!queuq.empty()) {
        auto currentPosition = queuq.front();
        queuq.pop();
        if (currentPosition == finish) {
            pair<int, int> step = finish;
            while (step != start) {
                auto prev = previos[step.first][step.second];
                if (prev.first == step.first) {
                    path.push_back(prev.second > step.second ? 'L' : 'R');
                }
                else {
                    path.push_back(prev.first > step.first ? 'U' : 'D');
                }
                step = prev;
            }
            reverse(path.begin(), path.end());
            return path; 
        }
        for (int i = 0; i < 4; ++i) {
            int newX = currentPosition.first + changesX[i];
            int newY = currentPosition.second + changesY[i];
            if (newX >= 0 && newX < length && newY >= 0 && newY < width && !visited[newX][newY]) {
                if (maze[newX][newY] == '.' || maze[newX][newY] == 'F') {
                    visited[newX][newY] = true;
                    previos[newX][newY] = currentPosition;
                    queuq.push({ newX, newY });
                }
            }
        }
    }
    return path; 
}
int main() {
    int length, width;
    cin >> length >> width;
    vector<vector<char>> maze(length, vector<char>(width));
    pair<int, int> start, finish;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                start = { i, j };
                maze[i][j] = '.'; 
            }
            if (maze[i][j] == 'F') {
                finish = { i, j };
            }
        }
    }
    vector<char> way = BFS(maze, start, finish);
    cout << way.size() << endl;
    for (char elem : way) {
        cout << elem;
    }
    return 0;
}

