#include <iostream>

// Import C++23 modules
import systems_linear_systems;
import vectors_basics;
import vectors_dot_product;
import vectors_coordinate_systems;
import vectors_cross_product;
import vectors_scalar_triple_product;
import vectors_projection;
import matrices_basics;
import matrices_multiplication;
import matrices_determinants;
import matrices_inversion;
import matrices_orthogonal;
import transforms_matrices;
import transforms_rotations;
import transforms_reflections;
import transforms_scales;

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "      Linear Algebra Module Suite         " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Running test functions for all concepts:\n" << std::endl;

    std::cout << "[Testing] ";
    test_systems_linear_systems();
    std::cout << "[Testing] ";
    test_vectors_basics();
    std::cout << "[Testing] ";
    test_vectors_dot_product();
    std::cout << "[Testing] ";
    test_vectors_coordinate_systems();
    std::cout << "[Testing] ";
    test_vectors_cross_product();
    std::cout << "[Testing] ";
    test_vectors_scalar_triple_product();
    std::cout << "[Testing] ";
    test_vectors_projection();
    std::cout << "[Testing] ";
    test_matrices_basics();
    std::cout << "[Testing] ";
    test_matrices_multiplication();
    std::cout << "[Testing] ";
    test_matrices_determinants();
    std::cout << "[Testing] ";
    test_matrices_inversion();
    std::cout << "[Testing] ";
    test_matrices_orthogonal();
    std::cout << "[Testing] ";
    test_transforms_matrices();
    std::cout << "[Testing] ";
    test_transforms_rotations();
    std::cout << "[Testing] ";
    test_transforms_reflections();
    std::cout << "[Testing] ";
    test_transforms_scales();

    std::cout << "\nAll module tests completed successfully!" << std::endl;
    std::cout << "==========================================" << std::endl;
    return 0;
}
