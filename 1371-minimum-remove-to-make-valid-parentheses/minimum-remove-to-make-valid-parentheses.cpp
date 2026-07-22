class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_map<int, bool>m;

        for(int i =0; i<s.size(); i++){
            if(s[i]=='(')
            st.push(i);
 
            else if(s[i]==')'){
                if(st.empty()){
                   m[i]=1;
                }
                else
                st.pop();
            }
        }

        while(!st.empty()){
            m[st.top()]=1;
            st.pop();
        }        

        string ans="";

        for(int i=0; i<s.size(); i++){
            if(!m.count(i)){
              ans.push_back(s[i]);
            }
        }

        return ans;
    }
};