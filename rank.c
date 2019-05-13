#include<stdio.h>


void displayData(int *data, int count) {
    for(int i = 0; i < count; i++){
        printf("%d,", data[i]);
    }
}

void sort(int *points, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            if (points[i] < points[j]) {
                points[i] = points[i] ^ points[j];
                points[j] = points[i] ^ points[j];
                points[i] = points[i] ^ points[j];
            }
        }
    }
}

void calculateRank(int *points, int*ranks, int count) {
    int rank = 1;
    ranks[0] = rank;
    for (int i = 1; i < count; i++) {
        if (points[i] != points[i-1]) {
            rank = i + 1;
        }
        ranks[i] = rank;
    }
}

int main(int argc, char **argv) {
    
    int n = 0;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int points[n];
    for(int i = 0; i < n; i++) {
        printf("Enter elements at points[%d]:", i);
        scanf("%d", &points[i]);
    }
    printf("\n******************* Input Data *******************************\n");
    displayData(points, n);
    
    printf("\n******************* Sort Input Data *******************************\n");
    //Sort the input data array
    sort(points, n);
    
    displayData(points, n);
    
    int ranks[n];
    
    //calculate the rank using sorted array
    calculateRank(points, ranks, n);
    
    printf("\n******************* Display Rank Data *******************************\n");
    //Display the rank
    displayData(ranks, n);
    printf("\n");

    return 0;
}
