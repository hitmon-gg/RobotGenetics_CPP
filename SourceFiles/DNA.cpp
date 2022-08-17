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
    
    // Randomize proteins N S E W
    for (int i{0}; i < (c_numOfProteins - 1); i++){
        NumGen numObjA(0, 3);
        m_proteins[i] = numObjA.getRandNum();
    }
    
    // Randomize protein Move
    NumGen numObjB(0, 4);
    m_proteins[4] = numObjB.getRandNum();
}
