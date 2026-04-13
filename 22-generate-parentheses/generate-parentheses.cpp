class Solution {
public:
void permutationofstring(vector<string>& v, string &current, int open, int close){
    
    if(open == 0 && close == 0){
        v.push_back(current);
        return;
    }
    
    // add '('
    if(open > 0){
        current.push_back('(');
        permutationofstring(v, current, open-1, close);
        current.pop_back();
    }
    
    // add ')'
    if(close > open){
        current.push_back(')');
        permutationofstring(v, current, open, close-1);
        current.pop_back();
    }
}
   vector<string> generateParenthesis(int n) {
    vector<string> v;
    string current = "";
    permutationofstring(v, current, n, n);
    return v;
}
};