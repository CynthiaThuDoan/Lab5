#include <stdio.h>

// Function to print all possible combinations of scoring plays
void printCombinations(int td, int fg, int safety) {
    printf("%d TD + %d TD + %d TD + %d TD + %d TD + %d 3pt FG + %d Safety\n", td/5, (td%5)/4, (td%4)/3, (td%3)/2, (td%2)/1, fg, safety);
}

// Function to calculate and print combinations for a given score
void calculateCombinations(int score) {
    for (int td = 0; td <= score / 6; td++) {
        for (int fg = 0; fg <= score / 3; fg++) {
            for (int safety = 0; safety <= score / 2; safety++) {
                if ((td * 6 + fg * 3 + safety * 2) == score) {
                    printCombinations(td, fg, safety);
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        // Prompt user for input until a value less than or equal to 1 is entered
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            // Terminate the program if input is less than or equal to 1
            break;
        }

        // Display possible combinations for the entered score
        printf("Possible combinations of scoring plays:\n");
        calculateCombinations(score);
    }

    return 0;
}
