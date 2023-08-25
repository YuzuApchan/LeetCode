#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        int totalE = rowNum * colNum;
        vector<int> res(totalE);
        int ceiling = 0;
        int floor = rowNum - 1;
        int left = 0;
        int right = colNum - 1;
        for (int idx = 0; idx < totalE;)
        {
            for (int toRight = left; toRight <= right; toRight++, idx++)
            {
                res[idx] = matrix[ceiling][toRight];
            }
            ceiling++;
            for (int toFloor = ceiling; toFloor <= floor; toFloor++, idx++)
            {
                res[idx] = matrix[toFloor][right];
            }
            right--;
            for (int toLeft = right; toLeft >= left; toLeft--, idx++)
            {
                res[idx] = matrix[floor][toLeft];
            }
            floor--;
            for (int toCeiling = floor; toCeiling >= ceiling; toCeiling--, idx++)
            {
                res[idx] = matrix[toCeiling][left];
            }
            left++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> m{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    s.spiralOrder(m);
    cout << 111 << endl;
    return 0;
}
