cmake_minimum_required(VERSION 3.28)
project(LinearAlgebra CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable common compiler warnings for clean code
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Macro to easily add individual concept executables with C++ modules
macro(add_concept_executable TARGET_NAME SOURCE_FILE)
    add_executable(${TARGET_NAME} ${SOURCE_FILE})
endmacro()

# ==========================================
# 01 Systems of Equations
# ==========================================
add_concept_executable(systems_linear_systems "01_Systems_of_Equations/01_Linear_Systems.cppm")

# ==========================================
# 02 Vectors
# ==========================================
add_concept_executable(vectors_basics "02_Vectors/01_Basics.cppm")
add_concept_executable(vectors_dot_product "02_Vectors/02_Dot_Product.cppm")
add_concept_executable(vectors_coordinate_systems "02_Vectors/03_Coordinate_Systems.cppm")
add_concept_executable(vectors_cross_product "02_Vectors/04_Cross_Product.cppm")
add_concept_executable(vectors_scalar_triple_product "02_Vectors/05_Scalar_Triple_Product.cppm")
add_concept_executable(vectors_projection "02_Vectors/06_Vector_Projection.cppm")

# ==========================================
# 03 Matrices
# ==========================================
add_concept_executable(matrices_basics "03_Matrices/01_Basics.cppm")
add_concept_executable(matrices_multiplication "03_Matrices/02_Matrix_Multiplication.cppm")
add_concept_executable(matrices_determinants "03_Matrices/03_Determinants.cppm")
add_concept_executable(matrices_inversion "03_Matrices/04_Matrix_Inversion.cppm")
add_concept_executable(matrices_orthogonal "03_Matrices/05_Orthogonal_Matrices.cppm")

# ==========================================
# 04 Transforms
# ==========================================
add_concept_executable(transforms_matrices "04_Transforms/01_Transformation_Matrices.cppm")
add_concept_executable(transforms_rotations "04_Transforms/02_Rotations.cppm")
add_concept_executable(transforms_reflections "04_Transforms/03_Reflections.cppm")
add_concept_executable(transforms_scales "04_Transforms/04_Scales.cppm")
