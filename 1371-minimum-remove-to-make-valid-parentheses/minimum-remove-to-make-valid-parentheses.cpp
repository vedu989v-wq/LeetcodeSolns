class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        vector<bool>excess(s.size(), 0);

        for(int i =0; i<s.size(); i++){
            if(s[i]=='(')
            st.push(i);
 
            else if(s[i]==')'){
                if(st.empty()){
                   excess[i]=1;
                }
                else
                st.pop();
            }
        }

        while(!st.empty()){
            excess[st.top()]=1;
            st.pop();
        }        

        string ans="";

        for(int i=0; i<s.size(); i++){
            if(!excess[i]){
              ans.push_back(s[i]);
            }
        }

        return ans;
    }
};