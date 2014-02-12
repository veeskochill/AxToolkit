#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

const int size = 65;
float data[size][size];
float maxVary = 200.0;
float H = 1.0;

//calculate the quadrant midpoint using generalized midpoint
void CalculateMidpoint(int step, int mx, int my, float stepVary)
{
    int sx, bx; //small, big x
    sx = mx - step;
    bx = mx + step;

    int sy, by; //small, big y
    sy = my - step;
    by = my + step;

    data[mx][my] = data[mx-step][my-step] 
                    + data[mx-step][my+step]
                    + data[mx+step][my+step]
                    + data[mx+step][my-step];
    data[mx][my] /= 4.0;

    float rd = 2.0*((float)rand()/RAND_MAX)-1.0;
    data[mx][my] += rd*stepVary;


}

//calculate the edges of this quadrant
void CalculateEdges(int step, int mx, int my, float stepVary)
{
    //for each quadrant 
    int sx, bx; //small, big x
    sx = mx - step;
    bx = mx + step;

    int sy, by; //small, big y
    sy = my - step;
    by = my + step;

    data[bx][my] = (data[bx][sy] + data[bx][by]) /2;
    data[sx][my] = (data[sx][sy] + data[sx][by]) /2;
    data[mx][by] = (data[sx][by] + data[bx][by]) /2;
    data[mx][sy] = (data[sx][sy] + data[bx][sy]) /2;

    float rd =0; 

    rd = 2.0*((float)rand()/RAND_MAX)-1.0;
    data[bx][my] += rd*stepVary;

    rd = 2.0*((float)rand()/RAND_MAX)-1.0;
    data[sx][my] += rd*stepVary;

    rd = 2.0*((float)rand()/RAND_MAX)-1.0;
    data[mx][by] += rd*stepVary;

    rd = 2.0*((float)rand()/RAND_MAX)-1.0;
    data[mx][sy] += rd*stepVary;

}

void RSquareDiamond(int step, int mx, int my, float stepVary)
{

    CalculateMidpoint(step, mx, my, stepVary);
    CalculateEdges(step, mx, my, stepVary);

    stepVary *= pow(2.0f,-H);

    if(step >= 2)    //termination clause
    {
        int halfStep = step/2;
        //recursive step, clockwise quadrants
        RSquareDiamond(halfStep, mx - halfStep, my - halfStep, stepVary);
        RSquareDiamond(halfStep, mx + halfStep, my - halfStep, stepVary);
        RSquareDiamond(halfStep, mx + halfStep, my + halfStep, stepVary);
        RSquareDiamond(halfStep, mx - halfStep, my + halfStep, stepVary);
    }
}

int main()
{
    
    //set to zero
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            data[i][j] = 0;

    //set the corners
    data[0][0] = 10;
    data[0][size-1] = 4;
    data[size-1][0] = 8;
    data[size-1][size-1] = 2;

    int step = (size -1)/2;



for(int ui =0;ui<1;ui++)
{
    srand(8);
    char name[14];
    cin >> H;
    RSquareDiamond(step, 0+step, 0+step, maxVary);

    cin >> name;
    ofstream *ofs = new ofstream(name, ios::out);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            *ofs << i<< "\t"<< j<<"\t"<< data[i][j] << "\n";
        }
        *ofs << "\n";
    }
ofs->close();
}
    int rdm;
    std::cin >> rdm;
    return 0;
}