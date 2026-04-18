class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int>count;
        unordered_map<char, int>index;
        for(int i=0; i<s.length(); i++){
            index[s[i]]=i;
            count[s[i]]++;
            
            if(count[s[i]]>1){
                index[s[i]]=-1;
            }
        }

        int min_idx=INT_MAX;

           for (const auto& pair : index) {
            if(pair.second!=-1)
        min_idx=min(min_idx, pair.second);
    }

        // if(!index.empty()){
        //     auto it=index.end();
        //     return (*it).second;
        // }
     if(min_idx!=INT_MAX)
     return min_idx;
     
        return -1;
    }
};