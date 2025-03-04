#include<vector>
/// Generates the body mesh (open or closed)
/// filament.cpp
/// user defined parameters
#define NPOINTS 101
#define GEOMTYPE 2    // 0 cylinder; 1 vertical line; 2 horizontal line; 3 horizontal cos; 4 horizontal square wave
std::vector<double> filaparams{1, 0., 1}; //length, amplitude, length1, length2
std::vector<int> spantype{0, 0}; // right(0 const; 1 oblique line; 2 cos), left(...)
std::vector<double> normal{0, 0, 1}; // extension direction
std::vector<std::vector<double>> spanparams{{0.0, 1.0, 0.0, 0.0}, {0.5, 1.0, 0.0, 0.0}}; // left(amplitude, frequency, phase, intercept), right(...)
#define CLOSED false
/// end of description