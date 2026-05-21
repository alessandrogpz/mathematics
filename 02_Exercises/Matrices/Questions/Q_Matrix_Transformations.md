---
topic: Matrices
difficulty: Hard
tags: [exercise, question, transformation, scaling, rotation, translation, homogeneous-coordinates]
---
# Question
A 2D point is located at $(2, 1)$. Using homogeneous coordinates, its column vector is $\mathbf{p} = \begin{bmatrix} 2 \\ 1 \\ 1 \end{bmatrix}$.

Apply the following operations mathematically in the standard SRT order (Scale, Rotate, Translate):

1. Uniform scale by 3.
    
2. Rotate 90° counter-clockwise.
    
3. Translate by $T_x = 5$ and $T_y = -2$.
    

Construct the three distinct $3 \times 3$ matrices. Multiply them together to create a single transformation matrix $M$, then multiply $M \mathbf{p}$ to find the final coordinates.

---
**Check Answer:** [[S_Matrix_Transformations]]