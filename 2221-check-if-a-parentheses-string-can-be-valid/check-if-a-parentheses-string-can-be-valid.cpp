//1)We prioritise open brackets first, if there are no open brackets remaining, we head towards the unlocked characters, and then we declare that, there cannot be a valid parenthesis made

//2)But suppose, if we remove an unlocked character for the sake of balancing brackets, but still there are unlocked characters+openBrackets remaining in the stack, we use another loop to empty them both, if unlocked gets empty first, we declare that valid parenthesis cant be made, else we return true;

//3) check for extreme edge test cases to verify the solution:
// )()()( 011111

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int length=s.size();
        //if length of string is odd, we return false.
        if(length%2==1){
            return false;
        }

        stack<int>openBrackets, unlocked;

        //Iterating through the stirng ot handle '(' and ')'

        for(int i=0; i<length; i++){
            if(locked[i]=='0'){
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

        //Match the remaining open brackets with unlocked characters

        //Core Line of the remaining problem: execute every line step by step in your brain for accurate results
        while(!openBrackets.empty() && !unlocked.empty() && openBrackets.top()<unlocked.top()){
           openBrackets.pop();
           unlocked.pop();
        }

        if(!openBrackets.empty())
        return false;

        return true;
    }
};