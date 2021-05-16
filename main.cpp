#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <string>
#include <iostream>

using namespace std;

int xyn2oneD(int x, int y, int n, int iw) {
    return x*3+n+(y*iw*3);
}

bool comparecolor(const unsigned char * data, int index1D, unsigned char r, unsigned char g, unsigned char b)
{
    if(data[index1D]==r && data[index1D]==g && data[index1D]==b) {
        return true;
    } else {
        return false;
    }
}


int main(int argc, char **argv)
{
    string inputPath = "einsteinSample.bmp";
    
    int iw, ih, n;
    
    // load images
    unsigned char *idata = stbi_load(inputPath.c_str(), &iw, &ih, &n, 0);
    cout<<"w: "<<iw<<", h: "<<ih<<", n: "<<n<<endl;

    int ow = iw;
    int oh = ih;
    unsigned char *odata = (unsigned char *) malloc(ow * oh * n);
    
    for(int j=0; j<ih; j++) {
        for(int i=0; i<iw; i++) {
            int index = i*3+0+j*iw*3;

            if(comparecolor(idata, index, 255, 255, 255)) {
                odata[i*3+0+j*iw*3] = 255;
                odata[i*3+1+j*iw*3] = 0;
                odata[i*3+2+j*iw*3] = 0;
            } else {
                odata[i*3+0+j*iw*3] = idata[i*3+0+j*iw*3];
                odata[i*3+1+j*iw*3] = idata[i*3+1+j*iw*3];
                odata[i*3+2+j*iw*3] = idata[i*3+2+j*iw*3];
            }

        }
    }


    string outputPath = "out.bmp";
    
    // write
    stbi_write_png(outputPath.c_str(), ow, oh, n, odata, 0);

    stbi_image_free(idata);
    stbi_image_free(odata);

   return 0;
}