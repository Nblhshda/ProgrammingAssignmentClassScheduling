/*
 MAISARAH BINTI HAMZAH  1810325
NUR MAISARA BINTI AHMAD RASID  1818356
NOR NABILAH SHUHADA BINTI MOHD KAMAL  1817510
SITI NUR AISHAH BINTI SULAIMAN  1816454
CSC3401 Operating System Section 5
*/
// C++ implementation for non-preemptive Priority Scheduling  
#include <bits/stdc++.h> 
using namespace std; 
 
  
struct Course
{
   int ccode;     // course code
   int duration;      // class duration
   int priority;  //priority
   int arrival_time;   //prefered arrival time
}; 
  

bool comp(Course a, Course b) 
{ 
    if(a.priority == b.priority) 
	return (a.arrival_time < b.arrival_time); 
	
	else
	    return (a.priority < b.priority); 

}  

void findWaitingTime(Course proc[], int wt[], int n) 
{ 
	// declaring service array that stores cumulative burst time  
	int service[n]; 
	  
	// Initilising initial elements of the arrays 
	service[0] = proc[0].arrival_time; 
	wt[0]=0; 
  
  
for(int i = 1; i < n; i++) 
{ 
	service[i] = proc[i-1].duration + service[i-1]; 
	  
	wt[i] = service[i] - proc[i].arrival_time; 
  
// If waiting time is negative, change it into zero 
      
    if(wt[i]<0) 
    { 
    wt[i]=0; 
    } 
} 
  
} 
  
void findTurnAroundTime(Course proc[], int n, int tat[],int wt[]) 
{ 
	// Filling turnaroundtime array 
	  
	for(int i=0; i<n; i++) 
	{ 
	    tat[i]=proc[i].duration + wt[i]; 
	} 
      
} 
  
void priorityScheduling(Course proc[], int n) 
{ 
	cout << "Output for Priority Non-Preemptive scheduling algorithm" << endl;
	sort(proc, proc + n, comp); 
	cout<< "\nOrder of the course code: \n"; 
	    for (int  i = 0 ; i <  n; i++) 
	        cout << proc[i].ccode <<" " ; 
	        
	
	//Declare waiting time and turnaround time array 
	int wt[n],tat[n]; 
	  
	double wavg=0,tavg=0; 
	  
	// Function call to find waiting time array 
	findWaitingTime(proc, wt, n); 
	//Function call to find turnaround time 
	findTurnAroundTime(proc, n, tat, wt); 
	      
	int stime[n],ctime[n]; 
	  
	stime[0] = proc[0].arrival_time; 
	ctime[0]=stime[0]+tat[0]; 
	 int j=1; 
	// calculating starting and ending time 
	for(int i = 1; i < n; i++) 
	    { 
	        stime[i]=ctime[i-1]; 
	        ctime[i]=stime[i]+tat[i]-wt[i];
	    } 
	      
	cout<<"\n\nCourse Code\tPriority\tArrival time\tBurst time\tWaiting Time\tTurn-Around Time\tCompletion time"<<endl; 
	      
	    // display the process details 
	      
	for(int i=0; i<n; i++) 
	    { 
	        wavg += wt[i]; 
	        tavg += tat[i]; 
	          
	        cout<<proc[i].ccode<<"\t\t"<<proc[i].priority<<"\t\t"<< 
	            proc[i].arrival_time<<"\t\t"<<proc[i].duration<<"\t\t"<<wt[i]
				<<"\t\t"<<tat[i]<<"\t\t\t"<<ctime[i]<<endl; 
	    } 
      
        // display the average waiting time 
        //and average turn around time 
      
    cout<<"\nAverage waiting time is : "; 
    cout<<wavg/(float)n<<endl; 
    cout<<"average turnaround time : "; 
    cout<<tavg/(float)n<<endl; 
  
} 
  
int main() 
{ 
    Course proc[] = {{2201,3,2,0}, {3401, 5, 6,2}, {1103,4,3,1},
					{2302,2,5,4},{2602,9,7,6},{3102,4,4,5},{2011,10,10,7}};
    int n = sizeof proc / sizeof proc[0];   
    
    priorityScheduling(proc, n);  
  
    return 0; 
} 
