#include <stdio.h>
#define P 5
#define R 3

int allocation[P][R] = {
    {0,1,0},
    {2,0,0},
    {3,0,3},
    {2,1,1},
    {0,0,2}
};

int request [P][R] = {
    {0,0,0},
    {2,0,2},
    {0,0,0},
    {1,0,0},
    {0,0,2}
};

int available[R] = {0,0,0};
int finish[P];

void detectDeadLock() {
    int work[R];
    for(int i = 0 ; i < R ; ++i) {
        work[i] = available[i];
    }

    for(int i = 0 ; i < P ; ++i) {
        finish[i] = 0;
    }

    int found;
    do {
        found = 0;
        for(int i = 0 ; i < P ; ++i) {
            if(!finish) {
                int canProceed = 1;
                for(int j = 0 ; j < R; ++j) {
                    if(request[i][j] > work[j]) {
                        canProceed = 0;
                        break;
                    }
                }
                if(canProceed) {
                    for(int j = 0 ; j < R ; ++j) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
    }while(found);
    int deadlock[P] , count = 0;
    printf("Process Finish Status : \n");
    for(int i = 0 ; i < P ; ++i) {
        printf("P%d : %s\n" , i , finish[i] ? "Finished" : "Not-Finished");
        if(!finish[i])
            deadlock[count++] = i;

    }
    if (count == 0) {
        printf("\nNo deadlock detected: \n");
    } else {
        printf("DeadLock Detected: \n");
        for(int i = 0 ; i < count ; ++i) 
            printf("P%d " , deadlock[i]);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    detectDeadLock();
    return 0;
}
