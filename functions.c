/* Copyright 2023 < 323CA Dumitrascu Filip Teodor > */
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

void load(int ****array, int *layer, int **rows, int **columns)
{
	int m, n;
	scanf("%d %d", &m, &n);

	/**
	 * Resizable array allocation taking into account whether it is
	 * the first allocation or a reallocation of an existing memory.
	 */
	if (!(*layer)) {
		alloc_array_of_matrices(array, 1);
		alloc_array(rows, 1);
		alloc_array(columns, 1);

	} else {
		realloc_array_of_matrices(array, (*layer) + 1);
		realloc_array(rows, (*layer) + 1);
		realloc_array(columns, (*layer) + 1);
	}

	/**
	 * Matrix allocation
	 */
	alloc_matrix(&(*array)[*layer], m, n);

	(*rows)[*layer] = m;
	(*columns)[*layer] = n;

	/**
	 * Matrix reading
	 */
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			scanf("%d ", &(*array)[*layer][i][j]);

	(*layer)++;
}

void display(int layer, int *rows, int *columns)
{
	int index;
	scanf("%d", &index);

	if (index >= layer || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	printf("%d %d\n", rows[index], columns[index]);
}

void print(int ***array, int layer, int *rows, int *columns)
{
	int index;
	scanf("%d", &index);
	if (index >= layer || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	/**
	 * Print element by element
	 */
	for (int i = 0; i < rows[index]; i++) {
		for (int j = 0; j < columns[index]; j++)
			printf("%d ", array[index][i][j]);
		printf("\n");
	}
}

void correct(int ****array, int layer, int **rows, int **columns)
{
	int index, *new_rows = NULL, *new_columns = NULL, l, c;
	scanf("%d", &index);

	/**
	 * Read from the stdin the positions of the elements
	 * to be placed in the resized matrix
	 */
	scanf("%d", &l);
	alloc_array(&new_rows, l);
	for (int i = 0; i < l; i++)
		scanf("%d", &new_rows[i]);

	scanf("%d", &c);
	alloc_array(&new_columns, c);
	for (int i = 0; i < c; i++)
		scanf("%d", &new_columns[i]);

	if (index >= layer || index < 0) {
		free(new_rows);
		free(new_columns);
		printf("No matrix with the given index\n");
		return;
	}

	/**
	 * Allocate the resized matrix and place the elements
	 */
	int **resized = NULL;
	alloc_matrix(&resized, l, c);
	for (int i = 0 ; i < l; i++)
		for (int j = 0; j < c; j++)
			resized[i][j] = (*array)[index][new_rows[i]][new_columns[j]];

	/**
	 * Deallocates the memory the current matrix
	 */
	free_matrix(&(*array)[index], (*rows)[index]);

	/**
	 * Place the resized matrix instead
	 */
	(*array)[index] = resized;

	free(new_rows);
	free(new_columns);

	(*rows)[index] = l;
	(*columns)[index] = c;
}

void multiplicate(int ****array, int *layer, int **rows, int **columns)
{
	int m1, m2;
	scanf("%d %d", &m1, &m2);

	if (m1 >= *layer || m2 >= *layer || m1 < 0 || m2 < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	if ((*rows)[m2] != (*columns)[m1]) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	realloc_array_of_matrices(array, (*layer) + 1);
	realloc_array(rows, (*layer) + 1);
	realloc_array(columns, (*layer) + 1);

	(*rows)[*layer] = (*rows)[m1];
	(*columns)[*layer] = (*columns)[m2];
	alloc_matrix(&(*array)[*layer], (*rows)[*layer], (*columns)[*layer]);

	for (int i = 0; i < (*rows)[m1]; i++) {
		for (int j = 0; j < (*columns)[m2]; j++) {
			for (int k = 0; k < (*rows)[m2]; k++) {
				(*array)[*layer][i][j] = ((*array)[*layer][i][j] +
				(*array)[m1][i][k] * (*array)[m2][k][j]) % MODULO;

				if ((*array)[*layer][i][j] < 0)
					(*array)[*layer][i][j] += MODULO;
			}
		}
	}

	(*layer)++;
}

void ordonate(int ****array, int layer, int **rows, int **columns)
{
	int *sum = NULL;
	alloc_array(&sum, layer);

	/**
	 * Calculates the sum for each matrix
	 */
	for (int num = 0; num < layer; num++) {
		for (int i = 0; i < (*rows)[num]; i++)
			for (int j = 0; j < (*columns)[num]; j++)
				sum[num] = (sum[num] + (*array)[num][i][j]) % MODULO;

		if (sum[num] < 0)
			sum[num] += MODULO;
	}

	/**
	 * Using a bubble sort, iterates and change places of the matrices
	 */
	for (int i = 0; i < layer - 1; i++) {
		for (int j = i + 1; j < layer; j++) {
			if (sum[i] > sum[j]) {
				int **ptr = (*array)[i];
				(*array)[i] = (*array)[j];
				(*array)[j] = ptr;

				swap(&(*rows)[i], &(*rows)[j]);
				swap(&(*columns)[i], &(*columns)[j]);
				swap(&sum[i], &sum[j]);
			}
		}
	}

	free(sum);
}

void transpose(int ****array, int layer, int **rows, int **columns)
{
	int index;
	scanf("%d", &index);

	if (index >= layer || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	/**
	 * Allocate space for the transposed matrix
	 */
	int **transposed = NULL;
	alloc_matrix(&transposed, (*columns)[index], (*rows)[index]);

	/**
	 * Placing transposed values in the matrix
	 */
	for (int i = 0; i < (*columns)[index]; i++)
		for (int j = 0; j < (*rows)[index]; j++)
			transposed[i][j] = (*array)[index][j][i];

	/**
	 * Releasing the current matrix from memory
	 */
	free_matrix(&(*array)[index], (*rows)[index]);

	/**
	 * Place the transposed matrix instead
	 */
	(*array)[index] = transposed;

	/**
	 *  Swaps the dimensions for the transposed matrix
	 */
	swap(&(*rows)[index], &(*columns)[index]);
}

void raise(int ****array, int layer, int **rows, int **columns)
{
	int index, power;
	scanf("%d %d", &index, &power);

	if (index >= layer || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	if (power < 0) {
		printf("Power should be positive\n");
		return;
	}

	if ((*rows)[index] != (*columns)[index]) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	int **temp = NULL, **raised = NULL;
	alloc_matrix(&temp, (*rows)[index], (*rows)[index]);
	alloc_matrix(&raised, (*rows)[index], (*rows)[index]);

	/**
	 * Initialise the raised matrix as a unity matrix because
	 * this way it has no effect for the first multiplication
	 */
	for (int i = 0; i < (*rows)[index]; i++)
		raised[i][i] = 1;

	while (power) {
		if (power % 2) {
			for (int i = 0; i < (*rows)[index]; i++)
				for (int j = 0; j < (*rows)[index]; j++)
					for (int k = 0; k < (*rows)[index]; k++)
						temp[i][j] = (temp[i][j] + raised[i][k] *
						(*array)[index][k][j]) % MODULO;
			power--;

			for (int i = 0; i < (*rows)[index]; i++)
				for (int j = 0; j < (*rows)[index]; j++)
					raised[i][j] = temp[i][j];

			reset_matrix(&temp, (*rows)[index], (*rows)[index]);

		} else {
			for (int i = 0; i < (*rows)[index]; i++)
				for (int j = 0; j < (*rows)[index]; j++)
					for (int k = 0; k < (*rows)[index]; k++)
						temp[i][j] = (temp[i][j] + (*array)[index][i][k] *
						(*array)[index][k][j]) % MODULO;
			power /= 2;

			for (int i = 0; i < (*rows)[index]; i++)
				for (int j = 0; j < (*rows)[index]; j++)
					(*array)[index][i][j] = temp[i][j];

			reset_matrix(&temp, (*rows)[index], (*rows)[index]);
		}
	}

	/**
	 * Place the result in the array and add MODULO for negatie values
	 */
	for (int i = 0; i < (*rows)[index]; i++) {
		for (int j = 0; j < (*rows)[index]; j++) {
			(*array)[index][i][j] = raised[i][j];
			if ((*array)[index][i][j] < 0)
				(*array)[index][i][j] += MODULO;
		}
	}

	free_matrix(&raised, (*rows)[index]);
	free_matrix(&temp, (*rows)[index]);
}

void eliminate(int ****array, int *layer, int **rows, int **columns)
{
	int index;
	scanf("%d", &index);

	if (index >= *layer || index < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	/**
	 * Deallocates index matrix's memory
	 */
	free_matrix(&(*array)[index], (*rows)[index]);

	if ((*layer) != 1) {
		/**
		 * Matrices are shifted by one position in the resizable array
		 */
		for (int i = index; i < (*layer) - 1; i++) {
			(*array)[i] = (*array)[i + 1];
			(*rows)[i] = (*rows)[i + 1];
			(*columns)[i] = (*columns)[i + 1];
		}

		realloc_array_of_matrices(array, (*layer) - 1);
		realloc_array(rows, (*layer) - 1);
		realloc_array(columns, (*layer) - 1);

	} else {
		/**
		 * If the resizable array has only one matrix deallocates the array too
		 */
		free((*array));
		free((*rows));
		free((*columns));
	}

	(*layer)--;
}

void quit(int ****array, int layer, int **rows, int **columns)
{
	/**
	 * Frees matrix by matrix from the array
	 */
	for (int num = 0; num < layer; num++)
		free_matrix(&(*array)[num], (*rows)[num]);

	if (layer) {
		free((*array));
		free((*rows));
		free((*columns));
	}
}
