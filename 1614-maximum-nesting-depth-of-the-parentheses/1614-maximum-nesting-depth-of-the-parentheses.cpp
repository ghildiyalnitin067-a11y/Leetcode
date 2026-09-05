class Solution {
public:
    int maxDepth(string s) {
        int nested_depth = 0;
        int ans = 0;
        
        for(char c:s){
           if(c == '('){
            nested_depth++;
            ans = max(nested_depth,ans);
           }
           else if(c == ')'){
            nested_depth--;
           }
        }
        return ans;
    }
};