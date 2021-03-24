#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		int i, j;
		for (i = 0; i < nums.size()-1; i++)
		{
			for (j = i+1; j < nums.size(); j++)
			{
				if (nums[i]+ nums[j]== target)
				{
					return {i,j};
				}
			}
		}
        return vector<int>();
    }
};


/*
    test
*/
int main(int argc, char *argv[]) {
	int len = argc-2;
	cout << "array with " << len << " numbers"<< endl;
	int *arr = (int *)malloc(sizeof(int) * len);
	for (int i=1; i <= len; i++) {
		arr[i-1] = atoi(argv[i]);
//		cout << argv[i] << endl;
	}
	int target = atoi(argv[argc-1]);
//	cout << argv[argc-1] << endl;

	vector<int> nums(arr, arr + len);
	Solution s;
	cout << s.twoSum(nums, target).front() << endl;
    cout << s.twoSum(nums, target).back() << endl;

    return 0;
}
