class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) swap(num1, num2);
        int diff = num1.size() - num2.size();
        num2 = string(diff, '0') + num2;   
        
        string res = num1;   
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; i--) {
            int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
            res[i] = (sum % 10) + '0';
            carry = sum / 10;
        }
        
        if (carry) {
            res = "1" + res;
        }
        
        return res;
    }
};