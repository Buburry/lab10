#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream source;
    source.open("score.txt");

    int  numdata = 0;
    double mean = 0, stdand = 0,value;
    string textline;

    while (getline(source, textline)) {
        value = atof(textline.c_str());
        mean += value;
        numdata++;
    }
    source.clear(); // Clear the end-of-file flag
    source.seekg(0, ios::beg); // Reset file pointer to the beginning

    mean = mean/ numdata;

    while (getline(source, textline)) {
        value = atof(textline.c_str());
        stdand += pow((value - mean), 2);
    }

    stdand = sqrt(stdand / numdata);

    source.close();

    cout << "Number of data = " << numdata << endl;
    cout << setprecision(3);
    cout << "Mean = " <<  mean << endl;
    cout << "Standard deviation = " <<  stdand << endl;

    return 0;
}
