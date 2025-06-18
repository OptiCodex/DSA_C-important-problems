# Euclid's Theorem for GCD (Greatest Common Divisor)

## 1. Introduction

Euclid's theorem provides the foundation for finding the GCD (Greatest Common Divisor) of two integers. There are two major forms:

- **Modulo-based Euclidean Algorithm**
- **Subtraction-based Euclidean Algorithm**

---

## 2. Modulo-Based Euclidean Algorithm

### Theorem:

> For two integers `a` and `b`,
>
> **gcd(a, b) = gcd(b, a % b)**

### Base Case:

> **gcd(a, 0) = a**

### Steps:

1. Divide `a` by `b`, get the remainder `r = a % b`
2. Replace `a` with `b` and `b` with `r`
3. Repeat until `b = 0`
4. The non-zero `a` is the GCD

### Example:

Find `gcd(48, 18)`

```
gcd(48, 18) => gcd(18, 48 % 18) => gcd(18, 12)
gcd(18, 12) => gcd(12, 6)
gcd(12, 6)  => gcd(6, 0)
=> GCD = 6
```

### C++ Code:

```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
```

### Time Complexity:

> **O(log max(a, b))**

---

## 3. Subtraction-Based Euclidean Algorithm

### Theorem:

> If `a > b`, then:
>
> **gcd(a, b) = gcd(a - b, b)**

This method uses subtraction repeatedly until both numbers become equal.

### Steps:

1. Subtract the smaller number from the larger
2. Repeat until both numbers become equal
3. That value is the GCD

### Example:

Find `gcd(48, 18)`

```
gcd(48, 18) => gcd(30, 18) [48 - 18]
gcd(30, 18) => gcd(12, 18) [30 - 18]
gcd(12, 18) => gcd(12, 6)  [18 - 12]
gcd(12, 6)  => gcd(6, 6)   [12 - 6]
gcd(6, 6)   => gcd(6, 0)
=> GCD = 6
```

### Recursive C++ Code:

```cpp
int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;

    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}
```

### Time Complexity:

> **O(max(a, b))**

---

## 4. Comparison

| Method             | Formula                     | Time Complexity    |
| ------------------ | --------------------------- | ------------------ |
| Modulo (Efficient) | `gcd(a, b) = gcd(b, a % b)` | `O(log max(a, b))` |
| Subtraction        | `gcd(a, b) = gcd(a, b - a)` | `O(max(a, b))`     |

---

## 5. Summary

Both methods are mathematically correct, but the modulo-based version is faster and commonly used in programming.

Use subtraction-based when modulo operation is not available (e.g., older systems, or basic manual computation).

