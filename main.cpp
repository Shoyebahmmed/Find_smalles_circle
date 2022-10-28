#include <iostream>
#include <vector> 
#include <string>
#include <fstream>
#include <math.h>
#include <limits.h>
#include <chrono>
using namespace std;
using namespace std::chrono;



double functionToCalculateA(pair<double, double>X, pair<double, double>Y, pair<double, double>Z);
double functionToCalculateD(pair<double, double>X, pair<double, double>Y, pair<double, double>Z);
double functionToCalculateE(pair<double, double>X, pair<double, double>Y, pair<double, double>Z);
double	functionToCalculateF(pair<double, double>X, pair<double, double>Y, pair<double, double>Z);
pair<double, double> functionToCalculateCircleCenter(double a, double e, double d);
double functionToCalculateRadius(double a, double  e, double d, double f);
bool fuctionToCheckCircle(pair<double, double>center, double radius, vector<pair<double, double>> array);
void FunctionToCheckSmallCircle(vector<pair<double, double>> data);




int main()
{
    vector<pair<double, double>> a1;
    pair<double, double> num;
    fstream file;
    file.open("Data1.txt");

    if (!file) {
        cout << "File does not exsit" << endl;
        exit(0);
    }

    else {
        string line;
        string part = "";
        while (!file.eof())
        {
            getline(file, line, ',');
            num.first = stoi(line);
            getline(file, line, '\n');
            num.second = stoi(line);
            a1.push_back(num);
        }
    }

  ;
    // for (int j = 0; j < a1.size() ; j++) {
    //     pair<int, int> X = a1[j];
    //     cout << X.first << ", " << X.second << endl;
    // }

  //  auto start = high_resolution_clock::now();
  //   FunctionToCheckSmallCircle(a1);
  //   auto stop = high_resolution_clock::now();
  //   auto duration = duration_cast<microseconds>(stop - start);
  //   cout << "Execution Time = " << duration.count() << endl;

  pair <double, double> A;
  A.first = 1;
  A.second = 2;

  pair <double, double> B;
  B.first = 3;
  B.second = 4;

  pair <double, double> C;
  C.first = 5;
  C.second = 6;

cout << functionToCalculateA(A,B,C);
}


double functionToCalculateA(pair<double, double>X, pair<double, double>Y, pair<double, double>Z){
 double a = ( (X.first * Y.second*1) + (Y.first*Z.second*1) + (Z.first*X.second*1) ) - ((X.first* Z.second*1) + (Y.first*X.second*1) + (Z.first*Y.second*1));
 return a;
}



double functionToCalculateD(pair<double, double>X, pair<double, double>Y, pair<double, double>Z){
  double d = ( pow(X.first,2)*Y.second + pow(X.second,2)*Y.second - pow(X.first,2)*Z.second - pow(X.second,2)*Z.second - pow(Y.first,2)*X.second + pow(Y.first,2)*Z.second - pow(Y.second,2)*X.second + pow(Y.second,2)*Z.second + pow(Z.first,2)*X.second - pow(Z.first,2)*Y.second + pow(Z.second,2)*X.second - pow(Z.second,2)*Y.second);

	return d;

}



double functionToCalculateE(pair<double, double>X, pair<double, double>Y, pair<double, double>Z){
  double e =( pow(X.first,2)*Y.first - pow(X.first,2)*Z.first + pow(X.second,2)*Y.first - pow(X.second,2)*Z.first - pow(Y.first,2)*X.first + pow(Y.first,2)*Z.first - pow(Y.second,2)*X.first + pow(Y.second,2)*Z.first + pow(Z.first,2)*X.first - pow(Z.first,2)*Y.first + pow(Z.second,2)*X.first - pow(Z.second,2)*Y.first );

  return e;
}



double	functionToCalculateF(pair<double, double>X, pair<double, double>Y, pair<double, double>Z){
  double F =( pow(X.first,2)*Y.first*Z.second - pow(X.first,2)*Z.first*Y.second
           + pow(X.second,2)*Y.first*Z.second - pow(X.second,2)*Z.first*Y.second
           - pow(Y.first,2)*X.first*Z.second + pow(Y.first,2)*Z.first*X.second
           - pow(Y.second,2)*X.first*Z.second + pow(Y.second,2)*Z.first*X.second
           + pow(Z.first,2)*X.first*Y.second - pow(Z.first,2)*Y.first*X.second
           + pow(Z.second,2)*X.first*Y.second - pow(Z.second,2)*Y.first*X.second );

  return F;
}



pair<double, double> functionToCalculateCircleCenter(double a, double e, double d){
  
  double Xc = (d/(2*a));
  double Yc = (-e/(2*a));
  pair<double,double>center;
  center.first=Xc;
  center.second=Yc;
  return center;
}



double functionToCalculateRadius(double a, double  e, double d, double f) {
    double Rc = sqrt( ( (pow(d,2) + pow(e,2) ) / (4*pow(a,2))) + (f/a) ) ;
    return Rc;

}


bool fuctionToCheckCircle(pair<double, double>center, double radius, vector<pair<double, double>> array) {

    for (int i = 0; i < array.size(); i++) {
        pair<double, double> currPoint = array[i];
        double X = currPoint.first - center.first;
        double Y = currPoint.second - center.second;

        
        
        if (pow(X, 2) + pow(Y, 2) <= pow(radius, 2)) continue;

        else return false;

    }// for loop
    return true;

}// function


void FunctionToCheckSmallCircle(vector<pair<double, double>> data) {
    pair<double, double>X;
    pair<double, double>Y;
    pair<double, double>Z;
    pair<double, double> center;
    pair<double, double>minCenter;
    double radius;
    bool status;
    double tempRadius = INT_MAX;

    for (int i = 0; i < data.size(); i++) {

        for (int j = i+1; j < data.size(); j++) {

          for(int k = j+1; k < data.size(); k++) {

            X = data[i];

            Y = data[j];

            Z = data[k];


            double a = functionToCalculateA(X, Y, Z);

		        double d = functionToCalculateD(X, Y, Z);

		        double e = functionToCalculateE(X, Y, Z);

		        double f = functionToCalculateF(X, Y, Z);

		        center = functionToCalculateCircleCenter(a, e, d);

	          radius = functionToCalculateRadius(a,e,d,f);

            status = fuctionToCheckCircle(center, radius, data);


            if (status == true)
            {
                if (radius < tempRadius)
                {
                    tempRadius = radius;
                    minCenter = center;
                }
            }
            else
            {
                continue;
            }

        }
      }
    }

     cout << "Smallest circle center (" << minCenter.first << ", " << minCenter.second << ")" <<
        "\nRedius is = " << tempRadius << "\nSurface = " << (2 * 3.2426 * tempRadius) << endl;

}