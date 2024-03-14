#include <iostream>
#include <map>
#include <string>

#define RESET_COLOR "\033[0m"
#define GREEN_TEXT "\033[32m"

using namespace std;

// typedef för map där key = kontonummer och value = saldo
typedef map<string, double> AccountMap;

void createAccount(AccountMap &accounts) {
    string accountNr;
    double initialBalance;
    
    cout << "Ange kontonummer: ";
    cin >> accountNr;
    cout << "Ange initialt saldo: ";
    cin >> initialBalance;
    
    // Lägg till kontonummer och saldo i mapen
    accounts[accountNr] = initialBalance;
    
    cout << GREEN_TEXT << "Konto skapat!" << RESET_COLOR << endl;
}

bool login(AccountMap &accounts, string accountNr) {
    // Kolla om kontot finns i mapen
    if (accounts.find(accountNr) != accounts.end()) {
        cout << GREEN_TEXT << "Inloggad på konto " << accountNr << RESET_COLOR << endl;
        return true;
    } else {
        cout << GREEN_TEXT << "Konto [" << accountNr << "] hittades inte." << RESET_COLOR << endl;
        return false;
    }
}

void withdraw(AccountMap &accounts, string accountNr, double amount) {
    // Kolla om kontot finns i mapen
    if (accounts.find(accountNr) != accounts.end()) {
        // Kolla om tillräckligt saldo finns
        if (accounts[accountNr] >= amount) {
            accounts[accountNr] -= amount;
            cout << GREEN_TEXT << "Uttag genomfört" << RESET_COLOR << endl;
            cout << "Nytt saldo: " << accounts[accountNr] << endl;
        } else {
            cout << GREEN_TEXT << "Otillräckligt saldo för uttag." << RESET_COLOR << endl;
        }
    } else {
        cout << GREEN_TEXT << "Konto " << accountNr << " hittades inte." << RESET_COLOR<< endl;
    }
}

void deposit(AccountMap &accounts, string accountNr, double amount) {
    // Kolla om kontot finns i mapen
    if (accounts.find(accountNr) != accounts.end()) {
        accounts[accountNr] += amount;
        cout << GREEN_TEXT << "Insättning genomförd." << RESET_COLOR << endl;
        cout << "Nytt saldo: " << accounts[accountNr] << endl;
    } else {
        cout << GREEN_TEXT << "Konto " << accountNr << " hittades inte." << RESET_COLOR << endl;
    }
}

void printMenu() {
        cout << "\n--------------------" << endl;
        cout << "      BANKOMAT      " << endl;
        cout << "--------------------\n" << endl;
        cout << "1. Skapa konto" << endl;
        cout << "2. Logga in" << endl;
        cout << "3. Ta ut pengar" << endl;
        cout << "4. Sätt in pengar" << endl;
        cout << "5. Avsluta" << endl;
}

int main() {
    AccountMap accounts;
    int choice;
    string accountNr;
    double amount;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            case 2:
                cout << "Ange kontonummer: ";
                cin >> accountNr;
                login(accounts, accountNr);
                break;
            case 3:
                cout << "Ange kontonummer: ";
                cin >> accountNr;
                cout << "Ange belopp att ta ut: ";
                cin >> amount;
                withdraw(accounts, accountNr, amount);
                break;
            case 4:
                cout << "Ange kontonummer: ";
                cin >> accountNr;
                cout << "Ange belopp att sätta in: ";
                cin >> amount;
                deposit(accounts, accountNr, amount);
                break;
            case 5:
                cout << GREEN_TEXT << "Avslutar programmet." << RESET_COLOR << endl;
                break;
            default:
                cout << GREEN_TEXT << "Ogiltigt val. Försök igen." << RESET_COLOR << endl;
        }
    } while (choice != 5);

    return 0;
}