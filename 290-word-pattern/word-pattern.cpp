#include <sstream>
#include <string>

class Solution {
public:

    bool wordPattern(string pattern, string s) {
        unordered_map<char, string>m;
        unordered_set<string> used;
        vector<string>v;
        string segment;
        stringstream ss(s);
        while (getline(ss, segment, ' ')) {
            
    // Note: this will produce an empty string for the double space
    if (!segment.empty()) { 
        // process segment
        v.push_back(segment);
    }}

    //  ADDED (size check to avoid out-of-bounds)
        if (pattern.length() != v.size())
         return false;

    for(int i=0; i<pattern.length(); i++){
         if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != v[i]) 
                return false;
            }
            else{
                // ADDED: ensure bijection (no two chars map to same word)
                if(used.count(v[i]))
                return false;

                m[pattern[i]] = v[i];
                used.insert(v[i]); //  ADDED
            }
    }
    
    
    return true;
    }
};