# Coordinate Systems: Right-Hand vs Left-Hand

In 3D space, the orientation of the axes ($x, y, z$) can follow one of two conventions. This choice affects the direction of operations like the **Cross Product**.

## Axis Orientation: Three-Finger Rule (Standard)
To construct a standard **Right-Handed Coordinate System** using your right hand:
*   **Thumb:** Points along the positive $X$-axis (Right).
*   **Index Finger:** Points along the positive $Y$-axis (Up).
*   **Middle Finger:** Points along the positive $Z$-axis (Towards you, perpendicular to your palm).

In a **Left-Handed System**, using your left hand, the thumb ($X$), index ($Y$), and middle finger ($Z$) point in the same relative directions, but the $Z$-axis now points away from you.

*   **Right-Hand Cross Product:** $\vec{i} \times \vec{j} = \vec{k}$

---

## Positive Rotations: The Cyclic Order Rule
To determine the direction of a standard **positive rotation** about any axis, use the **Cyclic Order**:
$$
X \rightarrow Y \rightarrow Z \rightarrow X
$$

Using the **Right-Hand Rule** for rotation:
1.  **Thumb (Axis):** Points along the positive axis of rotation (the invariant axis).
2.  **Fingers Start:** Start at the next axis in the cycle.
3.  **Fingers Curl:** Swing toward the third axis in the cycle.

### 1. Rotating around the $Z$-axis
*   **Thumb (Axis):** Points along $+Z$.
*   **The Cycle:** After $Z$ comes $X$, then $Y$ ($Z \rightarrow X \rightarrow Y$).
*   **The Swing:** Your fingers curl from $+X$ toward $+Y$.

### 2. Rotating around the $X$-axis
*   **Thumb (Axis):** Points along $+X$.
*   **The Cycle:** After $X$ comes $Y$, then $Z$ ($X \rightarrow Y \rightarrow Z$).
*   **The Swing:** Your fingers curl from $+Y$ toward $+Z$.

### 3. Rotating around the $Y$-axis
*   **Thumb (Axis):** Points along $+Y$.
*   **The Cycle:** After $Y$ comes $Z$, then $X$ ($Y \rightarrow Z \rightarrow X$).
*   **The Swing:** Your fingers curl from $+Z$ toward $+X$.

---

## Why It Matters
When working with **Cross Products** (see [[04_Cross_Product]]), the resulting vector $\vec{a} \times \vec{b}$ is defined to follow the **Right-Hand Rule**. If you are working in a Left-Handed coordinate system, your visual intuition for "up" or "forward" might be inverted compared to the mathematical result.

---

## Code Implementation

*   **C++ Source Code:** [[03_Code/02_Vectors/03_Coordinate_Systems.cppm|03_Coordinate_Systems.cppm]]
