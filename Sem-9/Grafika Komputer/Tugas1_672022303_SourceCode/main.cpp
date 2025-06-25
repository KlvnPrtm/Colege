#include <GL/gl.h>
#include <GL/glut.h>

float x1_pos = 10, x2_pos = 30;   // posisi awal x untuk garis 1 dan 2
int dir1 = 1, dir2 = 1;           // arah gerak 1 = kanan, -1 = kiri
float speed = 0.5;                // kecepatan gerak

// Warna awal
float color1[3] = {1, 0, 0};      // merah
float color2[3] = {0, 0, 1};      // biru

// Warna saat ini
float currColor1[3] = {1, 0, 0};
float currColor2[3] = {0, 0, 1};

// Window bounds
float minX = 0;
float maxX = 50;

void init(void)
{
    glClearColor(1, 1, 1, 0); // background putih
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 50, 0, 500); // ukuran bidang 2D
}

void drawHorizontalLine(float xStart, float xEnd, float y, float r, float g, float b) {
    glColor3f(r, g, b);
    glLineWidth(5.0);
    glBegin(GL_LINES);
        glVertex2f(xStart, y);
        glVertex2f(xEnd, y);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar garis horizontal 1
    drawHorizontalLine(x1_pos, x1_pos + 10, 150, currColor1[0], currColor1[1], currColor1[2]);

    // Gambar garis horizontal 2
    drawHorizontalLine(x2_pos, x2_pos + 10, 350, currColor2[0], currColor2[1], currColor2[2]);

    glutSwapBuffers();
}

void timer(int value) {
    // Update posisi
    x1_pos += speed * dir1;
    x2_pos += speed * dir2;

    // Cek batas kanan
    if (x1_pos + 10 >= maxX || x2_pos + 10 >= maxX) {
        dir1 = -1;
        dir2 = -1;

        // Ubah warna menjadi sama (misal: hijau)
        currColor1[0] = 0;
        currColor1[1] = 1;
        currColor1[2] = 0;

        currColor2[0] = 0;
        currColor2[1] = 1;
        currColor2[2] = 0;
    }

    // Cek batas kiri
    if (x1_pos <= minX || x2_pos <= minX) {
        dir1 = 1;
        dir2 = 1;

        // Kembalikan ke warna awal
        for (int i = 0; i < 3; i++) {
            currColor1[i] = color1[i];
            currColor2[i] = color2[i];
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
    glutCreateWindow("NAMA - 672022303");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
