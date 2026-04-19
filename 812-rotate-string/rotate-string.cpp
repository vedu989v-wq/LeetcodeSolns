class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)
        return true;
        if(s.length()!=goal.length())
        return false;
        string solutor=s+s;
        for(int i=0; i<solutor.length()-goal.length(); i++){
            string sub=solutor.substr(i, goal.length());
            if(sub==goal)
            return true;
        }
        return false;
    }
};