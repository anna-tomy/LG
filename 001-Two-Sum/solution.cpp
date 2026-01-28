class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> idxN(n);
        
        // 1. Store value with original index
        for(int i = 0; i < n; i++) idxN[i] = {nums[i], i};
        
        // 2. Sort the pairs based on the first element (the value)
        sort(idxN.begin(), idxN.end());
        
        int left = 0, right = n - 1;
        while(left < right) {
            int sum = idxN[left].first + idxN[right].first;
            
            if(sum == target) {
                return {idxN[left].second, idxN[right].second};
            }
            else if(sum < target) {
                left++;  // Need a larger sum
            }
            else {
                right--; // Fix: Need a smaller sum, move leftward
            }
        }
        return {};
    }
};
