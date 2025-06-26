class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int count = 0;
        int value = 0;
        int power = 0;

        // Traverse from right to left (LSB to MSB)
        for (int i = n - 1; i >= 0; i--) {
            int bit = s[i] - '0';

            if (bit == 0) {
                count++; // 0s can always be taken
            } else {
                if (power < 31) { // prevent overflow
                    int add = 1 << power;
                    if (value + add <= k) {
                        value += add;
                        count++;
                    }
                }
            }
            power++;
        }

        return count;
    }
};
