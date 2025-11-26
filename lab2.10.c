#include <stdio.h>
int main(){
    int N_PERIODS, cmdCode, i;
    float initialBalance, PENALTY_FEE, amount;
    float Balance, APR, interest;
    float totalPenalties = 0.0;

    printf("Enter Your InitialBalance, Penalty and month \n");
    if(scanf("%f %f %d", &initialBalance, &PENALTY_FEE, &N_PERIODS) != 3){
        return 1;
    }
    Balance = initialBalance;

    printf("Starting Balance: %.2f \n", initialBalance);


    for(i = 1; i <= N_PERIODS; i++){

        if(scanf("%d %f", &cmdCode, &amount) != 2){
           break; 
        }
        switch(cmdCode){
            case 1:
                Balance += amount;

                printf("--- Month %d --- \n", i);
                printf("Deposit : [%.2f] \n", amount);
                break;
            case 2:
                if(amount <= Balance){
                    Balance -= amount;

                    printf("--- Month %d --- \n", i);
                    printf("Withdrawal : [%.2f] \n", amount);
                }
                
                else{
                    totalPenalties += PENALTY_FEE;

                    printf("--- Month %d --- \n", i);
                    printf("WITHDRAWAL FAILED. Penalty [%.2f] applied \n",PENALTY_FEE);
                }
                break;
            case 3:
                if(Balance < 1000.00){
                    APR = 0.01;
                }

                else if(Balance >= 1000.00){
                    APR = 0.025;
                }

                interest = Balance * (APR/12.0);
                Balance += interest;

                printf("--- Month %d --- \n", i);
                printf("Interest : [%.2f] (Rate : [%.2f] Percent) \n", interest, APR*100);
                break;

            default:
                printf("Error : Invalid Command. \n");
                break;
        }   
    }

    printf("Final Balance : %.2f \n", Balance);

    printf("Total Penalties : %.2f \n", totalPenalties);
    return 0;
}
