#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    int i, j, N, TAT[10], WT[10], pos, temp;
    int Sum_wt = 0, Sum_tat = 0, AT[10], BT[10], PR[10];
    printf("Enter Total Process:\t");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Enter Arrival Time for Process %d :", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter Burst Time for Process %d :", i + 1);
        scanf("%d", &BT[i]);
        printf("Enter Priority of Process %d :", i + 1);
        scanf("%d", &PR[i]);
    }

    // Sort the processes according to priority
    for (i = 0; i < N; i++) {
        pos = i;
        for (j = i + 1; j < N; j++) {
            if (PR[j] < PR[pos]) {
                pos = j;
            }
        }

        // Swap Priority
        temp = PR[i];
        PR[i] = PR[pos];
        PR[pos] = temp;

        // Swap Burst Time
        temp = BT[i];
        BT[i] = BT[pos];
        BT[pos] = temp;

        // Swap Arrival Time
        temp = AT[i];
        AT[i] = AT[pos];
        AT[pos] = temp;
    }

    WT[0] = 0;
    printf("\nProcess\t AT\t BT\t PR\t TAT\t WT\n");

    for (i = 0; i < N; i++) {
        TAT[i] = 0;
        WT[i] = 0;

        for (j = 0; j < i; j++) {
            WT[i] += BT[j];
        }
        TAT[i] = WT[i] + BT[i];
        Sum_wt += WT[i];
        Sum_tat += TAT[i];
        printf("P[%d]\t %d\t %d\t %d\t %d\t %d\n", i + 1, AT[i], BT[i], PR[i], TAT[i], WT[i]);
    }
    printf("\nAverage Waiting Time = %f\n", (Sum_wt * 1.0) / N);
    printf("Avg Turnaround Time = %f\n\n", (Sum_tat * 1.0) / N);
    return (EXIT_SUCCESS);
}