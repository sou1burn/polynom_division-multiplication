#include <iostream>
#include "C:\Users\spike\source\repos\main_09\lab_09_01.h"

void print_polynom(int* coefs, int pow) {

    for (int i = pow; i >= 0; i--) {
        if (coefs[i] != 0) {
            if (i < pow) {
                std::cout << " + ";
            }
            if (i == 0) {
                std::cout << coefs[i];
            }
            else if (i == 1) {
                std::cout << coefs[i] << "x";
            }
            else {
                std::cout << coefs[i] << "x^" << i;
            }
        }
    }
    std::cout << std::endl;
}

void polynom_division(int* p1x_coeffs, int p1x_pow, int* p2x_coeffs, int p2x_pow, float* result, float* remains) {

    for (int i = 0; i <= p1x_pow; ++i) {
        remains[i] = p1x_coeffs[i];
    }

    while (p1x_pow >=  p2x_pow) {
        result[p1x_pow - p2x_pow] = remains[p1x_pow] / p2x_coeffs[p2x_pow];

        for (int i = 0; i <= p2x_pow; ++i) {
            remains[p1x_pow - i] -= result[p1x_pow - p2x_pow] * p2x_coeffs[p2x_pow - i];
        }
        p1x_pow--;
    }

}

void print_division_result(float* coefs, int pow) {

    for (int i = pow; i >= 0; i--) {
        if (coefs[i] != 0) {
            if (i < pow) {
                std::cout << " + ";
            }
            if (i == 0) {
                std::cout << coefs[i];
            }
            else if (i == 1) {
                std::cout << coefs[i] << "x";
            }
            else {
                std::cout << coefs[i] << "x^" << i;
            }
        }
    }
    std::cout << std::endl;
}

void polynom_multiplication(int p1x_pow, int* p1x_coeffs, int p2x_pow, int* p2x_coeffs, int result_pow, int* result_coeffs) {

    for (int i = 0; i <= result_pow; i++) {
        result_coeffs[i] = 0;
    }

    for (int i = 0; i <= p1x_pow; ++i) {
        for (int j = 0; j <= p2x_pow; ++j) {
            result_coeffs[i + j] += p1x_coeffs[i] * p2x_coeffs[j];
        }
    }
}