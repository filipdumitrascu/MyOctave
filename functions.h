/* Copyright 2023 < 323CA Dumitrascu Filip Teodor > */
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "utils.h"

/**
 * @brief The function allocates memory for a matrix in the resizable array
 * inserting the matrix or puting it at the final position. Reads from stdin
 * the values for the matrix and stores the numbers of columns and rows for the
 * matrix in two separate arrays.
 * 
 * @param array the array with matrices
 * @param layer which layer (where to load)
 * @param rows how many rows
 * @param columns how many columns
 */
void load(int ****array, int *layer, int **rows, int **columns);

/**
 * @brief The function displays the dimensions of a matrix
 * 
 * @param layer which matrix
 * @param rows where the number of rows is stored
 * @param columns where the number of columns in stored
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
 * @param rows how many rows should have
 * @param columns how many columns should have
 */
void crop(int ****array, int layer, int **rows, int **columns);

/**
 * @brief The function multiplicates two matrices
 * and stores the result in the array
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
 * @param layer how many matrices
 * @param rows the array with rows
 * @param columns the array with columns
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
 * @param rows the array of rows
 * @param columns the array of columns
 */
void raise(int ****array, int layer, int **rows, int **columns);

/**
 * @brief The function eliminates a matrix from the resizable array
 * 
 * @param array the array of matrices
 * @param layer which layer
 * @param rows the array of rows
 * @param columns the array of columns
 */
void eliminate(int ****array, int *layer, int **rows, int **columns);

/**
 * @brief The function exits the program and deallocates the entire memory
 * 
 * @param array the array of matrices
 * @param layer which layer
 * @param rows the array of rows
 * @param columns the array of columns
 */
void quit(int ****array, int layer, int **rows, int **columns);

#endif /* FUNCTIONS_H_ */
