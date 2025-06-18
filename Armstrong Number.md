# 🔢 Armstrong Number (Narcissistic Number)

---

## 💡 What is an Armstrong Number?

An **Armstrong number** (also called a **narcissistic number**) is a number that is equal to the **sum of its own digits each raised to the power of the number of digits**.

---

## 🧠 Armstrong Number Rule

For a number with `k` digits:

```
(d₁)^k + (d₂)^k + ... + (dₖ)^k = number
```

If this holds true, the number is Armstrong.

---

## 🔢 Examples

### ✅ 153

- Digits: 1, 5, 3
- Number of digits = 3  
- Check:  
  `1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✅`

### ❌ 123

- Check:  
  `1³ + 2³ + 3³ = 36 ≠ 123 ❌`

---

## ✅ C++ Code

```cpp
#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int num) {
    int original = num;
    int sum = 0;
    int digits = 0;

    // Count digits
    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    // Calculate sum of powers
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    if (isArmstrong(n)) {
        cout << n << " is an Armstrong number.\\n";
    } else {
        cout << n << " is not an Armstrong number.\\n";
    }
    return 0;
}
```

---

## 🔁 Dry Run: Check for 9474

- Digits: 9, 4, 7, 4 (4 digits)

```text
3^3 = 9 
7^3 = 342 
1^3 = 1  
--------------
Sum  = 371

So, **371 is an Armstrong number**.

---

## 🧪 Test Cases

| Input | Output                         |
|-------|--------------------------------|
| 153   | Armstrong number ✅            |
| 370   | Armstrong number ✅            |
| 371   | Armstrong number ✅            |
| 123   | Not an Armstrong number ❌     |

---

## 🧠 Time and Space Complexity

| Metric          | Value              |
|-----------------|--------------------|
| Time Complexity | O(d) (d = digits)  |
| Space           | O(1)               |

---

## 📌 Summary

| Concept       | Description                                     |
|---------------|-------------------------------------------------|
| Armstrong     | Sum of digits raised to number of digits power |
| Use `pow()`   | To compute each digit power                    |

---

