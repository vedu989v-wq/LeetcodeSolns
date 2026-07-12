class Solution {
public:
        
        double myPow(double x, int n) {
        long long N=n;
        
        //1) Case of negative exponent
        if(N<0){
        x=1/x;
        N=-N;
        }

        //initialising exponentiation trick variables
        double result=1;
        double current_prdct=x;

        while(N>0){
            if(N%2==1){
                result*=current_prdct;
            }
            //this step is heart of the code, it drastically reduces time by running approximately log(N) steps, where N is the exponent
            current_prdct=current_prdct*current_prdct;
            N=N/2;
        }

        return result;

    }
};
