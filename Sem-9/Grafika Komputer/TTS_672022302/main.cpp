#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

struct Geometry {
    char type;
    float r, g, b;
    float angle;
};

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
bool isAnimating = false;
Geometry grid[3][3];

void randomColor(float &r, float &g, float &b) {
    r = static_cast<float>(rand()) / RAND_MAX;
    g = static_cast<float>(rand()) / RAND_MAX;
    b = static_cast<float>(rand()) / RAND_MAX;
}

void drawTriangle(float size) {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, size);
    glVertex2f(-size, -size);
    glVertex2f(size, -size);
    glEnd();
}

void drawDiamond(float size) {
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, size);
    glVertex2f(-size, 0.0f);
    glVertex2f(0.0f, -size);
    glVertex2f(size, 0.0f);
    glEnd();
}

void drawPentagon(float size) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 5; ++i) {
        float angle = i * 2.0f * 3.1415926f / 5.0f - 3.1415926f / 2.0f;
        glVertex2f(size * cos(angle), size * sin(angle));
    }
    glEnd();
}

void drawCircle(float size) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 50; ++i) {
        float angle = i * 2.0f * 3.1415926f / 50.0f;
        glVertex2f(size * cos(angle), size * sin(angle));
    }
    glEnd();
}

void drawGeometry(char type, float size) {
    switch (type) {
        case 'A': drawTriangle(size); break;
        case 'B': drawDiamond(size); break;
        case 'C': drawCircle(size); break;
        case 'D': drawPentagon(size); break;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    float cellSize = 2.0f / 3.0f;
    float offsetX = -1.0f + cellSize / 2;
    float offsetY = 1.0f - cellSize / 2;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            Geometry &geom = grid[row][col];

            float x = offsetX + col * cellSize;
            float y = offsetY - row * cellSize;

            glPushMatrix();
            glTranslatef(x, y, 0.0f);
            glRotatef(geom.angle, 0, 0, 1);
            glColor3f(geom.r, geom.g, geom.b);
            drawGeometry(geom.type, 0.2f);
            glPopMatrix();
        }
    }

    glutSwapBuffers();
}

void idle() {
    if (isAnimating) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                grid[row][col].angle += 0.07f;
                if (grid[row][col].angle > 360) grid[row][col].angle -= 360;
            }
        }
        glutPostRedisplay();
    }
}


void mouse(int button, int state, int, int) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                randomColor(grid[row][col].r, grid[row][col].g, grid[row][col].b);
            }
        }
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int, int) {
    if (key == 'm' || key == 'M') {
        isAnimating = !isAnimating;
    }
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    srand(static_cast<unsigned int>(time(0)));

    std::vector<char> inputs(9);
    std::cout << "Masukkan 9 input geometri (A=Triangle, B=Diamond, C=Circle, D=Pentagon):\n";
    for (int i = 0; i < 9; ++i) {
        std::cout << i + 1 << ". Geometry: ";
        std::cin >> inputs[i];
        inputs[i] = toupper(inputs[i]);
    }

    for (int i = 0; i < 9; ++i) {
        int row = i / 3;
        int col = i % 3;
        grid[row][col].type = inputs[i];
        randomColor(grid[row][col].r, grid[row][col].g, grid[row][col].b);
        grid[row][col].angle = 0.0f;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Geometry Grid (3x3)");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
