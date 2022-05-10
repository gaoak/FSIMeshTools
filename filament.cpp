/// Generates the body mesh (open or closed)
/// user defined parameters
#define NPOINTS 628
//#define FILAMENT
//#define CLOSED false
#define CYLINDER
#define CLOSED true
/// end of description

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#define SEGTYPE 2

using namespace std;

vector<double> Cylinder(double t, double r) {
    vector<double> res(3);
    double theta = 2. * M_PI * t;
    res[0] = r * cos(theta);
    res[1] = r * sin(theta);
    res[2] = 0.;
    return res;
}

vector<double> VerticalLine(double t, double r) {
    vector<double> res(3);
    res[0] = 0.;
    res[1] = t-0.5;
    res[2] = 0.;
    return res;
}

vector<double> GeometryShape(double t, double r) {
#ifdef CYLINDER
    return Cylinder(t, r);
#else
    return VerticalLine(t, r);
#endif
}

void GeneratePoints(int N, double r, vector<vector<double> > &points) {
    points.clear();
    points.push_back(vector<double>());
    double dt = 1./N;
    for(int i=0; i<N; ++i) {
        points.push_back(GeometryShape(dt*i, r));
    }
}

void GenerateElements(vector<vector<double> > &points, vector<vector<int> > &elements, vector<vector<int> > &boundCondition, bool closed) {
    if(points.size()<3) {
        return;
    }
    elements.clear();
    boundCondition.clear();
    elements.push_back(vector<int>());
    boundCondition.push_back(vector<int>());
    int Ne = (int)points.size() - 2;
    for(int i=1; i<=Ne; ++i) {
        vector<int> p = {i, i, i+1, i+1, SEGTYPE, 1};
        elements.push_back(p);
    }
    if(closed) {
        vector<int> p = {Ne+1, Ne+1, 1, 1, SEGTYPE, 1};
        elements.push_back(p);
    }
    for(int i=1; i<(int)points.size(); ++i) {
        vector<int> p = {i, 0, 0, 0, 0, 0, 0};
        boundCondition.push_back(p);
    }
    boundCondition[1][1] = 1;
}

void Output(string filename, vector<vector<double> > &points, vector<vector<int> > &ele, vector<vector<int> > &bc) {
    char buff[1000];
    string endtag("END");
    ofstream ofile(filename.c_str());
    ofile << "Frame3D\n";
    sprintf(buff, "%5d %5d %5d\n", int(points.size()) - 1, int(ele.size()) - 1, 1);
    ofile << buff << endtag << "\n"; 
    //output points
    sprintf(buff, "%5d %22s %22s %22s\n", int(points.size())-1, "X", "Y", "Z");
    ofile << buff;
    for(size_t i=1; i<points.size(); ++i) {
        sprintf(buff, "%5d %22.18f %22.18f %22.18f\n", (int)i, points[i][0], points[i][1], points[i][2]);
        ofile << buff;
    }
    ofile << endtag << "\n";
    // output elements
    sprintf(buff, "%5d %5s %5s %5s %5s %5s\n", int(ele.size()) - 1, "I", "J", "K", "TYPE", "MAT");
    ofile << buff;
    for(size_t i=1; i<ele.size(); ++i) {
        sprintf(buff, "%5d %5d %5d %5d %5d %5d\n", ele[i][0], ele[i][1], ele[i][2], ele[i][3], ele[i][4], ele[i][5]);
        ofile << buff;
    }
    ofile << endtag << "\n";
    // output boundary conditions
    sprintf(buff, "%5d %5s %5s %5s %5s %5s %5s\n", int(points.size()) - 1, "XTRA", "YTRA", "ZTRA", "XROT", "YROT", "ZROT");
    ofile << buff;
    for(size_t i=1; i<points.size(); ++i) {
        sprintf(buff, "%5d %5d %5d %5d %5d %5d %5d\n", bc[i][0], bc[i][1], bc[i][2], bc[i][3], bc[i][4], bc[i][5], bc[i][6]);
        ofile << buff;
    }
    ofile << endtag << "\n";
    // output property parameters
    ofile << "1   E           G           A           RHO         GAMMA       IP          IA          IB" << "\n";
    ofile << "1   0.100D+01   0.100D+01   0.100D+01   0.100D+01   0.100D+01   0.100D+01   0.150D+01   0.500D+00" << "\n";
    ofile << endtag << endl;
    ofile.close();
}

int main() {
    double radius = 0.5;
    int Np = NPOINTS;
    string filename("Beam.dat");
    vector<vector<double> > points;
    vector<vector<int> > elements;
    vector<vector<int> > boundCondition;
    GeneratePoints(Np, radius, points);
    GenerateElements(points, elements, boundCondition, CLOSED);
    Output(filename, points, elements, boundCondition);
    
    return 0;
}
