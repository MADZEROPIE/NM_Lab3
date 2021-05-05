#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

#include <vector>
#include <random>

double ftest_1(double x) {
    return (1 + 2 * x) / (4 * x);
}

double ftest_2(double x) {
    return (1 + 2 * x) / (4 * x) + cos(10*x);
}

double ftest_3(double x) {
    return (1 + 2 * x) / (4 * x) + cos(100*x);
}

double ans_1() {
    return 0.25 * log(2) + 0.5;  // 0.6732867951399863
}

double ans_2() {
    return 0.25 * log(2) + 0.5 + (sin(20) - sin(10)) / 10;  // 0.8189834313016861
}

double ans_3() {
    return 0.25 * log(2) + 0.5 + (sin(200) - sin(100)) / 100;  // 0.669617478578944
}


class G_Func {
private:
    HillFunc hill;
    NumIntegration<HillFunc> I;
public:
    
    double operator()(double x) {
        hill.x = x;
        return I.adaptiveIntegral(0.1);
    }
};

class HillFunc {
private:
    std::vector<double> A, B;
    double alp;
    int num_coeffs = 14;
    double x;
public:
    friend class G_Func;

public:
    HillFunc(uint64_t seed = 0) {
        A.resize(num_coeffs); B.resize(num_coeffs);
        std::uniform_real_distribution<double> distr1(-1, 1);
        std::uniform_real_distribution<double> distr2(0, 1);
        std::mt19937 gen(seed);
        for (int i = 0; i < num_coeffs; ++i) {
            A[i] = distr1(gen);
            B[i] = distr1(gen);
        }
        alp = distr2(gen);
    }
    HillFunc(const std::vector<double>& _A, const std::vector<double>& _B,
        double _alp) : A(_A), B(_B) {
        alp = _alp;
    }

    double operator() (double t){
        double res = 0.0;
        for (int i = 0; i < num_coeffs; ++i) {
            res += A[i] * sin(2 * M_PI * (i + 1) * (alp - x) * t) + B[i] * cos(2 * M_PI * (i + 1) * (alp - x) * t);
        }
        return res;
    }

    std::pair<std::vector<double>, std::vector<double> > getCoeffs() {
        return std::make_pair(A, B);
    }

    double getAlpha() {
        return alp;
    }
};


template <class F>
class NumIntegration {
 private:
    F func;
    double a = 1.0, b = 2.0;
    double result = 0.0;
    int64_t adap_count = 0;

 public:
     enum class IntegeralType {midp, trap, simp};

    NumIntegration(const F& _func, double _a, double _b) : func(_func) {
        a = _a; b = _b;
    }

    double midpointIntegral(int steps = 1) {
        result = 0;
        const double h = (b - a) / steps;
        for (int i = 0; i < steps; ++i) {
            double x = a + i * h;
            result += func(x + h / 2);
        }
        result *= h;
        return result;
    }

    double trapezoidalIntegral(int steps = 1) {
        result = 0;
        const double h = (b - a) / steps;
        for (int i = 0; i < steps; ++i) {
            double x = a + i * h;
            result += (func(x) + func(x+h))/2;
        }
        result *= h;
        return result;
    }

    double simpsonIntegral(int steps = 1) {
        result = 0;
        const double h = (b - a) /(2 * steps);
        for (int i = 0; i < steps; ++i) {
            double x = a + 2 * i * h;
            result += (func(x) + 4 * func(x + h) + func(x + 2*h)) / 3;
        }
        result *= h;
        return result;
    }

    double adaptiveIntegral(double eps, IntegeralType type = IntegeralType::simp) {
        if (type == IntegeralType::midp) {
            double i1 = midpointIntegral(1);
            double i2 = midpointIntegral(2);
            if (fabs(i2 - i1) > eps) {
                return adaptiveIntegral(eps / 2);
            }
            else return i1;  // Or i2 ???
        }
        if (type == IntegeralType::trap) {
            double i1 = trapezoidalIntegral(1);
            double i2 = trapezoidalIntegral(2);
            if (fabs(i2 - i1) > eps) {
                return adaptiveIntegral(eps / 2);
            }
            else return i1;  // Or i2 ???
        }
        if (type == IntegeralType::simp) {
            double i1 = simpsonIntegral(1);
            double i2 = simpsonIntegral(2);
            if (fabs(i2 - i1) > eps) {
                return adaptiveIntegral(eps / 2);
            }
            else return i1;  // Or i2 ???
        }
    }
};