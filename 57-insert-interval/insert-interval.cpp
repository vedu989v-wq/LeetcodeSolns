class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
        return intervals;
        
        vector<vector<int>>ans;
       sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
       
       for(int i=0; i<intervals.size()-1; i++){
        while(i<intervals.size()-1 && intervals[i][0]<=intervals[i+1][0] && intervals[i+1][0]<=intervals[i][1]){
            if(intervals[i][0]<=intervals[i+1][1] && intervals[i+1][1]<=intervals[i][1]){
                intervals[i+1]={intervals[i][0], intervals[i][1]};
            }
            else
               intervals[i+1]={intervals[i][0], intervals[i+1][1]};

            i++;
        }
        ans.push_back(intervals[i]);

        if(i==intervals.size()-2)
        ans.push_back(intervals[i+1]);
       }
    

       return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0)
        return {{newInterval[0], newInterval[1]}};

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });


        //step1: merge the new interval
        vector<vector<int>>ans;
        bool done=false;
        for(int i=0; i<intervals.size(); i++){
            //case1: we find the first element of new interval in between of any present interval
            if(newInterval[0]>=intervals[i][0] && newInterval[0]<=intervals[i][1]){
             if(newInterval[1]>=intervals[i][1])
             intervals[i]={intervals[i][0], newInterval[1]};
            
            else{
                intervals[i]={intervals[i][0], intervals[i][1]};
            }
            ans=merge(intervals);
            done=true;
            break;
            }
            

            //case2: we find the last element of newinterval in between of any present interval
            else if(newInterval[1]>=intervals[i][0] && newInterval[1]<=intervals[i][1]){
                if(newInterval[0]<=intervals[i][0])
                intervals[i]={newInterval[0], intervals[i][1]};
                else
                intervals[i]={intervals[i][0], intervals[i][1]};

                ans=merge(intervals);
                done=true;
                break;
            }
            //case3: we find the first and last elements of new interval in between of ending of one interval, and starting of other interval
            else {

                if(i < intervals.size() - 1 &&
                   intervals[i][1] <= newInterval[0] &&
                   intervals[i + 1][0] >= newInterval[1]) {

                    int j = 0;

                    while(j < intervals.size() &&
                          intervals[j][1] <= newInterval[0]) {
                        ans.push_back(intervals[j]);
                        j++;
                    }

                    ans.push_back(newInterval);

                    while(j < intervals.size()) {
                        ans.push_back(intervals[j]);
                        j++;
                    }

                    done = true;
                    break;
                }

                // single interval special case
                else if(intervals.size() == 1) {

                    if(intervals[0][1] <= newInterval[0]) {
                        ans.push_back(intervals[0]);
                        ans.push_back(newInterval);
                    }
                    else if(intervals[0][0] >= newInterval[1]) {
                        ans.push_back(newInterval);
                        ans.push_back(intervals[0]);
                    }

                    if(!ans.empty()) {
                        done = true;
                        break;
                    }
                }
            }
        }
        //all missing edge cases
        if(!done){
            intervals.push_back(newInterval);
            ans=merge(intervals);
        }
        return ans;
    }

            
    
};