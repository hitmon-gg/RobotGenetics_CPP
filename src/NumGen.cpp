//
//  NumGen.cpp
//  CISP400 FInal
//
//  Created by Admin on 6/23/22.
//  Copyright © 2022 Admin. All rights reserved.
//

#include <cstdlib>
#include "NumGen.hpp"

void NumGen::setRandNum(int min, int max) {
    m_num = (std::rand() % (max - min + 1)) + min;
}

int NumGen::getRandNum() const { return m_num; }
