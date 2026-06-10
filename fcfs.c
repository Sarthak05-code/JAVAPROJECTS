#include <stdio.h>

int main(int argc, char const *argv[])
{
    int pid;
    printf("Enter the number of process: ");
    if (scanf("%d", &pid) != 1 || pid <= 0) {
        return 1;
    }

    int burstTime[pid];
    int completedTime[pid];
    int turnaroundTime[pid];
    int waitingTime[pid];

    for (int i = 0; i < pid; ++i)
    {
        printf("Enter burstTime[%d]: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    int time = 0;
    for (int i = 0; i < pid; i++)
    {
        time += burstTime[i];
        completedTime[i] = time;
    }

    for (int i = 0; i < pid; ++i)
    {
        turnaroundTime[i] = completedTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }

    printf("PID \t BurstTime \t CompletedTime \t TurnAroundTime \t WaitingTime\n");
    for (int i = 0; i < pid; ++i)
    {
        printf("%d\t %d\t %d\t %d\t %d\n", i, burstTime[i], completedTime[i], turnaroundTime[i], waitingTime[i]);
    }

    return 0;
}
