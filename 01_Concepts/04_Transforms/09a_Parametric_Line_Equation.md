# Intuition: The Parametric Line Equation

In the equation $\text{Line}(t)$, **$t$ is a scalar parameter**. You can think of it as a slider or a timeline that tracks your position as you move along an infinite straight line.

A parametric line equation always follows this structure:

$$
\text{Line}(t) = \text{Start Point} + t \times (\text{Direction Vector})
$$

In our stereographic projection example, the line represents the path of the light beam:

* **When $t = 0$:** You are exactly at the starting point (the light source/pole).
* **When $t = 1$:** You are exactly at the destination point on the circle's surface.
* **When $t$ is any other number:** You are moving along that same light beam. If $t > 1$, you have passed through the circle and are continuing out.

By setting the $w$ component of the line to $0$, we are asking the math: *"At what exact value of $t$ does this light beam slice through the vertical $w=0$ axis?"* Solving for $t$ gives us the exact scale factor needed to find the coordinates on the screen.

For the detailed, step-by-step linear algebra derivation of how changing the projection pole changes the denominator, see the background note: [[09b_Stereographic_Projection_Derivation]].