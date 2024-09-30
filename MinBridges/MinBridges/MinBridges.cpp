#include <iostream>
#include <vector>
using namespace std;
void DFS(int x, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[x] = true;
    for (int y : graph[x]) {
        if (!visited[y]) {
            DFS(y, graph, visited);
        }
    }
}
int main() {
    int islands, bridges;
    cin >> islands >> bridges;
    vector<vector<int>> graph(islands);
    for (int i = 0; i != bridges; ++i) {
        int island1, island2;
        cin >> island1 >> island2;
        --island1; --island2;
        graph[island1].push_back(island2);
        graph[island2].push_back(island1);
    }
    vector<bool> visited(islands, false);
    vector<int> components;
    int count = 0;
    for (int i = 0; i != islands; ++i) { 
        if (!visited[i]) {
            ++count;
            components.push_back(i);
            DFS(i, graph, visited);
        }
    }
    if (count == 1) {
        cout << 0 << endl;
    }
    else {
        cout << count - 1 << endl;
        for (int i = 1; i != components.size(); ++i) {
            cout << components[i - 1] + 1 << " " << components[i] + 1 << endl;
        }
    }
    return 0;
}



