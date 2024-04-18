#include <iostream>
#include "lab_09_01.h"

int main() {
    int p1x_pow;
    int p2x_pow;

    std::cout << "Enter power of p1(x): ";
    std::cin >> p1x_pow;

    int* p1x_coeffs = (int*)malloc((p1x_pow + 1) * sizeof(int));

    if (p1x_coeffs == nullptr) {
        std::cout << "Memory allocation failed for p1x_coeffs.\n";
        return 1;
    }

    for (int i = p1x_pow; i >= 0; i--) {
        std::cout << "Enter coefficient of p1(x) for power " << i << ": ";
        std::cin >> p1x_coeffs[i];
    }

    std::cout << "Enter power of p2(x): ";
    std::cin >> p2x_pow;

    int* p2x_coeffs = (int*)malloc((p2x_pow + 1) * sizeof(int));

    if (p2x_coeffs == nullptr) {
        std::cout << "Memory allocation failed for p2x_coeffs.\n";
        free(p1x_coeffs);
        return 1;
    }

    for (int i = p2x_pow; i >= 0; i--) {
        std::cout << "Enter coefficient of p2(x) for power " << i << ": ";
        std::cin >> p2x_coeffs[i];
    }

    std::cout << "Entered polynom p1(x) is: ";
    print_polynom(p1x_coeffs, p1x_pow);
    std::cout << "Entered polynom p2(x) is: ";
    print_polynom(p2x_coeffs, p2x_pow);

    float* result_coeffs = (float*)malloc((p1x_pow - p2x_pow + 1) * sizeof(float));
    float* remainder = (float*)malloc((p1x_pow + 1) * sizeof(float));

    polynom_division(p1x_coeffs, p1x_pow, p2x_coeffs, p2x_pow, result_coeffs, remainder);
    int result_pow = p1x_pow + p2x_pow;
    int* result_of_multiplication = (int*)malloc((result_pow + 1) * sizeof(int));

    polynom_multiplication(p1x_pow, p1x_coeffs, p2x_pow, p2x_coeffs, result_pow, result_of_multiplication);
    std::cout << "Result of multiplication p1(x) * p2(x) is: \n";
    print_polynom(result_of_multiplication, result_pow);

    if ((p1x_pow - p2x_pow) < 0) {
        std::cout << "Because degree of p1(x) is less then degree of p2(x), result and both remainder of division p1(x) / p2(x) is: \n";
        print_polynom(p1x_coeffs, p1x_pow);
        return 0;
    }

    if (p2x_pow == 0 && p2x_coeffs[0] == 0) {
        std::cout << "Error, you tried to divide by zero \n";
        return 0;
    }

    std::cout << "Result of division p1(x) / p2(x) is: \n";
    print_division_result(result_coeffs, p1x_pow - p2x_pow);

    std::cout << "Remainder is: \n";
    print_division_result(remainder, p2x_pow - 1);

    free(p1x_coeffs);
    free(p2x_coeffs);
    free(result_coeffs);
    free(remainder);
    free(result_of_multiplication);

    return 0;
}
