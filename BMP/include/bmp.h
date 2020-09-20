#ifndef BMP_H_INCLUDED
#define BMP_H_INCLUDED

#pragma pack(push, 1)

typedef struct tagBITMAPHEADER {
  uint16_t  bfType;
  uint32_t bfSize;
  uint16_t bfReserved1;
  uint16_t bfReserved2;
  uint32_t bfOffBits;
  uint32_t biSize;
  int biWidth;
  int biHeight;
  uint16_t biPlanes;
  uint16_t biBitCount;
  uint32_t biCompression;
  uint32_t biSizeImage;
  int biXPelsPerMeter;
  int biYPelsPerMeter;
  uint32_t biClrUsed;
  uint32_t biClrImportant;
} BITMAPHEADER;

#pragma pack(pop)

typedef struct RGB {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} RGB;

typedef struct BMP {
 BITMAPHEADER header;
 RGB** data;
} BMP;

int load_bmp(char* filename, BMP* picture);

void destroy_bmp(BMP* picture);

int save_bmp(char* filename, BMP* picture);

int crop_bmp(int x, int y, int w, int h, BMP* picture, BMP* new_picture);

int rotate_bmp(BMP* picture, BMP* new_picture);

#endif
