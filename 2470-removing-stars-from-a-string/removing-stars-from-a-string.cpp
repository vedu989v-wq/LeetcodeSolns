class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    continue;
                }
                else{
                    st.pop();
                }
            }
        }
        stack<char>rev;
        while(!st.empty()){
            int a=st.top();
            rev.push(a);
            st.pop();
        }
      string ans="";
      while(!rev.empty()){
        ans.push_back(rev.top());
        rev.pop();
      }

      return ans;
    }
};