#include<stdio.h>
#include<conio.h>

// Rearranging the arrival time, process id, burst time according to arrival time of process. 
int rearrange(int n,float *AT1, float *BT1, float *ID1){       
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(AT1[i] > AT1[j]){
                int temp= AT1[i];
                AT1[i] = AT1[j];
                AT1[j] = temp;

                int temp1= BT1[i];
                BT1[i] = BT1[j];
                BT1[j] = temp1;

                int temp2= ID1[i];
                ID1[i] = ID1[j];
                ID1[j] = temp2;
            }
        }
    }
    return 0;
}

//Calculating Completion time.
int completion_time(int n,float *AT2, float *BT2, float *CT2){
    int ct =0;
    for(int i=0;i<n;i++){
        if(AT2[i]>ct){
            ct = CT2[i] = (AT2[i]-ct)+ct+BT2[i];

        }
        else{
            ct = CT2[i] = ct+BT2[i];
        }
    }
    return 0;
}

//Calculating Worst time and Turnaround Time.
int worst_and_Ta_time(int n,float *AT2, float *BT2, float *CT2, float *TA, float *WT, float *avg_tat , float *avg_wtt){
    for(int i=0;i<n;i++){
        TA[i] = CT2[i] - AT2[i];
        *avg_tat += TA[i];
        WT[i] = TA[i] - BT2[i];
        *avg_wtt += WT[i];
    }
    return 0;
}


// main function
int main(){
    int n;  // Number of Process to be executed.
    printf("Enter the number of process Id:");
    scanf("%d", &n);
    float ID[n], AT[n], BT[n], CT[n], TA[n], WT[n]; // (AT=Arrival Time, BT= Burst Time, CT= Completion Time, TA= Turnaround Time, WT= Worst TIme)
    float avg_ta=0, avg_wt=0;

    printf("Enter the Process Id, Arrival Time, Burst Time of processes from 0--%d\n", n);
    for(int i=0;i<n;i++){
        printf("Enter the Process Id(In numeric) of process %d: ", i);   //Input Process Id Data of Processes.
        scanf("%f",&ID[i]);
        printf("Enter the arrival time of process %d: ", i);   //Input Arrival Time Data of Processes.
        scanf("%f",&AT[i]);
        printf("Enter the burst time of process %d: ", i);    //Input Burst Time Data of Processes.
        scanf("%f",&BT[i]);
    }
    //Print the input data.
    printf("\n\n\n\nINPUT (FIRST COME FIRST SERVE):\n");
    printf("|============|==============|===========|\n");
    printf("|Process ID  |Arrival Time  |Burst Time |\n");
    printf("|============|==============|===========|\n");
    for(int i=0;i<n;i++){
    printf("|%6.2f      |%6.2f        |%6.2f     |\n", ID[i], AT[i], BT[i]);
    printf("|------------|--------------|-----------|\n");
    }


    rearrange(n, AT, BT, ID);   //reaaranging in terms of arrival time of process.

    completion_time(n, AT, BT, CT);  //Calculating Completion Time

    worst_and_Ta_time(n, AT, BT, CT, TA, WT, &avg_ta, &avg_wt);  //Calculating Worst Time and Turnaround Time
    
    //Printing the result after applying fcfs
    printf("\n\n\n\nRESULT (FIRST COME FIRST SERVE):\n");
    printf("|==============|=================|===============|=================|=================|=============|\n");
    printf("|Process ID    |Arrival Time     |Burst Time     |Completion Time  |TurnAround Time  |Waiting Time |\n");
    printf("|==============|=================|===============|=================|=================|=============|\n");
    for(int i=0;i<n;i++){
    printf("|%6.2f        |%6.2f           |%6.2f         |%6.2f           |%6.2f           |%6.2f       |\n", ID[i],AT[i], BT[i], CT[i], TA[i], WT[i]);
    printf("|--------------|-----------------|---------------|-----------------|-----------------|-------------|\n");
    }

    printf("\nAverage Turnaround Time: %.2f", avg_ta/n);
    printf("\nAverage Waiting Time: %.2f\n\n", avg_wt/n);

    //GANTT CHART

    printf("Gantt Chart of the Process:\n");
    float ctt = 0;
    int i=0;
    while( ctt < CT[n-1]){
        if(ctt < AT[i]){
            printf("         IDLE");
            ctt += AT[i]-ctt;
        }
        else{
            printf("         P%4.0f",ID[i]);
            ctt = CT[i];
            i++;
        }
    }
    printf("\n");
    ctt=0,i=0;
    printf("|%6.1f|      ", 00.0);
    while(ctt < CT[n-1]){
        if(ctt < AT[i]){
            printf("|%6.1f|      ",AT[i]);
            ctt += AT[i]-ctt;
        }
        else{
            printf("|%6.1f|      ",CT[i]);
            ctt = CT[i];
            i++;
        }
    }
    printf("\n\n\n");

    return 0;
}