class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int unbalanced=0;

        for(int i=0; i<s.size(); i++){
            char ch=s[i];
            //if an opening bracket is encountered, push it into the stack
            if(ch=='[')
            st.push(ch);

            else{
                //if the stack is not empty, pop the top
                if(!st.empty())
                st.pop();

                //else: oncrease the number of unbalanced brackets
                else
                unbalanced++;
            }
        }

        return (unbalanced+1)/2;
    }
};