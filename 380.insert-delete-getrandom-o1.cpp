#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class RandomizedSet
{
public:
    vector<int> nums;
    unordered_map<int, int> val2Idx;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (val2Idx.count(val) > 0)
        {
            return false;
        }
        val2Idx[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (0 == val2Idx.count(val))
        {
            return false;
        }
        int idx = val2Idx[val];
        val2Idx[nums.back()] = idx;
        swap(nums[idx], nums.back());
        nums.pop_back();
        val2Idx.erase(val);
        return true;
    }

    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    RandomizedSet r;
    r.insert(0);
    r.insert(1);
    r.remove(0);
    r.insert(2);
    r.remove(1);
    r.getRandom();
    return 0;
}
