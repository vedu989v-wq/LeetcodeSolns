class Solution {
public:
    int scoreOfParentheses(string s) {
       stack<int>st;

       //score of the outermost level
       st.push(0);
       
       for(int i=0; i<s.size(); i++){
        //starting a new parantheses level
        if(s[i]=='('){
            st.push(0);
        }
        else{
            //store accumulated score inside current pair
            int v=st.top();
            st.pop();
           
            int curr_score;
            //condition for storing current score

            //if nothing was inside it was ()
            if(v==0){
               curr_score=1;
            }
            //else we got n_size consecutive brackets
            else{
                curr_score=2*v;
            }

            st.top()=st.top()+curr_score;
        }
       }
     return st.top();
    }
};