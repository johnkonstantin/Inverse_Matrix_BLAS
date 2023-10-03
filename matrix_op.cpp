#include "matrix_op.h"

void mult_matrix(const float* A, const float* B, float* C, size_t N) {
	cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, 1.0, A, N, B, N, 0.0, C, N);
}

void sum_matrix(const float* A, float* B, size_t N) {
	for (size_t i = 0; i < N; ++i) {
		cblas_saxpy(N, 1.0, A + i * N, 1.0, B + i * N, 1.0);
	}
}

void print_matrix(const float* A, size_t N) {
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < N; ++j) {
			if (A[i * N + j] < 1e-01) {
				std::cout << 0 << " ";
			}
			else if (A[i * N + j] > 8e-01) {
				std::cout << 1 << " ";
			}
			else {
				std::cout << std::setprecision(2) << A[i * N + j] << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void mult_matrix_number(float* A, float num, size_t N) {
	for (size_t i = 0; i < N; ++i) {
		cblas_sscal(N, num, A + i * N, 1);
	}
}

float* trans_matrix(const float* A, size_t N) {
	float* res = new float[N * N];
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < N; ++j) {
			res[i * N + j] = A[j * N + i];
		}
	}
	return res;
}