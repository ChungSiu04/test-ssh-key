#include<iostream>
#include <algorithm>
#include <conio.h>
using namespace std;

//B�i 3. Cho d�y n so thuc (5=n<=20), H�y viet c�c chuong tr�nh con sau: 
// a.Sap xep d�y tr�n tang dan theo giai thuat doi cho truc tiep: inter change sort
// b. sap xep giam dan theo giai thuat chon truc tiep: selection sort
// c.Sap xep d�y tr�n theo thu tu so duong o dau d�y, so �m o cuoi d�y
// H�y viet chuong tr�nh ch�nh nhap v�o n so thuc, thuc hien c�c chuong tr�nh con o tr�n.
// Chuong tr�nh ch�nh nam trong 1 v�ng lap cho ph�p chan ph�m de tiep tuc hoac de ket th�c.


void tangdan(float a[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}


void giamdan(float a[], int n) {
	int max, i, j;
    for ( i = 0; i < n - 1; i++) {
        max = i;
        for ( j = i + 1; j < n; j++) {
            if (a[j] > a[max]) {
                max = j;
            }
        }
        swap(a[i], a[max]);
    }
}
void duongam(float a[], int n) {
int soduong = 0;
    int soam = n - 1;
    
    while (soduong < soam) {
        while (soduong < n && a[soduong] > 0) {
            soduong++;
        }
        while (soam >= 0 && a[soam] < 0) {
           soam --;
        }
        if (soduong < soam) {
            swap(a[soduong], a[soam]);
            soduong++;
        	soam--;
        }
    }
}

int main() {
    int n;
    char choice;
	
    do {
        cout << "Nhap so luong phan tu (5 <= n <= 20): ";
        cin >> n;
    } while (n < 5 || n > 20);

    float a[n];
    for (int i = 0; i < n; i++) {
    	cout<<" nhap so phan tu thu "<< i+1 << ":";
        cin >> a[i];
    }

    do {
        cout << "Chon chuc nang:\n";
        cout << "a. Sap xep day tang dan theo giai thuat doi cho truc tiep\n";
        cout << "b. Sap xep day giam dan theo giai thuat chon truc tiep\n";
        cout << "c. Sap xep day theo thu tu so duong o dau day, so am o cuoi day\n";
        cout << "Esc. Thoat\n";

        choice = getch();

        switch (choice) {
            case 'a':
               tangdan(a, n);
                break;
            case 'b':
        		giamdan(a, n);
                break;
            case 'c':
                duongam(a, n);
                break;
        }

        cout << "Day sau khi sap xep: ";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

    } while (choice != 27); // 27 l� m� ASCII c?a ph�m Esc

    return 0;
}


