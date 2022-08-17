//
//  NumGen.cpp
//  CISP400 FInal
//
//  Created by Admin on 6/23/22.
//  Copyright © 2022 Admin. All rights reserved.
//

#include <cctype>
#include <random>
#include "NumGen.hpp"

std::random_device rd;
std::mt19937 gen(rd());

NumGen::NumGen(int min, int max) {

    std::uniform_int_distribution<int> dist(min, max);
    m_num = dist(gen);
}

int NumGen::getRandNum() const { return m_num; }
