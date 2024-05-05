#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

double f(double x) {
    return cos(x) - pow(x - 1, 2);
}

double dixit(double (*f)(double x),double a, double b, double eps) {
    auto start = high_resolution_clock::now();

    double c;
    int count = 0;
    do{
        c = (a + b) / 2.0;
        if (f(a) * f(c) < 0) b = c;
        else if(f(b) * f(c) < 0) a = c;
        else{   
            cout << "The root is not found" << endl;
            return 0;
        }
        count++;
    } while (fabs(b-a) > eps);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "N = " << count << "\tExecution time: " << duration.count() << " microseconds\t";

    return c;
}

double f_(double (*f)(double x),double x) {
    double dx = 1e-4;
    return (f(x + dx) - f(x-dx)) / (2*dx);
}

double f__(double (*f)(double x), double x) {
    double dx = 1e-4;
    return (f_(f,x+dx)-f_(f,x-dx)) / (2*dx);
}

double f_max(double (*f)(double x), double a, double b) {
    double max, dx, tmp;
    dx = 0.1;

    max = fabs(f_(f, a));

    for (int i = 1; a+i*dx <= b; ++i) {
        tmp = fabs(f_(f, a + i*dx));
        if (tmp > max) max = tmp;
    }
    return max;
}

double f_min(double (*f)(double x), double a,double b) {
    double min, dx,tmp;
    dx = 0.1;

    min = fabs(f_(f,a));
    for (int i=1; a+i*dx <= b; ++i) {
        tmp = fabs(f_(f, a + i*dx));
        if (tmp < min) min = tmp;
    }

    return min;
}

double chord(double (*f)(double x), double a, double b, double eps) {
    auto start = high_resolution_clock::now();

    double x_new, x_last, pin, m, M;
    int count = 0;

    if (f(a)*f__(f,a) > 0) {
        x_last = b;
        pin = a;
    }
    else if(f(b)*f__(f,b)>0) {
        x_last = a;
        pin = b;
    }

    else if (f(a)*f__(f, a) < 0) {
        x_last = a;
        pin = b;
    }
    else if (f(b) * f__(f, b) < 0) {
        x_last = b;
        pin = a;
    }
    else {
        cout << "Error";
        return 0;
    }
    m = f_min(f, a, b);
    M = f_max(f, a, b);
    while (true) {
        x_new = x_last - (pin - x_last)*(f(x_last)) / (f(pin)-f(x_last));
        count++;
        if (fabs(x_new - x_last) < eps*m/(M-m)) break;
        x_last = x_new;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "N = " << count << "\tExecution time: " << duration.count() << " microseconds\t";

    return x_new;
}

double newton(double (*f)(double x), double a, double b, double eps) {
    auto start = high_resolution_clock::now();
    
    double x1,x2,x3,q;
    int count = 0;

    if (f(a) * f__(f, a) > 0) x1 = a;
    else x1 = b;
    while (true) {
        if (count == 0) {
            x2 = x1 - f(x1) / f_(f, x1);
            x3 = x2 - f(x2) / f_(f, x2);
        }
        q = (x3 - x2) / (x2 - x1);
        if ((x3-x2)*q/(1-q)<eps) break;
        x1 = x2;
        x2 = x1 - f(x1) / f_(f, x1);
        x2 = x3;
        x3 = x2 - f(x2) / f_(f, x2);
        count++;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "N = " << count << "\tExecution time: " << duration.count() << " microseconds\t";

    return x3;
}

int main()
{
    double a = 1.0;
    double b = 2.0;
    double eps = 0.0001;

    cout << "Root by ditix = " << dixit(f, a, b, eps) << endl;
    cout << "Root by chord = " << chord(f, a, b, eps) << endl;
    cout << "Root by newton = " << newton(f, a, b, eps) << endl;
}