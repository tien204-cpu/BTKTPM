#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0 && b == 0 && c == 0) return -1;
    if (a == 0 && b == 0) return 0;
    if (a == 0) {
        double y = -c / b;
        if (y < 0) return 0;
        x[0] = sqrt(y);
        x[1] = -sqrt(y);
        return 2;
    }
    double delta = b*b - 4*a*c;
    if (delta < 0) return 0;
    double y1 = (-b + sqrt(delta)) / (2*a);
    double y2 = (-b - sqrt(delta)) / (2*a);
    int count = 0;
    if (y1 >= 0) {
        x[count++] = sqrt(y1);
        x[count++] = -sqrt(y1);
    }
    if (y2 >= 0 && y2 != y1) {
        x[count++] = sqrt(y2);
        x[count++] = -sqrt(y2);
    }
    return count;
}

// Hàm test
void runTest(double a, double b, double c, const string& expected) {
    double x[4];
    int n = solveQuartic(a, b, c, x);
    ostringstream out;
    if (n == -1) {
        out << "Infinite solutions.";
    } else if (n == 0) {
        out << "No solution.";
    } else {
        out << "The equation has " << n << " real solution(s): ";
        for (int i = 0; i < n; i++) out << x[i] << " ";
    }
    string result = out.str();

    cout << "Input: " << a << " " << b << " " << c << "\n";
    cout << "Expected: " << expected << "\n";
    cout << "Got:      " << result << "\n";
    cout << (result.find(expected) != string::npos ? "✅ PASSED" : "❌ FAILED") << "\n\n";
}

int main() {
    runTest(0,0,0,"Infinite solutions.");
    runTest(0,0,5,"No solution.");
    runTest(0,2,-8,"The equation has 2 real solution(s):");
    runTest(1,0,-4,"The equation has 2 real solution(s):");
    runTest(1,-5,4,"The equation has 4 real solution(s):");
    runTest(1,2,10,"No solution.");
    runTest(1,-2,1,"The equation has 2 real solution(s):");
    runTest(-1,-5,-6,"No solution.");
}
