#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

// Posisi awal garis
float x1Pos = 10, x2Pos = 30;
float y1Pos = 100, y2Pos = 300;
float dx = 0.2; // Kecepatan gerak (arah horizontal)

// Warna awal garis
float color1[3] = {1.0, 0.0, 0.0}; // Merah
float color2[3] = {0.0, 0.0, 1.0}; // Biru

// Warna saat ini
float curColor1[3] = {1.0, 0.0, 0.0};
float curColor2[3] = {0.0, 0.0, 1.0};

// Window size (harus sesuai gluOrtho2D dan glutInitWindowSize)
float winLeft = 0;
float winRight = 50;

void init(void)
{
    glClearColor(1, 1, 1, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 50, 0, 500); // bidang 2D
}

void drawLine(float x, float y, float r, float g, float b) {
    glColor3f(r, g, b);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y + 100); // Panjang garis
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar kedua garis
    drawLine(x1Pos, y1Pos, curColor1[0], curColor1[1], curColor1[2]);
    drawLine(x2Pos, y2Pos, curColor2[0], curColor2[1], curColor2[2]);

    glutSwapBuffers();
}

void timer(int a) {
    // Update posisi
    x1Pos += dx;
    x2Pos += dx;

    // Cek batas kanan
    if (x1Pos + 1 >= winRight || x2Pos + 1 >= winRight) {
        dx = -dx; // pantul ke kiri
        // Set warna jadi sama
        for (int i = 0; i < 3; i++) {
            curColor1[i] = 0.0; // Hijau misal
            curColor2[i] = 0.8;
        }
    }

    // Cek batas kiri
    if (x1Pos <= winLeft || x2Pos <= winLeft) {
        dx = -dx; // pantul ke kanan
        // Reset warna ke warna awal
        for (int i = 0; i < 3; i++) {
            curColor1[i] = color1[i];
            curColor2[i] = color2[i];
        }
    }

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Garis Bergerak - 672022302");

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    init();

    glutMainLoop();
    return 0;
}
