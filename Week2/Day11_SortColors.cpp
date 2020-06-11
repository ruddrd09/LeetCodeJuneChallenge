class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, i = 0, h = n-1;
        while(i <= h) {
            if(nums[i] == 0) {
                swap(nums[i], nums[l]);
                i++;
                l++;
            } else if(nums[i] == 2) {
                swap(nums[i], nums[h]);
                h--;
            } else {
                i++;
            }
        }
    }
};