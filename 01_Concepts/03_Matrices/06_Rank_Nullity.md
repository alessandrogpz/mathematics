# Rank and Nullity

Rank and nullity are fundamental properties of a matrix that describe the dimensions of its associated vector spaces.

## Rank
The **rank** of a matrix $A$, denoted as $\text{rank}(A)$, is the dimension of the vector space spanned by its columns (or rows).
- **Equivalent Definitions:**
  - The number of linearly independent columns.
  - The number of linearly independent rows.
  - The number of non-zero rows in its **Row Echelon Form (REF)**.
- **Full Rank:** An $n \times n$ matrix has "full rank" if $\text{rank}(A) = n$. This is a requirement for the matrix to be invertible.

## Nullity
The **nullity** of a matrix $A$, denoted as $\text{null}(A)$, is the dimension of its **null space** (the set of all vectors $\vec{x}$ such that $A\vec{x} = \vec{0}$).
- It represents the number of "free variables" in the system $A\vec{x} = \vec{0}$.

## The Rank-Nullity Theorem
For any $m \times n$ matrix $A$:
$$\text{rank}(A) + \text{nullity}(A) = n$$
Where $n$ is the number of columns in the matrix.

### Why It Matters
- **Invertibility:** A square $n \times n$ matrix is invertible if and only if $\text{rank}(A) = n$ (and thus $\text{nullity}(A) = 0$).
- **Solutions to $A\vec{x} = \vec{b}$:** The rank tells us if a solution exists, and the nullity tells us if that solution is unique or if there are infinitely many.
