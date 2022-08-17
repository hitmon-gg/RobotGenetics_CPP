//
//  NumGen.hpp
//  CISP400 FInal
//
//  Created by Admin on 6/23/22.
//  Copyright © 2022 Admin. All rights reserved.
//

#ifndef NumGen_hpp
#define NumGen_hpp

#include <stdio.h>

class NumGen{
    unsigned int m_num;
    
public:
    NumGen(int, int);
    int  getRandNum() const;
};

#endif /* NumGen_hpp */
