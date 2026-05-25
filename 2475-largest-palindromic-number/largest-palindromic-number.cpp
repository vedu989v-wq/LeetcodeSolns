class Solution {
public:
    string largestPalindromic(string num) {

        //phase 1: marking
        vector<int>v(10,0);
        for(int i=0; i<num.length(); i++ ){
            v[num[i]-'0']++;
        }
        string part="";
        bool toggle=0;
        //phase 2: checking/finding
        for(int i=9; i>=0; i--){
        int pairs=v[i]/2;
        
        if(!part.empty() || i!=0){
        while(pairs--){
            part.push_back(char('0'+i));
        }
        }

        if(v[i]%2==1 && toggle==0){
            toggle=1;
        }
    }

    //all zeroes case
    if(part.empty()){

    for(int i=9; i>=0; i--){

        if(v[i]>0){
            return string(1, char(i+'0'));
        }
    }
}

        string rem=part;
        reverse(rem.begin(), rem.end());

        if(toggle){
            for(int i=9; i>=0; i--){
                if(v[i]%2==1){
                
                part.push_back(char(i+'0'));
                break;
                
                }
            }
        }


        return part+rem;
    }
};