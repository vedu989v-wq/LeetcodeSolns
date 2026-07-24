class Solution {
public:
    int minInsertions(string s) {
       stack<char>st;
       int moves=0;
       for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            st.push('(');
        }
        else{

            //checking whether ') is part of '))'
            bool isPair=false;
            if(i+1<s.size() && s[i+1] == ')'){
                isPair=true;
                i++;             //consume second ')'
            }

            if(!isPair)
            moves++;            //insert one ')' to make '))'

            if(!st.empty())
            st.pop();          //match with an existing '('
            else
            moves++;
        }
       }

       //Every remaining '(' needs two ')'
       while(!st.empty()){
        st.pop();
        moves+=2;
       }

       return moves;
    }
};