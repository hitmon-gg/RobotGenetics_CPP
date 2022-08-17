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

class RobotData{
    int  m_accumulator;
    std::vector<int> m_fitnessScore;
    int  m_size;
    
public:
    void setFitnessScore();
    void resetAccumulator();
    void setAccumulator(int);
    int  getRobotFitness(int) const;
    void outputData() const;
};

#endif /* RobotData_hpp */
