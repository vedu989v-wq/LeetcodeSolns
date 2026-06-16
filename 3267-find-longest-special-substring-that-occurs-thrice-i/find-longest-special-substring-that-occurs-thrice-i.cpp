class Solution {
public:
//venn diagram approach: because we dont know where and how to move the pointers (i.e; start and end)
    int maximumLength(string s) {
        unordered_map<string, int>m;

    //Below loop only counts special substrings  
        for(int start=0; start<s.length(); start++){
            string currs="";
            for(int end=start; end<s.length(); end++){
                
                if(currs.length()==0 || currs[currs.length()-1]==s[end]){
                currs.push_back(s[end]);
                m[currs]++;
                }
                else
                break;
            }
        }
       int len=-1;
        for (const auto& [specialsub, count] : m) {
        if(count>=3 && (int)specialsub.length()>len)
         len=specialsub.length();
        }
        
        
    return len;
    }
};