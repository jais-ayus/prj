#include <stdio.h>
#include <stdlib.h>

float usd_to_eur(float amount) {
    return amount * 0.93;
}

float usd_to_gbp(float amount) {
    return amount * 0.79;
}

float usd_to_inr(float amount) {
    return amount * 82.5;
}

float eur_to_usd(float amount) {
    return amount * 1.08;
}

float eur_to_gbp(float amount) {
    return amount * 0.86;
}

float eur_to_inr(float amount) {
    return amount * 89.1;
}

float gbp_to_usd(float amount) {
    return amount * 1.26;
}

float gbp_to_eur(float amount) {
    return amount * 1.18;
}

float gbp_to_inr(float amount) {
    return amount * 103.6;
}

float inr_to_usd(float amount) {
    return amount / 82.5;
}

float inr_to_eur(float amount) {
    return amount / 89.1;
}

float inr_to_gbp(float amount) {
    return amount / 103.6;
}

int getValidChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (choice < 1 || choice > 13) {
        printf("Invalid choice. Please enter a valid option: ");
        scanf("%d", &choice);
    }
    return choice;
}

float getValidAmount() {
    float amount;
    printf("Enter the amount: ");
    scanf("%f", &amount);
    return amount;
}

void performConversion(int choice, float amount) {
    float result;
    switch (choice) {
        case 1:
            result = usd_to_eur(amount);
            printf("%.2f USD is equal to %.2f EUR\n", amount, result);
            break;
        case 2:
            result = usd_to_gbp(amount);
            printf("%.2f USD is equal to %.2f GBP\n", amount, result);
            break;
        case 3:
            result = usd_to_inr(amount);
            printf("%.2f USD is equal to %.2f INR\n", amount, result);
            break;
        case 4:
            result = eur_to_usd(amount);
            printf("%.2f EUR is equal to %.2f USD\n", amount, result);
            break;
        case 5:
            result = eur_to_gbp(amount);
            printf("%.2f EUR is equal to %.2f GBP\n", amount, result);
            break;
        case 6:
            result = eur_to_inr(amount);
            printf("%.2f EUR is equal to %.2f INR\n", amount, result);
            break;
        case 7:
            result = gbp_to_usd(amount);
            printf("%.2f GBP is equal to %.2f USD\n", amount, result);
            break;
        case 8:
            result = gbp_to_eur(amount);
            printf("%.2f GBP is equal to %.2f EUR\n", amount, result);
            break;
        case 9:
            result = gbp_to_inr(amount);
            printf("%.2f GBP is equal to %.2f INR\n", amount, result);
            break;
        case 10:
            result = inr_to_usd(amount);
            printf("%.2f INR is equal to %.2f USD\n", amount, result);
            break;
        case 11:
            result = inr_to_eur(amount);
            printf("%.2f INR is equal to %.2f EUR\n", amount, result);
            break;
        case 12:
            result = inr_to_gbp(amount);
            printf("%.2f INR is equal to %.2f GBP\n", amount, result);
            break;
    }
}

void printMenu() {
    printf("\nCurrency Converter\n");
    printf("===================\n");
    printf("1. USD to EUR\n");
    printf("2. USD to GBP\n");
    printf("3. USD to INR\n");
    printf("4. EUR to USD\n");
    printf("5. EUR to GBP\n");
    printf("6. EUR to INR\n");
    printf("7. GBP to USD\n");
    printf("8. GBP to EUR\n");
    printf("9. GBP to INR\n");
    printf("10. INR to USD\n");
    printf("11. INR to EUR\n");
    printf("12. INR to GBP\n");
    printf("13. Exit\n");
}

int main() {
    printf("Welcome to the Currency Converter\n");

    while (1) {
        printMenu();
        
        int choice = getValidChoice();

        if (choice == 13) {
            printf("Thank you for using the Currency Converter. Exiting.\n");
            break;
        }

        float amount = getValidAmount();

        printf("\nResult: ");
        performConversion(choice, amount);
    }

    return 0;
}
