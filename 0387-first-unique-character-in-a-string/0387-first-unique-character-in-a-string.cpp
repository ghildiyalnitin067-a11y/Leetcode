class Solution {
public:
    int firstUniqChar(string s) {
        int freq[256] = {0};

    for(char n : s){
        freq[n -'a']++;;
    }

    for(int i=0;i<s.length();i++){
        if(freq[s[i] - 'a'] == 1){
            return i;
            break;
        }
    }
    return -1;
    }
};