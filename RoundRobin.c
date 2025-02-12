#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int i, j, N, time, remain, count = 0, TQ, TAT, WT;
    int Sum_wt = 0, Sum_tat = 0, AT[10], BT[10], Temp[10];

    printf("Enter Total Process:\t");
    scanf("%d", &N);
    remain = N;

    for (i = 0; i < N; i++) {
        printf("Enter Arrival Time for Process %d :", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter Burst Time for Process %d :", i + 1);
        scanf("%d", &BT[i]);
        Temp[i] = BT[i];
    }

    printf("Enter Time Quantum:\t");
    scanf("%d", &TQ);
    
    printf("\n\nProcess\t| AT | BT | Turnaround Time | Waiting Time\n\n");

    for (time = 0, i = 0; remain != 0;) {
        if (Temp[i] <= TQ && Temp[i] > 0) {
            time = time + Temp[i];
            Temp[i] = 0;
            count = 1;
        } else if (Temp[i] > 0) {
            Temp[i] = Temp[i] - TQ;
            time = time + TQ;
        }
        if (Temp[i] == 0 && count == 1) {
            remain--;
            TAT = time - AT[i];
            WT = TAT - BT[i];
            printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", i + 1, AT[i], BT[i], TAT, WT);
            Sum_wt += WT;
            Sum_tat += TAT;
            count = 0;
        }
        if (i == N - 1)
            i = 0;
        else if (AT[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\naverage waiting time=%f\n",(Sum_wt*1.0)/N);
    printf("\naverage turnaround time=%f\n\n",(Sum_tat*1.0)/N);
    return (EXIT_SUCCESS);
}
