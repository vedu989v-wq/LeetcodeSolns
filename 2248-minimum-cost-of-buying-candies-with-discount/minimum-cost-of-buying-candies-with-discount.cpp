class Solution {
public:
    int minimumCost(vector<int>& cost) {

        //every 3rd candy is free

        sort(cost.begin(), cost.end());
        int tog=0;
        int mincost=0;

        for(int i=cost.size()-1; i>=0; i-- ){
            tog++;
            if(tog%3==0){
             tog=0;
            }
            else{
            mincost=mincost+cost[i];
            }
        }

        return mincost;
           }
};