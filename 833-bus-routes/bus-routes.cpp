class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stationToBuses;
        int n = routes.size();

        // Map station → buses that go through it
        for (int i = 0; i < n; ++i) {
            for (int station : routes[i]) {
                stationToBuses[station].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visitedStations;
        vector<bool> visitedBus(n, false);

        q.push(source);
        visitedStations.insert(source);
        int busesTaken = 0;

        while (!q.empty()) {
            int sz = q.size();
            busesTaken++;

            while (sz--) {
                int currStation = q.front();
                q.pop();

                for (int bus : stationToBuses[currStation]) {
                    if (visitedBus[bus]) continue;
                    visitedBus[bus] = true;

                    for (int nextStation : routes[bus]) {
                        if (nextStation == target) return busesTaken;
                        if (visitedStations.find(nextStation) == visitedStations.end()) {
                            visitedStations.insert(nextStation);
                            q.push(nextStation);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
