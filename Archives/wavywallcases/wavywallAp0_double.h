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
std::vector<double> xFMesh{-70.5, 5.5};
std::vector<int> NxFMesh{15200};
std::vector<double> yFMesh{-1.2, -1.1, 3, 20};
std::vector<int> NyFMesh{  20, 820, 680};

/// Generates the body mesh (open or closed)
/// filament.cpp
/// user defined parameters
/*
#define NPOINTS 201
#define GEOMTYPE   2 // 0 cylinder; 1 vertical line; 2 horizontal line; 3 horizontal cos
#define PARAMS0    1 //maximum length
#define PARAMS1    0.1 //cos amplitude
#define CLOSED false */

#define NPOINTS 15001
#define GEOMTYPE   2 // 0 cylinder; 1 vertical line; 2 horizontal line;
                     //3 horizontal cos; 4 horizontal square wave
std::vector<double> filaparams{75., 0., 1}; //length, amplitude, length1, length2
#define CLOSED false
/// end of description