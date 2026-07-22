//No DP solution: same as problem 2116

class Solution {
public:
    bool checkValidString(string s) {
        int length=s.size();

        stack<int>openBrackets, unlocked;

        for(int i=0; i<length; i++){
            if(s[i]=='*'){
                unlocked.push(i);
            }
            else if(s[i]=='('){
                openBrackets.push(i);
            }
            else if(s[i]==')'){
                if(!openBrackets.empty()){
                    openBrackets.pop();
                }
                else if(!unlocked.empty()){
                    unlocked.pop();
                }
                else{
                    return false;
                }
            }
        }

        while(!openBrackets.empty() && !unlocked.empty() && openBrackets.top()<unlocked.top()){
            openBrackets.pop();
            unlocked.pop();
        }

        if(!openBrackets.empty())
        return false;

        return true;
    }
};