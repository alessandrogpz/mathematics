---
topic: Transforms
tags: [exercise, solution, skew, shear, linear-transformation]
---

# Solution: Skew (Shear) in 3D Space

This solution note is scaffolded to record your step-by-step derivations for the skew exercises in [[Q_Skews]].

---

## Part 1: Calculation

### 1. Skew Matrix Construction
We construct the $3 \times 3$ skew matrix $\mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b})$ using:
$$
\vec{a} = \begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix}, \quad \vec{b} = \begin{bmatrix} 0 \\\\ 1 \\\\ 0 \end{bmatrix}, \quad \theta = 45^\circ
$$

Using the outer-product formulation:
$$
\mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b}) = \mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T
$$

First, calculate the outer product $\vec{a}\vec{b}^T$:
$$
\vec{a}\vec{b}^T = \begin{bmatrix} a_x \\\\ a_y \\\\ a_z \end{bmatrix} \begin{bmatrix} b_x & b_y & b_z \end{bmatrix} = \begin{bmatrix} a_x b_x & a_x b_y & a_x b_z \\\\ a_y b_x & a_y b_y & a_y b_z \\\\ a_z b_x & a_z b_y & a_z b_z \end{bmatrix}
$$

This gives the general skew matrix form:
$$
\mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b}) = \begin{bmatrix} 1 + a_x b_x \tan\theta & a_x b_y \tan\theta & a_x b_z \tan\theta \\\\ a_y b_x \tan\theta & 1 + a_y b_y \tan\theta & a_y b_z \tan\theta \\\\ a_z b_x \tan\theta & a_z b_y \tan\theta & 1 + a_z b_z \tan\theta \end{bmatrix}
$$

For our given values, we have $\tan(45^\circ) = 1$. Substituting $\vec{a}$ and $\vec{b}$:
$$
\mathbf{M}_{\text{skew}}(45^\circ, \vec{a}, \vec{b}) = \begin{bmatrix} 1 + (1)(0)(1) & (1)(1)(1) & (1)(0)(1) \\\\ (0)(0)(1) & 1 + (0)(1)(1) & (0)(0)(1) \\\\ (0)(0)(1) & (0)(1)(1) & 1 + (0)(0)(1) \end{bmatrix} = \begin{bmatrix} 1 & 1 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix}
$$

#### Derivation of the Outer Product Formula (How to arrive at $\mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T$)
From the geometry of a skew transformation:
*   The transformed vector is $\vec{v}' = \vec{v} + \text{displacement vector}$.
*   The height of the vector relative to the measurement axis $\vec{b}$ is its projection: $\vec{v}_{\parallel \vec{b}} = \text{Comp}_{\vec{b}} \vec{v} = (\vec{b} \cdot \vec{v})$.
*   The displacement is along the direction $\vec{a}$, proportional to the height and the skew factor $K = \tan\theta$:
    $$
    \text{displacement} = (\vec{b} \cdot \vec{v})\tan\theta \, \vec{a}
    $$
*   Therefore:
    $$
    \vec{v}' = \vec{v} + (\vec{b} \cdot \vec{v})\tan\theta \, \vec{a}
    $$
*   Using the algebraic identity $(\vec{b} \cdot \vec{v})\vec{a} = \vec{a}(\vec{b}^T \vec{v}) = (\vec{a}\vec{b}^T)\vec{v}$, we get:
    $$
    \vec{v}' = \vec{v} + (\vec{a}\vec{b}^T)\vec{v}\tan\theta = (\mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T)\vec{v}
    $$
    $$
    \mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b}) = \mathbf{I} + \tan\theta \, \vec{a}\vec{b}^T
    $$

### 2. Transform a Vector
To calculate the transformed vector $\vec{v}'$ for the input vector $\vec{v} = [2, 3, 5]^T$:
$$
\vec{v}' = \mathbf{M}_{\text{skew}}(45^\circ, \vec{a}, \vec{b})\vec{v} = \begin{bmatrix} 1 & 1 & 0 \\\\ 0 & 1 & 0 \\\\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} 2 \\\\ 3 \\\\ 5 \end{bmatrix} = \begin{bmatrix} 2 + 3 \\\\ 3 \\\\ 5 \end{bmatrix} = \begin{bmatrix} 5 \\\\ 3 \\\\ 5 \end{bmatrix}
$$

### 3. Geometric Verification
To geometrically verify the result using the vector equation:
$$
\vec{v}' = \vec{v} + (\vec{b} \cdot \vec{v})\tan\theta \, \vec{a}
$$

1. **Calculate the Dot Product (Projection Height):**
   $$
   \vec{b} \cdot \vec{v} = \begin{bmatrix} 0 \\\\ 1 \\\\ 0 \end{bmatrix} \cdot \begin{bmatrix} 2 \\\\ 3 \\\\ 5 \end{bmatrix} = (0)(2) + (1)(3) + (0)(5) = 3
   $$

2. **Evaluate the Equation:**
   Substitute the components ($\vec{b} \cdot \vec{v} = 3$, $\tan(45^\circ) = 1$, and $\vec{a} = [1, 0, 0]^T$):
   $$
   \vec{v}' = \begin{bmatrix} 2 \\\\ 3 \\\\ 5 \end{bmatrix} + (3)(1)\begin{bmatrix} 1 \\\\ 0 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 2 \\\\ 3 \\\\ 5 \end{bmatrix} + \begin{bmatrix} 3 \\\\ 0 \\\\ 0 \end{bmatrix} = \begin{bmatrix} 5 \\\\ 3 \\\\ 5 \end{bmatrix}
   $$

Both the matrix multiplication result and the geometric formula yield the identical result:
$$
\vec{v}' = \begin{bmatrix} 5 \\\\ 3 \\\\ 5 \end{bmatrix}
$$

---

## Part 2: Conceptual Understanding

### 1. Determinant of Skew
[Insert your geometric explanation of volume preservation and determinant calculation here]

### 2. Composition of Opposite Skews
[Insert your algebraic proof of $\mathbf{M}_{\text{skew}}(\theta, \vec{a}, \vec{b})\mathbf{M}_{\text{skew}}(-\theta, \vec{a}, \vec{b}) = \mathbf{I}$ here]

### 3. Orthogonality Constraint
[Insert your analysis of the perpendicularity constraint ($\vec{a} \cdot \vec{b} = 0$) and the consequences of parallel vectors here]

---

**Back to Question:** [[Q_Skews]] | **Related Concepts:** [[05_Skews]]
