class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int>v1;
        long long a=num;
        int count_zero=0;
    //edge case: zero
    if(num==0){
        return 0;
    }
    
    // breaking phase
        if(num>=0){

        while(a){
            int temp=a/10;
            int rem=a%10;
            if(rem==0)
            count_zero++;
            else{
                v1.push_back(rem);
            }
            a=a/10;
        }
        sort(v1.begin(), v1.end());
        
        }
        else{
            a=-a;
           
           while(a){
            int temp=a/10;
            int rem=a%10;
            v1.push_back(rem);
            a=a/10;
        }
            sort(v1.begin(), v1.end(), [](int &a, int&b){
                return a>b;
            });
        }
        
        long long ans=0;
        
        //building phase
        if(num>=0){
            int temp=v1[0];
            ans=ans*10+temp;

            while(count_zero){
                ans=ans*10;
                count_zero--;
            }

            for(int i=1; i<v1.size(); i++){
                ans=ans*10+v1[i];
            }
        }
        else{
            for(int i=0; i<v1.size(); i++){
                ans=ans*10+v1[i];
            }
        }

        return (num>=0)?ans:-ans;
        

    }
};