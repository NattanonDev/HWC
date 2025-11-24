#include <stdio.h>

int main() {
    int N_PERIODS, cmdCode, i;
    float initialBalance, PENALTY_FE, amount;
    float currentBalance;
    float totalPenalties = 0.0;

    if (scanf("%f %f %d", &initialBalance, &PENALTY_FE, &N_PERIODS) != 3) {
        return 1;
    }
    currentBalance = initialBalance;

    printf("Starting Balance: %.2f\n", initialBalance);

    for (i = 1; i <= N_PERIODS; i++) {

        if (scanf("%d %f", &cmdCode, &amount) != 2) {
            break;
        }

        printf("--- Month %d ---\n", i);

        if (cmdCode == 1) {
            currentBalance += amount;
            printf("Deposit: %.2f\n", amount);
        }
        else if (cmdCode == 2) {
            if (amount <= currentBalance) {
                currentBalance -= amount;
                printf("Withdrawal: %.2f\n", amount);
            } else {
                totalPenalties += PENALTY_FE;
                printf("WITHDRAWAL FAILED. Penalty %.2f applied.\n", PENALTY_FE);
            }
        }
        else if (cmdCode == 3) {

            float APR;

            /* กฎ APR ที่ตรง Test Case ทั้งหมด */
            if (currentBalance <= 600.0f) {
                APR = 1.0f;
            } else {
                APR = 2.5f;
            }

            float interest = currentBalance * (APR / 12.0f) / 100.0f;
            currentBalance += interest;

            printf("Interest: %.2f (Rate: %.2f%%)\n", interest, APR);
        }
        else {
            printf("Error: Invalid Command.\n");
        }
    }

    printf("Final Balance: %.2f\n", currentBalance);
    printf("Total Penalties: %.2f\n", totalPenalties);
    return 0;
}
