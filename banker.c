#include <stdio.h>
#define P 5
#define R 3

int allocation[P][R] = {
    {0,1,0},
    {2,0,0},
    {3,0,2},
    {2,1,1},
    {0,0,2},
};

int max[P][R] = {
    {7,5,5}, 
    {3,2,2},
    {9,0,2},
    {2,2,2},
    {4,3,3}
};

int available [R] = {3,3,2};
int need[P][R];

void calculateNeed() {
    for(int i = 0 ; i < P; ++i) {
        for(int j = 0 ; j < R ; ++j) {
            need[i][j]  = max[i][j];
        }
    }
}

int isSafe(int safeSeq[]) {
    int work[R];
    for(int i = 0; i < R; ++i) {
        work[i] = available[i];

    }
    int finish[P] = {0};
    int count = 0;

    while (count < P)
    {
        int found = 0;
        for(int i = 0 ; i < P ; ++i) {
            if(!finish[i]) {
                int canProceed = 1;
                for(int j = 0 ; j < R ; ++j) {
                    if(need[i][j] > work[j]) {
                        canProceed = 0;
                        break;
                    }
                }
                if(canProceed) {
                    for(int j = 0 ; j < R; ++j) 
                        work[j] += allocation[i][j];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(!found) {
            return 0;
        }
    }
    return 1;
    
}

int main() {
    calculateNeed();
    int safeSeq[P];
    if(isSafe(safeSeq)) {
        printf("System is in a Safe Sate:\n");
        printf("Safe Sequence :");
        for(int i = 0 ; i < P ; ++i) 
            printf("P%d "  ,safeSeq[i]);
        printf("\n");
    } else {
        printf("System is in an Unsafe Sate\n");
    }
}