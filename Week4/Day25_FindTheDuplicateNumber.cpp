class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(nums[abs(nums[i])] > 0) {
                nums[abs(nums[i])] *= -1;
            } else {
                return abs(nums[i]);
            }
        }
        return -1;
    }
};

class Solution {  //Solution 2
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-1;i++) {
            if(nums[i] == nums[i+1]) {
                return nums[i];
            }
        }
        return 0;
    }
};