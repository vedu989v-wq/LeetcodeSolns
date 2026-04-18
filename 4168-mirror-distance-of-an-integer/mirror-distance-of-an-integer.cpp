class Solution {
public:
    int reverse(int n){
        int temp=n;
        int reversed=0;
        while(temp){
            int bit=temp%10;
            reversed=reversed*10+bit;
            temp=temp/10;
        }
        return reversed;
    }
    int mirrorDistance(int n) {
        int x=n-reverse(n);
        if(x<0)
        return -x;

        return x;
    }
};