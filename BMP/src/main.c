#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"bmp.h"


int main(int argc, char *argv[]) {

  if (argc != 8)
    return 526;

  BMP picture;
  BMP cropped_picture;
  BMP rotated_picture;

  int x = atoi(argv[4]);
  int y = atoi(argv[5]);
  int w = atoi(argv[6]);
  int h = atoi(argv[7]);

  load_bmp(argv[2], &picture);

  if (x < 0 || y < 0 || 
      w < 0 || h < 0 ||
      x + w > picture.header.biWidth ||
      y + h > picture.header.biHeight)
    return 526;

  crop_bmp(x, y, w, h, &picture, &cropped_picture); 
  rotate_bmp(&cropped_picture, &rotated_picture);
  save_bmp(argv[3], &rotated_picture);

  destroy_bmp(&picture);
  destroy_bmp(&cropped_picture);
  destroy_bmp(&rotated_picture);

  return 0;
}

