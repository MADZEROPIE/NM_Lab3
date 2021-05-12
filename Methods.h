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

auto f1 = [](double x) { return ftest_1(x); };
auto f2 = [](double x) { return ftest_2(x); };
auto f3 = [](double x) { return ftest_3(x); };

template <class F>
double rectInteg(F func, double a, double b, int steps = 1) {
    double res = 0;
    double h = (b - a) / steps;
    for (int i = 0; i < steps; ++i) {
        res += func(a + i * h + h / 2);
    }
    return res*h;
}

template <class F>
double trapInteg(F func, double a, double b, int steps = 1) {
    double res = 0;
    double h = (b - a) / steps;
    for (int i = 0; i < steps; ++i) {
        res += func(a + i * h) + func(a + (i + 1) * h);
    }
    return res * h / 2;
}

template <class F>
double simpInteg(F func, double a, double b, int steps = 1) {
    double res = 0;
    double h = (b - a) /(steps);
    for (int i = 0; i < steps; ++i) {
        res += func(a + i * h) + 4 * func(a + i * h + h / 2) + func(a + (i + 1) * h);
    }
    return res * h / 6;
}

enum class IntegType{rect,trap,simp};

static int counter = 0;

class THillFunc {
private:
    std::vector<double> A, B;
    double alp;
    int num_coeffs = 14;
    double x;
public:
    friend class G_Func;

public:
    THillFunc(uint64_t seed = 0) {
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
    THillFunc(const std::vector<double>& _A, const std::vector<double>& _B,
        double _alp) : A(_A), B(_B) {
        alp = _alp;
    }

    double operator() (double t) {
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

struct TResults {
    double x;
    double y;
    int T;
};

template <class F>
double adapInteg(const F& func, double a, double b, double eps, IntegType type) {
    double h = (b - a);
    ++counter;
    if (type == IntegType::rect) {
        double i1 = rectInteg(func, a, b, 1);
        double i2 = rectInteg(func, a, b, 2);
        if (fabs(i2 - i1) > eps) {
            return adapInteg(func, a, a + h / 2, eps / 2, type) + adapInteg(func, a + h / 2, b, eps / 2, type);
        }
        return i1;
    }
    if (type == IntegType::trap) {
        double i1 = trapInteg(func, a, b, 1);
        double i2 = trapInteg(func, a, b, 2);
        if (fabs(i2 - i1) > eps) {
            return adapInteg(func, a, a + h / 2, eps / 2, type) + adapInteg(func, a + h / 2, b, eps / 2, type);
        }
        return i1;
    }
    if (type == IntegType::simp) {
        double i1 = simpInteg(func, a, b, 1);
        double i2 = simpInteg(func, a, b, 2);
        if (fabs(i2 - i1) > eps) {
            return adapInteg(func, a, a + h / 2, eps / 2, type) + adapInteg(func, a + h / 2, b, eps / 2, type);
        }
        return i1;
    }
}



class G_Func {
public:
    THillFunc hill;
public:
    G_Func(const THillFunc& h) {
        hill = h;
    }
    TResults operator()(double x, double eps, IntegType type = IntegType::simp) {
        counter = 0;
        hill.x = x;
        TResults res;
        res.x = x;
        res.y = adapInteg(hill, -M_PI_2, M_PI_2, eps, type);
        res.T = counter;
        return res;
    }
};