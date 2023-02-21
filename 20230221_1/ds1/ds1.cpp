// ds1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <vector>
#include <unordered_set>

class Solution_217 {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> set;
    for (auto item : nums) {
      if (!set.insert(item).second) {
        return true;
      }
    }
    return false;
  }

  bool containsDuplicate1(std::vector<int>& nums) {
    std::vector<int> vec;
    for (auto item : nums) {
      if (vec.empty()) {
        vec.push_back(item);
        continue;
      }

      for (auto ite : vec) {
        if (item == ite) {
          return true;
        }
      }

      vec.push_back(item);
    }
    return false;
  }
};

class Solution_53 {
 public:
   // leetcode爆内存
  int maxSubArray(std::vector<int>& nums) {
    int start_index = 0, max_index = 0;
    int cur_max_sum = 0 , temp_sum = 0, max_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      start_index = i;
      temp_sum = 0;
      for (int j = i; j < nums.size(); j++) {
        temp_sum += nums[j];
        if (j == 0 && i == 0) {
          max_sum = temp_sum;
        }

        if (j == i) {
          cur_max_sum = temp_sum;
        }

        if (temp_sum > cur_max_sum) {
          cur_max_sum = temp_sum;
          max_index = j;
        }

        if (temp_sum > max_sum) {
          max_sum = temp_sum;
        }
      }
    }
    return max_sum;
  }

  int maxSubArray1(std::vector<int>& nums) {
    int pre = 0, maxAns = nums[0];
    for (const auto& x : nums) {
      pre = std::max(pre + x, x);
      maxAns = std::max(maxAns, pre);
    }
    return maxAns;
  }
};

#include <iostream>

int main() {
  std::vector<int> nums1 = {1, 2, 3, 1};
  std::vector<int> nums2 = {1, 2, 3, 4};
  std::vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  std::vector<int> nums4 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

  Solution_53 s;
  s.maxSubArray1(nums4);

  /*Solution_217 s;
  std::cout << s.containsDuplicate1(nums1) << std::endl;
  std::cout << s.containsDuplicate1(nums2) << std::endl;
  std::cout << s.containsDuplicate1(nums3) << std::endl;*/

  return 0;
}
