#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void drawArray1D(int arr[], int size, int x, int y);
void drawArray2D(int arr[][5], int rows, int cols, int x, int y);
void drawArray3D(int arr[][5][5], int depth, int rows, int cols, int x, int y);
void drawForm();


int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Arreglo de una dimensión
    int array1D[5] = {1, 2, 3, 4, 5};

    // Arreglo de dos dimensiones
    int array2D[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // Arreglo de tres dimensiones
    int array3D[5][5][5];
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                array3D[i][j][k] = rand() % 100 + 1;
            }
        }
    }

    char key;
    while (1) {
        cleardevice();
        outtextxy(150, 20, "Presiona 1 para Arreglo 1D, 2 para Arreglo 2D, 3 para Arreglo 3D, ESC para salir");

        key = getch();
        if (key == '1') {
            cleardevice();
            drawArray1D(array1D, 5, 50, 50);
            getch(); // Espera a que se presione una tecla
        } else if (key == '2') {
            cleardevice();
            drawArray2D(array2D, 5, 5, 50, 50);
            getch(); // Espera a que se presione una tecla
        } else if (key == '3') {
            cleardevice();
            drawArray3D(array3D, 5, 5, 5, 50, 50);
            getch(); // Espera a que se presione una tecla
        } else if (key == 27) { // ESC key to exit
            break;
        }
    }

    closegraph();
    return 0;
}

void drawArray1D(int arr[], int size, int x, int y) {
    char buffer[50];
    int sum = 0;
    outtextxy(x, y - 20, "Arreglo 1D");
    for (int i = 0; i < size; i++) {
        sprintf(buffer, "%d", arr[i]);
        rectangle(x + i * 50, y, x + i * 50 + 40, y + 40);
        outtextxy(x + i * 50 + 10, y + 10, buffer);
        sum += arr[i];
    }
    sprintf(buffer, "Suma: %d", sum);
    outtextxy(x + size * 50 + 10, y + 10, buffer);
}

void drawArray2D(int arr[][5], int rows, int cols, int x, int y) {
    char buffer[50];
    int rowSum, colSum[5] = {0};
    outtextxy(x, y - 20, "Arreglo 2D");
    for (int i = 0; i < rows; i++) {
        rowSum = 0;
        for (int j = 0; j < cols; j++) {
            sprintf(buffer, "%d", arr[i][j]);
            rectangle(x + j * 50, y + i * 50, x + j * 50 + 40, y + i * 50 + 40);
            outtextxy(x + j * 50 + 10, y + i * 50 + 10, buffer);
            rowSum += arr[i][j];
            colSum[j] += arr[i][j];
        }
        sprintf(buffer, "%d", rowSum);
        outtextxy(x + cols * 50 + 10, y + i * 50 + 10, buffer);
    }
    for (int j = 0; j < cols; j++) {
        sprintf(buffer, "%d", colSum[j]);
        outtextxy(x + j * 50 + 10, y + rows * 50 + 10, buffer);
    }
}

void drawArray3D(int arr[][5][5], int depth, int rows, int cols, int x, int y) {
    char buffer[50];
    int rowSum, colSum[5];
    outtextxy(x, y - 20, "Arreglo 3D");

    for (int k = 0; k < depth; k++) {
        int offsetX = (k % 2) * 300; // Para colocar dos caras por fila
        int offsetY = (k / 2) * 300; // Para colocar dos filas de caras

        for (int j = 0; j < cols; j++) {
            colSum[j] = 0; // Reiniciar la suma de columnas para cada cara
        }

        for (int i = 0; i < rows; i++) {
            rowSum = 0;
            for (int j = 0; j < cols; j++) {
                sprintf(buffer, "%d", arr[k][i][j]);
                rectangle(x + j * 50 + offsetX, y + i * 50 + offsetY, x + j * 50 + 40 + offsetX, y + i * 50 + 40 + offsetY);
                outtextxy(x + j * 50 + 10 + offsetX, y + i * 50 + 10 + offsetY, buffer);
                rowSum += arr[k][i][j];
                colSum[j] += arr[k][i][j];
            }
            sprintf(buffer, "%d", rowSum);
            outtextxy(x + cols * 50 + 10 + offsetX, y + i * 50 + 10 + offsetY, buffer);
        }
        for (int j = 0; j < cols; j++) {
            sprintf(buffer, "%d", colSum[j]);
            outtextxy(x + j * 50 + 10 + offsetX, y + rows * 50 + 10 + offsetY, buffer);
        }
    }
}

