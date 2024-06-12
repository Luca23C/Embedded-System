/*
 * File:   scheduler.c
 * Author: enric
 *
 * Created on 12 giugno 2024, 12.05
 */


#include "xc.h"
#include "scheduler.h"

void scheduler(heartbeat schedInfo[], int nTasks) 
{
    int i;
    for (i = 0; i < nTasks; i++) {
        schedInfo[i].n++;
        if (schedInfo[i].enable == 1) {
            if( schedInfo[i].n >= schedInfo[i].N){ // periodic task 
                schedInfo[i].f(schedInfo[i].params);            
                schedInfo[i].n = 0;
            }
            if(schedInfo[i].N == -1){              // a periodic task
                schedInfo[i].f(schedInfo[i].params);            
                schedInfo[i].n = 0;
            }
        }
        
        
    }
}