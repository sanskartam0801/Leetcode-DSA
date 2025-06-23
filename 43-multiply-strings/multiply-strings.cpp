class Solution {
public:
    string add(string one, string two) {
        int i = one.length() - 1;
        int j = two.length() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += one[i--] - '0';
            if (j >= 0) sum += two[j--] - '0';
            ans += (sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        string ans = "";

        for (int i = n1 - 1; i >= 0; i--) {
            string temp = "";
            int carry = 0;

            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0') + carry;
                temp += (mul % 10 + '0');
                carry = mul / 10;
            }

            if (carry) temp += (carry + '0');
            reverse(temp.begin(), temp.end());

            // Add trailing zeros for place value
            temp.append(n1 - 1 - i, '0');

            // Add to the final answer
            ans = add(ans, temp);
        }

        return ans;
    }
};
