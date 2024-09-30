#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <set>
using namespace std;
const int INF = numeric_limits<int>::max();
struct Edge
{
    int end, weight;
};
vector<int> dijkstra(int start, const vector<vector<Edge>>& graph) {
    vector<int>distance;
    distance.assign(graph.size(), INF);
    distance[start] = 0;
    set<pair<int, int>> visited;
    visited.insert({ 0,start });
    while (!visited.empty()) {
        int currentPoint = visited.begin()->second;
        int currentDistance = visited.begin()->first;
        visited.erase(visited.begin());
        for (const Edge& edge : graph[currentPoint]) {
            int length = currentDistance + edge.weight;
            if (length < distance[edge.end]) {
                distance[edge.end] = length;
                visited.insert({ length, edge.end });
            }
        }
    }
 return distance;
}
int main()
{
    int vertices, edges, warehouse;
    cin >> vertices >> edges >> warehouse;
    vector<int>orders;
    for (int i = 0; i != 3; ++i) {
        int order;
        cin >> order;
        orders.push_back(order);
    }
    vector<vector<Edge>> graph(vertices + 1);
    for (int i = 0; i != edges; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start].push_back({end, weight});
        graph[end].push_back({start, weight});
    }
    vector<int>distance = dijkstra(warehouse,graph);
    vector<int>distOrders;
    for (int order : orders) {
        distOrders.push_back(distance[order]);
    }
    int minDist = INF;
    vector<int>bestPath;
    while (next_permutation(orders.begin(), orders.end()) == true) {
        int warehouseToFirst = dijkstra(warehouse, graph)[orders[0]];
        int FirstToSecond = dijkstra(orders[0], graph)[orders[1]];
        int SecondToThird = dijkstra(orders[1], graph)[orders[2]];
        int thirdToWarehouse = dijkstra(orders[2], graph)[warehouse];
        int currentDistance = warehouseToFirst + FirstToSecond + SecondToThird + thirdToWarehouse;
        if (currentDistance < minDist) {
            minDist = currentDistance;
            bestPath.clear();
            bestPath.push_back(warehouse);
            for (int order : orders) {
                bestPath.push_back(order);
            }
            bestPath.push_back(warehouse);
        }
    }
    cout << bestPath.size() << endl;
    for (int vertex : bestPath) {
        cout << vertex << " ";
    }
    return 0;
}

