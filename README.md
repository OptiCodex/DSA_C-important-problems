# 📚 Book Allocation & Painter's Partition Problem

## 📁 Table of Contents

- [Problem Statement](#problem-statement)
- [Intuition](#intuition)
- [Binary Search Approach](#binary-search-approach)
- [C++ Code](#c-code)
- [Dry Run Example](#dry-run-example)
- [Applications](#applications)
- [Painter's Partition Problem](#painters-partition-problem)
- [Dry Run for Painter's Problem](#dry-run-for-painters-problem)
- [Conclusion](#conclusion)

---

## 📘 Problem Statement

Given:

- An array `arr[]` where `arr[i]` is the number of pages in the i-th book.
- `m` = number of students.

Objective:

- Allocate books **contiguously** such that:
  - Each book is assigned to exactly one student.
  - Each student gets at least one book.
  - Minimize the **maximum** number of pages assigned to any student.

---

## 🧠 Intuition

- This is a **"minimum-maximum" optimization** problem — we apply **Binary Search on the answer**.
- Books cannot be split and must be assigned in **continuous blocks**.
- The goal is to find the **minimum of the maximum load** a student has to read.

---

## 📊 Binary Search Approach

### Step 1: Define Search Space

- `low = max(arr)` → At least one student reads the largest book.
- `high = sum(arr)` → One student reads all books.

### Step 2: Binary Search on Max Pages per Student

- Try a `mid` value between low and high.
- Use a **greedy approach** to check if it's possible to divide books among students such that **no one gets more than **``** pages**.

---

## 💻 C++ Code

```cpp
bool isPossible(vector<int>& arr, int m, int maxPages) {
    int studentCount = 1, pages = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > maxPages) return false;
        if (pages + arr[i] > maxPages) {
            studentCount++;
            pages = arr[i];
        } else {
            pages += arr[i];
        }
    }
    return studentCount <= m;
}

int allocateBooks(vector<int>& arr, int m) {
    int n = arr.size();
    if (m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}
```

---

## 🧲 Dry Run Example

```
Input: arr = [12, 34, 67, 90], m = 2
Search space: low = 90, high = 203

Iteration 1:
  mid = 146
  Allocation:
    Student 1: 12 + 34 + 67 = 113
    Student 2: 90
  ✅ 2 students → valid → update answer = 146, high = 145

Iteration 2:
  mid = 117 → ✅ valid → answer = 117, high = 116

Iteration 3:
  mid = 103 → ❌ requires 3 students → low = 104

Keep narrowing → final answer = 113
```

✅ **Final Output**: Minimum maximum number of pages = **113**

---

## 🚀 Applications

This Binary Search on Answer technique also applies to:

- **Painter's Partition Problem**
- **Split Array Largest Sum** (Leetcode 410)
- **Minimum Time to Paint Boards**

---

## 🎨 Painter's Partition Problem

### Problem:

Given `boards[] = [10, 20, 30, 40]`, and `k` painters.

Each painter paints **contiguous boards**. Minimize the **maximum time** to paint all boards.

### Approach:

- Exactly the same as Book Allocation:
  - `low = max(boards)`
  - `high = sum(boards)`
  - Binary search on the answer.

### Code:

```cpp
bool isPossible(vector<int>& boards, int k, int maxLen) {
    int painters = 1, total = 0;
    for (int i = 0; i < boards.size(); i++) {
        if (boards[i] > maxLen) return false;
        if (total + boards[i] > maxLen) {
            painters++;
            total = boards[i];
        } else {
            total += boards[i];
        }
    }
    return painters <= k;
}

int minTimeToPaint(vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(boards, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
```

---

## 📉 Dry Run for Painter's Problem

```
Input: boards = [10, 20, 30, 40], k = 2
Search Space = [40, 100]

Iteration 1:
  mid = 70
  Allocation:
    Painter 1: 10+20+30 = 60
    Painter 2: 40
  ✅ 2 painters → answer = 70, high = 69

Iteration 2:
  mid = 54 → ❌ → need 3 painters → low = 55

Iteration 3:
  mid = 62 → ✅ → answer = 62, high = 61

Iteration 4:
  mid = 60 → ✅ → final answer = 60
```

✅ **Final Output**: Minimum time required = **60**

---

## 🏊 Conclusion

Both **Book Allocation** and **Painter's Partition** problems follow the same Binary Search on Answer pattern.

> If you ever see:\
> **"Minimum of the Maximum"** or **"Split into contiguous parts"**,\
> then Binary Search + Greedy is likely the best approach.

---

> 💡 **Tip:** Always dry run edge cases like when `students > books` or when there's only 1 student.
