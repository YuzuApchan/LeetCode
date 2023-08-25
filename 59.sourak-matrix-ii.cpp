#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n));
        int status = 0;
        int eNum = n * n;
        int left = 0;
        int ceiling = 0;
        int right = n - 1;
        int floor = n - 1;
        int i = 1;
        while (i <= eNum)
        {
            switch (status)
            {
            case 0:
                for (int toRight = left; toRight <= right; toRight++)
                {
                    res[ceiling][toRight] = i;
                    i++;
                }
                ceiling++;
                status++;
                break;
            case 1:
                for (int toFloor = ceiling; toFloor <= floor; toFloor++)
                {
                    res[toFloor][right] = i;
                    i++;
                }
                right--;
                status++;
                break;
            case 2:
                for (int toLeft = right; toLeft >= left; toLeft--)
                {
                    res[floor][toLeft] = i;
                    i++;
                }
                floor--;
                status++;
                break;
            case 3:
                for (int toCeiling = floor; toCeiling >= ceiling; toCeiling--)
                {
                    res[toCeiling][left] = i;
                    i++;
                }
                left++;
                status = 0;
                break;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.generateMatrix(3);
    s.generateMatrix(1);
    return 0;
}
