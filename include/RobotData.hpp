//
//  RobotData.hpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#ifndef RobotData_hpp
#define RobotData_hpp

#include <stdio.h>
#include <vector>

class RobotData 
{
    int  m_accumulator;
    int  m_size;
    std::vector<int> m_fitnessScoreVector;
    
public:
    RobotData() { m_accumulator = 0; m_size = 0; }

    void setFitnessScore();
    void resetAccumulator();
    void setAccumulator(int);
    [[nodiscard]] int getRobotFitness(int) const;
    void outputData();
};

#endif /* RobotData_hpp */
