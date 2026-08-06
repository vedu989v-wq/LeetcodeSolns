class Solution {
public:
    int smallestNumber(int n, int t) {
        int a=n;
        while(a%10!=0){
            int k=a;
            int pd=1;
            while(k){
                int bit=k%10;
                k=k/10;
                pd=pd*bit;
            }
            if(pd%t==0)
            return a;

            a++;
        }
        if(a%10==0)
        return a;
        
        return 0;
    }
};