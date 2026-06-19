# Quaternion Intuition: Dimensional Projections

Quaternions are a four-dimensional extension of complex numbers. While complex numbers extend the real numbers into a 2D plane ($\mathbb{C} = \mathbb{R} + i\mathbb{R}$), quaternions extend them into a 4D space ($\mathbb{H} = \mathbb{R} + i\mathbb{R} + j\mathbb{R} + k\mathbb{R}$). 

In graphics programming, game engines, physics simulations, and quantum mechanics, quaternions provide an elegant, compact, and computationally efficient way to represent and compute 3D rotations without suffering from **Gimbal Lock**.

---

## 1. Geometric Intuition: Dimensional Projections

To build an intuitive understanding of a 4D object (like a quaternion) operating in our 3D world, we can study how rotation in $N$-dimensional space is viewed by projecting it down into $N-1$ dimensions using **Stereographic Projection**. This conformal (angle-preserving) mapping technique allows us to trace high-dimensional rotations as continuous motions and coordinate warping in lower-dimensional spaces.

### 1D Projection (Rotating a 2D Circle onto a Line)

Consider a 2D unit circle (a 1-sphere, $S^1$) sitting in a 2D plane defined by a real horizontal axis $w$ and an imaginary vertical axis $i$. The circle represents all complex numbers $z = w + xi$ with magnitude $\|z\| = 1$ (so $w^2 + x^2 = 1$). 

We project this circle onto the vertical 1D imaginary axis (the line $w = 0$) using a projection source at the "south pole" $(-1, 0)$, representing the point $-1$ on the real axis:
1. Draw a straight line from the projection source $(-1, 0)$ through any point $(w, x)$ on the circle.
2. The intersection of this line with the vertical axis ($w = 0$) is the stereographic projection of that point.

<center>
  <!-- Placeholder for 1D Projection Diagram: mapping_circle_to_line.webp -->
  <img src="../../98_Assets/Concepts/mapping_circle_to_line.webp" width="650" height="250" alt="Stereographic projection of a 2D circle onto a 1D line">
</center>

Algebraically, the stereographic projection $p$ of a point $w + xi$ is given by:

$$
p = \frac{x}{w + 1}i
$$

Under this mapping, specific reference points on the circle project as follows:
*   **The point $+1$ ($w = 1, x = 0$):** Projects to the origin ($0$) in the center of the vertical line.
*   **The point $i$ ($w = 0, x = 1$):** Projects to the point $i$ on the line.
*   **The point $-i$ ($w = 0, x = -1$):** Projects to the point $-i$ on the line.
*   **The point $-1$ ($w = -1, x = 0$):** Since this is the projection source, the projection line is horizontal and parallel to the vertical axis, projecting it to infinity ($\pm\infty$).

#### Visualizing Rotation as a Continuous Flow
If we rotate the circle counterclockwise (corresponding to successive multiplications by $i$: $1 \to i \to -1 \to -i \to 1$), we can watch how the projected points flow along the 1D line:

<center>
  <!-- Placeholder for 2D Projection Diagram: rotating_2D_streographic_projection.webp -->
  <img src="../../98_Assets/Concepts/rotating_2D_streographic_projection.webp" width="400" height="300" alt="Rotating stereographic projection of a 2D sphere onto a 1D line">
</center>

1. A point starting at the center (the projection of $+1$) flows **upwards** towards $i$.
2. As the circle continues to rotate towards $-1$, the projected point moves rapidly upwards past $i$ towards $+\infty$.
3. As the point on the circle crosses the south pole $-1$, its projection wraps around from $+\infty$ to $-\infty$.
4. The projected point then continues flowing upwards from $-\infty$ through $-i$, eventually returning to the center $0$.

Thus, a closed 2D rotation of the circle corresponds to a continuous, upward flow along the 1D line that wraps around at infinity.

### 2D Projection (Rotating a 3D Sphere onto a Plane)

We scale this concept up by projecting a 3D unit sphere (a 2-sphere, $S^2$) onto a 2D plane. Let the sphere be defined by $w^2 + x^2 + y^2 = 1$ in a 3D coordinate system where:
*   The vertical axis is the real axis ($w$, representing the scalar component).
*   The horizontal axes are the imaginary axes ($i$ and $j$, representing the vector components).

We project the sphere from the south pole $S = -1$ (the point $(-1, 0, 0)$ where the real component $w = -1$) onto the horizontal $ij$-plane ($w = 0$).

<center>
  <!-- Placeholder for 2D Projection Diagram: mapping_sphere_to_plane_1.webp -->
  <img src="../../98_Assets/Concepts/mapping_sphere_to_plane_1.webp" width="900" height="200" alt="Stereographic projection of a 3D sphere onto a 2D plane">
</center>

1. Draw a line from the projection source $(-1, 0, 0)$ through any point $(w, x, y)$ on the sphere.
2. The intersection of this line with the $ij$-plane is its projected point.

<center>
  <!-- Placeholder for 2D Projection Diagram: mapping_sphere_to_plane.webp -->
  <img src="../../98_Assets/Concepts/mapping_sphere_to_plane.webp" width="450" height="300" alt="Stereographic projection of a 3D sphere onto a 2D plane">
</center>

Algebraically, the projection of a sphere point $q = w + xi + yj$ onto the $ij$-plane is:

$$
p = \frac{x}{w + 1}i + \frac{y}{w + 1}j
$$

Looking at the $ij$-plane from above, this projection divides the sphere into three distinct regions:
*   **The Equator ($w = 0$):** The equator contains the imaginary unit coordinates ($i, j, -i, -j$). Since $w = 0$, the projection simplifies to $p = xi + yj$, meaning the equator projects exactly onto the unit circle in the plane, staying fixed in place.
*   **The Northern Hemisphere ($w > 0$):** Because $w > 0$, the scaling factor $\frac{1}{w+1}$ is less than $1$. This compresses the hemisphere containing the north pole $+1$ entirely **inside** the unit circle. The north pole $+1$ itself projects directly to the origin.
*   **The Southern Hemisphere ($w < 0$):** Because $w < 0$, the scaling factor $\frac{1}{w+1}$ is greater than $1$. This stretches the hemisphere containing the south pole $-1$ entirely **outside** the unit circle, with the south pole $-1$ projecting to infinity.

<center>
  <!-- Placeholder for 2D Projection Diagram: mapping_sphere_to_plane_3.webp -->
  <img src="../../98_Assets/Concepts/mapping_sphere_to_plane_3.webp" width="400" height="300" alt="Stereographic projection of a 3D sphere onto a 2D plane">
</center>

#### Visualizing Sphere Rotations
*   **Rotation around the Real Axis ($w$):** Since this rotation occurs entirely within the horizontal $ij$-plane, it projects to a simple, un-warped 2D rotation of the $ij$-plane around the origin.
*   **Rotation around an Axis in the $ij$-Plane:** This rotation mixes the real component $w$ with the imaginary components $x$ and $y$. On the plane, the projected coordinate grid (latitude and longitude lines) warps, compressing towards the origin as points rotate towards the north pole, and expanding outwards to infinity as they rotate towards the south pole.

### 3D Projection (Rotating a 4D Hypersphere onto 3D Space)

By extension, a quaternion represents a point on a 4D unit hypersphere (a 3-sphere, $S^3$), defined by:
*   $w^2 + x^2 + y^2 + z^2 = 1$ in a 4D space with one real axis $w$ and three imaginary axes $i, j, k$.

We can visualize 4D rotations of this hypersphere by stereographically projecting it from the pole $w = -1$ (the point $(-1, 0, 0, 0)$) onto our 3D space (the $ijk$-space, where $w = 0$).

Algebraically, the projection of a quaternion $q = w + xi + yj + zk$ is:

$$
p = \frac{x}{w + 1}i + \frac{y}{w + 1}j + \frac{z}{w + 1}k
$$

Under this projection:
*   **The 3D Equator ($w = 0$):** The set of points where the real component is zero forms a 3D unit sphere ($x^2 + y^2 + z^2 = 1$). This projects exactly onto the 3D unit sphere in our space, staying fixed.
*   **The Hyper-hemisphere containing $+1$ ($w > 0$):** Projects entirely **inside** our 3D unit sphere, with $+1$ mapping to the origin.
*   **The Hyper-hemisphere containing $-1$ ($w < 0$):** Projects entirely **outside** our 3D unit sphere, with $-1$ mapping to infinity.

As the 4D hypersphere rotates:
*   Rotations that only mix $i, j, k$ (leaving the real component $w$ unchanged) project to pure 3D rotations of our space.
*   Rotations that mix the real component $w$ with the imaginary components cause our 3D space grid to warp, expanding from the origin and stretching out to infinity or compressing inwards.

---

## References & Additional Resources

*   **Ben Eater & Grant Sanderson (3Blue1Brown) - Quaternions Interactive Visualizations:** [eater.net/quaternions](https://eater.net/quaternions)
*   **How to Use Quaternions:** [youtube.com/watch?v=bKd2lPjl92c](https://www.youtube.com/watch?v=bKd2lPjl92c)
*   **Godot's quaternion variant is beautiful (and misunderstood):** [youtube.com/watch?v=Ri2xIhcii8I](https://www.youtube.com/watch?v=Ri2xIhcii8I)
