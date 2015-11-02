
/* 
* Arshdeep Singh
*
* This program will take in a photo and do things to it.
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
    char pixels[height][width];
    fread(header, 1, 54, infile)
    
    
    FILE *outfile1 = fopen("copy1.bmp", "wb");
    FILE *outfile2 = fopen("copy2.bmp", "wb");
    FILE *outfile3 = fopen("copy3.bmp", "wb");
    FILE *outfile4 = fopen("copy4.bmp", "wb");
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}