// Related Concept: [[01_Concepts/03_Matrices/02_Matrix_Multiplication|02_Matrix_Multiplication]]
module;
#include <iostream>

export module matrices_multiplication;

import vectors_basics;
import matrices_basics;
import vectors_dot_product;

export namespace matrices {

    Matrix3x3 matrixMultiplication3x3(const Matrix3x3& a, const Matrix3x3& b)
    {
        Matrix3x3 result{};

        for (size_t r = 0; r < 3; ++r)
        {
            for (size_t c = 0; c < 3; ++c)
            {
                // Extract row r of matrix 'a' as a 3D vector
                vectors::vector3 rowVector{ a[r, 0], a[r, 1], a[r, 2] };

                // Extract column c of matrix 'b' as a 3D vector
                vectors::vector3 colVector{ b[0, c], b[1, c], b[2, c] };

                // The element at (r, c) is the dot product of the row and column vectors
                result[r, c] = vectors::dot(rowVector, colVector);
            }
        }
        return result;
    }
}
