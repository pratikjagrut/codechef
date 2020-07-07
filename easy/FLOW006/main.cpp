#include <iostream>
using namespace std;

int main() {
	int t, n, sum;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        sum=0;
        while (n > 0)
        {
            int digit = n % 10;
            n = n / 10;
            sum += digit;
        }
        cout << sum << endl;
    }
	return 0;
}
