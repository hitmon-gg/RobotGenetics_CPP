//
//  DNA.cpp
//  CISP400 FInal
//
//  Created by Admin on 6/23/22.
//  Copyright © 2022 Admin. All rights reserved.
//

#include "DNA.hpp"
#include "NumGen.hpp"

DNA::DNA(){
    NumGen numObj;
    
    // Randomize proteins N S E W
    for (int i{0}; i < (c_numOfProteins - 1); i++){
        numObj.setRandNum(0, 3);
        m_proteins[i] = numObj.getRandNum();
    }
    
    // Randomize protein Move
    numObj.setRandNum(0, 4);
    m_proteins[4] = numObj.getRandNum();
}
