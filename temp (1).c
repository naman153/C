#include<stdio.h>
#include<conio.h>

int rearrange(int n,float *AT1, float *BT1, float *ID1){ 
    int time=0;
    for(int i=0;i<n-1;i++){
        int max=0;
        int k=i;
        int j=i;
        while(j<n){
            if(AT1[j]<=time && BT1[j]>max){
                max=BT1[j];
                k=j;
            }
            j++;
        }

        if(( i>0 && AT1[k] - BT1[i-1]) > 0){
            time = time + (AT1[k]-BT1[i-1])+BT1[k];
        }
        else{
            time= time+BT1[k];
        }

        int temp= BT1[i];
        BT1[i] = BT1[k];
        BT1[k] = temp;

        temp= AT1[i];
        AT1[i] = AT1[k];
        AT1[k] = temp;

        temp= ID1[i];
        ID1[i] = ID1[k];
        ID1[k] = temp;

    }

    return 0;
}


int rearrange_ans(int n,float *AT1, float *BT1, float *ID1, float *CT1, float *TAT1, float *WT1){       
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ID1[i] > ID1[j]){
                int temp= ID1[i];
                ID1[i] = ID1[j];
                ID1[j] = temp;

                temp= AT1[i];
                AT1[i] = AT1[j];
                AT1[j] = temp;

                temp= BT1[i];
                BT1[i] = BT1[j];
                BT1[j] = temp;

                temp= CT1[i];
                CT1[i] = CT1[j];
                CT1[j] = temp;

                temp= TAT1[i];
                TAT1[i] = TAT1[j];
                TAT1[j] = temp;

                temp= WT1[i];
                WT1[i] = WT1[j];
                WT1[j] = temp;
            }
        }
    }
    return 0;
}

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

int worst_and_Ta_time(int n,float *AT2, float *BT2, float *CT2, float *TA, float *WT, float *avg_tat , float *avg_wtt){
    for(int i=0;i<n;i++){
        TA[i] = CT2[i] - AT2[i];
        *avg_tat += TA[i];
        WT[i] = TA[i] - BT2[i];
        *avg_wtt += WT[i];
    }
    return 0;
}


int main(){
    int n; 
    printf("Enter the number of process Id:");
    scanf("%d", &n);
    float ID[n], AT[n], BT[n], CT[n], TA[n], WT[n]; 
    float avg_ta=0, avg_wt=0;

    printf("Enter the Process Id, Arrival Time, Burst Time of processes from 0--%d\n", n);
    for(int i=0;i<n;i++){
        printf("Enter the Process Id(In numeric) of process %d: ", i);   
        scanf("%f",&ID[i]);
        printf("Enter the arrival time of process %d: ", i);   
        scanf("%f",&AT[i]);
        printf("Enter the burst time of process %d: ", i);
        scanf("%f", &BT[i]);
    }
    .
    printf("\n\n\n\nINPUT (FIRST COME FIRST SERVE):\n");
    printf("|============|==============|===========|\n");
    printf("|Process ID  |Arrival Time  |Burst Time |\n");
    printf("|============|==============|===========|\n");
    for(int i=0;i<n;i++){
    printf("|P%-6.0f     |%6.2f        |%6.2f     |\n", ID[i], AT[i], BT[i]);
    printf("|------------|--------------|-----------|\n");
    }


    rearrange(n, AT, BT, ID);   

    completion_time(n, AT, BT, CT);  

    worst_and_Ta_time(n, AT, BT, CT, TA, WT, &avg_ta, &avg_wt); 


    printf("\n\nGantt Chart of the Process:\n");
    float ctt = 0;
    int i=0;
    while( ctt < CT[n-1]){
        if(ctt < AT[i]){
            printf("      |  IDLE |");
            ctt += AT[i]-ctt;
        }
        else{
            printf("     |  P%-3.0f |",ID[i]);
            ctt = CT[i];
            i++;
        }
    }
    printf("\n");
    ctt=0,i=0;
    printf("|%5.1f|       ", 00.0);
    while(ctt < CT[n-1]){
        if(ctt < AT[i]){
            printf("|%5.1f|       ",AT[i]);
            ctt += AT[i]-ctt;
        }
        else{
            printf("|%5.1f|       ",CT[i]);
            ctt = CT[i];
            i++;
        }
    }

    rearrange_ans(n, AT, BT, ID, CT, TA, WT);   
    
    printf("|Process ID    |Arrival Time     |Burst Time     |Completion Time  |TurnAround Time  |Waiting Time |\n");
    for(int i=0;i<n;i++){
    printf("|P%-6.0f       |%6.2f           |%6.2f         |%6.2f           |%6.2f           |%6.2f       |\n", ID[i],AT[i], BT[i], CT[i], TA[i], WT[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_ta/n);
    printf("\nAverage Waiting Time: %.2f\n\n", avg_wt/n);



    return 0;
}