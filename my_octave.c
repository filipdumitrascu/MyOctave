/* Copyright 2023 < 323CA Dumitrascu Filip Teodor > */
#include <stdio.h>

#include "functions.h"

int main(void)
{
	char command;
	int layer = 0, ***array = NULL, *rows = NULL, *columns = NULL;

	while (1) {
		scanf("%c", &command);

		switch (command) {
		case 76: // 'L'
			load(&array, &layer, &rows, &columns);
			break;

		case 68: // 'D'
			display(layer, rows, columns);
			break;

		case 80: // 'P'
			print(array, layer, rows, columns);
			break;

		case 67: // 'C'
			correct(&array, layer, &rows, &columns);
			break;

		case 77: // 'M'
			multiplicate(&array, &layer, &rows, &columns);
			break;

		case 79: // 'O'
			ordonate(&array, layer, &rows, &columns);
			break;

		case 84: // 'T'
			transpose(&array, layer, &rows, &columns);
			break;

		case 82: // 'R'
			raise(&array, layer, &rows, &columns);
			break;

		case 70: // 'F'
			eliminate(&array, &layer, &rows, &columns);
			break;

		case 81: // 'Q'
			quit(&array, layer, &rows, &columns);
			return 0;

		case 83: // 'S'
			break;

		case 10: // '\n'
			break;

		default:
			printf("Unrecognized command\n");
		}
	}
}
