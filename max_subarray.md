# 最大子数组
### [LintCode 41. Maximum Subarray](https://www.lintcode.com/problem/maximum-subarray/description)

> #### 描述
>
> 给定一个整数数组，找到一个具有最大和的子数组，返回其最大和。 
>
> #### 样例
>
> 给出数组`[−2,2,−3,4,−1,2,1,−5,3]`，符合要求的子数组为`[4,−1,2,1]`，其最大和为`6`
>
> #### 挑战
>
> 要求时间复杂度为O(n)

```c++
int maxSubArray(vector<int> &nums) {
    int res = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        res = max(res, sum);
        sum = max(sum, 0);
    }
    return res;
}
```

---

### [LintCode 42. Maximum Subarray II](https://www.lintcode.com/problem/maximum-subarray-ii/description)

> #### 描述
>
> 给定一个整数数组，找出两个 *不重叠* 子数组使得它们的和最大。
> 每个子数组的数字在数组中的位置应该是连续的。
> 返回最大的和。
>
> #### 样例
>
> 给出数组 `[1, 3, -1, 2, -1, 2]`
> 这两个子数组分别为 `[1, 3]` 和 `[2, -1, 2]` 或者 `[1, 3, -1, 2]` 和 `[2]`，它们的最大和都是 `7`
>
> #### 挑战
>
> 要求时间复杂度为 O(*n*)

从左右两边构建最大子数组序列，每个节点储存该子序列的最大子数组的和，所求最大值应该为 $left[i]+right[i+1]$．

---

### [LintCode 45. Maximum Subarray Difference](https://www.lintcode.com/problem/maximum-subarray-difference/description)

> #### 描述
>
> 给定一个整数数组，找出两个**不重叠**的子数组A和B，使两个子数组和的差的绝对值**|SUM(A) - SUM(B)|**最大。
>
> 返回这个最大的差值。
>
> #### 样例
>
> 给出数组**[1, 2, -3, 1]**，返回 6
>
> #### 挑战
>
> 时间复杂度为O(n)，空间复杂度为O(n)

从左右两边分别构建`left_min` `left_max` `right_min` `right_max`四个序列．所求值应为

$max[abs(leftMax[i]-rightMin[i+1]), abs(leftMin[i]-rightMax[i+1])]$

---

### [LintCode 46. Majority Element](https://www.lintcode.com/problem/majority-element/description)

