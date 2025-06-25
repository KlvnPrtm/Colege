#include <GL/glut.h>
#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

Point points[1000];
int pointCount = 0;

enum Mode { SOLID_WHITE, SOLID_COLOR, WIREFRAME };
Mode currentMode = SOLID_WHITE;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}

void getColor(int shapeIndex, float* color) {
    if (currentMode == SOLID_WHITE || currentMode == WIREFRAME) {
        color[0] = 1.0;
        color[1] = 1.0;
        color[2] = 1.0;
    } else if (currentMode == SOLID_COLOR) {
        if (shapeIndex == 0) {
            color[0] = 0.0; color[1] = 0.0; color[2] = 1.0;
        } else if (shapeIndex == 1) {
            color[0] = 1.0; color[1] = 0.0; color[2] = 0.0;
        } else if (shapeIndex == 2) {
            color[0] = 0.0; color[1] = 1.0; color[2] = 0.0;
        }
    }
}

void drawShapes() {
    glPolygonMode(GL_FRONT_AND_BACK, currentMode == WIREFRAME ? GL_LINE : GL_FILL);

    float color[3];

    getColor(0, color);
    glColor3fv(color);
    glBegin(GL_POLYGON);
    glVertex2i(100, 150);
    glVertex2i(200, 150);
    glVertex2i(200, 250);
    glVertex2i(100, 250);
    glEnd();

    getColor(1, color);
    glColor3fv(color);
    glBegin(GL_POLYGON);
    glVertex2i(270, 150);
    glVertex2i(320, 250);
    glVertex2i(370, 150);
    glEnd();

    getColor(2, color);
    glColor3fv(color);
    glBegin(GL_POLYGON);
    glVertex2i(440, 150);
    glVertex2i(540, 150);
    glVertex2i(540, 250);
    glVertex2i(440, 250);
    glEnd();
}

void drawPoints() {
    glColor3f(1.0, 1.0, 0.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    for (int i = 0; i < pointCount; ++i)
        glVertex2i(points[i].x, 480 - points[i].y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawShapes();
    drawPoints();
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': case 'A':
            currentMode = SOLID_COLOR;
            cout << "Mode: SOLID COLOR (Biru, Merah, Hijau)\n";
            break;
        case 's': case 'S':
            currentMode = SOLID_WHITE;
            cout << "Mode: SOLID PUTIH\n";
            break;
        case 'd': case 'D':
            currentMode = WIREFRAME;
            cout << "Mode: WIREFRAME PUTIH\n";
            break;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && pointCount < 1000) {
        points[pointCount++] = {x, y};
        cout << "Klik kiri di (" << x << ", " << y << ")\n";
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Tugas 2 OpenGL - 672022302");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
