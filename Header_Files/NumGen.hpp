//
//  NumGen.hpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#ifndef NumGen_hpp
#define NumGen_hpp

#include <stdio.h>

class NumGen {
    unsigned int m_num;
    
public:
    NumGen(int, int);
    int  getRandNum() const;
};

#endif /* NumGen_hpp */
