#include <iostream>
using namespace std;

int main() {
	int n, k, total;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        long t;
        cin >> t;
        if (t % k == 0)
            total++;
    }
    cout << total << endl;
	return 0;
}
