#include <stdio.h>

void printCombinations(int score) {
    char combination[100];
    int count = 0;

    for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {
        for (int td7 = 0; td7 * 7 <= score - td2pt * 8; td7++) {
            for (int td = 0; td * 6 <= score - td2pt * 8 - td7 * 7; td++) {
                for (int fg = 0; fg * 3 <= score - td2pt * 8 - td7 * 7 - td * 6; fg++) {
                    for (int safety = 0; safety * 2 <= score - td2pt * 8 - td7 * 7 - td * 6 - fg * 3; safety++) {
                        if (td2pt * 8 + td7 * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            sprintf(combination, "%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety", td2pt, td7, td, fg, safety);
                            printf("%s\n", combination);
                            count++;
                        }
                    }
                }
            }
        }
    }

    if (count == 0) {
        printf("No combinations found.\n");
    }
}

int main() {
    int score;
    int stop = 0;

    printf("Enter 0 or 1 to STOP\n");

    while (!stop) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            stop = 1;
            printf("Goodbye!\n");
        } else {
            printf("Possible combinations of scoring plays:\n");
            printCombinations(score);
        }
    }

    return 0;
}
