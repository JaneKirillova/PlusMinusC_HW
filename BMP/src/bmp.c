#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"bmp.h"

int load_bmp(char* filename, BMP* picture) {
  FILE* F = fopen(filename, "rb");

  if (F == NULL)
    return 526;

  fread(&picture->header, sizeof(picture->header), 1, F);
  fseek(F, picture->header.bfOffBits, SEEK_SET);

  int w = picture->header.biWidth;
  int h = picture->header.biHeight;
  int padding = w - (w / 4) * 4;

  picture->data = malloc(sizeof(RGB*) * h);
  if (picture->data == NULL) {
    free(picture->data);
    return 526;
  }


  RGB* tmp = malloc(sizeof(RGB) * h * w);
  if (tmp == NULL) {
    free(picture->data);
    return 526;
  }

  for(int i = 0; i < h; i++)
    picture->data[i] = tmp + i * w;

  for (int i = 0; i < h; i++) {
    fread(picture->data[i], sizeof(RGB)*w, 1, F);
    fseek(F, padding, SEEK_CUR);
  }
  
  fclose(F);

  return 0;
}

int crop_bmp(int x, int y, int w, int h, BMP* picture, BMP* new_picture) {
  new_picture->header = picture->header;
  new_picture->header.biWidth = w;
  new_picture->header.biHeight = h;
  new_picture->header.biSizeImage = h * w * sizeof(RGB);

  new_picture->data = malloc(sizeof(RGB*) * h);
  if (picture->data == NULL) {
      free(picture->data);
      return 526;
  }

  RGB* tmp = malloc(sizeof(RGB) * h * w);
  if (tmp == NULL) {
    free(picture->data);
    return 526;
  }

  for(int i = 0; i < h; i++)
    new_picture->data[i] = tmp + i * w;

  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      new_picture->data[i][j] = picture->data[i + x][j + y];

  return 0;
}

int rotate_bmp(BMP* picture, BMP* new_picture) {
  new_picture->header = picture->header;
  int w = picture->header.biHeight;
  int h = picture->header.biWidth;
  new_picture->header.biWidth = w;
  new_picture->header.biHeight = h;

  new_picture->data = malloc(sizeof(RGB*)*h);
  if (picture->data == NULL) {
      free(picture->data);
      return 526;
  }

  RGB* tmp = malloc(sizeof(RGB) * h * w);
  if (tmp == NULL) {
    free(picture->data);
    return 526;
  }

  for(int i = 0; i < h; i++)
    new_picture->data[i] = tmp + i * w;

  for(int i = 0; i < h; i++) 
    for(int j = 0; j < w; j++)
      new_picture->data[i][j] = picture->data[j][h - i - 1];

  return 0;
}

int save_bmp(char* filename, BMP* picture) {
  int w = picture->header.biWidth;
  int h = picture->header.biHeight;
  int padding = w - (w / 4) * 4;

  picture->header.bfSize = 54 + (3 * w + padding) * h;
  picture->header.biSizeImage = (3 * w + padding) * h;
  
  FILE* F = fopen(filename, "wb");
  if (F == NULL)
    return 526;

  fwrite(&picture->header, sizeof(picture->header), 1, F);
  fseek(F, picture->header.bfOffBits, SEEK_SET);

  int zero = 0;
  
  for (int j = 0; j < h; j++) {
    fwrite(picture->data[j], sizeof(RGB) * w, 1, F);
    fwrite(&zero, padding, 1, F);
  }

  fclose(F);

  return 0;
}

void destroy_bmp(BMP* picture) {
  free(picture->data[0]);
  free(picture->data);
}

