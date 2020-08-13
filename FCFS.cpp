/*
 MAISARAH BINTI HAMZAH  1810325
NUR MAISARA BINTI AHMAD RASID  1818356
NOR NABILAH SHUHADA BINTI MOHD KAMAL  1817510
SITI NUR AISHAH BINTI SULAIMAN  1816454
CSC3401 Operating System Section 5
*/
// C++ program for implementation of FCFS 
#include <bits/stdc++.h>
#include<iostream> 
using namespace std; 

using namespace std;
 
struct Process
{
   int ccode;     // course code
   int duration;      // class duration
   int priority;  //priority
   int arrival_time;   //prefered arrival time
};  

bool comp(Process a, Process b) 
{ 
    return (a.arrival_time < b.arrival_time); 
} 
// Function to find the waiting time for all 
// processes 
void findWaitingTime(Process proc[], int n, int wt[]) 
{ 
    int service_time[n]; 
    service_time[0] = 0; 
    wt[0] = 0; 
  
    // calculating waiting time 
    for (int i = 1; i < n ; i++) 
    { 
        // Add burst time of previous processes 
        service_time[i] = service_time[i-1] + proc[i-1].duration; 
  
        // Find waiting time for current process 
        wt[i] = service_time[i] - proc[i].arrival_time; 
  
        // If waiting time for a process is in negative 
        // that means it is already in the ready queue 
        // before CPU becomes idle so its waiting time is 0 
        if (wt[i] < 0) 
            wt[i] = 0; 
    } 
} 
  
// Function to calculate turn around time 
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[]) 
{ 
    // Calculating turnaround time 
    for (int i = 0; i < n ; i++) 
        tat[i] = proc[i].duration + wt[i]; 
} 
  
// Function to calculate average waiting and turn-around times. 
void findavgTime(Process proc[], int n) 
{ 
	cout << "FCFS scheduling algorithm" << endl;
	sort(proc, proc + n, comp);
	cout<< "\nOrder of the course code: \n"; 
    for (int  i = 0 ; i <  n; i++) 
        cout << proc[i].ccode <<" " ; 
        
    int wt[n], tat[n]; 
  
    // Function to find waiting time of all processes 
    findWaitingTime(proc, n, wt); 
  
    // Function to find turn around time for all processes 
    findTurnAroundTime(proc, n, wt, tat); 
  
    // Display processes along with all details 
    cout << "\n\nCourse Code " << " Burst Time " << " Arrival Time "
         << " Waiting Time " << " Turn-Around Time "
         << " Completion Time \n"; 
    int total_wt = 0, total_tat = 0; 
    for (int i = 0 ; i < n ; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        int compl_time = tat[i] + proc[i].arrival_time; 
        cout << " " << proc[i].ccode << "\t\t" << proc[i].duration << "\t\t"
             << proc[i].arrival_time << "\t\t" << wt[i] << "\t\t "
             << tat[i]  <<  "\t\t " << compl_time << endl; 
    } 
  
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
} 
  
// Driver code 
int main() 
{ 
     
	Process proc[] = {{2201,3,2,0}, {3401, 5, 6,2}, {1103,4,3,1},
					{2302,2,5,4},{2602,9,7,6},{3102,4,4,5},{2011,10,10,7}};
    int n = sizeof proc / sizeof proc[0]; 
    
	findavgTime(proc, n); 
	  
    
    return 0; 
} 
