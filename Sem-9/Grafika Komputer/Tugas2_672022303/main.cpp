#include <GL/glut.h>
#include <cmath> // untuk sin, cos

// Gambar persegi panjang
void drawRect(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

// Gambar segitiga
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

// Gambar lingkaran
void drawCircle(float cx, float cy, float r, int segments, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * i / segments;
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// Gambar bayangan persegi (abu gelap)
void drawShadowRect(float x1, float y1, float x2, float y2) {
    drawRect(x1 - 10, y1 - 10, x2 - 10, y2 - 10, 0.3, 0.3, 0.3);
}

// Gambar bayangan lingkaran
void drawShadowCircle(float cx, float cy, float r) {
    drawCircle(cx - 10, cy - 10, r, 50, 0.3, 0.3, 0.3);
}

// Gambar langit dengan gradasi biru
void drawGradientSky(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
        glColor3f(0.1f, 0.4f, 0.8f); // atas
        glVertex2f(x1, y2);
        glVertex2f(x2, y2);
        glColor3f(0.5f, 0.8f, 1.0f); // bawah
        glVertex2f(x2, y1);
        glVertex2f(x1, y1);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // LANGIT dengan gradasi
    drawGradientSky(0, 250, 800, 500);

    // RUMPUT
    drawRect(0, 0, 800, 250, 0.6, 1.0, 0.6);

    // MATAHARI
    drawCircle(700, 430, 40, 100, 1, 1, 0);

    // RUMAH & BAYANGAN
    drawShadowRect(300, 100, 450, 200);
    drawShadowRect(355, 100, 395, 160);
    drawRect(300, 100, 450, 200, 0.9, 0.6, 0.3); // rumah
    drawTriangle(280, 200, 470, 200, 375, 270, 0.8, 0.3, 0.1); // atap
    drawRect(355, 100, 395, 160, 0.4, 0.2, 0); // pintu

    // POHON KIRI
    drawShadowRect(120, 100, 135, 180);
    drawShadowCircle(127, 200, 30);
    drawRect(120, 100, 135, 180, 0.4, 0.2, 0); // batang
    drawCircle(127, 200, 30, 50, 0, 0.6, 0);   // daun

    // POHON KANAN
    drawShadowRect(550, 100, 565, 180);
    drawShadowCircle(557, 200, 30);
    drawRect(550, 100, 565, 180, 0.4, 0.2, 0);
    drawCircle(557, 200, 30, 50, 0, 0.6, 0);

    // JALAN
    drawRect(0, 60, 800, 100, 0.3, 0.3, 0.3);
    for (int i = 0; i < 800; i += 80) {
        drawRect(i, 78, i + 40, 82, 1, 1, 1); // garis putih jalan
    }

    // MOBIL & BAYANGAN
    drawShadowRect(100, 100, 170, 130);
    drawShadowCircle(115, 100, 8);
    drawShadowCircle(155, 100, 8);
    drawRect(100, 100, 170, 130, 1, 0, 0); // body mobil
    drawCircle(115, 100, 8, 30, 0, 0, 0);  // roda kiri
    drawCircle(155, 100, 8, 30, 0, 0, 0);  // roda kanan

    glFlush();
}

void init() {
    glClearColor(0.9, 0.9, 0.9, 1.0); // background abu terang
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pemandangan Sekitar Rumah - 672022303");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
