# Permutation in String (Sliding Window)

## Problem Statement

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`. In other words, one of `s1`'s permutations is a substring of `s2`.

**Example:**

```cpp
s1 = "ab";
s2 = "eidbaooo";
// Output: true (because "ba" is a permutation of "ab")
```

---

## Approach: Sliding Window + Frequency Count

### Idea:

- A permutation of `s1` must have the same character frequency as `s1`.
- We can use a sliding window of length `s1.length()` over `s2` and check if the frequency of the characters in the current window matches with `s1`.

### Why Sliding Window?

- We want to check all substrings of length `s1.length()` in `s2`, but efficiently.
- Instead of generating substrings, we just update a character frequency array.

---

## C++ Code:

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> count1(26, 0), count2(26, 0);

        // Count frequency of characters in s1 and in the first window of s2
        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2) return true;

        // Slide the window
        for (int i = s1.length(); i < s2.length(); i++) {
            count2[s2[i] - 'a']++; // Add new character
            count2[s2[i - s1.length()] - 'a']--; // Remove old character

            if (count1 == count2) return true;
        }

        return false;
    }
};
```

---

## Dry Run Example:

Let:

```cpp
s1 = "ab", s2 = "eidbaooo"
```

### Step-by-Step:

1. Initial `count1` = [1 (a), 1 (b), 0, ..., 0]
2. First window in `s2` = "ei" → `count2` = [0, 0, 0, 0, 1 (e), 0, ..., 1 (i)] → ❌
3. Slide window:
   - i = 2 → window = "id" → Add `d`, Remove `e`
   - i = 3 → window = "db" → Add `b`, Remove `i`
   - i = 4 → window = "ba" → Add `a`, Remove `d` → ✅ Equal to `count1`

Return `true`

---

## Time & Space Complexity

| Complexity | Value                        |
| ---------- | ---------------------------- |
| Time       | O(n) where n = s2.length()   |
| Space      | O(1) → Only 26-length arrays |

---

## Summary:

- ✅ Use frequency count arrays
- ✅ Slide window instead of generating substrings
- ✅ Check equality at each window

---

## Practice:

- Leetcode 567: Permutation in String
- Leetcode 438: Find All Anagrams in a String

---


