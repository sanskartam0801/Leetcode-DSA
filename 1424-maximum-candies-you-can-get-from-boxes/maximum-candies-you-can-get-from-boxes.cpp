class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> hasKey(n, false);
        vector<bool> hasBox(n, false);
        vector<bool> used(n, false);
        queue<int> q;
        int totalCandies = 0;

        for (int box : initialBoxes) {
            hasBox[box] = true;
        }

        for (int i = 0; i < n; ++i) {
            if (hasBox[i] && (status[i] || hasKey[i])) {
                q.push(i);
                used[i] = true;
            }
        }

        while (!q.empty()) {
            int box = q.front(); q.pop();
            totalCandies += candies[box];

            // Get keys from the current box
            for (int key : keys[box]) {
                if (!hasKey[key]) {
                    hasKey[key] = true;
                    if (hasBox[key] && !used[key] && status[key] == 0) {
                        q.push(key);
                        used[key] = true;
                    }
                }
            }

            // Get boxes inside the current box
            for (int contained : containedBoxes[box]) {
                hasBox[contained] = true;
                if ((status[contained] || hasKey[contained]) && !used[contained]) {
                    q.push(contained);
                    used[contained] = true;
                }
            }
        }

        return totalCandies;
    }
};
