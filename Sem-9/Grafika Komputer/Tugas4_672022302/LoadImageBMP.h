#pragma once
#include <stdio.h>
#include <GL/freeglut.h>

GLuint loadBMP_custom(const char* imagepath) {
    unsigned char header[54];
    unsigned int dataPos, width, height, imageSize;
    unsigned char* data;

    FILE* file;
    fopen_s(&file, imagepath, "rb");
    if (!file) { printf("Image could not be opened: %s\n", imagepath); return 0; }

    if (fread(header, 1, 54, file) != 54) {
        printf("Not a correct BMP file\n");
        fclose(file);
        return 0;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        printf("Not a correct BMP file\n");
        fclose(file);
        return 0;
    }

    if (*(int*)&(header[0x1E]) != 0 || *(int*)&(header[0x1C]) != 24) {
        printf("Unsupported BMP format\n");
        fclose(file);
        return 0;
    }

    dataPos = *(int*)&(header[0x0A]);
    imageSize = *(int*)&(header[0x22]);
    width = *(int*)&(header[0x12]);
    height = *(int*)&(header[0x16]);

    if (imageSize == 0) imageSize = width * height * 3;
    if (dataPos == 0) dataPos = 54;

    data = new unsigned char[imageSize];
    fread(data, 1, imageSize, file);
    fclose(file);

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
                 GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

    delete[] data;
    return textureID;
}
