// ---X----Contest Written Syntax--X---
//tried to solve with greedy

// class Solution {
// public:
//     int largestInteger(int n, int s) {
//         int proxysum=s;
//         int ans=0;
        
//     while(n){
//         proxysum=s;
//         for(int i=9; i>=0; i--){
//             proxysum=proxysum-i;
//             if(proxysum<0)
//                 return -1;
//             else{
//                 ans=ans*10+i;
//                 s=proxysum;
//                 break;
//             }

            
//         }
//         if(proxysum==0){
//                 while(n){
//                     ans=ans*10;
//                     n--;
//                 }
//             }
//         n--;
//     }
//         return ans;
//     }
// };

// --X--- Upsolving---X--

//optimal greedy method
class Solution {
public:
    int largestInteger(int n, int s) {
       if(s>9*n)
       return -1;
       if(s==0)
       return 0;

       int ans=0;

       for(int i=0; i<n; i++){
        int digit=min(9, s);
        ans=ans*10+digit;
        s=s-digit;
       }

       return ans;
    }
};