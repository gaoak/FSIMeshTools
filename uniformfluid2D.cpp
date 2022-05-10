#include<iostream>
#include<fstream>
#include<string>

using namespace std;

char buff[1000];

void outputline(ofstream &file, double xmin, double xmax, int Nx, char X) {
    sprintf(buff, "%05d         %c\n", Nx, X);
    file << buff;
    double dx = (xmax - xmin)/(Nx - 1.);
    for(int i=0; i<Nx; ++i) {
        sprintf(buff, "%05d   %25.17e\n", i+1, xmin + dx * i);
        file << buff;
    }
}

int main(int argc, char *argv[]) {
    int Nx = 3801;
    int Ny = 1601;
    double xmin = -8.;
    double xmax = 30.;
    double ymin = -8.;
    double ymax =  8.;
    string filename("FluidMesh.dat");
    ofstream outfile(filename.c_str());
    outputline(outfile, xmin, xmax, Nx, 'X');
    outputline(outfile, ymin, ymax, Ny, 'Y');
    outfile.close();
}
