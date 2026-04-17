#include<sstream>
class Solution {
public:
    int countSegments(string s) {
        if(s.length()==0)
        return 0;

        vector<string>v;
        string segment;
        stringstream ss(s);
        while (getline(ss, segment, ' ')) {
            
    // Note: this will produce an empty string for the double space
    if (!segment.empty()) { 
        // process segment
        v.push_back(segment);
    }}

    return v.size();
    }
};