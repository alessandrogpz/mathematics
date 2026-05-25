# Rotations in 3D Space

In 3D game engines and graphics programming, rotations are fundamental transformations. A rotation typically occurs within a local coordinate system where the axis of rotation is aligned with one of the coordinate axes ($x$, $y$, or $z$), though they can also be performed about an arbitrary axis specified by a unit direction vector.

## 1. Handedness and Rotation Conventions
To ensure consistency across calculations, we follow standard convention:
*   **Right-Handed Coordinate System:** A positive rotation angle $\theta$ represents a **counterclockwise** rotation when looking down the axis of rotation toward the origin (i.e., when the axis points directly toward the viewer).

---

## 2. Derivation: Rotation About a Coordinate Axis
A rotation about the $x$, $y$, or $z$ axis occurs in the plane formed by the *other* two axes. 

Let's derive the transformation matrix for a vector $\vec{v}$ rotated through an angle $\theta$ **about the $z$-axis**:
*   Using the standard orthogonal basis vectors $\vec{i}$, $\vec{j}$, and $\vec{k}$ parallel to the coordinate axes, we express any vector $\vec{v}$ as:
    $$\vec{v} = v_x \vec{i} + v_y \vec{j} + v_z \vec{k}$$
*   Since the rotation is *about* the $z$-axis, the basis vector $\vec{k}$ is parallel to the axis of rotation. Therefore, **the $z$-component $v_z$ remains unchanged**.
*   The basis vectors $\vec{i}$ and $\vec{j}$ lie in the $xy$-plane of rotation and are both rotated by the angle $\theta$.

### Step 1: Rotating the $\vec{i}$ Basis Component ($v_x\vec{i}$)
Rotating the positive x-axis basis vector $\vec{i}$ by an angle $\theta$ sweeps it into the first quadrant. Using right-triangle trigonometry, we decompose the rotated vector into its new components along $\vec{i}$ and $\vec{j}$:

$$\cos\theta = \frac{\text{Adjacent}}{\text{Hypotenuse}} \implies \text{Adjacent} = v_x\cos\theta \quad (\text{along } \vec{i})$$
$$\sin\theta = \frac{\text{Opposite}}{\text{Hypotenuse}} \implies \text{Opposite} = v_x\sin\theta \quad (\text{along } \vec{j})$$

Thus, the rotated $x$-component is:
$$v_x\vec{i}' = v_x\cos\theta\vec{i} + v_x\sin\theta\vec{j}$$

![[98_Assets/Concepts/vxi.webp]]

---

### Step 2: Rotating the $\vec{j}$ Basis Component ($v_y\vec{j}$)
Rotating the positive y-axis basis vector $\vec{j}$ by an angle $\theta$ sweeps it into the second quadrant. 
*   **Sign Correction:** Because the vector swings to the left of the positive y-axis, its new component along the $\vec{i}$ axis points in the negative direction:

$$\cos\theta = \frac{\text{Adjacent}}{\text{Hypotenuse}} \implies \text{Adjacent} = v_y\cos\theta \quad (\text{along } \vec{j})$$
$$\sin\theta = \frac{\text{Opposite}}{\text{Hypotenuse}} \implies \text{Opposite} = v_y\sin\theta \quad (\text{along } -\vec{i})$$

Thus, the rotated $y$-component is:
$$v_y\vec{j}' = -v_y\sin\theta\vec{i} + v_y\cos\theta\vec{j}$$

![[98_Assets/Concepts/vyj.webp]]


---

### Step 3: Combining the Rotated Components
By summing the transformed parts, the final rotated vector $\vec{v}'$ is:
$$\vec{v}' = v_x\vec{i}' + v_y\vec{j}' + v_z\vec{k}$$
$$\vec{v}' = (v_x\cos\theta - v_y\sin\theta)\vec{i} + (v_x\sin\theta + v_y\cos\theta)\vec{j} + v_z\vec{k}$$

We can express this system of linear equations as a matrix-vector product:
$$\begin{bmatrix} v'_x \\ v'_y \\ v'_z \end{bmatrix} = \begin{bmatrix} \cos\theta & -\sin\theta & 0 \\ \sin\theta & \cos\theta & 0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} v_x \\ v_y \\ v_z \end{bmatrix}$$

This $3 \times 3$ matrix is the **general transformation matrix for rotating through an angle $\theta$ about the $z$-axis**.

---

## 3. Standard 3D Rotation Matrices

Applying this identical geometric derivation to rotations about the other coordinate axes yields the three principal rotation matrices:

### Rotation About the $x$-Axis ($\mathbf{M}_{\text{rot } x}$)
Rotates vectors within the $yz$-plane:
$$\mathbf{M}_{\text{rot } x} = \begin{bmatrix} 1 & 0 & 0 \\ 0 & \cos\theta & -\sin\theta \\ 0 & \sin\theta & \cos\theta \end{bmatrix}$$

### Rotation About the $y$-Axis ($\mathbf{M}_{\text{rot } y}$)
Rotates vectors within the $zx$-plane:
$$\mathbf{M}_{\text{rot } y} = \begin{bmatrix} \cos\theta & 0 & \sin\theta \\ 0 & 1 & 0 \\ -\sin\theta & 0 & \cos\theta \end{bmatrix}$$

### Rotation About the $z$-Axis ($\mathbf{M}_{\text{rot } z}$)
Rotates vectors within the $xy$-plane:
$$\mathbf{M}_{\text{rot } z} = \begin{bmatrix} \cos\theta & -\sin\theta & 0 \\ \sin\theta & \cos\theta & 0 \\ 0 & 0 & 1 \end{bmatrix}$$

> [!IMPORTANT]
> Because coordinate systems are cyclic ($x \to y \to z \to x$), rotating in the $zx$-plane causes the negative sign to appear in the bottom-left entry $(3, 1)$ instead of the top-right entry $(1, 3)$ in $\mathbf{M}_{\text{rot } y}$.

---

## 4. Properties of Rotation Matrices
All principal rotation matrices are **orthogonal matrices**, meaning they exhibit the following key properties:
1.  **Inverse equals Transpose:** $\mathbf{M}^{-1} = \mathbf{M}^T$. This makes inverting a rotation incredibly cheap computationally.
2.  **Determinant equals 1:** $\det(\mathbf{M}) = 1$. This confirms they are orientation-preserving pure rotations.
3.  **Preservation:** They preserve vector lengths, angles, and dot products.
