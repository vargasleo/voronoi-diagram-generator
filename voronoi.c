#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int x;
    int y;
} Point;

double euclidean_distance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    int linhas, colunas, seeds;
    int **matrix;
    Point *seed_points;
    srand(time(0));

    printf("Linhas: ");
    scanf("%d", &linhas);
    printf("Colunas: ");
    scanf("%d", &colunas);
    printf("Sementes: ");
    scanf("%d", &seeds);

    matrix = (int **)malloc(linhas * sizeof(int *));
    seed_points = (Point *)malloc(seeds * sizeof(Point));
    for (int i = 0; i < linhas; i++)
    {
        matrix[i] = (int *)malloc(colunas * sizeof(int));
        for (int j = 0; j < colunas; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < seeds; i++)
    {
        seed_points[i].x = rand() % linhas;
        seed_points[i].y = rand() % colunas;
        matrix[seed_points[i].x][seed_points[i].y] = i + 1;
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (matrix[i][j] == 0)
            {
                double min_distance = INFINITY;
                int closest = 0;
                for (int k = 0; k < seeds; k++)
                {
                    double distance = euclidean_distance((Point){i, j}, seed_points[k]);
                    if (distance < min_distance)
                    {
                        min_distance = distance;
                        closest = k + 1;
                    }
                }
                matrix[i][j] = closest;
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(seed_points);

    return 0;
}
