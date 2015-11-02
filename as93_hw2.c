
/* 
* Arshdeep Singh
*TCSS333 C Programing
* November 1, 2015
* Monika
*
* This program will take in a photo and do things to it.
*
* EXTRA CREDIT: The fifth effect is a rotation of the rgb values, it makes a holographic looking photo.
*/



#include <stdio.h>
#include <string.h>



int main(void) {
    
    //holds the name of the picture to edit
    char picName[256];
    
    int height;
    int width;
    
    
    printf("\n"); //start of program.
    
    printf("Enter the file name: ");
    scanf( "%s", picName );
    strcat(picName, ".bmp"); //add .bmp to the end of what the user typed.
    
    printf("Enter height and width (in pixels) : ");
    scanf( "%d%d", &height, &width);
    

    FILE *infile = fopen(picName, "rb");
    
    char header[54];
    unsigned char pixels[height][width * 3];
    
    fread(header, 1, 54, infile);
    fread(pixels, 1, height * width * 3, infile);
    fclose(infile);
    
    
    int i,j; //used for looping
    int side = width * 3; //total number of pixels on the wide side
    
    
    FILE *outfile1 = fopen("copy1.bmp", "wb");
    fwrite(header, sizeof(char), 54, infile);
    //remove red
    unsigned char new_pix1[height][width*3];
    for (i = 0; i < height; i++) {
        for (j = 0; j < side; j += 3) { //NOTE: moving up 3 because 3 bits for rgb
            
            //do nothing to the pixels that are represented by i and i+1.
            new_pix1[i][j] = pixels[i][j];
            new_pix1[i][j+1] = pixels[i][j+1];
            
            //change only the red
            new_pix1[i][j+2] = 0;
            
        }
    }
    fwrite(new_pix1, sizeof(char), height * width * 3, outfile1);
    fclose(outfile1);
    

    FILE *outfile2 = fopen("copy2.bmp", "wb");
    fwrite(header, sizeof(char), 54, infile);
    //grayscale
    unsigned char new_pix2[height][width*3];
    unsigned char average;
    //for each pixel's rgb, make the rgb to be average value between the rgbs.
    for (i = 0; i < height; i++) {

        for (j = 0; j <side; j += 3) {
            average = (pixels[i][j] + pixels[i][j+1] + pixels[i][j+2] ) / 3;
            new_pix2[i][j] = average;
            new_pix2[i][j+1] = average;
            new_pix2[i][j+2] = average;
        }
    }
    fwrite(new_pix2, sizeof(char), height * width * 3, outfile2);
    fclose(outfile2);
    
    int center = side / 2; // middle of all the columns (middle of width)
    int final = side - 3; //the pixel at the very end of the width
    
    FILE *outfile3 = fopen("copy3.bmp", "wb");
    fwrite(header, sizeof(char), 54, infile);
    unsigned char new_pix3[height][width*3];
    //vertical flip
    for (i = 0; i < height; i++) {
        for (j = 0; j < center; j += 3) {
            //do the first half
            new_pix3[i][j] = pixels[i][final - j];
            new_pix3[i][j + 1] = pixels[i][final - j + 1];
            new_pix3[i][j + 2] = pixels[i][final - j + 2];
            //do the second half
            new_pix3[i][final - j] = pixels[i][j];
            new_pix3[i][final - j + 1] = pixels[i][j + 1];
            new_pix3[i][final - j + 2] = pixels[i][j + 2];
        }
    }
    fwrite(new_pix3, sizeof(char), height * width * 3, outfile3);
    fclose(outfile3);
    
    
    FILE *outfile4 = fopen("copy4.bmp", "wb");
    fwrite(header, sizeof(char), 54, infile);
    unsigned char new_pix4[height][width*3];
    //vertical mirror
    for (i = 0; i < height; i ++) {
        for (j = 0; j < center; j +=3) {
            //do the first half
            new_pix4[i][j] = pixels[i][j];
            new_pix4[i][j + 1] = pixels[i][j + 1];
            new_pix4[i][j + 2] = pixels[i][j + 2];
            //do the second half
            new_pix4[i][final - j] = pixels[i][j];
            new_pix4[i][final - j + 1] = pixels[i][j + 1];
            new_pix4[i][final - j + 2] = pixels[i][j + 2];
        }
    }
    fwrite(new_pix4, sizeof(char), height * width * 3, outfile4);
    fclose(outfile4);
    

    FILE *outfile5 = fopen("copy5.bmp", "wb");
    fwrite(header, sizeof(char), 54, infile);
    unsigned char new_pix5[height][width*3];
    //alternate the rgb values.
    for (i = 0; i < height; i++) {
        for (j = 0; j < side; j += 3) {
            new_pix5[i][j] = pixels[i][j + 1];
            new_pix5[i][j+1] = pixels[i][j + 2];
            new_pix5[i][j+2] = pixels[i][j];
        }
    }
    fwrite(new_pix5, sizeof(char), height * width * 3, outfile5);
    fclose(outfile5);
    
    
    
    
    return 0;
    
}
























