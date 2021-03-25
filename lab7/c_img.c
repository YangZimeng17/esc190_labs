#include "c_img.h"
#include <stdio.h>
#include <math.h>

void create_img(struct rgb_img **im, size_t height, size_t width){
    *im = (struct rgb_img *)malloc(sizeof(struct rgb_img));
    (*im)->height = height;
    (*im)->width = width;
    (*im)->raster = (uint8_t *)malloc(3 * height * width);
}


int read_2bytes(FILE *fp){
    uint8_t bytes[2];
    fread(bytes, sizeof(uint8_t), 1, fp);
    fread(bytes+1, sizeof(uint8_t), 1, fp);
    return (  ((int)bytes[0]) << 8)  + (int)bytes[1];
}

void write_2bytes(FILE *fp, int num){
    uint8_t bytes[2];
    bytes[0] = (uint8_t)((num & 0XFFFF) >> 8);
    bytes[1] = (uint8_t)(num & 0XFF);
    fwrite(bytes, 1, 1, fp);
    fwrite(bytes+1, 1, 1, fp);
}

void read_in_img(struct rgb_img **im, char *filename){
    FILE *fp = fopen(filename, "rb");
    size_t height = read_2bytes(fp);
    size_t width = read_2bytes(fp);
    create_img(im, height, width);
    fread((*im)->raster, 1, 3*width*height, fp);
}

void write_img(struct rgb_img *im, char *filename){
    FILE *fp = fopen(filename, "wb");
    write_2bytes(fp, im->height);
    write_2bytes(fp, im->width);
    fwrite(im->raster, 1, im->height * im->width * 3, fp);
    fclose(fp);
}

uint8_t get_pixel(struct rgb_img *im, int y, int x, int col){
    return im->raster[3 * (y*(im->width) + x) + col];
}

void set_pixel(struct rgb_img *im, int y, int x, int r, int g, int b){
    im->raster[3 * (y*(im->width) + x) + 0] = r;
    im->raster[3 * (y*(im->width) + x) + 1] = g;
    im->raster[3 * (y*(im->width) + x) + 2] = b;
}

void destroy_image(struct rgb_img *im)
{
    free(im->raster);
    free(im);
}


void print_grad(struct rgb_img *grad){
    int height = grad->height;
    int width = grad->width;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("%d\t", get_pixel(grad, i, j, 0));
        }
    printf("\n");
    }
}



void modify_img(struct rgb_img *im, char *resname[], double scale[]){

    //char resname=["res1", "res2"];

    struct rgb_img *fim;
    //struct rgb_img *tmp;
    //int r, g, b, rx, gx, bx, ry, gy, by, dx2, dy2;
    uint8_t r, g, b, r1, g1, b1;
    int height, width, y, x, x1,x2,y1,y2;

    height=im->height;
    width=im->width;

    create_img(&fim, height, width);

    for(int i=0; i<5; i++){
        for (y=0; y<height; y++){
            for (x=0; x<width; x++){

               r=get_pixel( im, y, x, 0);
               r1=(r*scale[i]>255)? 255: (uint8_t)(r*scale[i]);
               g=get_pixel( im, y, x, 1);
               g1=(g*scale[i]>255)? 255: (uint8_t)(g*scale[i]);
               b=get_pixel( im, y, x, 2);
               b1=(b*scale[i]>255)? 255: (uint8_t)(b*scale[i]);
               //printf("orig:(%d, %d, %d)", r, g, b);
               //printf("mody:(%d, %d, %d)", r1, g1, b1);

               set_pixel(fim, y, x, r1, g1, b1);
            }
        }
        write_img(fim, resname[i]);
        //write_img(fim, "result1.bin");
    }

}

int main(void){
    struct rgb_img *grad, *im;
    //char filename[40]="6x5.bin";
    char filename[40]="UofTPresidentMericGertler-smaller.bin";

    //array Scale contains 5 factors to modify brightness
    double scale[5]={0.2, 0.4, 0.6, 0.8, 1.5}; //an array

    // resultant binary photos to be stored in the array.
    char *resname[5]={"res1.bin","res2.bin","res3.bin","res4.bin","res5.bin"};
    read_in_img(&im, filename);

    modify_img(im, resname, scale);

    //calc_energy(im, &grad);
    //print_grad(grad);

    destroy_image(im);

}
