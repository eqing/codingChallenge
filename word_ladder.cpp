#include "headers.h"

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        queue<string> que;
        que.push(start);
        int dist = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                string word = que.front();
                if (word == end)
                    return dist;
                que.pop();
                for (int i = 0; i < word.size(); ++i) {
                    for (char c = 'a'; c < 'z'; ++c) {
                        if (c != word[i]) {
                            swap(c, word[i]);
                            if (dict.find(word) != dict.end()) {
                                que.push(word);
                                dict.erase(word);
                            }
                            swap(c, word[i]);
                        }
                    }
                }
            }
            dist++;
        }
    }
};
