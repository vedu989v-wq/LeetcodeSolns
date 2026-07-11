class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int>nearest_left(s.length(), -1);
        vector<int>nearest_ryt(s.length(), -1);
        vector<int>p_sum_of_plates(s.length()+1, 0);


        //counting no. of plates in string and storing in p_sum array

        for(int i=0; i<s.length(); i++){
            p_sum_of_plates[i+1]=p_sum_of_plates[i]+(s[i]=='*');
        }

        //counting nearest lefts of all the plates
        int left=-1;
        for(int i=0; i<s.length(); i++){
          if(s[i]=='|'){
            left=i;
          }
          nearest_left[i]=left;
          
        }
        //counting nearest rights of all plates
        int right=-1;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='|'){
                right=i;
            }
            nearest_ryt[i]=right;
        }
        
        vector<int>ans;
        for(int i=0; i<queries.size(); i++){
         int L=nearest_ryt[queries[i][0]];
         int R=nearest_left[queries[i][1]];

         if(L==-1 || R==-1 || L>=R ){
          ans.push_back(0);
         }
         else{
            ans.push_back(p_sum_of_plates[R]-p_sum_of_plates[L]);
         }

        }

        return ans;


    }
};