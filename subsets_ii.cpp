#include "headers.h"

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup( vector<int> &S) {
        std::sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> oneResult;
        subsetsWithDupHelper(S, 0, oneResult, result);
        return result;
    }
    
    void subsetsWithDupHelper(const vector<int> &nums, const int curIdx, 
        vector<int> &oneResult, vector<vector<int> > &result)
    {
        result.push_back(oneResult);

        for (int i = curIdx; i < nums.size(); ++i) {
            if (i != curIdx && nums[i] == nums[i - 1])
                continue;
            oneResult.push_back(nums[i]);
            subsetsWithDupHelper(nums, i + 1, oneResult, result);
            oneResult.pop_back();
        }
    }
};

class Solution2 {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup( vector<int> &S) {
        std::sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> oneResult;
        subsetsWithDupHelper(S, 0, oneResult, result, true);
        return result;
    }
    
    void subsetsWithDupHelper(const vector<int> &nums, const int curIdx, 
        vector<int> &oneResult, vector<vector<int> > &result,
        bool prevTaken)
    {
        if (curIdx == nums.size()) {
            result.push_back(oneResult);
            return;
        }
    
        subsetsWithDupHelper(nums, curIdx + 1, oneResult, result, false);
        if (curIdx == 0 || prevTaken || nums[curIdx] != nums[curIdx - 1]) {
            oneResult.push_back(nums[curIdx]);
            subsetsWithDupHelper(nums, curIdx + 1, oneResult, result, true);
            oneResult.pop_back();
        }
    }
};