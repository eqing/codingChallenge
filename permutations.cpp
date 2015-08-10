#include "headers.h"

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int> > results;
        if (nums.size() == 0) {
            return results;
        }
        
        permutationHelper(0, nums, results);
        return results;
    }
    
    void permutationHelper(const int start, vector<int> &nums,
        vector<vector<int> > &results)
    {
        if (start == nums.size()) {
            results.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[i], nums[start]);
            permutationHelper(start + 1, nums, results);
            swap(nums[i], nums[start]);
        }
    }
};

int main()
{
	
}