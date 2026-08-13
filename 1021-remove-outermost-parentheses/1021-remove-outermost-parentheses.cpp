class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int iterate = 0;
        for(char c : s){
            if(c=='('){
                if(iterate>0) result += c;
                iterate++;
            }else{
                iterate--;
                if(iterate >0) result +=c;
            }
        }
        return result;
    }
};