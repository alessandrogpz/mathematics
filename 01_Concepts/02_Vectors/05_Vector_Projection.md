# Vector Projection

Vector projection allows us to decompose one vector into a component that lies along the direction of another vector.

## Scalar Projection (Component)
The scalar projection of $\vec{a}$ onto $\vec{b}$ is the "length" of the shadow that $\vec{a}$ casts on $\vec{b}$. It is denoted as $\text{comp}_{\vec{b}}\vec{a}$.

$$\text{comp}_{\vec{b}}\vec{a} = \|\vec{a}\| \cos(\theta)$$
Since $\vec{a} \cdot \vec{b} = \|\vec{a}\| \|\vec{b}\| \cos(\theta)$, we can solve for $\|\vec{a}\| \cos(\theta)$:
$$\text{comp}_{\vec{b}}\vec{a} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|}$$

## Vector Projection
The vector projection of $\vec{a}$ onto $\vec{b}$ is the actual vector along $\vec{b}$. It is denoted as $\text{proj}_{\vec{b}}\vec{a}$.
To get the vector, we multiply the scalar projection by the unit vector of $\vec{b}$:

$$\text{proj}_{\vec{b}}\vec{a} = \left( \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|} \right) \frac{\vec{b}}{\|\vec{b}\|} = \frac{\vec{a} \cdot \vec{b}}{\|\vec{b}\|^2} \vec{b}$$
