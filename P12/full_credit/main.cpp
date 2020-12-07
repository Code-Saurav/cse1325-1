#include "mandelbrot.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    
    int width=1000;
    int height=width;
    int icount= 60;
    int nthreads=1;
    std::string filename = "default.ppm";
    if (argc!=1){
        try
        {
            width = std::stoi(argv[1]);
            height = std::stoi(argv[2]);
            icount = std::stoi(argv[3]);
            nthreads = std::stoi(argv[4]);
            filename = argv[5];
        }
        catch (std::exception &err)
        {
            std::cout << "\nInvalid argument" << std::endl;
            std::cout << err.what() << std::endl;
            return -2;
        }
    }
    
    std::cout << "Width: " << width << " Height: " << height << " icount: " << icount << " threads: "<< nthreads<<std::endl;
    Mandelbrot mandel(width, height, icount, nthreads);
    try
    {
        std::ofstream ppm_file{filename};
        ppm_file << mandel;
    }
    catch (std::exception &erno)
    {
        return -1;
    }
    std::cout << "Wrote: "<<filename<<std::endl;
    return 0;
}