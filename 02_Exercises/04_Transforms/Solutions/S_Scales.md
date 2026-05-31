---
topic: Transforms
tags: [exercise, solution, scaling, arbitrary-scale, uniform-scale]
---

# Solution: Scaling in 3D Space

This solution note provides the mathematical derivations, explicit matrix constructions, and vector verifications for your practice exercises.

---

## Part 1: Calculation

### 1. Scale Matrix Construction

We start with the vector equation for arbitrary scaling by factor $s$ along a unit direction vector $\vec{a}$ (where $\|\vec{a}\| = 1$):

$$
\vec{v}' = s\vec{v}_{\parallel a} + \vec{v}_{\perp a}
$$

To represent this transformation in matrix form, we decompose the input vector $\vec{v}$ into:
*   **Parallel Component ($\vec{v}_{\parallel a}$):** The projection of $\vec{v}$ onto the unit vector $\vec{a}$:
    $$
    \vec{v}_{\parallel a} = \text{proj}_{\vec{a}}\vec{v} = (\vec{v} \cdot \vec{a})\vec{a}
    $$
    Using matrix notation for the dot product of $3 \times 1$ column vectors $\vec{v}$ and $\vec{a}$:
    $$
    \vec{v} \cdot \vec{a} = \vec{a}^T\vec{v}
    $$
    Substituting this back into the projection formula:
    $$
    \vec{v}_{\parallel a} = (\vec{a}^T\vec{v})\vec{a} = \vec{a}(\vec{a}^T\vec{v}) = (\vec{a}\vec{a}^T)\vec{v}
    $$
*   **Perpendicular Component ($\vec{v}_{\perp a}$):** The component orthogonal to the scaling direction $\vec{a}$:
    $$
    \vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a} = \mathbf{I}\vec{v} - (\vec{a}\vec{a}^T)\vec{v} = (\mathbf{I} - \vec{a}\vec{a}^T)\vec{v}
    $$

Substituting these back into the main scaling equation:

$$
\vec{v}' = s(\vec{a}\vec{a}^T)\vec{v} + (\mathbf{I} - \vec{a}\vec{a}^T)\vec{v}
$$

Factoring out the common vector $\vec{v}$:

$$
\vec{v}' = \big(s\vec{a}\vec{a}^T + \mathbf{I} - \vec{a}\vec{a}^T\big)\vec{v}
$$

$$
\vec{v}' = \big(\mathbf{I} + (s-1)\vec{a}\vec{a}^T\big)\vec{v}
$$

Since the transformation is represented by $\vec{v}' = \mathbf{M}_{\text{scale}}(s, \vec{a})\vec{v}$, this proves the **Arbitrary Scale Matrix**:

$$
\mathbf{M}_{\text{scale}}(s, \vec{a}) = \mathbf{I} + (s-1)\vec{a}\vec{a}^T
$$

From here, we expand this operator into explicit $3 \times 3$ coordinate form:

$$
\mathbf{M}_{\text{scale}}(s, \vec{a}) = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} + (s-1)\begin{bmatrix} a_x^2 & a_x a_y & a_x a_z \\\\ a_x a_y & a_y^2 & a_y a_z \\\\ a_x a_z & a_y a_z & a_z^2 \end{bmatrix}
$$

$$
\mathbf{M}_{\text{scale}}(s, \vec{a}) = \begin{bmatrix} (s-1)a_x^2 + 1 & (s-1)a_x a_y & (s-1)a_x a_z \\\\ (s-1)a_x a_y & (s-1)a_y^2 + 1 & (s-1)a_y a_z \\\\ (s-1)a_x a_z & (s-1)a_y a_z & (s-1)a_z^2 + 1 \end{bmatrix}
$$

Now we substitute our specific values, $s = 3$ and the unit vector $\vec{a} = \begin{bmatrix} 0 \\\\ \frac{\sqrt{2}}{2} \\\\ \frac{\sqrt{2}}{2} \end{bmatrix}$:
*   $a_x = 0$
*   $a_y = \frac{\sqrt{2}}{2} \implies a_y^2 = \frac{1}{2}$
*   $a_z = \frac{\sqrt{2}}{2} \implies a_z^2 = \frac{1}{2}$
*   $a_x a_y = 0 \cdot \frac{\sqrt{2}}{2} = 0$
*   $a_x a_z = 0 \cdot \frac{\sqrt{2}}{2} = 0$
*   $a_y a_z = \frac{\sqrt{2}}{2} \cdot \frac{\sqrt{2}}{2} = \frac{1}{2}$

Evaluating the matrix elements:
*   $(s-1)a_x^2 + 1 = 2(0) + 1 = 1$
*   $(s-1)a_x a_y = 2(0) = 0$
*   $(s-1)a_x a_z = 2(0) = 0$
*   $(s-1)a_y^2 + 1 = 2\left(\frac{1}{2}\right) + 1 = 2$
*   $(s-1)a_y a_z = 2\left(\frac{1}{2}\right) = 1$
*   $(s-1)a_z^2 + 1 = 2\left(\frac{1}{2}\right) + 1 = 2$

This yields the complete transformation matrix:

$$
\mathbf{M}_{\text{scale}}(3, \vec{a}) = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 2 & 1 \\\\ 0 & 1 & 2 \end{bmatrix}
$$

This matrix represents a scaling transformation of scale $s = 3$ along the $\vec{a}$ axis.

---

### 2. Transform a Vector

We calculate the scaled vector $\vec{v}' = \mathbf{M}_{\text{scale}}(3, \vec{a})\vec{v}$ for the input vector $\vec{v} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}$:

$$
\vec{v}' = \begin{bmatrix} 1 & 0 & 0 \\\\ 0 & 2 & 1 \\\\ 0 & 1 & 2 \end{bmatrix} \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
$$

$$
\vec{v}' = \begin{bmatrix} 1(4) + 0(1) + 0(-1) \\\\ 0(4) + 2(1) + 1(-1) \\\\ 0(4) + 1(1) + 2(-1) \end{bmatrix}
$$

$$
\vec{v}' = \begin{bmatrix} 4 \\\\ 2 - 1 \\\\ 1 - 2 \end{bmatrix} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
$$

**Geometric Observation:** The resulting vector $\vec{v}'$ is exactly equal to the input vector $\vec{v}$. This is because the input vector $\vec{v}$ lies completely perpendicular (orthogonal) to the scaling direction $\vec{a}$, which we verify by their dot product:
$$
\vec{v} \cdot \vec{a} = 4(0) + 1\left(\frac{\sqrt{2}}{2}\right) - 1\left(\frac{\sqrt{2}}{2}\right) = 0
$$
Since $\vec{v}$ is perpendicular to $\vec{a}$, scaling space along $\vec{a}$ leaves $\vec{v}$ entirely unaffected.

---

### 3. Geometric Verification

We verify this result by decomposing the vector $\vec{v}$ into parallel and perpendicular components relative to the unit vector $\vec{a}$:

*   **Parallel Component ($\vec{v}_{\parallel a}$):**
    $$
    \vec{v}_{\parallel a} = (\vec{v} \cdot \vec{a})\vec{a}
    $$
    Since the dot product $\vec{v} \cdot \vec{a} = 0$:
    $$
    \vec{v}_{\parallel a} = 0 \cdot \vec{a} = \begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix}
    $$
*   **Perpendicular Component ($\vec{v}_{\perp a}$):**
    $$
    \vec{v}_{\perp a} = \vec{v} - \vec{v}_{\parallel a} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix} - \begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
    $$

*   **Decomposition Verification:**
    Applying the scale factor $s = 3$ to only the parallel component and adding the perpendicular component:
    $$
    \vec{v}' = s\vec{v}_{\parallel a} + \vec{v}_{\perp a}
    $$
    $$
    \vec{v}' = 3\begin{bmatrix} 0 \\\\ 0 \\\\ 0 \end{bmatrix} + \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix} = \begin{bmatrix} 4 \\\\ 1 \\\\ -1 \end{bmatrix}
    $$

This perfectly matches the matrix multiplication result from Step 2!

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

The following C++ helper functions construct an arbitrary 3D scaling matrix and apply it to a vector:

```cpp

```

---

**Back to Question:** [[Q_Scales]] | **Related Concepts:** [[04_Scales]]
