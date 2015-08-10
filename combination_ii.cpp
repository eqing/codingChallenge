#include <headers.h>

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        std::sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> oneResult;
        combinationSum2Helper(num, 0, target, oneResult, result);
        return result;
    }
    
    void combinationSum2Helper(const vector<int> &num, const int curIdx, 
        const int target, vector<int> &oneResult, vector<vector<int> > &result)
    {
        if (target <= 0) {
            if (target == 0)
                result.push_back(oneResult);
            return;
        } 
        
        for (int i = curIdx; i < num.size(); ++i) {
            if (i == curIdx || num[i] != num[i - 1]) {
                oneResult.push_back(num[i]);
                combinationSum2Helper(num, i + 1, target - num[i], oneResult, result);
                oneResult.pop_back();
            }
        }
    }
};
