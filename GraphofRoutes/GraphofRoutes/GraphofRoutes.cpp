#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int stops, routes, numberOfStops;
    cin >> stops >> routes;
    vector<vector<int>>firstGraph(stops, vector<int>(stops, 0));
    vector<vector<int>>secondGraph(stops, vector<int>(stops, 0));
    for (int i = 0; i != routes; ++i) {
        cin >> numberOfStops;
        vector<int>stops(numberOfStops);
        for (int k = 0; k != numberOfStops; ++k) {
            cin >> stops[k];
        }
        for (int j = 1; j != numberOfStops; ++j) {
            firstGraph[stops[j - 1] - 1][stops[j] - 1] = 1;
            firstGraph[stops[j] - 1][stops[j - 1] - 1] = 1;
        }
        for (int z = 0; z != numberOfStops; ++z) {
            for (int s = 0; s != numberOfStops; ++s) {
                secondGraph[stops[z] - 1][stops[s] - 1] = 1;
            }
        }
    }
    for (const auto& halts : firstGraph) {
        for (size_t i = 0; i < halts.size(); ++i) {
            cout << halts[i];
            if (i < halts.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i != stops; ++i) {
        secondGraph[i][i] = 0;
    }
    for (const auto& halts : secondGraph) {
        for (size_t i = 0; i < halts.size(); ++i) {
            cout << halts[i];
            if (i < halts.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}