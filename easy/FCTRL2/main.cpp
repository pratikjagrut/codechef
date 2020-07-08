#include<iostream>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while (t > 0)
    {
        int a[200], array_size = 1;
        a[0] = 1;
        cin >> n;
        for (int i = 2; i <= n; i++)
        {   
            int carry = 0;
            for (int j = 0; j < array_size; j++)
            {
                int x = a[j] * i + carry;
                a[j] = x % 10;
                carry = x / 10;
            }

            while (carry)
            {
                a[array_size] = carry % 10;
                carry = carry / 10;
                array_size++;
            }
        }
        for (int i = array_size - 1; i >= 0; i--)
        {
            cout << a[i];
        }

        cout << endl;
        t--;
    }
    
}