# Matrix Inversion

The primary purpose of a matrix inverse is to reverse a transformation. If $M$ transforms vector $\vec{v}$ into $\vec{u}$, then $M^{-1}$ transforms $\vec{u}$ back into $\vec{v}$.

## Fundamental Properties
| Property | Description |
| :--- | :--- |
| **Right Inverse** | $M M^{-1} = I$ |
| **Left Inverse** | $M^{-1} M = I$ |
| **Existence** | An inverse exists if and only if $\det(M) \neq 0$. |

## Method 1: Adjugate Matrix (Laplace)
To calculate the inverse of a matrix:
1. Calculate the matrix of cofactors $C$.
2. Transpose the cofactor matrix to get the **adjugate matrix**: $\text{adj}(A) = C^T$.
3. Divide each component by the determinant:
   $$A^{-1} = \frac{1}{\det(A)} \text{adj}(A)$$

## Method 2: Gauss-Jordan Elimination
This method uses an **augmented matrix** $[M | I]$:
1. Write the matrix $M$ on the left and the identity matrix $I$ on the right.
2. Apply row operations to transform the left side into the identity matrix.
3. Apply the *same* operations to the right side simultaneously.
4. When the left side becomes $I$, the right side will have become $M^{-1}$.

### Possible Row Operations
| Operation | Effect on Determinant (Optional Info) |
| :--- | :--- |
| **Row Swap** | Swapping two rows. |
| **Scalar Mult** | Multiplying a row by a non-zero scalar. |
| **Row Addition** | Adding or subtracting a multiple of one row from another. |
