---
topic: Transforms
tags: [exercise, solution, scaling, arbitrary-scale, uniform-scale]
---

# Solution: Scaling in 3D Space

This solution note is scaffolded to record your step-by-step derivations.

---

## Part 1: Calculation

### 1. Scale Matrix Construction
[Insert your calculation of the outer product matrix $\vec{a}\vec{a}^T$ and the final $3 \times 3$ scale matrix $\mathbf{M}_{\text{scale}}(s, \vec{a})$ here]

### 2. Transform a Vector
[Insert your matrix-vector multiplication $\vec{v}' = \mathbf{M}_{\text{scale}}(s, \vec{a})\vec{v}$ here]

### 3. Geometric Verification
[Insert your decomposition calculations for $\vec{v}_{\parallel a}$, $\vec{v}_{\perp a}$, and the verification sum $s\vec{v}_{\parallel a} + \vec{v}_{\perp a}$ here]

---

## Part 2: Conceptual Understanding

### 1. Determinant of Scaling
[Insert your geometric explanation of how a 1D stretch along $\vec{a}$ scales 3D volume by $s$ here]

### 2. Operator Unification ($s = 0$)
[Insert your analysis of the matrix when $s = 0$, its resulting equation, and its relationship to the plane projection matrix here]

### 3. Operator Unification ($s = -1$)
[Insert your comparison of the scaling operator when $s = -1$ to the plane reflection matrix $\mathbf{M}_{\text{reflect}}(\vec{a})$ here]

---

## Code Implementation
```cpp
// Optional C++ snippet here
```

---

**Back to Question:** [[Q_Scales]] | **Related Concepts:** [[04_Scales]]
