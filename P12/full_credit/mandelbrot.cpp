#include "mandelbrot.h"

#include <array>
#include <thread>
#include <mutex>

const int MAX_COLOR = 255;

Mandelbrot::Mandelbrot(int width, int height, int icount, int nthreads) 
  : _width{width}, _height{height}, _icount{icount}, _nthreads{nthreads} {

    // Allocate memory for the results
    _values = new int[_width * _height];
    int start =0;
    int arr[_nthreads];
    for (int i=0;i<_nthreads;++i){
        arr[i]=start+_height/_nthreads;
        start+=_height/_nthreads;
        std::cout<<start<<std::endl;
    }
    start= 0;
    std::thread mythread[_nthreads];
    for (int i=0; i<_nthreads;i++){
        if ((start+_height/_nthreads)<=_height) mythread[i]=std::thread{&Mandelbrot::calculate_rows,this,start,start+_height/_nthreads-1};
        start+=_height/_nthreads;
    }
    for (int i=0; i<_nthreads;i++) mythread[i].join();

    // Calculate the results
}

// Deallocate results memory
Mandelbrot::~Mandelbrot() {delete[] _values;}

// Calculate a range of rows (y values) 
void Mandelbrot::calculate_rows (int y1, int y2) {
    for (int y = y1; y <= y2; y++)  {
    // std::cout<<y<<'\t';
        for (int x = 0; x < _width; x++) {
            calculate_point(x, y);
        }
    }
}

// Calculate a specific point in the Mandelbrot set
void Mandelbrot::calculate_point (int x, int y)  {
    std::complex<double> point{static_cast<double>(x) / static_cast<double>(_width)  - 1.5, 
                               static_cast<double>(y) / static_cast<double>(_height) - 0.5};
    std::complex<double> z(0, 0);
    int iterations = 0;
    while (std::abs(z) < 2 && iterations++ <= _icount) z = z*z + point;
    _values[y*_width+x] = (iterations < _icount) ? (MAX_COLOR*iterations)/_icount : 0;
}

// Print out the results in ppm type 3 file format
std::ostream& operator<<(std::ostream& ost, const Mandelbrot& mandelbrot) {
    ost << "P3\n" << mandelbrot._width << ' ' << mandelbrot._height << ' '<< MAX_COLOR << '\n';
    for (int i = 0; i < mandelbrot._width * mandelbrot._height; i++) {
             ost << mandelbrot._values[i] << ' ' << 0 << ' ' << 0 << "\n";
    }
    return ost;
}

