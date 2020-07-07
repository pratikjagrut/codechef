#include <iostream>
using namespace std;

int main() {
	int amount;
    float balance;
    cin >> amount;
    cin >> balance;
    if (amount % 5 == 0 && (amount+0.5) <= balance)
        printf("%.2f", (balance-amount-0.5));
    else
        cout << balance;
    
	return 0;
}
