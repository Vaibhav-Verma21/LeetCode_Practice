class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
          int tG=0;
          int tC=0;
          int tank=0;
          int start=0;
          for(int i=0;i<gas.size();i++){
            tG+=gas[i];
            tC+=cost[i];
            tank+=gas[i]-cost[i];
            if(tank<0){
                start=i+1;
                tank=0;
            }
          }
          if(tC>tG) return -1;
          return start;
    }
};