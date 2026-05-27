class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev=-1;

        for(int i=0; i<s.size(); i++){
            int num=0;
            if('0'<=s[i] && s[i]<='9'){
            while(i<s.size() && '0'<=s[i] && s[i]<='9'){
              num=num*10 +(s[i]-'0');
              i++;
            }
                if(num > prev){
                    prev=num;
                }
                else
                return false;
            
        }
        
    }

        return true;

    }
};