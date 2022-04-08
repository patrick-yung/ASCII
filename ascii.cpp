/*

CSCI 3280, Introduction to Multimedia Systems
Spring 2022

Assignment 01 Skeleton

ascii.cpp

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
	//	1. Open BMP file
	//
	Bitmap image_data(argv[1]);

	if(image_data.getData() == NULL)
	{
		printf("unable to load bmp image!\n");
		return -1;
	}


	//
	//	Your code goes here ....
	//
	//	2. Obtain Luminance
	//

	int width = image_data.getWidth();
	int hight = image_data.getHeight();
	//
	//	3. Quantization & ascii mapping
	//
	int size=255/MAX_SHADES+1;

	FILE *final = fopen(argv[2], "w");
	fprintf( final, "%d %d", width, hight );

	

	unsigned char red, green, blue;
	int value;
    for(int n=0;n<hight;n++){
		fputc('\n', final);
        for(int q=0;q<width;q++){
			image_data.getColor(q, n, red, green, blue);
			value=MAX_SHADES-1-(0.299 * red + 0.587 * green + 0.114 * blue)/41;
			fputc(shades[value], final);
        }
    }

	//
	//  4. ASCII art txt file
	//
	


	fclose(final);
	
	
	//  free memory if any

	return 0;
} 
