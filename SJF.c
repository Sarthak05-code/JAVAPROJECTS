#include <stdio.h>

int main(void)
{
    int n;

    // --- Input ---
    printf("Number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int burst[n], finish[n], wait[n], tat[n];
    int done[n];                               // tracks if process is completed

    for (int i = 0; i < n; i++) {
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
        done[i] = 0;                           // mark all as not done
    }

    // --- SJF Scheduling (Non-Preemptive, all arrive at 0) ---
    int time = 0;

    printf("\nExecution order: ");

    for (int count = 0; count < n; count++) {
        // find the process with the shortest burst that isn't done yet
        int shortest = -1;

        for (int i = 0; i < n; i++) {
            if (done[i]) continue;             // skip completed processes

            if (shortest == -1 || burst[i] < burst[shortest])
                shortest = i;                  // update shortest if smaller found
        }

        // run the shortest process to completion
        printf("P%d ", shortest + 1);
        time        += burst[shortest];
        finish[shortest] = time;
        done[shortest]   = 1;                  // mark as completed
    }

    // --- Calculate TAT and WT ---
    for (int i = 0; i < n; i++) {
        tat[i]  = finish[i];                   // TAT = CT - arrival (arrival = 0)
        wait[i] = tat[i] - burst[i];           // WT  = TAT - BT
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