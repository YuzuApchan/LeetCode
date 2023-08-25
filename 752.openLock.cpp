/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    string plusOne(string curLockStatus, int pos)
    {
        if ('9' == curLockStatus[pos])
        {
            curLockStatus[pos] = '0';
        }
        curLockStatus[pos] += 1;
        return curLockStatus;
    }
    string minusOne(string curLockStatus, int pos)
    {
        if ('0' == curLockStatus[pos])
        {
            curLockStatus[pos] = '9';
        }
        curLockStatus[pos] -= 1;
        return curLockStatus;
    }
    int openLock(vector<string> &deadends, string target)
    {
        // unordered_set<string> skip(deadends.begin(), deadends.end());
        unordered_set<string> skip;
        for (string deadend : deadends)
        {
            skip.insert(deadend);
        }
        int times = 0;
        queue<string> q;

        q.push("0000");
        skip.insert("0000");
        while (false == q.empty())
        {
            int qCurSize = q.size();
            for (int idx = 0; idx < qCurSize; idx++)
            {
                string cur = q.front();
                q.pop();
                if (cur == target)
                {
                    return times;
                }
                for (int pos = 0; pos < 4; pos++)
                {
                    string afterPlusOne = plusOne(cur, pos);
                    string afterMinusOne = minusOne(cur, pos);
                    if (0 == skip.count(afterPlusOne))
                    {
                        q.push(afterPlusOne);
                        skip.insert(afterPlusOne);
                    }
                    if (0 == skip.count(afterMinusOne))
                    {
                        q.push(afterMinusOne);
                        skip.insert(afterMinusOne);
                    }
                }
            }
            times++;
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> deadends = {"8888"};
    solution.openLock(deadends, "0009");
    return 0;
}
