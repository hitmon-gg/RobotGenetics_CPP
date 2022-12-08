//
//  MergeSort.cpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#include "MergeSort.hpp"
#include "Robot.hpp"

/**
 *  Functions: msort, merge
 *  Parameters: f => first
                m => middle
 *              l => last
 *              robotArray => array holding all robot objs, from main.
 *              tmp => temporary array used in sorting
 *  Notes: Classic merge sort array utilizing recursion. Sorts robots based
 *         on their turn member variable in ascending order.
 */
void msort(int f, int l, Robot robotArray[], Robot tmp[]) 
{
    int m;
    
    if (f < l) 
    {
        m = (f + l) / 2;
        msort(f, m, robotArray, tmp);
        msort(m + 1, l, robotArray, tmp);
        merge(f, m, l, robotArray, tmp);
    }
}

void merge(int f, int m, int l, Robot robotArray[], Robot tmp[]) 
{
    int t1, t2, t3;
    t1 = f; t2 = m + 1; t3 = f;
    
    while (t1 <= m && t2 <= l) 
    {
        if (robotArray[t1].getTurns() < robotArray[t2].getTurns())
        {
            tmp[t3++] = robotArray[t1++];

        } else {

            tmp[t3++] = robotArray[t2++];
        }
    }
    
    while (t1 <= m) 
    {
        tmp[t3++] = robotArray[t1++];
    }

    while (t2 <= l)
    {
        tmp[t3++] = robotArray[t2++];
    }

    for (t1 = f; t1 <= l; t1++)
    {
        robotArray[t1] = tmp[t1];
    }
}

