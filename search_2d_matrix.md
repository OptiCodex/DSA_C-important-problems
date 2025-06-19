# 🔍 2D Matrix Search – Type 1 & Type 2

---

## 📘 Type 1: Row-wise and Column-wise Sorted Matrix

### ✅ Matrix Conditions:
- Each row is sorted in ascending order
- Each column is sorted in ascending order
- BUT matrix is not globally sorted

### 📈 Time Complexity:
- **O(n + m)** where n = rows, m = columns

### 🧠 Intuition:
Start from the **top-right corner**:
- If `matrix[i][j] == target` → ✅ Found
- If `matrix[i][j] > target` → move **left**
- If `matrix[i][j] < target` → move **down**

### 💻 C++ Code:

```cpp
bool searchMatrixType1(int matrix[][4], int row, int col, int target) {
    int i = 0, j = col - 1;
    while (i < row && j >= 0) {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] > target) j--;
        else i++;
    }
    return false;
}
```

### 🧪 Dry Run Example

For matrix:
```
10 20 30 40
15 25 35 45
27 29 37 48
```
Target = 29

- Start at (0,3) = 40 → too big → move left
- (0,2) = 30 → too big → move left
- (0,1) = 20 → too small → move down
- (1,1) = 25 → too small → move down
- (2,1) = 29 → ✅ Found

---

## 📘 Type 2: Fully Sorted 2D Matrix

### ✅ Matrix Conditions:
- Rows are sorted in ascending order
- First element of each row > last element of previous row
- Matrix behaves like a **1D sorted array**

### 📈 Time Complexity:
- **O(log(n × m))**

### 🧠 Approach:
Use binary search as if matrix is a flat array:
- Convert `mid` index → `(row, col)` using:
  - `row = mid / cols`
  - `col = mid % cols`

### 💻 C++ Code:

```cpp
pair<int,int> searchMatrixType2(int matrix[][3], int row, int col, int target) {
    int start = 0, end = row - 1;

    while (start <= end) {
        int midr = (start + end) / 2;

        if (target < matrix[midr][0]) {
            end = midr - 1;
        }
        else if (target > matrix[midr][col - 1]) {
            start = midr + 1;
        }
        else {
            // Binary search in row
            int left = 0, right = col - 1;
            while (left <= right) {
                int midc = (left + right) / 2;
                if (matrix[midr][midc] == target)
                    return {midr, midc};
                else if (matrix[midr][midc] < target)
                    left = midc + 1;
                else
                    right = midc - 1;
            }
            return {-1, -1};
        }
    }

    return {-1, -1};
}
```

---

### 🧪 Dry Run Example

For matrix:
```
1   3   5
7   9   11
13  15  17
```

Target = 9

- midr = 1 → row: [7, 9, 11]
- Binary search in this row → mid = 1 → value = 9 → ✅ Found

---

## 🧾 Summary Table

| Type | Matrix Property                         | Time Complexity | Technique         |
|------|------------------------------------------|------------------|-------------------|
| 1    | Each row & column sorted (not global)    | O(n + m)         | Staircase Search  |
| 2    | Fully sorted matrix (like 1D array)      | O(log(n × m))    | Binary Search     |

---

✍️ Author: Mukesh Siyol (IIT Delhi)