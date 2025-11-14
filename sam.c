#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv){
    FILE *file = fopen (argv [1],"r");
    if (!file){
	printf("Ошибка открытия файла\n");
	return 1;
    } 

    int n, m;
    fscanf(file, "%d %d", &n, &m);

    if (m<4){
	printf("Нет четвёртого столбца\n");
	fclose(file);
	return 1;
    }

    if (n<2){
	printf("Нет второй строки\n");
	fclose(file);
	return 1;
    }

    int **matrix = (int**) malloc (n * sizeof(int*));
    for (int i = 0; i<n; i++){
	matrix[i] = (int*) malloc (m * sizeof(int));
	for (int j = 0; j<m; j++){
	    fscanf(file, "%d", &matrix[i][j]);
	}
    }
    fclose(file);

    printf("Вывод матрицы:\n", n, m);
    for(int i=0; i<n; i++){
	for(int j=0; j<m; j++){
	    printf("%4d ", matrix[i][j]);
	}
	printf("\n");
    }
    printf("\n");

    int max = matrix[0][3];
    int max_row = 0;

    for (int i = 1; i < n; i++){
	if (matrix[i][3] > max_row) {
	    max = matrix[i][3];
	    max_row = i;
	}
    }
    printf("Максимальный элемент 4-го столбца: matrix[%d][3] = %d\n", max_row, max);
    double s = 10.0;
    for (int j = 0; j < m; j++) {
	s += exp(1 - matrix[1][j]);
    }
    printf("Сумма S = %.2f\n", s);
    printf("Замена максимального элемента 4-го столбца на S\n", max_row, matrix[max_row][3]);
    matrix[max_row][3] = (int)s;
    printf("\nНовая матрица:\n");
    for (int i = 0; i < n; i++){
	for (int j = 0; j < m; j++){
	    printf("%4d ", matrix[i][j]);
	}
	printf("\n");
    }

    for (int i = 0; i < n; i++){
	free(matrix[i]);
    }
    free(matrix);

return 0;
}

