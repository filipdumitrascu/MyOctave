/* Copyright 2023 < 323CA Dumitrascu Filip Teodor > */
#ifndef UTILS_H_
#define UTILS_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define MODULO 10007

/**
 * Useful macro for handling error codes
 */
#define DIE(assertion, call_description)                                       \
	do {                                                                       \
		if (assertion) {                                                       \
			fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);                 \
			perror(call_description);                                          \
			exit(errno);                                                       \
		}                                                                      \
	} while (0)

/**
 * @brief Allocates the memory of an array and
 * initializes the elements with 0.
 * 
 * @param array the array
 * @param num the number of elements
 */
void alloc_array(int **array, int num);

/**
 * @brief Reallocates the memory of an array
 * 
 * @param array the array
 * @param num the new number of elements
 */
void realloc_array(int **array, int num);

/**
 * @brief Allocates memory for an array of matrices
 * 
 * @param array the array of matrices
 * @param num the number of matrices
 */
void alloc_array_of_matrices(int ****array, int num);

/**
 * @brief Reallocates memory for an array of matrices
 * 
 * @param array the array of matrices
 * @param num the new number of
 */
void realloc_array_of_matrices(int ****array, int num);

/**
 * @brief Allocates the memory of a matrix.
 * 
 * @param matrix the array of matrices
 * @param rows how many rows
 * @param columns how many columns
 */
void alloc_matrix(int ***matrix, int rows, int columns);

/**
 * @brief Deallocates the memory of a matrix
 * 
 * @param matrix the array of matrices
 * @param rows how many rows
 */
void free_matrix(int ***matrix, int rows);

/**
 * @brief The function assigns 0 to all values in a matrix
 * 
 * @param matrix the array of matrices
 * @param rows how many rows
 * @param columns how many columns
 */
void reset_matrix(int ***matrix, int rows, int columns);

/**
 * @brief Swaps the values between two integers
 * 
 * @param a first value
 * @param b second value
 */
void swap(int *a, int *b);

#endif /* UTILS_H_ */
