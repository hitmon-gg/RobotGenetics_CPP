//
//  NumGen.cpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#include <cctype>
#include <random>
#include "../include/NumGen.hpp"

std::random_device rd;
std::mt19937 gen(rd());

NumGen::NumGen(int min, int max) 
{
    std::uniform_int_distribution<int> dist(min, max);
    m_num = dist(gen);
}

int NumGen::getRandNum() const { return m_num; }
