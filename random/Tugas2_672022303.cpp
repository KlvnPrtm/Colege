#include <GL/glut.h>
#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

Point points[1000];
int pointCount = 0;

bool isWireframe = false;
bool isReset = true;

float colorLeft[3]   = {1.0, 1.0, 1.0};
float colorCenter[3] = {1.0, 1.0, 1.0};
float colorRight[3]  = {1.0, 1.0, 1.0};

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}

void drawShapes() {
    if (isWireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor3fv(colorLeft);
    glBegin(GL_POLYGON);
    glVertex2i(100, 150);
    glVertex2i(200, 150);
    glVertex2i(200, 250);
    glVertex2i(100, 250);
    glEnd();

    glColor3fv(colorCenter);
    glBegin(GL_POLYGON);
    glVertex2i(270, 170);  
    glVertex2i(320, 270);  
    glVertex2i(370, 170); 
    glEnd();

    glColor3fv(colorRight);
    glBegin(GL_POLYGON);
    glVertex2i(440, 150);
    glVertex2i(540, 150);
    glVertex2i(540, 250);
    glVertex2i(440, 250);
    glEnd();
}

void drawPoints() {
    glColor3f(1, 0, 0); 
    glPointSize(5);
    glBegin(GL_POINTS);
    for (int i = 0; i < pointCount; i++) {
        glVertex2i(points[i].x, 480 - points[i].y);
    }
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
            colorLeft[0] = 0; colorLeft[1] = 0; colorLeft[2] = 1;
            colorCenter[0] = 1; colorCenter[1] = 0; colorCenter[2] = 0;
            colorRight[0] = 0; colorRight[1] = 1; colorRight[2] = 0;
            isReset = false;
            cout << "Tombol A ditekan → Warna berubah\n";
            break;

        case 's': case 'S':
            for (int i = 0; i < 3; i++) {
                colorLeft[i] = 1.0;
                colorCenter[i] = 1.0;
                colorRight[i] = 1.0;
            }
            isReset = true;
            cout << "Tombol S ditekan → Warna kembali putih\n";
            break;

        case 'd': case 'D':
            isWireframe = !isWireframe;
            cout << "Tombol D ditekan → Mode: " << (isWireframe ? "Wireframe\n" : "Solid\n");
            break;

        case 'w': case 'W': 
            pointCount = 0;
            cout << "Tombol W ditekan → Titik dihapus semua\n";
            break;
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (pointCount < 1000) {
            points[pointCount].x = x;
            points[pointCount].y = y;
            pointCount++;
            cout << "Klik kiri di (" << x << ", " << y << ")\n";
            glutPostRedisplay();
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Tugas 2 OpenGL - 672022303");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}