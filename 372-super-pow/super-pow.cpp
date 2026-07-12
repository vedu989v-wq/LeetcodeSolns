class Solution {
public:
    int myPow(int x, int n) {
        long long N=n;

        x=x%1337; //preventing initial overflow
        
        //1) Case of negative exponent
        if(N<0){
        x=1/x;
        N=-N;
        }

        //initialising exponentiation trick variables
        int result=1;
        int current_prdct=x;

        while(N>0){
            if(N%2==1){
                result=(result*current_prdct)%1337;
            }
            //this step is heart of the code, it drastically reduces time by running approximately log(N) steps, where N is the exponent
            current_prdct=(current_prdct*current_prdct)%1337;
            N=N/2;
        }

        return result;
    }
    int superPow(int a, vector<int>& b) {
        int ans=1;
         //processing each digit from left to right
         for(int i=0; i<b.size(); i++){
          //Core Logic: (previous answer^10 * a^current_digit )%1337  
          ans=(myPow(ans, 10)*myPow(a,b[i])) %1337;
         }
         return ans;
    }

};