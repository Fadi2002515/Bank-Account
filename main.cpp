#include<iostream>
#include<vector>
using namespace std;

void welcoming() {
	cout << "Welcome to Livonia Bank" << endl;
	cout << "How can we help you today?" << endl;
	cout << "1-Deposit" << endl;
	cout << "2-Withdraw" << endl;
	cout << "3-Open creidt card" << endl;
	cout << "4-open savings account" << endl;
	cout << "5-Asking about account balance" << endl;
	cout << "6-Showing the transactions history" << endl;
}

class BankAccount {


public:

	
		void choosing(int choice, char &letter) {
			if (choice == 1) {
				cout << "A-Check ,B-Cash" << endl;
				cin >> letter;
			}

		}

		void Details(int choice) {
			if (choice == 3) {
				cout << "You buy something with the card, the bank pays the store, you pay the bank later ,and if you delay interest is added" << endl;
			}
			else if (choice == 4) {
				cout << "You deposit money, the bank keeps it safe, the bank pays you interest , and your balance slowly grows " << endl;
			}
		}
		
};

class Bank : public BankAccount {

public:
	void Deposit(char letter, double& amt, double& balance, vector<double>& transactions) {

		transactions;

		if (letter == 'A' || letter == 'a') {

			cout << "How much is in your check?" << endl;
			cin >> amt;
			balance += amt;
		}
		else if (letter == 'B' || letter == 'b') {

			cout << "How much cash would you like to deposit?" << endl;
			cin >> amt;
			balance += amt;

		}
		transactions.push_back(amt);
	}

	void withdraw(int choice, double& amt, double& balance, vector<double>& transactions) {

	transactions;

		if (choice == 2) {
			cout << "How much would you like to withdraw?" << endl;
			cin >> amt;
			balance -= amt;
		}
		transactions.push_back(amt);
	}

	void asking(double& balance) {
		cout << "Your balance is " << balance << endl;
	}

	void showHistory(const vector<double>& transactions) {
		if (transactions.empty()) {
			cout << "No transactions yet." << endl;
			return;
		}

		cout << "Transaction history:" << endl;
		for (int i = 0; i < transactions.size(); i++) {
			cout << transactions[i] << endl;
		}
	}
	};

	int main() {

		int choice;
		char again = ' ';
		char letter = ' ';
		double balance = 985.40;
		double amt = 0.0;
		vector < double>transactions;
		BankAccount C;
		Bank B;
		do {
			welcoming();
			cin >> choice;

			if (choice == 1) {
				C.choosing(choice, letter);
				B.Deposit(letter, amt, balance, transactions);
				B.asking(balance);
			}
			else if (choice == 2) {
				B.withdraw(choice, amt, balance, transactions);
				B.asking(balance);
			}
			else if (choice == 3 || choice == 4) {
				C.Details(choice);
			}
			else if (choice == 5) {
				B.asking(balance);
			}
			else if (choice == 6) {
				B.showHistory(transactions);
			}
			else {
				cout << "Invalid choice." << endl;
			}

			cout << "Would you like to do another transaction? (Y/N): ";
			cin >> again;

		} while (again == 'Y' || again == 'y');

		cout << "Thank you for choosing Livonia Bank" << endl;

		return 0;
	}
