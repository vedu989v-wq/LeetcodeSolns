class Solution {
public:
    int minimizedStringLength(string s) {
       vector<int>countocc(26, 0);
       int len=0;
       for(int i=0; i<s.length(); i++){
        countocc[s[i]-'a']++;
       }
       for(int i=0; i<26; i++){
        if(countocc[i]>=1)
        len++;
       }
       return len;
    }
};