# Valid Palindrome (Without using <cctype> library)

## Problem:
Check if a string is a palindrome, ignoring non-alphanumeric characters and case sensitivity.

---

### ✅ Approach:
- Use two pointers (`left` and `right`) to scan the string from both ends.
- Skip non-alphanumeric characters manually.
- Convert uppercase to lowercase manually.
- Compare characters.
- Do not use any extra space or standard library helpers like `isalnum()` or `tolower()`.

---

### 🔧 C++ Code (with `continue`):
```cpp
class Solution {
public:
    // Custom isAlnum function
    bool isAlnum(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z') ||
               (c >= '0' && c <= '9');
    }

    // Custom toLower function
    char toLower(char c) {
        if (c >= 'A' && c <= 'Z')
            return c + 32; // Convert uppercase to lowercase
        return c;
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (!isAlnum(s[left])) {
                left++;
                continue;
            }

            if (!isAlnum(s[right])) {
                right--;
                continue;
            }

            if (toLower(s[left]) != toLower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};
```

---

### 📘 Dry Run:
**Input:** "A man, a plan, a canal: Panama"

| Step | left | right | s[left] | s[right] | toLower(left) | toLower(right) | Action         |
|------|------|--------|---------|-----------|----------------|------------------|----------------|
| 1    | 0    | 29     | 'A'     | 'a'       | 'a'            | 'a'              | match ✅        |
| 2    | 1    | 28     | ' '     | 'm'       | skip space     |                  | continue       |
| 3    | 2    | 28     | 'm'     | 'm'       | 'm'            | 'm'              | match ✅        |
| 4    | 3    | 27     | 'a'     | 'a'       | 'a'            | 'a'              | match ✅        |
| 5    | 4    | 26     | 'n'     | 'n'       | 'n'            | 'n'              | match ✅        |
| 6    | 5    | 25     | ','     | 'a'       | skip comma     |                  | continue       |
| 7    | 6    | 25     | ' '     | 'a'       | skip space     |                  | continue       |
| 8    | 7    | 25     | 'a'     | 'a'       | 'a'            | 'a'              | match ✅        |
| ...  | ...  | ...    | ...     | ...       | ...            | ...              | ...            |
| last| 14   | 15     | 'c'     | 'c'       | 'c'            | 'c'              | match ✅        |
| end | 15   | 14     |         |           | left >= right  |                  | return true ✅  |

---

### 🔄 What does `continue` do?
- If current character is not alphanumeric, we `continue` to next loop iteration.
- It **skips remaining lines in the current loop** and **goes directly to the next iteration**.

### 🔁 Visual Flow:
```
while (left < right):
    if s[left] is not alphanumeric:
        left++
        continue  <-- skip to next loop round

    if s[right] is not alphanumeric:
        right--
        continue  <-- skip to next loop round

    compare lowercase(left, right)
    if mismatch: return false
    else: move both pointers
```

---

### ✅ Output Examples:
```cpp
Input:  "race a car"        → Output: false
Input:  " "                 → Output: true
Input:  "No 'x' in Nixon"   → Output: true
```

---

### 🧠 Time and Space Complexity:
- Time: O(n)
- Space: O(1)  ✅ Optimal
