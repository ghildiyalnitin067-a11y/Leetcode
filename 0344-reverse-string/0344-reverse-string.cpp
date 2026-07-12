class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> ans(s.size());
        int j=0;

        for(int i=s.size()-1 ;i>=0;i--){
            ans[j] = s[i];
            j++;
        }

        for(int i=0;i< s.size();i++){
            s[i] = ans[i];
        }

    }
};