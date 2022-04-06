#include<bits/stdc++.h>
using namespace std;

void rod_cut(int price[], int n) {
    int i, j;
    int rev[n+1], cut[n+1];
    rev[0] = 0;
    for(j = 1; j <= n; j++) {
        int q = -99999;
        for(i = 1; i <= j; i++) {
            if(q < (price[i] + rev[j - i])) {
                q = price[i] + rev[j - i];
                cut[j] = i;
            }
        }
        rev[j] = q;
    }

    cout << "\n\nLength \t Revenue \tCut Point\n\n";
    for(i = 1; i <= n; i++) {
        cout << i << "\t  " << rev[i] << "\t        " << cut[i] << endl;
    }
}

int main() {
    int n, i;
    cout << "Enter length of rod : ";
    cin >> n;
    int price[n];
    cout << "\nEnter price of Rods \n\n";
    for(i = 1; i <= n; i++) {
        cout << "Enter price of length " << i << " : ";
        cin >> price[i];
    }
    rod_cut(price, n);
    return 0;
}