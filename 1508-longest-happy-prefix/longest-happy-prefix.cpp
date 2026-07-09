class Solution {
public:
    string longestPrefix(string s) {
        int pre=0;
        int suf=1;
 
        vector<int>lps(s.size(), 0);
        while(suf<s.size()){
           if(s[pre]==s[suf]){
            lps[suf]=pre+1;
            pre++, suf++;
           }
           else{
            if(pre==0){
                lps[suf]=0;
                suf++;
            }
            else{
                pre=lps[pre-1];
            }
           }
        }
        cout<<lps[s.size()-1];
        string ans="";
        for(int i=0; i<lps[s.size()-1]; i++){
            ans.push_back(s[i]);
        }

        return ans;
    }
};