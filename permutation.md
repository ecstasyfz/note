# 排列

#### 递归

```c++
vector<vector<int>> res;
vector<vector<int>> permute_recursion1(vector<int> &nums) {
    if (nums.size() == 0) res.push_back({});
    else helper(nums, nums.size() - 1);
    return res;
}

void helper(vector<int> &nums, int n) {
    if (n < 0) {
        res.push_back(nums);
        break;
    }
    for (int i = 0; i <= n; i++) {
     	swap(nums[i], nums[n]);
       	helper(nums, n - 1);
       	swap(nums[i], nums[n]);
    }
}
```

```c++
vector<vector<int>> res;
vector<int> *p_nums;
vector<vector<int>> permute_recursion2(vector<int> &nums) {
    if (nums.size() == 0) {
        res.push_back({});
    } else {
        p_nums = &nums;
        vector<int> permutation(nums.size());
        bool visited[nums.size()];
        for (int i = 0; i < permutation.size(); i++) {
            visited[i] = false;
        }
        helper(nums, visited, nums.size() - 1);
    }
    return res;
}
void helper(vector<int> &permutation, bool *visited, int n) {
    if (n < 0) {
        res.push_back(premutation);
        return;
    }
    for (int i = 0; i < permutation.size(); i++) {
        if (visited[i]) continue;
        int old_value = permutation[n];
        permutation[n] = (*p_nums)[i];
        visited[i] = true;
        helper(permutation, visited, n - 1);
        visited[i] = false;
        permutation[n] = old_value;
    }
}
```

```c++
vector<vector<int>>permute_lexicographical_order(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    res.push_back(nums);
    while (true) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i < 0) break;
        int j = nums.size() - 1;
        while (nums[j] <= nums[i]) j--;
        swap(nums[i], nums[j]);
        sort(nums.begin() + i + 1, nums.end());
        res.push_back(nums);
    }
    return res;
}
```

```c++
vector<vector<int>>permute_recursion1(vector<int> &nums) {
    if (nums.size() == 0) return {};
    vector<vector<int>> res;
    stack<pair<vector<int>, vector<int>>> st;
    st.push(make_pair(vector<int>(), vector<int>(nums.size(), 0)));
    while (!st.empty()) {
        auto pa = st.top();
        st.pop();
        if (pa.first.size() == nums.size() - 1) {
            for (int i = 0; i < nums.size(); i++) {
                vector<int> visited = pa.second;
                if (visited[i]) continue;
                vector<int> permutation = pa.first;
                permutation.push_back(nums[i]);
                res.push_back(permutation);
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                vector<int> visited = pa.second;
                if (visited[i]) continue;
                vector<int> permutation = pa.first;
                permutation.push_back(nums[i]);
                visited[i] = 1;
                st.push(make_pair(permutation, visited));
            }
        }
    }	
    return res;
}

```

