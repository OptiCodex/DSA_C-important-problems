# 🏳️‍🌈 Sorting 0s, 1s, and 2s (Dutch National Flag Problem)

## 🧠 Problem Statement:
Given an array consisting only of 0s, 1s, and 2s, sort it in-place in one pass without using any library sort functions.

### 📝 Example:
Input:  [2, 0, 1, 1, 0, 2]  
Output: [0, 0, 1, 1, 2, 2]

---

## ✅ Dutch National Flag Algorithm (Best Approach)
We use three pointers:
- `low` → start of 1s (after all 0s)
- `mid` → current element
- `high` → end of 1s (before all 2s)

### 🔁 Dry Run:

Initial: `arr = [2, 0, 1, 1, 0, 2]`  
`low = 0`, `mid = 0`, `high = 5`

| Step | mid | arr[mid] | Action            | Array              |
|------|-----|----------|-------------------|--------------------|
| 1    | 0   | 2        | swap with high    | [2, 0, 1, 1, 0, 2] → [2, 0, 1, 1, 0, 2], high-- |
| 2    | 0   | 2        | swap with high    | [2, 0, 1, 1, 0, 2] → [0, 0, 1, 1, 2, 2], high-- |
| 3    | 0   | 0        | swap with low     | [0, 0, 1, 1, 2, 2], low++, mid++ |
| 4    | 1   | 0        | swap with low     | [0, 0, 1, 1, 2, 2], low++, mid++ |
| 5    | 2   | 1        | mid++             |                     |
| 6    | 3   | 1        | mid++             |                     |

Result: `[0, 0, 1, 1, 2, 2]` ✅

---

## 🧾 C++ Code:

```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
