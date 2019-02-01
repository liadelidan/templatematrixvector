#include <eigen3/Eigen/Dense>
#include "Matrix.hpp"
#include <string>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <chrono>

/**
 * Class TimeChecker cpp file.
 * Created by Liad Elidan, 203380050, user:sharon1832
 */

std::stack<std::chrono::time_point<std::chrono::system_clock>> tictoc_stack;

/**
 * Function tic function as provided from the course.
 */
void tic()
{
    tictoc_stack.push(std::chrono::system_clock::now());
}

/**
 * Function toc function as provided from the course.
 */
void toc()
{
    std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - tictoc_stack.top();
    std::cout << elapsed_seconds.count();
    tictoc_stack.pop();
}

/**
 * Main function of the class TimeChecker.
 * @param argc, amount of argument received.
 * @param argv, arguments receieved.
 * @return 0 if everything is fine.
 */
int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        std::cerr << "error in input" << std::endl;
    }
    int n = std::stoi(argv[1]);
    std::cout << "size " << n << std::endl;
    //eigen matrixes
    Eigen::MatrixXd m1 = Eigen::MatrixXd::Random(n, n);
    Eigen::MatrixXd m2 = Eigen::MatrixXd::Random(n, n);

    //my matrix
    std::vector<int> myVector(n*n, 1);
    Matrix<int> myMatrix(n, n, myVector);

    //calculating time of eigen matrixes
    std::cout << "eigen mult ";
    Eigen::MatrixXd resultMatrix;
    tic();
    resultMatrix = m1 * m2;
    toc();
    std::cout << std::endl;

    std::cout << "eigen add ";
    tic();
    resultMatrix = m1 + m2;
    toc();
    std::cout << std::endl;

    //calculating time of my implementation of matrix
    Matrix<int> myResultMatrix(n, n);

    std::cout << "matlib mult ";
    tic();
    try
    {
        myResultMatrix = myMatrix * myMatrix;
    }
    catch (const std::length_error &exp)
    {
        std::cerr << exp.what() << std::endl;
    }
    toc();
    std::cout << std::endl;
    std::cout << "matlib add ";
    tic();

    try
    {
        myResultMatrix = myMatrix + myMatrix;
    }
    catch ( const std::length_error &exp)
    {
        std::cerr << exp.what() << std::endl;
    }
    toc();
    std::cout << std::endl;
}
