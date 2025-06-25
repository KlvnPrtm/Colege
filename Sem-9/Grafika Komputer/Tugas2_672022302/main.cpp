#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

void mulai() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000, 0.0, 1000);
}

void lingkaran(float cx, float cy, float r, int segmen, float R, float G, float B) {
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segmen; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segmen);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.9);
    glVertex2i(0, 1000);
    glVertex2i(1000, 1000);
    glColor3f(0.7, 0.8, 1);
    glVertex2i(1000, 100);
    glVertex2i(0, 100);
    glEnd();

    lingkaran(900, 900, 50, 100, 1.0, 1.0, 0.0);

    glColor3f(0.8, 0.9, 0.9);
    glBegin(GL_TRIANGLES);
    glVertex2i(200, 100);
    glVertex2i(500, 100);
    glVertex2i(350, 500);
    glEnd();

    glColor3f(0.7, 0.8, 0.9);
    glBegin(GL_TRIANGLES);
    glVertex2i(400, 100);
    glVertex2i(800, 100);
    glVertex2i(600, 550);
    glEnd();

    glColor3f(0.1, 0.6, 0.1);
    glBegin(GL_POLYGON);
    glVertex2i(0, 100);
    glVertex2i(1000, 100);
    glVertex2i(1000, 0);
    glVertex2i(0, 0);
    glEnd();

    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2i(0, 100);
    glVertex2i(1000, 100);
    glVertex2i(1000, 200);
    glVertex2i(0, 200);
    glEnd();

    glColor3f(0.3, 0.5, 0.7);
    glBegin(GL_POLYGON);
    glVertex2i(400, 200);
    glVertex2i(600, 200);
    glVertex2i(600, 400);
    glVertex2i(400, 400);
    glEnd();

    glColor3f(0.5, 0.2, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2i(380, 400);
    glVertex2i(620, 400);
    glVertex2i(500, 500);
    glEnd();

    glColor3f(0.2, 0.1, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(470, 200);
    glVertex2i(530, 200);
    glVertex2i(530, 300);
    glVertex2i(470, 300);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2i(420, 320);
    glVertex2i(450, 320);
    glVertex2i(450, 350);
    glVertex2i(420, 350);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(550, 320);
    glVertex2i(580, 320);
    glVertex2i(580, 350);
    glVertex2i(550, 350);
    glEnd();

    glColor3f(0.4, 0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2i(150, 200);
    glVertex2i(170, 200);
    glVertex2i(170, 300);
    glVertex2i(150, 300);
    glEnd();

    lingkaran(160, 330, 40, 100, 0.0, 0.6, 0.0);
    lingkaran(140, 310, 40, 100, 0.0, 0.7, 0.0);
    lingkaran(180, 310, 40, 100, 0.0, 0.7, 0.0);

    lingkaran(200, 800, 30, 100, 1.0, 1.0, 1.0);
    lingkaran(230, 820, 30, 100, 1.0, 1.0, 1.0);
    lingkaran(260, 800, 30, 100, 1.0, 1.0, 1.0);

    lingkaran(700, 750, 25, 100, 1.0, 1.0, 1.0);
    lingkaran(730, 770, 30, 100, 1.0, 1.0, 1.0);
    lingkaran(760, 750, 25, 100, 1.0, 1.0, 1.0);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1280, 800);
    glutCreateWindow("672022302_Tugas2 - Pemandangan Sekitar Rumah");
    mulai();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
