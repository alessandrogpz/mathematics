---
topic: Transforms
tags: [exercise, solution, rotations, rodrigues-rotation, matrix-derivation]
---
# Solution: 3D Rotations and Rodrigues' Rotation Formula

---

## Part 1: Coordinate Axis Rotation

### 1. Rotation Matrix ($\mathbf{M}_{\text{rot } y}$)

To rotate a vector $\vec{v} = v_x\vec{i} + v_y\vec{j} + v_z\vec{k}$ through a positive angle $\theta$ about the $y$-axis:
*   Because the rotation is centered on the $y$-axis, the basis vector $\vec{j}$ remains stationary:
    $$v_y' = v_y$$
*   The rotation occurs strictly in the $zx$-plane. We project and rotate the basis vectors $\vec{i}$ (x-axis) and $\vec{k}$ (z-axis) relative to a local orthonormal 2D basis where the horizontal axis is $\vec{i}$ and the vertical axis is $\vec{k}$:

#### Step A: Rotating the $x$-component basis vector ($v_x\vec{i}$)
Rotating positive $\vec{i}$ by an angle $\theta$ counterclockwise in the $zx$-plane sweeps it into the first quadrant between $\vec{i}$ and $\vec{k}$:
*   $$\cos\theta = \frac{\text{Adjacent}}{\text{Hypotenuse}} \implies \text{Adjacent} = v_x\cos\theta \quad (\text{along } \vec{i})$$
*   $$\sin\theta = \frac{\text{Opposite}}{\text{Hypotenuse}} \implies \text{Opposite} = v_x\sin\theta \quad (\text{along } \vec{k})$$

Thus:
$$\vec{v}_x\vec{i}' = v_x\cos\theta\vec{i} + v_x\sin\theta\vec{k}$$

#### Step B: Rotating the $z$-component basis vector ($v_z\vec{k}$)
Rotating positive $\vec{k}$ by an angle $\theta$ counterclockwise sweeps it into the second quadrant, landing it between $\vec{k}$ and $-\vec{i}$:
*   $$\cos\theta = \frac{\text{Adjacent}}{\text{Hypotenuse}} \implies \text{Adjacent} = v_z\cos\theta \quad (\text{along } \vec{k})$$
*   $$\sin\theta = \frac{\text{Opposite}}{\text{Hypotenuse}} \implies \text{Opposite} = v_z\sin\theta \quad (\text{along } -\vec{i})$$

Thus:
$$\vec{v}_z\vec{k}' = -v_z\sin\theta\vec{i} + v_z\cos\theta\vec{k}$$

#### Step C: Combined Rotated Vector
Adding these rotated components together gives the final transformed vector $\vec{v}'$:
$$\vec{v}' = \vec{i}(v_x\cos\theta - v_z\sin\theta) + v_y\vec{j} + \vec{k}(v_x\sin\theta + v_z\cos\theta)$$

Expressed as a system of linear equations in matrix form:
$$\begin{bmatrix} v'_x \\ v'_y \\ v'_z \end{bmatrix} = \begin{bmatrix} \cos\theta & 0 & -\sin\theta \\ 0 & 1 & 0 \\ \sin\theta & 0 & \cos\theta \end{bmatrix} \begin{bmatrix} v_x \\ v_y \\ v_z \end{bmatrix}$$

This is the explicit **$3 \times 3$ Rotation Matrix about the $y$-axis ($\mathbf{M}_{\text{rot } y}$)**

---

### 2. Transformed Vector Calculation
Given the initial vector $\vec{v} = \begin{bmatrix} 1 \\ 0 \\ 1 \end{bmatrix}$ and a positive rotation angle of $\theta = 90^\circ$:
We have $\cos 90^\circ = 0$, $\sin 90^\circ = 1$

$$\vec{v}' = \mathbf{M}_{\text{rot } y}\vec{v} = \begin{bmatrix} 0 & 0 & -1 \\ 0 & 1 & 0 \\ 1 & 0 & 0 \end{bmatrix} \begin{bmatrix} 1 \\ 0 \\ 1 \end{bmatrix} = \begin{bmatrix} (0)(1) + (0)(0) + (-1)(1) \\ (0)(1) + (1)(0) + (0)(1) \\ (1)(1) + (0)(0) + (0)(1) \end{bmatrix} = \begin{bmatrix} -1 \\ 0 \\ 1 \end{bmatrix}$$

---

### 3. Geometric Intuition
Here is the geometric intuition explaining why the rotated vector $\vec{v}'$ makes complete sense:
1.  **Y-axis Invariance:** The $y$-coordinate remains completely unchanged ($0$) because we are rotating centered on the $y$-axis.
2.  **Rotation Conventions (Direction of Swing):**
    *   **Under the Counter-Cyclic Convention:**
        *   **The $Z$-axis swings to the negative $X$-axis:** The original $Z$ coordinate was $1$. It rotates $90^\circ$ and lands on the negative side of the $X$-axis, becoming $-1$.
        *   **The $X$-axis swings to the positive $Z$-axis:** The original $X$ coordinate was $1$. It rotates $90^\circ$ to become your new $Z$ coordinate ($1$).
        *   This matches the calculated result: $\vec{v}' = \begin{bmatrix} -1 \\ 0 \\ 1 \end{bmatrix}$.
    *   **Under the Standard Cyclic Convention (Clockwise looking down $+y$):**
        *   **The $Z$-axis swings to the positive $X$-axis:** The original $Z$ coordinate was $1$. It rotates $90^\circ$ to become your new $X$ coordinate ($1$).
        *   **The $X$-axis swings to the negative $Z$-axis:** The original $X$ coordinate was $1$. It rotates $90^\circ$ and lands on the negative side of the $Z$-axis, becoming $-1$.
        *   This yields the standard cyclic result: $\vec{v}' = \begin{bmatrix} 1 \\ 0 \\ -1 \end{bmatrix}$.

---

## Part 2: Rotation About an Arbitrary Axis

### 1. Component Decomposition
[Insert your calculations for parallel and perpendicular pieces: $\vec{v}_{\parallel a} = (\vec{v} \cdot \vec{a})\vec{a}$ and $\vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a}$ here]

### 2. Rodrigues' Rotation Formula Application
[Insert your step-by-step substitution and vector arithmetic using Rodrigues' Rotation Formula here]

### 3. Matrix Multiplication Verification
*   **Skew-symmetric Matrix ($[\vec{a}]_{\times}$):** [Insert calculation here]
*   **Outer Product Matrix ($\vec{a}\vec{a}^T$):** [Insert calculation here]
*   **Arbitrary Axis Rotation Matrix ($\mathbf{M}_{\text{rot}}$):** [Insert calculation here]
*   **Product ($\mathbf{M}_{\text{rot}}\vec{v}$):** [Insert verification multiplication here]

---

## Code Implementation
```cpp
// Optional C++ snippet here
```

---

**Back to Question:** [[Q_Rotations]] | **Related Concepts:** [[02_Rotations]]
