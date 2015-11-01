#include <stdio.h>

/* This program changes the coloring of the image.
 Each pixel is made from a combination of Red, Green, Blue.
 For each of these 3 colors, there is a number indicating the intensity or brightness.
 These numbers range from 0 (none) to 255 (full).  The program interchanges
 the intensities of the green and blue components.
 The blue sky becomes green.   The green tree becomes purple/blue.
 The red things remain red.
 */

int main(void) {
    
    FILE *infile = fopen("test1.bmp", "rb");
    FILE *outfile = fopen("newtest1.bmp", "wb");
    
    
    
    char header[54];
    char pixels[160][240*3];
    
    
    fread( header, 1 , 54 , infile);
    fread( pixels, 1 , 115200 , infile);
    
    int r,c;
    
    for( r = 0; r < 160; r++) {
        for ( c = 0; c < 240*3; c += 3) {
            char temp;
            temp = pixels[r][c];
            pixels[r][c] = pixels[r][c+1];
            pixels[r][c+1] = temp;
        }
    }
    
    fwrite( header, sizeof(char)  , 54  ,  outfile);
    fwrite( pixels, sizeof(char)  , 115200  ,  outfile);
    
    fclose(infile);
    fclose(outfile);
    
    return 0;
    
}
