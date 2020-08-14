/*
 MAISARAH BINTI HAMZAH  1810325
NUR MAISARA BINTI AHMAD RASID  1818356
NOR NABILAH SHUHADA BINTI MOHD KAMAL  1817510
SITI NUR AISHAH BINTI SULAIMAN  1816454
CSC3401 Operating System Section 5
*/
// C++ implementation for non-preemptive SJF Scheduling 
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct Course
{
   int ccode;     // course code
   int duration;      // class duration
   int priority;  //priority
   int arrival_time;   //prefered arrival time
}; 

// Function to find the waiting time for all 
// processes 
void findWaitingTime(Course proc[], int n, int wt[]) 
{
	int comp[n]; 
    wt[0] = 0;
    comp[0] = proc[0].arrival_time + proc[0].duration;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] = comp[i-1] - proc[i].arrival_time ;
        comp[i] = comp[i-1] + proc[i].duration;
        
        if (wt[i] < 0) 
            wt[i] = 0; 
    } 
} 

// Function to calculate turn around time 
void findTurnAroundTime(Course proc[], int n, int wt[], int tat[]) 
{ 
    // Calculating turnaround time 
    for (int i = 0; i < n ; i++) 
        tat[i] = proc[i].duration + wt[i]; 
} 

bool comparison(Course a, Course b)
{
    return (a.arrival_time < b.arrival_time);
}

void SJF_NP(Course proc[], int n)
{
  cout << "Output for SJF Non-Preemptive scheduling algorithm" << endl;
  
  int i, j, temp ;

  //array instantiations
  int start[n], end[n], wait[n], tat[n];

  //calculations
  for(i = 1; i <= n; i++)
    {
      for(j = i+1; j <= n; j++)
	{
	  if (i >= 2 && proc[i-1].duration > proc[j-1].duration)
	    {
	      temp = proc[i-1].duration;
	      proc[i-1].duration = proc[j-1].duration;
	      proc[j-1].duration = temp;
	      temp = proc[i-1].arrival_time;
	      proc[i-1].arrival_time = proc[j-1].arrival_time;
	      proc[j-1].arrival_time = temp;
	      temp = proc[i-1].ccode;
	      proc[i-1].ccode = proc[j-1].ccode;
	      proc[j-1].ccode = temp;
	    }
	}

    }
    
    cout<< "\nOrder of the course code: \n"; 
	    for (int  i = 0 ; i <  n; i++) 
	        cout << proc[i].ccode <<" " ;
	        
	int wt[n]; 
  
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


int main() 
{ 
    Course proc[] = {{2201,3,2,0}, {3401, 5, 6,2}, {1103,4,3,1},
					{2302,2,5,4},{2602,9,7,6},{3102,4,4,5},{2011,10,10,7}};
    int n = sizeof proc / sizeof proc[0];   
    sort(proc, proc + n, comparison);
    SJF_NP(proc, n);
  
    return 0; 
} 
