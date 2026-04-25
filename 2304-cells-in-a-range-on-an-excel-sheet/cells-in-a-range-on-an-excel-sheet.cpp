class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>v;
        vector<char>v1;
        for(int i=s[0]; i<=s[3]; i++){
           for(int j=s[1]; j<=s[4]; j++){
            string s1;
            s1.push_back(char(i));
            s1.push_back(char(j));
            v.push_back(s1);
           }
        }
        return v;
    }
};