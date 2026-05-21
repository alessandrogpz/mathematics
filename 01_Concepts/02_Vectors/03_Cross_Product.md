# Cross Product

The cross product of two 3D vectors is another 3D vector that is perpendicular (orthogonal) to both original vectors.

## Algebraic Definition
Given $\vec{a} = (a_1, a_2, a_3)$ and $\vec{b} = (b_1, b_2, b_3)$:
$$\vec{a} \times \vec{b} = (a_2b_3 - a_3b_2, a_3b_1 - a_1b_3, a_1b_2 - a_2b_1)$$

## Geometric Definition
The magnitude of the cross product is related to the sine of the angle $\theta$ between them:
$$\|\vec{a} \times \vec{b}\| = \|\vec{a}\| \|\vec{b}\| \sin(\theta)$$

### Right-Hand Rule
The direction of $\vec{a} \times \vec{b}$ is determined by the right-hand rule:
- Point your fingers in the direction of $\vec{a}$.
- Curl them toward $\vec{b}$.
- Your thumb points in the direction of $\vec{a} \times \vec{b}$.

## Basic Properties
| Property | Formula | Description |
| :--- | :--- | :--- |
| **Anticommutative** | $\vec{a} \times \vec{b} = -(\vec{b} \times \vec{a})$ | Reversing order flips the vector |
| **Distributive** | $\vec{a} \times (\vec{b} + \vec{c}) = \vec{a} \times \vec{b} + \vec{a} \times \vec{c}$ | Over vector addition |
| **Scalar Factorization** | $(s\vec{a}) \times \vec{b} = \vec{a} \times (s\vec{b}) = s(\vec{a} \times \vec{b})$ | Scalars can be factored out |
| **Vector Triple Product** | $\vec{a} \times (\vec{b} \times \vec{c}) = \vec{b}(\vec{a} \cdot \vec{c}) - \vec{c}(\vec{a} \cdot \vec{b})$ | "BAC-CAB" rule |
| **Lagrange's Identity** | $\|\vec{a} \times \vec{b}\|^2 = \|\vec{a}\|^2 \|\vec{b}\|^2 - (\vec{a} \cdot \vec{b})^2$ | Relation to dot product |

## Area of a Parallelogram
The magnitude $\|\vec{a} \times \vec{b}\|$ is equal to the area of the parallelogram formed by $\vec{a}$ and $\vec{b}$.
- **Base:** $\|\vec{b}\|$
- **Height:** $\|\vec{a}\| \sin(\theta)$
- **Area:** $Base \times Height = \|\vec{a}\| \|\vec{b}\| \sin(\theta)$
