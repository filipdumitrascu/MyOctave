/* Copyright 2023 < 323CA Dumitrascu Filip Teodor > */
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "utils.h"

/**
 * @brief The function allocates memory for a matrix in the resizable array
 * and reads from stdin values for the matrix. Also, assigns the numbers
 * of columns and rows for each matrix in two separate arrays.
 * 
 * @param array the array with matrices
 * @param layer which layer
 * @param rows how many rows
 * @param columns how many columns
 */
void load(int ****array, int *layer, int **rows, int **columns);

/**
 * @brief The function displays the dimensions of a matrix
 * 
 * @param layer which layer
 * @param rows how many rows
 * @param columns how many columns
 */
void display(int layer, int *rows, int *columns);

/**
 * @brief The function prints a matrix values from the resizable array
 * 
 * @param array the array with matrices
 * @param layer which layer
 * @param rows how many rows
 * @param columns how many columns
 */
void print(int ***array, int layer, int *rows, int *columns);

/**
 * @brief The function resizes the given matrix
 * 
 * @param array the array with matrices
 * @param layer which layer
 * @param rows how many rows
 * @param columns how many columns
 */
void correct(int ****array, int layer, int **rows, int **columns);

/**
 * @brief The function multiplicates two matrices and stores the result in the array
 * 
 * @param array the array with matrices
 * @param layer which layer
 * @param rows how many rows
 * @param columns how many columns
 */
void multiplicate(int ****array, int *layer, int **rows, int **columns);

/**
 * @brief Sorts the matrices by the sum of the elements in ascending order
 * 
 * @param array the array with matrices
 * @param layer which layer
 * @param rows how many rows
 * @param columns how many columns
 */
void ordonate(int ****array, int layer, int **rows, int **columns);

/**
 * @brief The function transposes a matrix
 * 
 * @param array the array of matrices
 * @param layer which layer
 * @param rows how many rows
 * @param columns how many columns
 */
void transpose(int ****array, int layer, int **rows, int **columns);

/**
 * @brief The function raises a matrix to a given power in O(log2n)
 * 
 * @param array the array of matrices
 * @param layer which layer
 * @param rows hwo many rows
 * @param columns how many columns
 */
void raise(int ****array, int layer, int **rows, int **columns);

/**
 * @brief The function eliminates a matrix from the resizable array
 * 
 * @param array the array of matrices
 * @param layer which layer
 * @param rows how many rows
 * @param columns how many columns
 */
void eliminate(int ****array, int *layer, int **rows, int **columns);

/**
 * @brief The function exits the program and deallocates the entire memory
 * 
 * @param array the array of matrices
 * @param layer which layer
 * @param rows how many rows
 * @param columns how many columns
 */
void quit(int ****array, int layer, int **rows, int **columns);

#endif /* FUNCTIONS_H_ */
