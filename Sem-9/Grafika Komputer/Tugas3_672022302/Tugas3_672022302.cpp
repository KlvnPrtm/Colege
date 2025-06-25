#include <GL/glut.h>
#include <cmath>

float x = 300.0f, y = 300.0f;       // posisi bola
float dx = 3.0f, dy = 2.5f;         // kecepatan awal
float radius = 20.0f;
int windowWidth = 640, windowHeight = 480;

// Fungsi menggambar bola (lingkaran)
void drawCircle(float cx, float cy, float r) {
    int num_segments = 100;
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0); // kuning
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float px = r * cosf(theta);
        float py = r * sinf(theta);
        glVertex2f(cx + px, cy + py);
    }
    glEnd();
}

// Update posisi bola
void update(int value) {
    // Hitung jarak hanya ke arah yang dituju
    float distX = (dx > 0) ? (windowWidth - (x + radius)) : (x - radius);
    float distY = (dy > 0) ? (windowHeight - (y + radius)) : (y - radius);

    // Efek slowdown: semakin dekat ke dinding, semakin lambat (minimum 0.4)
    float slowdownX = fmax(0.9f, distX / 100.0f);
    float slowdownY = fmax(0.9f, distY / 100.0f);

    // Update posisi dengan kecepatan terpengaruh slowdown
    x += dx * slowdownX;
    y += dy * slowdownY;

    // Pantul ke arah sebaliknya jika menyentuh tepi
    if (x - radius <= 0 || x + radius >= windowWidth) {
        dx = -dx;
    }
    if (y - radius <= 0 || y + radius >= windowHeight) {
        dy = -dy;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 60 FPS
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(x, y, radius);
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // latar belakang hitam
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DVD Bounce - 672022302");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
