#include <stdio.h>

int main(void)
{
    int n, quantum;

    // --- Input ---
    printf("Number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    printf("Time quantum: ");
    if (scanf("%d", &quantum) != 1 || quantum <= 0) return 1;

    int burst[n], remaining[n], finish[n], wait[n], tat[n];

    for (int i = 0; i < n; i++) {
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];          // copy burst into remaining
    }

    // --- Round Robin Scheduling ---
    int done = 0, time = 0;

    printf("\nExecution order: ");

    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (remaining[i] <= 0) continue;  // already finished, skip

            printf("P%d ", i + 1);

            if (remaining[i] > quantum) {
                time        += quantum;
                remaining[i] -= quantum;
            } else {
                time        += remaining[i];
                remaining[i] = 0;
                finish[i]    = time;
                done++;
            }
        }
    }

    // --- Calculate TAT and WT ---
    for (int i = 0; i < n; i++) {
        tat[i]  = finish[i];               // TAT = CT - arrival (arrival = 0)
        wait[i] = tat[i] - burst[i];       // WT  = TAT - BT
    }

    // --- Results Table ---
    printf("\n\nProcess\t\tBT\tCT\tTAT\tWT\n");
    printf("-------\t\t--\t--\t---\t--\n");

    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t%d\t%d\t%d\n", i + 1, burst[i], finish[i], tat[i], wait[i]);
        total_tat += tat[i];
        total_wt  += wait[i];
    }

    printf("\nAvg TAT: %.2f | Avg WT: %.2f\n", total_tat / n, total_wt / n);

    return 0;
}