# Prepare markdown content for detailed explanation and dry run of sorting algorithms


## 🔁 Bubble Sort

### ✅ Logic:
- Repeatedly compare adjacent elements and swap if they are in the wrong order.
- Largest elements bubble to the end with each pass.

### 🧠 Time Complexity:
- Best: O(n) (if already sorted)
- Average/Worst: O(n²)

### 🔍 Dry Run:

Input: `[5, 2, 8, 1]`

Pass 1:
- Compare 5 and 2 → swap → `[2, 5, 8, 1]`
- Compare 5 and 8 → no swap
- Compare 8 and 1 → swap → `[2, 5, 1, 8]`

Pass 2:
- Compare 2 and 5 → no swap
- Compare 5 and 1 → swap → `[2, 1, 5, 8]`

Pass 3:
- Compare 2 and 1 → swap → `[1, 2, 5, 8]`

### ✅ Code (C++):

```cpp
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
