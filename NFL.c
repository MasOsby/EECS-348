/*
 * EECS 348 - Lab 8 (Task 1)
 * Single-run version: asks for one NFL score, prints all scoring combinations, then exits.
 * Scoring plays used: 8 (TD+2pt), 7 (TD+FG), 6 (TD), 3 (FG), 2 (Safety).
 */

#include <stdio.h>
int main(){
    int score;
    while(1){
        printf("Enter the NFL score: ");
        if(scanf("%d", &score) != 1){
            printf("Invalid input. Please enter an integer.\n");
            continue;
        }
        if(score < 0){
            printf("Invalid score: negative values are not allowed.\n");
            continue;;
        }
        if(score == 1){
            printf("You have enterred 1, Exiting program...");
            break;
        }
        int count = 0; 
        printf("Possible combinations if a team’s score is %d:\n", score);
        printf("%7s %6s %5s %5s %7s\n", "TD+2pt", "TD+FG", "TD", "FG", "Safety");
        printf("%7s %6s %5s %5s %7s\n", "-------", "-----", "---", "--", "------");
        for(int td2 = 0; td2 * 8 <= score; ++td2){
            for(int tdfg = 0; tdfg * 7 <= score - td2 * 8; ++tdfg){
                for(int td = 0; td * 6 <= score - td2 * 8 - tdfg * 7; ++td){
                    for(int fg = 0; fg * 3 <= score - td2 * 8 - tdfg * 7 - td * 6; ++fg){
                        int used = td2 * 8 + tdfg * 7 + td * 6 + fg * 3;
                        int rem = score - used;
                        if(rem < 0 || rem % 2 != 0) continue;
                        int safety = rem / 2;
                        if(safety < 0) continue;

                        printf("%7d %6d %5d %5d %7d\n", td2, tdfg, td, fg, safety);
                        count++;
                    }
                }
            }
        }
        if(count == 0){
            printf("No combinations possible for %d with standard NFL scoring.\n", score);
        }else{
            printf("Number of combinations: %d\n", count);  
    }
    }
    return 0;
}