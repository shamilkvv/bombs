#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <tuple>

class Bomb {
public:
    int x, y, r;

    Bomb() : x(0), y(0), r(0) {}
    Bomb(int x, int y, int r) : x(x), y(y), r(r) {}
};
