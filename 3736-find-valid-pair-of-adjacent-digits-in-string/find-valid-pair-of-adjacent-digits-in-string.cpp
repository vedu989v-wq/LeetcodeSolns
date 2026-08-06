class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int>m;
        
        string ans="";
        

        for(int i=0; i<s.length(); i++){ 
         m[s[i]]++;
        }
        
        for(int i=0; i<s.length()-1; i++)
        {
            if(s[i]!=s[i+1] && m[s[i]]== s[i]-'0' && m[s[i+1]]== s[i+1]-'0'){
                ans.push_back(s[i]);
                ans.push_back(s[i+1]);
                break;
            }
        }

        return ans.size()==2?ans:"";
    }
};