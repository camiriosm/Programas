#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define MAX_INPUT 100
#define NUM_CAMPOS 6
#define NUM_PERSONAS 3

void drawForm();
void getInput(char input[], int maxLength, int x, int y);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    char data[NUM_PERSONAS][NUM_CAMPOS][MAX_INPUT];

    for (int i = 0; i < NUM_PERSONAS; i++) {
        drawForm();

        // Obtener el nombre
        outtextxy(150, 120, "Nombre(s):");
        getInput(data[i][0], MAX_INPUT, 250, 120);

        // Obtener el apellido
        outtextxy(150, 160, "Apellido(s):");
        getInput(data[i][1], MAX_INPUT, 250, 160);

        // Obtener la edad
        outtextxy(150, 200, "Edad:");
        getInput(data[i][2], MAX_INPUT, 250, 200);

        // Obtener el estado civil
        outtextxy(150, 240, "Estado Civil:");
        getInput(data[i][3], MAX_INPUT, 250, 240);

        // Obtener el género
        outtextxy(150, 280, "Género:");
        getInput(data[i][4], MAX_INPUT, 250, 280);

        // Obtener el teléfono
        outtextxy(150, 320, "Teléfono:");
        getInput(data[i][5], MAX_INPUT, 250, 320); 
        
        cleardevice();
    }

    // Mostrar los datos ingresados
    int y_offset = 100;
    for (int i = 0; i < NUM_PERSONAS; i++) {
        char label[50];
        sprintf(label, "Datos ingresados de la persona %d:", i + 1);
        outtextxy(150, y_offset, label);
        y_offset += 20;

        for (int j = 0; j < NUM_CAMPOS; j++) {
            outtextxy(150, y_offset, data[i][j]);
            y_offset += 20;
        }
        y_offset += 20; // Espacio entre personas
    }

    getch();
    closegraph();
    return 0;
}

void drawForm() {
    setcolor(WHITE);
    rectangle(100, 100, 600, 500);
    outtextxy(250, 80, "Formulario");
}

void getInput(char input[], int maxLength, int x, int y) {
    int i = 0;
    char ch;
    while ((ch = getch()) != 13 && i < maxLength - 1) { // 13 es el código ASCII para Enter
        if (ch == 8) { // 8 es el código ASCII para Backspace
            if (i > 0) {
                i--;
                input[i] = '\0';
                outtextxy(x + i * 10, y, " ");
            }
        } else {
            input[i] = ch;
            input[i + 1] = '\0';
            outtextxy(x + i * 10, y, &ch);
            i++;
        }
    }
    input[i] = '\0';
}

