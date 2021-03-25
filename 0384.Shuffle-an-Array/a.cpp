#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

class Solution {
    vector<int> arr;
public:
    Solution(vector<int> &nums) {
        srand(time(NULL));
        this->arr = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(arr);
        for (int i = 0; i < arr.size(); ++i) {
            int j = rand()%(arr.size()-i);
            if (i != j) {
                swap(result[i], result[i + j]);
            }
        }
        return result;
    }
};


int main(int argc, char *argv[]) {
    vector<int> a = {1,2,3};
    Solution solution(a);
    solution.reset();
    solution.shuffle();

    return 0;
}