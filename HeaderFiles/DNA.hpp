//
//  DNA.hpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#ifndef DNA_hpp
#define DNA_hpp

#include <stdio.h>
#include "GlobalDefs.h"

struct DNA{
    // Element 0 N, 1 S, 2 E, 3 W, 4 Move
    // int 0 empty, 1 wall, 2 battery, 3 don't care
    int m_proteins[c_numOfProteins];
    
    DNA();
};

#endif /* DNA_hpp */
