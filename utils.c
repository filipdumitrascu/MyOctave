/* Copyright 2023 < 323CA Dumitrascu Filip Teodor > */
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void alloc_array(int **array, int num)
{
	*array = calloc(num, sizeof(int));
	DIE(!(*array), "Calloc for the array failed");
}

void realloc_array(int **array, int num)
{
	*array = realloc(*array, num * sizeof(int));
	DIE(!(*array), "Realloc for the array failed");
}

void alloc_array_of_matrices(int ****array, int num)
{
	*array = malloc(num * sizeof(int **));
	DIE(!(*array), "Malloc for resizable array failed");
}

void realloc_array_of_matrices(int ****array, int num)
{
	*array = realloc(*array, num * sizeof(int **));
	DIE(!(*array), "Realloc for resizable array failed");
}

void alloc_matrix(int ***matrix, int rows, int columns)
{
	(*matrix) = calloc(rows, sizeof(int *));
	DIE(!(*matrix), "Calloc for the array of pointers failed");

	for (int i = 0; i < rows; i++) {
		(*matrix)[i] = calloc(columns, sizeof(int));
		/**
		 * Knowing that DIE does not deallocate memory check the result of the
		 * malloc with an if and deallocate memory before calling DIE (from the
		 * defensive programming point of view)
		 */
		if (!(*matrix)[i]) {
			for (int j = 0; j < i; j++)
				free((*matrix)[j]);
			free(*matrix);
			DIE(1, "Calloc for a row failed");
		}
	}
}

void free_matrix(int ***matrix, int rows)
{
	for (int i = 0; i < rows; i++)
		free((*matrix)[i]);
	free(*matrix);
}

void reset_matrix(int ***matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			(*matrix)[i][j] = 0;
}

void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}
