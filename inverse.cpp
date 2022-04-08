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

    //
    // 3. Get RGB values for the resultant bitmap
    //
    int size=255/MAX_SHADES+1;
	Bitmap final(width, hight-1);
    unsigned int patrick=width;
    int color[256][256];
    char str[256];
    fgets(str, 256, fp);

    for(int n=0;n<hight;n++){
        char str[256];
        fgets(str, 256, fp);
        for(int q=0;q<width;q++){
                for(int tmp=0;tmp<MAX_SHADES;tmp++){
                    if(shades[tmp]==str[q]){
                        color[q][n]=size*(MAX_SHADES-tmp);
                        break;
                    }
                }    
        }
    }



    //
    // 4. Store the BMP file to the given place
    //

  for(int n=0;n<hight;n++){
        for(int q=0;q<width;q++){
            final.setColor(q, n, color[q][n], color[q][n], color[q][n]);
        }
    }


    final.save(argv[2]);
    fclose(fp);

    // free memory if any


    return 0;
}