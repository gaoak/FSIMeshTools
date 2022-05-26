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
#define NX0 8900
#define NX1 1000
#define NX2 1100

#define NY0 40
#define NY1 600
#define NY2 680

#define X0 -49.5
#define X1 -5.
#define X2  0.
#define X3 5.5

#define Y0 -0.2
#define Y1 0
#define Y2  3
#define Y3 20.


/// Generates the body mesh (open or closed)
/// filament.cpp
/// user defined parameters
#define NPOINTS 961
#define GEOMTYPE   3 // 0 cylinder; 1 vertical line; 2 horizontal line; 3 horizontal cos
#define PARAMS0    6 //cylinder radius or cos wavelength
#define PARAMS1    0.1 //cos amplitude
#define CLOSED false
/// end of description