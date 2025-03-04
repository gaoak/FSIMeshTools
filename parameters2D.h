#include<vector>
/// generates uniform fluid mesh
/// uniformfluid2D.cpp
/// user defined parameters
#define NX 5001
#define NY 4001
#define XMIN -20.
#define XMAX 30.
#define YMIN -20.
#define YMAX 20.
/// end of description

/// generates nonuniform fluid mesh
/// nonuniformfluid2D.cpp
/// user defined parameters
std::vector<double> xFMesh{-65.5, -60, 1, 6.5};
std::vector<int> NxFMesh{220, 6100, 220};
std::vector<double> yFMesh{-1.2, -1.1, 3, 20};
std::vector<int> NyFMesh{  10, 410, 680};

/// Generates the body mesh (open or closed)
/// filament.cpp
/// user defined parameters
#define CLOSED false
#define NPOINTS 101
#define GEOMTYPE 2    // 0 cylinder; 1 vertical line; 2 horizontal line; 3 horizontal cos; 4 horizontal square wave
std::vector<double> filaparams{1, 0., 1}; //length, amplitude, length1, length2
std::vector<double> normal{0, 0, 1}; // extension direction
std::vector<int> spantype{4, 4}; // right(0 const; 1 oblique line; 2 ellipse; 3 cos; 4 sawtooth), left(...)
std::vector<std::vector<double>> spanparams{{0.25, 0.20, 0.10, 0.0}, {0.25, 0.20, 0.10, 0.0}}; 
//0 left(leading span length, none, none, none), right(...)
//1 left(leading span length, slope, none, none), right(...)
//2 left(leading span length, chord center, chord radius, spanwise radius), right(...)
//3 left(leading span length, amplitude, frequency, phase), right(...)
//4 left(leading span length, saw width, saw height, none), right(...)
