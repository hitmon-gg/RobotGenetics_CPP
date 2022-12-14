//
//  DNA.cpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#include "../include/DNA.hpp"
#include "../include/NumGen.hpp"

/**
 *  Function: DNA()
 *  Parameters: none
 *  Notes: DNA no arg constructor, randomly generates the proteins
 *         used in each robots genes.
 */
DNA::DNA()
{
    
    // Randomize proteins 0 - 3: empty wall battery random (for robot sensor)
    for (int i{0}; i < (c_numOfProteins - 1); i++) 
    {
        NumGen numObjA(0, 3);
        m_proteins[i] = numObjA.getRandNum();
    }
    
    // Randomize protein Move 0 - 4: N S E W Random
    NumGen numObjB(0, 4);
    m_proteins[4] = numObjB.getRandNum();
}
