#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_combinations(int score) {
    int td, fg, safety, td_2pt, td_1fg; //each of the options for score contributers 
    for (td = 0; td * 6 <= score; td++) { //While the possible touch down's score does not exceed the score
        for (fg = 0; fg * 3 <= score - td * 6; fg++) { //Do the same for field goals
            for (safety = 0; safety * 2 <= score - (td * 6 + fg * 3); safety++) {//circle thorough possilbe amounts of safety
                for (td_2pt = 0; td_2pt * 8 <= score - (td * 6 + fg * 3 + safety * 2); td_2pt++) { //same for 2 point touch downs
                    for (td_1fg = 0; td_1fg * 7 <= score - (td * 6 + fg * 3 + safety * 2 + td_2pt * 8); td_1fg++) { //for 1pt field goals
                        if (td * 6 + fg * 3 + safety * 2 + td_2pt * 8 + td_1fg * 7 == score) { //check if this combination equals the inputted score
                            printf("%d TD + %d 3pt FG + %d Safety + %d TD 2pt + %d TD 1 FG\n", td, fg, safety, td_2pt, td_1fg); //display
                        }
                    }
                }
            }
        }
    }
}

int main() {
    char stop[] = "Stop";
    char input[50];
    int score;
    while (1) {
        printf("Enter 'Stop' to stop\n"); //display menu 
        printf("Enter the NFL score: ");
        scanf("%s", input);
        if (strcmp(input, stop) == 0) { //if the input equals stop
            break;
        }
        score = atoi(input);
        printf("possible combinations of scoring plays:\n");
        print_combinations(score);
    }
    return 0;
}
