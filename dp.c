#include <stdio.h>
#include <stdlib.h>

int getMin(int a, int b) {
    return (a < b) ? a : b;
}

int minCoins(int* coins, int n, int amount) {
    int dp[amount+1];
    // int* dp = malloc(amount+1);
    // Initialize dp array with a value that represents "infinity"
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    // Base case
    dp[0] = 0;

    // Calculate the minimum number of coins needed for each amount
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = getMin(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount] == (amount+1) ? -1 : dp[amount];
}

int main() {
    int n, amount;

    printf("Number of values of coins: ");
    scanf("%d", &n);

    int* coins = malloc(n);

    printf("Coins:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Amount: ");
    scanf("%d", &amount);
    printf("Answer: %d", minCoins(coins, n, amount));

    return 0;
}
