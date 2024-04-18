#ifndef lab_09_h
#define lab_09_h
void print_polynom(int* coefs, int pow);
void polynom_division(int* p1x_coeffs, int p1x_pow, int* p2x_coeffs, int p2x_pow, float* result, float* remains);
void print_division_result(float* coefs, int pow);
void polynom_multiplication(int p1x_pow, int* p1x_coeffs, int p2x_pow, int* p2x_coeffs, int result_pow, int* result_coeffs);
#endif
