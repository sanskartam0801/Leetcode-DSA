class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        vector<int>ans;
        for(int i=1;i<=8;i++) q.push(i);

        while(!q.empty()){
            int num = q.front(); q.pop();
            if(num>=low && num<=high) ans.push_back(num);
            int last = num%10;
            if(last==9) continue;
            int next = num*10 + (last+1);
            if(next>high) continue;
            q.push(next);
        }
        return ans;
    }
};