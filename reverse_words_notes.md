# 🔄 Reverse Words in a String - C++ Notes

## 🧹 Problem Statement

Given a string `s`, reverse the order of words. A word is defined as a sequence of non-space characters. Remove any leading or trailing spaces and reduce multiple spaces between words to a single space.

### ✅ Input:

```cpp
"  the sky  is blue  "
```

### ✅ Output:

```cpp
"blue is sky the"
```

---

## 🚀 Approach (Reverse + Rebuild)

We use the following steps:

1. **Reverse the entire string** – This places the words in reverse order.
2. **Extract each word** – Skip spaces and form each word.
3. **Reverse each individual word** – To fix their character order.
4. **Build the result** – Concatenate with single spaces and return.

---

## 📌 C++ Code

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());  // Step 1: Reverse entire string

        string ans = "";
        for (int i = 0; i < n; i++) {
            string word = "";

            // Step 2: Extract word by skipping spaces
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Step 3: Reverse each word and append to result
            if (word.length() > 0) {
                reverse(word.begin(), word.end());
                ans += " " + word;
            }
        }

        // Step 4: Remove leading space
        return ans.substr(1);
    }
};
```

---

## 🧐 Dry Run Example

### Input:

```cpp
"  the sky  is blue  "
```

### After Step 1 (full reverse):

```cpp
"  eulb si  yks eht  "
```

### Iteration Steps:

| i  | s[i] | Action              | word | ans                |
| -- | ---- | ------------------- | ---- | ------------------ |
| 2  | 'e'  | Extract word `eulb` | eulb | ""                 |
|    |      | Reverse to `blue`   | blue | " blue"            |
| 7  | 's'  | Extract word `si`   | si   | " blue is"         |
| 11 | 'y'  | Extract word `yks`  | yks  | " blue is sky"     |
| 15 | 'e'  | Extract word `eht`  | eht  | " blue is sky the" |

### Final Output (after `substr(1)`):

```cpp
"blue is sky the"
```

---

## 📈 Complexity

| Type          | Complexity |
| ------------- | ---------- |
| Time          | O(n)       |
| Space (extra) | O(n)       |

---

## ✅ Notes

- Efficient and simple.
- Avoids using extra vector or `stringstream`.
- If you want to skip `substr(1)`, use this check:

```cpp
if (!ans.empty()) ans += " ";
ans += word;
```

---

> Created by Mukesh Seol’s assistant for GitHub-friendly notes ✨

