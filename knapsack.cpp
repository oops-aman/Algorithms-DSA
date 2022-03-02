#include<iostream>
#include<stdlib.h>
using namespace std;

struct product {
    int product_num;
    int profit;
    int weight;
    float ratio;
    float quantity;
};

void knapSack(product P[], int m, int noOfProducts) {
    int i, j;
    float maxProfit = 0;
    for(i = 0; i < noOfProducts; i++) {
        for(j = i + 1; j < noOfProducts; j++) {
            if(P[i].ratio < P[j].ratio) {
                product temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }

    for(i = 0; i < noOfProducts; i++) {
        if(m == 0) 
            break;
        else if(P[i].weight < m) {
            P[i].quantity = 1;
            m -= P[i].weight;
        }
        else if(P[i].weight > m) {
            P[i].quantity = (float) m / P[i].weight;
            m = 0;
        }
    }

    cout <<"\nProducts to be taken : " << endl;
    for(i = 0; i < noOfProducts; i++) {
        cout <<"Product " << P[i].product_num << " : " << (P[i].quantity * P[i].weight) << " Units" <<endl;
        maxProfit += P[i].profit * P[i].quantity;
    }
    cout << "\nKnapSack value is : " << maxProfit << endl;
}

int main() {
    int i, j, noOfProducts, m;
    cout << "Enter number of products : ";
    cin >> noOfProducts;
    product P[noOfProducts];
    cout << "\nEnter capacity of sack : ";
    cin >> m;
    for(i = 0; i < noOfProducts; i++) {
        P[i].product_num = i + 1;
        printf("\nProduct %d", i + 1);
        cout << "\nEnter Profit : ";
        cin >> P[i].profit;
        cout<<"Enter Weight : ";
        cin >> P[i].weight;

        P[i].ratio = (float) P[i].profit / P[i].weight;
        P[i].quantity = 0;
    }

    knapSack(P, m, noOfProducts);
    return 0;
}