class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivotIndex = -1;
        int  LeftSum = 0;
        int RightSum = 0;
        unordered_map<int, int> LeftToRightSums;
        unordered_map<int, int> RightToLeftSums;
        for(int i=0; i<nums.size(); i++){
            LeftSum += nums[i];
            LeftToRightSums.insert(pair<int, int>(i, LeftSum));
            RightSum += nums[nums.size()-i-1];
            RightToLeftSums.insert(pair<int, int>(nums.size()-i-1, RightSum));
        }

        for(int i=0; i<nums.size(); i++){
            if(LeftToRightSums[i] == RightToLeftSums[i]){
                pivotIndex = i;
                break;
            }
        }
        return pivotIndex;
    }
};