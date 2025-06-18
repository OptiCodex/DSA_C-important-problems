
# 🧩 Leetcode 443 - String Compression

## ✅ Problem Statement

Given an array of characters `chars`, compress it in-place such that:
- Repeated characters are replaced by the character followed by the count.
- Only characters with count > 1 have the count written.
- The function returns the length of the compressed array.

> Example:
> Input: `['a','a','b','b','c','c','c']`  
> Output: `['a','2','b','2','c','3']`  
> Return: `6`

---

## ✅ Approach

We traverse the array and for each group of **consecutive repeating characters**:
1. Count the number of times the character repeats.
2. Insert the character.
3. If the count > 1, convert it to string and insert each digit.

We use a write pointer `idx` to insert values directly into the original array (`in-place` compression).

---

## ✅ C++ Code

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;  // Write index

        for (int i = 0; i < chars.size(); i++) {
            int count = 0;
            char ch = chars[i];

            // Count repeating characters
            while (i < chars.size() && chars[i] == ch) {
                count++;
                i++;
            }

            // Insert character
            chars[idx++] = ch;

            // Insert count if > 1
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[idx++] = c;
                }
            }

            // Adjust for loop increment
            i--;
        }

        return idx;
    }
};
```

---

## 🧠 Dry Run Example

Input:  
`chars = ['a','a','b','b','c','c','c']`

### Step-by-step:

| Step | i | ch | count | chars (after write)     | idx |
|------|---|----|-------|--------------------------|-----|
| 1    | 0 | a  | 2     | `['a','2']`               | 2   |
| 2    | 2 | b  | 2     | `['a','2','b','2']`       | 4   |
| 3    | 4 | c  | 3     | `['a','2','b','2','c','3']`| 6   |

Return value: `6`

Final compressed array: `['a','2','b','2','c','3']`

---

## 🧠 Key Concepts

- ✅ Group characters using `while` loop
- ✅ Use `to_string(count)` to convert integer to string
- ✅ Write directly into input array using `idx`
- ✅ Use `i--` to correct over-increment caused by `while` and `for`

---

## ⏱ Time and Space Complexity

- **Time:** O(n) — each character visited once
- **Space:** O(1) — constant extra space (in-place)

---

## 🔚 Final Notes

- Works for all valid inputs
- Handles multi-digit counts like `'a', '1', '2'` for 12 repetitions
- Clean logic with one loop and one `while`

---
