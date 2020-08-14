# Analysis
## INPUT

We initialize the same input in an array proc[] by using the structure name Course for the three algorithms which is given as the following:

struct Course

{

   int ccode;     // course code
   
   int duration;      // class duration
   
   int priority;  //priority
   
   int arrival_time;   //prefered arrival time
   
};

Course proc[] = {{ccode, duration, priority, arrival_time},...};

Course proc[] = {{2201,3,2,0}, {3401, 5, 6,2}, {1103,4,3,1}, {2302,2,5,4},{2602,9,7,6},{3102,4,4,5},{2011,10,10,7}};

| Course Code | Burst Time  | Priority | Arrival Time |
|-------------|-------------|----------|--------------|
| 2201        | 3           | 2        | 0            |
| 3401        | 5           | 6        | 2            |
| 1103        | 4           | 3        | 1            |
| 2302        | 2           | 5        | 4            |
| 2602        | 9           | 7        | 6            |
| 3102        | 4           | 4        | 5            |
| 2011        | 10          | 10       | 7            |
          Table 1 Initialized input of the algorithms
          
## OUTPUT

The outputs that we get from FCFS, Priority and SJF scheduling algorithms are the order of scheduling of the course, the attributes of each course code, the average waiting time and the average turnaround time which are given as the following:

1. FCFS

Order of the course code ---> 2201, 1103, 3401, 2302, 3102, 2602, 2011
| Course Code | Burst Time  | Arrival Time | Waiting Time | Turnaround Time | Completion Time |
|-------------|-------------|--------------|--------------|-----------------|-----------------|
| 2201        | 3           | 0            | 0            | 3               | 3               |
| 1103        | 4           | 1            | 2            | 6               | 7               |
| 3401        | 5           | 2            | 5            | 10              | 12              |
| 2302        | 2           | 4            | 8            | 10              | 14              |
| 3102        | 4           | 5            | 9            | 13              | 18              |
| 2602        | 9           | 6            | 12           | 21              | 27              |
| 2011        | 10          | 7            | 20           | 30              | 37              |
                                  Table 2 The output of FCFS

Average waiting time = 8

Average turnaround time = 13.2857

2. Priority(non-preemptive)

Order of the course code ---> 2201, 1103, 3102, 2302, 3401, 2602, 2011
| Course Code | Burst Time  | Priority | Arrival Time | Waiting Time | Turnaround Time | Completion Time |
|-------------|-------------|----------|--------------|--------------|-----------------|-----------------|
| 2201        | 3           | 2        | 0            | 0            | 3               | 3               |
| 1103        | 4           | 3        | 1            | 2            | 6               | 7               |
| 3102        | 4           | 4        | 5            | 2            | 6               | 11              |
| 2302        | 2           | 5        | 4            | 7            | 9               | 13              |
| 3401        | 5           | 6        | 2            | 11           | 16              | 18              |
| 2602        | 9           | 7        | 6            | 12           | 21              | 27              |
| 2011        | 10          | 10       | 7            | 20           | 30              | 37              |
                      Table 3 The output of Priority(non-preemptive) scheduling
                        
Average waiting time = 7.71429

Average turnaround time = 13

3. SJF

Order of the course code ---> 2201, 2302, 1103, 3102, 3401, 2602, 2011
| Course Code | Burst Time  | Priority | Arrival Time | Waiting Time | Turnaround Time | Completion Time |
|-------------|-------------|----------|--------------|--------------|-----------------|-----------------|
| 2201        | 3           | 2        | 0            | 0            | 3               | 3               |
| 2302        | 2           | 5        | 4            | 0            | 2               | 6               |
| 1103        | 4           | 3        | 1            | 4            | 8               | 9               |
| 3102        | 4           | 4        | 5            | 4            | 8               | 13              |
| 3401        | 5           | 6        | 2            | 11           | 16              | 18              |
| 2602        | 9           | 7        | 6            | 12           | 21              | 27              |
| 2011        | 10          | 10       | 7            | 20           | 30              | 37              |
                                Table 3 The output of SJF scheduling
                                
Average waiting time = 7.28571 

Average turnaround time = 12.5714


               








          
