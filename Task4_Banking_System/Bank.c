/*
 * TASK 4: High - Banking System (Mini Project)
 * Bank Account Management System in C.
 * Functions: Deposit, Withdraw, Balance Enquiry, and Exit.
 * Account data is stored permanently using file handling.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "accounts.dat"

typedef struct {
    int accNo;
    char name[50];
    char pin[5];
    double balance;
} Account;

/* Create a new bank account */
void createAccount() {
    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Account acc;
    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", acc.name);
    printf("Set a 4-digit PIN: ");
    scanf("%s", acc.pin);
    printf("Enter Initial Deposit Amount: ");
    scanf("%lf", &acc.balance);

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
    printf("Account created successfully! Account No: %d\n", acc.accNo);
}

/* Find account and verify PIN; returns 1 if match found (acc filled), else 0 */
int findAccount(int accNo, const char *pin, Account *acc, long *pos) {
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) return 0;

    while (fread(acc, sizeof(Account), 1, fp)) {
        if (acc->accNo == accNo) {
            *pos = ftell(fp) - (long)sizeof(Account);
            fclose(fp);
            if (pin != NULL && strcmp(acc->pin, pin) != 0) {
                return -1; /* wrong pin */
            }
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void depositAmount() {
    int accNo;
    char pin[5];
    double amount;
    Account acc;
    long pos;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter PIN: ");
    scanf("%s", pin);

    int status = findAccount(accNo, pin, &acc, &pos);
    if (status == 0) {
        printf("Account not found!\n");
        return;
    } else if (status == -1) {
        printf("Incorrect PIN!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    acc.balance += amount;

    FILE *fp = fopen(FILENAME, "rb+");
    fseek(fp, pos, SEEK_SET);
    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);

    printf("Deposit successful! New Balance: %.2f\n", acc.balance);
}

void withdrawAmount() {
    int accNo;
    char pin[5];
    double amount;
    Account acc;
    long pos;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter PIN: ");
    scanf("%s", pin);

    int status = findAccount(accNo, pin, &acc, &pos);
    if (status == 0) {
        printf("Account not found!\n");
        return;
    } else if (status == -1) {
        printf("Incorrect PIN!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    if (amount > acc.balance) {
        printf("Insufficient balance! Current balance: %.2f\n", acc.balance);
        return;
    }

    acc.balance -= amount;

    FILE *fp = fopen(FILENAME, "rb+");
    fseek(fp, pos, SEEK_SET);
    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);

    printf("Withdrawal successful! New Balance: %.2f\n", acc.balance);
}

void checkBalance() {
    int accNo;
    char pin[5];
    Account acc;
    long pos;

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter PIN: ");
    scanf("%s", pin);

    int status = findAccount(accNo, pin, &acc, &pos);
    if (status == 0) {
        printf("Account not found!\n");
        return;
    } else if (status == -1) {
        printf("Incorrect PIN!\n");
        return;
    }

    printf("\nAccount Holder: %s\n", acc.name);
    printf("Account Number: %d\n", acc.accNo);
    printf("Current Balance: %.2f\n", acc.balance);
}

int main() {
    int choice;

    do {
        printf("\n===== Bank Account Management System =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Balance Enquiry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: depositAmount(); break;
            case 3: withdrawAmount(); break;
            case 4: checkBalance(); break;
            case 5: printf("Thank you for banking with us. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
