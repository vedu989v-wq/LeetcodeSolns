class Solution {
public:
    bool check(string str){
        stack<char>s;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='('){
                s.push(str[i]);
            }
            else{
                if(s.empty())
                return 0;
                else
                s.pop();
            }
        }
        return s.empty();
    }
    void permutationofstring(int n, vector<string>&v, string &current){
        if(n==0){
            if(check(current))
            v.push_back(current); //Mistake 1: push is done in the base case, not below the recursive step
            return; 
        }
        
        for(int i=0; i<2; i++){
            if(i==0){
            current=current+'(';
            permutationofstring(n-1, v, current);
            current.pop_back(); //Mistake 2: pop is necessary for back track and removal of lastly added paranthesis..., at each step, not after pushing back, and after recursive steps.
            }
            else{
            current=current+')';
            permutationofstring(n-1, v, current);//Mistake 2: pop is necessary for back track and removal of lastly added paranthesis..., at each step, not after pushing back, and after recursive steps.
            current.pop_back();
            }
            
        }
          // ❌ This line was WRONG:
        // v.push_back(current);
        // Reason:
        // - It was adding incomplete/invalid strings
        // - Results should ONLY be added at base case

        // ❌ This pop_back was misplaced
        // current.pop_back();
        // - Backtracking must happen INSIDE each branch, not once at the end
        
        
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string current="";
        permutationofstring(n*2, v, current);
        
     return v;
    }
};