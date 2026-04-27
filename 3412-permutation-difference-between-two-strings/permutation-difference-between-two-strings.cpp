class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int pd=0;
        vector<int>v(26, 0);
        for(int i=0; i<s.length(); i++){
         v[s[i]-'a']=i;
        }
        for(int i=0; i<t.length(); i++){
            
                pd=pd+abs(v[t[i]-'a']-i);
            
        }

        return pd;
    }
};