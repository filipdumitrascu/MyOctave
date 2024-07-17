# My Octave

The project aims to implement an octave application simulator. Thus, it
dynamically allocates an array with matrices and performs operations on them effectively from a mathematical point of view.  

#### Contributor: Dumitrascu Filip-Teodor

## Content
1. [Simulator interaction](#simulator-interaction)
2. [Operations](#operations)


## Simulator interaction
Since the program does not have a graphical user interface, it uses the command
line interface (CLI) to read the uppercase letters that define the operation to
be performed on a particular matrix in the "array". It also changes the number
of "rows" and "columns" stored in separate arrays for the matrix.

## Operations 
Thus we consider the following:

- for the letter "L" increase the size of the array with matrices by 1
allocating space for the array and reads it.

- for the letter "P" display the values of the matrix.

- for the letter "D" display the dimensions of the matrix from the rows array and the columns array.

- for the letter "C" read the elements to be stored in the matrix, put then in the dynamically allocated "resized" matrix and consider by pointing as the matrix resized being the new matrix.

- for the letter "M" if the multiplication condition of two matrices is met,
increase the size of the matrix array by 1, allocate space for matrix, take
into account the size of the resulting matrix and calculate the product.

- for the letter "O" calculate the sum of the elements of each matrix and the
values are sorted by a bubble sort.

- for the letter "T" put in the dynamically allocated "transposed" matrix the elements and consider by pointing as the matrix transposed being the new matrix.

- for the letter "R" a unit matrix "raised" and a temporary matrix "temp" with
which is calculated the power of the matrix in a logharithmic complexity are
used. The matrix "temp" takes the value 0 after each multiplication so that it
can be reused and the "raised" matrix is placed in the vector as the new matrix.

- for the letter "F" the memory for the indicated matrix is released and the one
position per matrix, eliminating from the total number of matrices of the vector. 

- for the letter "Q" the total memory is cleared starting with the matrices and ending with the matrix, row and column vectors.
