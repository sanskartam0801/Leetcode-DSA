class Solution {
public:
    int find(int x, vector<int>& parent) {
        if(parent[x] != x)
            parent[x] = find(parent[x], parent); // path compression
        return parent[x];
    }

    void unionSet(int x, int y, vector<int>& parent) {
        int px = find(x, parent);
        int py = find(y, parent);
        if(px == py) return;

        // Always attach the larger root to the smaller one (lexicographically smallest)
        if(px < py) parent[py] = px;
        else parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for(int i = 0; i < 26; i++) parent[i] = i;

        for(int i = 0; i < s1.size(); i++) {
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            unionSet(a, b, parent);
        }

        string result = "";
        for(char c : baseStr) {
            int rep = find(c - 'a', parent);
            result += (char)(rep + 'a');
        }
        return result;
    }
};
