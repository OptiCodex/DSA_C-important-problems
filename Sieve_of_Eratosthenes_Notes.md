
# 🔢 Count Primes Using Sieve of Eratosthenes-->

---

## ✅ Problem Statement

Given an integer `n`, return the number of prime numbers that are strictly less than `n`.

---

## 🧠 Algorithm Used: Sieve of Eratosthenes

We use the **Sieve of Eratosthenes**, which is efficient for generating all prime numbers below `n`.

---

## ✅ Key Idea

- A number is **prime** if it has only two divisors: `1` and itself.
- Create a boolean array `prime[]` of size `n`, where `prime[i]` indicates whether `i` is a prime number.

---

## ✅ C++ Code (Overflow Safe)

```cpp
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> prime(n, true);
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
                for (long long j = 1LL * i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        return count;
    }
};
```

---

## 🔍 Dry Run Example

Let’s take `n = 10`.

### Initialization:
```
prime = [T, T, T, T, T, T, T, T, T, T]
index =  0  1  2  3  4  5  6  7  8  9
```

Set `prime[0] = false`, `prime[1] = false`

```
prime = [F, F, T, T, T, T, T, T, T, T]
```

### Step-by-step:

#### i = 2 → prime[2] = T
- count = 1
- Mark multiples of 2 starting from `2*2 = 4`
  - prime[4] = false
  - prime[6] = false
  - prime[8] = false

#### i = 3 → prime[3] = T
- count = 2
- Mark multiples of 3 starting from `3*3 = 9`
  - prime[9] = false

#### i = 4 → prime[4] = F → skip  
#### i = 5 → prime[5] = T
- count = 3

No multiples of 5 < 10 to mark

#### i = 6 → prime[6] = F → skip  
#### i = 7 → prime[7] = T
- count = 4

#### i = 8, 9 → not prime

---

## ✅ Final `prime[]` array

```
prime = [F, F, T, T, F, T, F, T, F, F]
index =  0  1  2  3  4  5  6  7  8  9
```

✅ Primes < 10 → **2, 3, 5, 7** → Output = **4**

---

## ⏱️ Time and Space Complexity

| Metric              | Value                  |
|---------------------|------------------------|
| Time Complexity     | O(n log log n)         |
| Space Complexity    | O(n)                   |

---

## ⚠️ Note on Overflow

To avoid overflow in:
```cpp
for (int j = i * i; j < n; j += i)
```

We use:
```cpp
for (long long j = 1LL * i * i; j < n; j += i)
```

This ensures multiplication is done in 64-bit space and avoids undefined behavior for large `i`.

---

## 🧠 Summary

- Use boolean array `prime[n]` initialized to `true`
- Loop from `2` to `n`
  - If `prime[i]` is true, increment count and mark all multiples of `i` as false
- Use `long long` in inner loop to avoid overflow

---
