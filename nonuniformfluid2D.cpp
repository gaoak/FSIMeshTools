/// generates uniform fluid mesh
/// user defined parameters
#define NX0 250
#define NX1 4000
#define NX2 250

#define NY0 925
#define NY1 300
#define NY2 925

#define X0 -40.
#define X1 -35.
#define X2  5.
#define X3 10.

#define Y0 -20.
#define Y1 -1.5
#define Y2  1.5
#define Y3 20.
/// end of description
#include<vector>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

char buff[1000];

void outputline(ofstream &file, std::vector<double> &x, std::vector<int> N, char X) {
    int Nx = 1;
    for(size_t s=0; s<N.size(); ++s) {
        Nx += N[s];
    }
    sprintf(buff, "%05d         %c\n", Nx, X);
    file << buff;
    int count = 1;
    for(size_t s=0; s<N.size(); ++s) {
        double dx = (x[s+1] - x[s])/N[s];
        for(int i=0; i<N[s]; ++i) {
            sprintf(buff, "%05d   %25.17e\n", count, x[s] + dx * i);
            file << buff;
            ++count;
        }
    }
    sprintf(buff, "%05d   %25.17e\n", count, x[N.size()]);
    file << buff;
}

int main(int argc, char *argv[]) {
    std::vector<int> Nx{NX0, NX1, NX2};
    std::vector<int> Ny{NY0, NY1, NY2};
    std::vector<double> x{X0, X1, X2, X3};
    std::vector<double> y{Y0, Y1, Y2, Y3};
    string filename("FluidMesh.dat");
    ofstream outfile(filename.c_str());
    outputline(outfile, x, Nx, 'X');
    outputline(outfile, y, Ny, 'Y');
    outfile.close();
}
