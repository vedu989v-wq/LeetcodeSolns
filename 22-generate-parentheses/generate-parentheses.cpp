class Solution {
public:
//theek thaak approach, not so good after all
   
    void permutationofstring(int n, vector<string>&v, string &current, int open, int close){
        if(open == 0 && close == 0 || n==0){
            
            v.push_back(current); //Mistake 1: push is done in the base case, not below the recursive step
            return; 
        }
        
        for(int i=0; i<2; i++){
            if(i==0){
            if(open>0){
            current=current+'(';
            permutationofstring(n-1, v, current, open-1, close);
            
            current.pop_back(); //Mistake 2: pop is necessary for back track and removal of lastly added paranthesis..., at each step, not after pushing back, and after recursive steps.
            }
            }
            else{
            if(close>open){
            current=current+')';
            permutationofstring(n-1, v, current, open, close-1);
            //Mistake 2: pop is necessary for back track and removal of lastly added paranthesis..., at each step, not after pushing back, and after recursive steps.
            current.pop_back();
            }
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
        permutationofstring(n*2, v, current, n, n);
        
     return v;
    }
};