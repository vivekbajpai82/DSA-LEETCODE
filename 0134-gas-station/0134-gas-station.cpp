class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0;
        int totalcost=0;
        for(int i=0;i<gas.size();i++){
            totalgas+=gas[i];
        }
        for(int j=0;j<cost.size();j++){
            totalcost+=cost[j];
        }
        if(totalgas<totalcost){
            return -1;
        }
        int start=0;
        int curr=0;
        for(int i=0;i<gas.size();i++){
            curr+=(gas[i]-cost[i]);
            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        return start;
    }
};