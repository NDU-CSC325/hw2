#pragma once
#include <utility>
#include <vector>
#include <queue>

/***********************************************************/
/**************** PROBLEM 1 ********************************/
/***********************************************************/

/**
 *  stops()->std::vector<int>
 * 
 * @param stations: location of available stations
 * @param distanceToB
 * @param distanceOnFull
 * @return locations of minimum set of stations the traveler stops on
 */
std::vector<int> stops(std::vector<int>& stations,int distanceToB,int distanceOnFull){
    std::vector<int> v;
    int d = 0;
            for (int i = 0; i < stations.size() - 1; i++){
                if ((stations[i + 1]-d) > distanceOnFull)){
                    v.push_back(stations[i]);
                    d = stations[i];
                }
            }
            if (distanceToB - d > distanceOnFull) v.push_back(stations[stations.size() - 1]);
            return v;
}   


/***********************************************************/
/**************** PROBLEM 2 ********************************/
/***********************************************************/

/**
 * Time needed to perform a job
 * of the form (preprocessing time, run time)
 */
#ifndef JOB
using Job = std::pair<int, int>;
#define JOB
#endif 


/**
 *  finish()->int
 * 
 * @param jobs: list of jobs
 * @return minimum time needed to perform all jobs
 */
int finish(std::vector<Job>& jobs) {
    int fin = -1;
    int a = 0'
     for (int i = 0; i < jobs.size();i++){
         a += jobs[i].first;
         int temp = a + jobs[i].second;
         if (temp > fin)
         fin = temp;
     }

    return fin;
}
/**
 *  schedule()->std::vector<Job>
 * 
 * @param jobs
 * @return order to preprocess all jobs to obtain minimum total time
 */
std::vector<Job> schedule(std::vector<Job>& jobs) {
    std::vector<Job> v(jobs);
    sort(v.begin(), v.end(), [](std::pair<int,int>&l, std::pair<int, int> & r) {
        return (l.second > r.second);
    });
     
    return v;
}

/***********************************************************/
/**************** PROBLEM 3 ********************************/
/***********************************************************/


/**
 * value of stock at time t
 * of the form (time,value)
 */
#ifndef STOCK
#define STOCK
using Stock = std::pair<int, int>;
#endif 
/**
 *  stock()->std::vector<Stock>
 * 
 * @param values list of stock values at different times
 * @param budget initial money the buyer has
 * @return list of stocks bought in the form (number of shares,price per share)
 */
bool cmp(const std::pair<int, int>& a, const std::pair<int,int>& b){
    return a.second < b.second;
}
std::vector<Stock> stock(std::vector<Stock>& values, int budget) {
    int count = 0;
    std::vector<Stock> result;
    sort(values.begin(), values.end(),cmp);
    for (int i = 0; i < values.size() and budget > 0; i++){
        int cur_count = std::min(budget / values[i].second, values[i].first);
        if (cur_count == 0)
        break;
        result.push_back(std::make_pair(cur_count, values[i].second));
        budget = budget - cur_count * values[i].second;
    }
    return result;
}
