
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SIZE 10
#define MAX 20

void displayGrid(int x, int y, int visited[SIZE][SIZE])
{
    system("cls");

    printf("\n");
    printf("   PATH FOLLOWING ROBOT SIMULATION\n\n");

    printf("   ");

    for (int i = 0; i < SIZE; i++)
        printf("%d ", i);

    printf("\n");

    for (int j = SIZE - 1; j >= 0; j--)
    {
        printf("%2d ", j);

        for (int i = 0; i < SIZE; i++)
        {
            if (i == x && j == y)
                printf("R ");
            else if (i == 0 && j == 0)
                printf("S ");
            else if (i == 9 && j == 9)
                printf("F ");
            else if (visited[i][j] == 1)
                printf("* ");
            else
                printf(". ");
        }

        printf("\n");
    }

    printf("\nR = Robot   S = Start   F = Finish");
    printf("\n* = Visited Path\n");
}

void moveRobot(int targetX, int targetY,
               int *x, int *y,
               int visited[SIZE][SIZE])
{
    // Move horizontally
    while (*x != targetX)
    {
        if (*x < targetX)
            (*x)++;
        else
            (*x)--;

        visited[*x][*y] = 1;

        displayGrid(*x, *y, visited);
        Sleep(500);
    }

    // Move vertically
    while (*y != targetY)
    {
        if (*y < targetY)
            (*y)++;
        else
            (*y)--;

        visited[*x][*y] = 1;

        displayGrid(*x, *y, visited);
        Sleep(500);
    }
}

int main()
{
    int x = 0, y = 0;
    int n;
    int px[MAX], py[MAX];

    int visited[SIZE][SIZE] = {0};

    visited[0][0] = 1;

    printf("\nPATH FOLLOWING ROBOT SIMULATION\n");

    printf("\nStarting Point: (0,0)");
    printf("\nEnding Point: (9,9)");

    printf("\n\nEnter number of coordinates: ");
    scanf("%d", &n);

    if (n < 0 || n > MAX)
    {
        printf("Invalid number of coordinates!");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter coordinate %d (x y): ", i + 1);
        scanf("%d %d", &px[i], &py[i]);

        if (px[i] < 0 || px[i] >= SIZE ||
            py[i] < 0 || py[i] >= SIZE)
        {
            printf("Invalid coordinate! Use 0 to 9.");
            return 0;
        }
    }

    printf("\nStarting Robot Movement...");
    Sleep(1500);

    displayGrid(x, y, visited);

    // Follow user entered coordinates
    for (int i = 0; i < n; i++)
    {
        moveRobot(px[i], py[i],
                  &x, &y, visited);
    }

    // Move towards final destination
    moveRobot(9, 9, &x, &y, visited);

    displayGrid(x, y, visited);

    printf("\n\nRobot Reached Destination!");
    printf("\nSimulation Completed Successfully!\n");

    return 0;
}
