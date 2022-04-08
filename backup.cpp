/*

CSCI 3280, Introduction to Multimedia Systems
Spring 2022

Assignment 01 Skeleton

inverse.cpp

*/

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include "bmp.h"		//	Simple .bmp library

#define MAX_SHADES 8

char shades[MAX_SHADES] = {'@','#','%','*','|','-','.',' '};

#define SAFE_FREE(p)  { if(p){ free(p);  (p)=NULL;} }

int main(int argc, char** argv)
{
    //
    // 1. Open the txt file
    //
    FILE *fp = fopen(argv[1], "r");
    if (!fp)
        return -1;


    //
    // Your code goes here ////
    //
    //
    // 2. read the ascii art file.
    //


    int width;
    int hight;
	fscanf(fp, "%d %d", &width, &hight );

    int value;
    //
    // 3. Get RGB values for the resultant bitmap
    //
    int size=255/MAX_SHADES+1;
    width++;

	Bitmap final((width-1)*2, hight*2);
    int color[256][256];

    for(int n=0;n<hight;n++){
        for(int q=0;q<width;q++){
            int picture=getc(fp);
                for(int m=0;m<MAX_SHADES;m++){
                    if(shades[m]==picture){
                        color[q][n]=size*(MAX_SHADES-m);
                    }
                }    
        }
    }

    int a=0;
    for(int n=0;n<hight;n++){
        for(int q=0;q<width;q++){
            if(q<width/2&&n<hight/2){
            final.setColor(q-1, n, color[q][n], color[q][n], color[q][n]);
            }else if(q>=width/2&&n<hight/2){
                final.setColor(q-1, n, color[width-q][n], color[width-q][n], color[width-q][n]);
            } else if(q<width/2&&n>=hight/2){
                final.setColor(q-1, n, color[q][hight-n], color[q][hight-n], color[q][hight-n]);
            }  else if(q>=width/2&&n>=hight/2){
                final.setColor(q-1, n, color[width-q][hight-n], color[width-q][hight-n], color[width-q][hight-n]);
            }      

        }
    }



    final.save(argv[2]);
    //
    // 4. Store the BMP file to the given place
    //

    fclose(fp);

    // free memory if any


    return 0;
}