// Related Concept: [[01_Concepts/03_Matrices/04_Matrix_Inversion|04_Matrix_Inversion]]
module;
#include <iostream>

export module matrices_inversion;

import matrices_basics;
import matrices_determinants;

export namespace matrices {

    [[nodiscard]]
    Matrix3x3 inverse(const Matrix3x3& m)
    {
        const double det = determinant(m);

        if (det == 0)
            return Matrix3x3{};

        const double inv_det = 1.0 / det;
        Matrix3x3 inverse{};

        inverse[0, 0] = ( (m)[1, 1] * (m)[2, 2] - (m)[1, 2] * (m)[2, 1] ) * inv_det;
        inverse[0, 1] = ( (m)[0, 2] * (m)[2, 1] - (m)[0, 1] * (m)[2, 2] ) * inv_det;
        inverse[0, 2] = ( (m)[0, 1] * (m)[1, 2] - (m)[0, 2] * (m)[1, 1] ) * inv_det;
        inverse[1, 0] = ( (m)[1, 2] * (m)[2, 0] - (m)[1, 0] * (m)[2, 2] ) * inv_det;
        inverse[1, 1] = ( (m)[0, 0] * (m)[2, 2] - (m)[0, 2] * (m)[2, 0] ) * inv_det;
        inverse[1, 2] = ( (m)[0, 2] * (m)[1, 0] - (m)[0, 0] * (m)[1, 2] ) * inv_det;
        inverse[2, 0] = ( (m)[1, 0] * (m)[2, 1] - (m)[1, 1] * (m)[2, 0] ) * inv_det;
        inverse[2, 1] = ( (m)[0, 1] * (m)[2, 0] - (m)[0, 0] * (m)[2, 1] ) * inv_det;
        inverse[2, 2] = ( (m)[0, 0] * (m)[1, 1] - (m)[0, 1] * (m)[1, 0] ) * inv_det;

        return inverse;
    }

}
