class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(int i=0; i<s.length(); i++){
            v1[s[i]-'a']++;
        }
        for(int i=0; i<t.length(); i++){
            v2[t[i]-'a']++;
        }
        if(v1!=v2){
            for(int i=0; i<26; i++){
                if(v1[i]!=v2[i]){
                    return 'a'+i;
                }
            }
        }
        return 'a';
        
    }
};