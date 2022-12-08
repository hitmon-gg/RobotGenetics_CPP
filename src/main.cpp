//
//  main.cpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#include <iostream>
#include <memory>

#include "RobotData.hpp"
#include "Robot.hpp"
#include "NumGen.hpp"
#include "Map.hpp"
#include "GlobalDefs.h"
#include "MergeSort.hpp"

void robotTesting(Robot[], RobotData&);
void cullAndCreate(Robot[]);
void resetRobots(Robot[]);

int main() 
{
    // Initialize and create array of Robots
    Robot robotArray[c_maxRobots];
    
    // Holds and processes robot fitness score data
    RobotData dataObj;
    
    // Perform Simulation
    std::cout << "Start Simulation.\n";
    std::cout << "Robots: " << c_maxRobots << '\n';
    std::cout << "Simulations: " << c_maxSimulations << '\n';

    // Simulation loop
    for (int i{0}; i < c_maxSimulations; i++) 
    {
        // Test Robots by running each one through a random maze
        robotTesting(robotArray, dataObj);
        
        // Segment off worst performing robots and combine best
        // performing robots to pass genes to lower half robot population
        cullAndCreate(robotArray);
        
        // Reset parent robots turns and battery states
        resetRobots(robotArray);
    }
    
    std::cout << "\nSimulation Complete!\n";
    
    // Store and output results
    dataObj.outputData();

    std::cout << "Press any key to exit.\n";
    std::cin.get();
    
    return 0;
}

/**
 *  Function: robotTesting
 *  Parameters: robotArray (type Robot), dataObj (type RobotData)
 *  Notes: Takes all robot objects created in robotArray and
 *         places each one in a randomly generated 10 x 10 'map'.
 *         The m_turns member variable in robot records the amount
 *         of turns it takes each robot before it runs out of battery
 *         while traversing the map.
 *
 *         Once the battery is drained to 0, the turns value is passed
 *         to the accumulator of dataObj, which records each robot's
 *         turn value and calculates an average turn for each generation
 *         of robots.
 */
void robotTesting(Robot robotArray[], RobotData& dataObj) 
{
    dataObj.resetAccumulator();
    
    // create a new map and use it to test robot, loop c_maxSimulation
    // times for c_maxRobots robots
    for (int i{0}; i < c_maxRobots; i++) 
    {
        Map mapObj;
        
        do
        {
            robotArray[i].move(mapObj);
            
        } while (robotArray[i].getBattery() > 0);
        
        dataObj.setAccumulator(robotArray[i].getTurns() - 5);
    }
    
    // Add fitness Score to robot data object
    dataObj.setFitnessScore();
}

/**
 *  Name: cullAndCreate
 *  Parameters: robotArray (type Robot)
 *  Notes: msort is called on robot array and sorts it in ascending
 *         order based on each robot's turn variable. This places
 *         the worst performing robots at the bottom of the array,
 *         where the lowest 50% of robots are then 'culled' from the
 *         group (sorry, evolution is harsh!) by having their objects
 *         overwritten in memory.
 *
 *         The top performing 50% of robots are 'bred' with eachother
 *         in pairs in descending order from the highest element in the
 *         array. The genes from the two robots are combined into two new
 *         robot objects (child1 and child2) and are inserted into the bottom
 *         half of the array, where this new generation of robots will then take
 *         part in the testing.
 */
void cullAndCreate(Robot robotArray[]) 
{
    Robot tmp[c_maxRobots]; // Temp array for sorting algorithm

    // Merge Sort Array based on turns taken to compelete test
    msort(0, (c_maxRobots - 1), robotArray, tmp);
    
    // Cull and create new robots in bottom half of array
    for (int i{0}; i < c_halfMaxRobots; i += 2) 
    {
        if (i == 0) 
        {
            Robot child1(robotArray[c_maxRobots - 1],
                            robotArray[c_maxRobots - 2], i);
            
            Robot child2(robotArray[c_maxRobots - 1],
                            robotArray[c_maxRobots - 2], (i + 1));
            
            robotArray[0] = child1;
            robotArray[1] = child2;

        } else  {
            
            Robot child1(robotArray[c_maxRobots - (i + 1)],
                            robotArray[c_maxRobots - (i + 2)], i);
            
            Robot child2(robotArray[c_maxRobots - (i + 1)],
                            robotArray[c_maxRobots - (i + 2)], (i + 1));
            
            robotArray[i]     = child1;
            robotArray[i + 1] = child2;
        }
    }
}

/**
 *  Name: resetRobots
 *  Parameters: robotArray (type Robot)
 *  Notes: Takes each robot obj in robotArray and re-initializes their
 *         battery value to '5', turns value to '0' and generates a new
 *         random starting position on the map with getRandNum().
 */
void resetRobots(Robot robotArray[]) 
{

    for (int i{c_halfMaxRobots - 1}; i < c_maxRobots; i++)
    {
        NumGen numObj(0, 99);
        
        robotArray[i].resetBattery();
        robotArray[i].resetTurns();
        robotArray[i].setPosition(numObj.getRandNum());
    }
}
