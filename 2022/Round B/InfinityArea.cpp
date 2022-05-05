// GoogleTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

struct DataSet
{
    double R; // Radii of the first circle
    double A; // A & B are parameters used to calculate the radii of the subsequent circles.
    double B;
};

double CalArea(DataSet &val)
{
    long double ans = 0;
    constexpr long double pi = 3.14159265358979323846;

    ans += val.R * val.R;

    while (val.R > 0)
    {
        ans += (val.R * val.A) * (val.R * val.A);
        ans += floor(val.R * val.A / val.B) * floor((val.R * val.A) / val.B);
        val.R = floor(val.R * val.A / val.B);
    }

    return ans * pi;
}

int main()
{
    // Input number of tests;
    int numberTest = 0;
    DataSet insertTemp;

    std::vector<DataSet> temp;
    std::vector<long double> totalArea;

    std::cin >> numberTest;

    for (int ndx = 0; ndx < numberTest; ++ndx)
    {
        std::cin >> insertTemp.R >> insertTemp.A >> insertTemp.B;

        temp.push_back(insertTemp);
    }

    // Process values.

    for (DataSet &portion : temp)
    {

        totalArea.push_back(CalArea(portion));
    }

    int ndx = 1;

    for (const long double &tp : totalArea)
    {

        std::cout << std::fixed << "Case #" << ndx++ << ": " << std::setprecision(6) << tp << std::endl;
    }

    return 0;
}