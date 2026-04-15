class Solution {
public:
   int validpar(string str){
    int validlen=0, invalidcount=0, old_len_store=0;
    stack<int>s;

    // ❗ Base case to handle edge like ")()())"
    s.push(-1);

    for(int i=0; i<str.length(); i++ ){
        if(str[i]=='(')
        s.push(i);
        else{
             // pop matching '('
            if(!s.empty())
             s.pop();

            if(s.empty()){
                // ❗ means no valid base → push current index as new base
                s.push(i);
                invalidcount++; // (kept your variable, not really needed)
                validlen = 0;   // reset current length
            }
            else{
                // ❗ CORE FIX: compute length using indices
                validlen = i - s.top();
                old_len_store = max(old_len_store, validlen);
            }
        }
    }
    return old_len_store;
   }
    int longestValidParentheses(string s) {
        return validpar(s);
    }
};