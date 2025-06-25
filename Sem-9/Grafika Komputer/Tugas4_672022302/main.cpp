#include <GL/freeglut.h>
#include "LoadImageBMP.h"
#include <iostream>

GLuint textures[6];
float angle = 0.0f;

void loadTextures() {
    const char* files[] = {
        "texture1.bmp", "texture2.bmp", "texture3.bmp",
        "texture4.bmp", "texture5.bmp", "texture6.bmp"
    };

    for (int i = 0; i < 6; ++i) {
        textures[i] = loadBMP_custom(files[i]);
        if (textures[i] == 0) {
            std::cerr << "Failed to load " << files[i] << std::endl;
        }
    }
}

void drawCube() {
    glEnable(GL_TEXTURE_2D);

    // DEPAN
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1, 0); glVertex3f(1, -1, 1);
    glTexCoord2f(1, 1); glVertex3f(1, 1, 1);
    glTexCoord2f(0, 1); glVertex3f(-1, 1, 1);
    glEnd();

    // BELAKANG
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f(-1, 1, -1);
    glTexCoord2f(0, 1); glVertex3f(1, 1, -1);
    glEnd();

    // ATAS
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-1, 1, 1);
    glTexCoord2f(1, 0); glVertex3f(1, 1, 1);
    glTexCoord2f(1, 1); glVertex3f(1, 1, -1);
    glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);
    glEnd();

    // BAWAH
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f(1, -1, 1);
    glTexCoord2f(0, 1); glVertex3f(-1, -1, 1);
    glEnd();

    // KANAN
    glBindTexture(GL_TEXTURE_2D, textures[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(1, -1, 1);
    glTexCoord2f(1, 0); glVertex3f(1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f(1, 1, -1);
    glTexCoord2f(0, 1); glVertex3f(1, 1, 1);
    glEnd();

    // KIRI
    glBindTexture(GL_TEXTURE_2D, textures[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1, 1); glVertex3f(-1, 1, 1);
    glTexCoord2f(0, 1); glVertex3f(-1, 1, -1);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -5);
    glRotatef(angle, 1.0, 1.0, 0.0);
    drawCube();
    glutSwapBuffers();
}

void update(int value) {
    angle += 1.0f;
    if (angle > 360) angle -= 360;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 100);
    glMatrixMode(GL_MODELVIEW);
    loadTextures();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Textured Cube - GLUT");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
