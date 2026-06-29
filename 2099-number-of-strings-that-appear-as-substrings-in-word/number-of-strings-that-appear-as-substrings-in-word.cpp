class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(int i=0; i<patterns.size(); i++){
            bool found=false;
            for(int j=0; j<word.length(); j++){
            int pwp=0;
            int wp=j;
            bool toggle=0;
            while(pwp<patterns[i].length() && wp<word.length()){
                if(patterns[i][pwp]!=word[wp]){
                   toggle=1;
                   break;
                }
                
                else if(patterns[i][pwp]==word[wp]){
                    pwp++;
                    wp++;
                }


            }
            if(toggle==0 && pwp==patterns[i].length()){
              found=true;
              break;
            }
        }
        if(found)
        count++;
    }
        return count;
    }
};