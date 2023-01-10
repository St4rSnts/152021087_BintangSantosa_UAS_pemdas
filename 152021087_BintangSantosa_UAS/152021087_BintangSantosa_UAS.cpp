#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Fungsi Mencari sigmaX
float MencariX(int SX[], int n)
{
    float hasilSX = 0;
    int i = 0;
    while(i < n){
        hasilSX += SX[i];
        i++;
    }
    return hasilSX;
}
// Fungsi Mencari sigmaY
float  MencariY(int SY[], int n)
{
    float hasilY = 0;
    int i = 0;
    while(i < n){
        hasilY += SY[i];
        i++;
    }
    return hasilY;
}
// Fungsi Mencari SigmaXY
float MencariXY(int SY1[], int SY2[], int n)
{
    float hasilSY1SY2 = 0;
    int i = 0;
    while(i < n){
        hasilSY1SY2 += SY1[i] * SY2[i];
        i++;
    }
    return hasilSY1SY2;
}
// Fungsi Mencari X kuadrat
float MencariX2(int SXKuadrat2[], int n)
{
    float hasilSXKuadrat2 = 0, hasilSXKuadrat = 0;
    int i = 0;
    while(i < n){
        hasilSXKuadrat2 += pow(SXKuadrat2[i],2);
        i++;
    }
    hasilSXKuadrat += hasilSXKuadrat2;
    return hasilSXKuadrat;
}
// Fungsi Mencari Y Kuadrat
float MencariY2(int SYkuadrat2[], int n)
{
    float hasilSYKuadrat2 = 0;
    int i = 0;
    while(i < n){
        hasilSYKuadrat2 += pow(SYkuadrat2[i],2);
        i++;
    }
    return hasilSYKuadrat2;
}
// Fungsi Mencari Korelasi Pearson
float MencariR(int x, int y, int xy, int xkuadrat2, float ykuadrat2, int n){
    float korelasipearson;
    korelasipearson = (n * xy - x * y) / sqrt((n * xkuadrat2 - x * x)* (n * ykuadrat2 - y * y));
    return korelasipearson;
}
//  Fungsi Mencari Koefisien Determinasi
float MencariKoefisienDeterminasi(float korelasi){
    float KoefisienDeterminasi;
    KoefisienDeterminasi = pow(korelasi,2) * 1;
    return KoefisienDeterminasi;
}
int main(){
    int data1[100],data2[100],j,i;
    float NilaiX,NilaiY,NilaiXkaliY,NilaiXpangkat2,NilaiYpangkat2,NilaiR,NilaiKoefisienDeterminasi;
    system("cls");
    cout << "===================== Korelasi ====================\n";
    cout<<"Masukkan jumlah data : ";cin >> j;
    i = 0;
    cout << "===================================================\n";
    while(i < j){
        cout<<"Masukkan nilai X ke-"<< i+1 << " : ";cin >> data1[i];
        cout<<"Masukkan nilai y ke-"<< i+1 << " : ";cin >> data2[i];
        i++;
    }
    // Memanggil Fungsi Mencari X
    NilaiX = MencariX(data1, j);
    // Memanggil Fungsi Mencari Y
    NilaiY = MencariY(data2, j);
    // Memanggil Fungsi Mencari X * Y
    NilaiXkaliY = MencariXY(data1, data2,j);
    // Memanggil Fungsi Mencari X Pangkat 2
    NilaiXpangkat2 = MencariX2(data1,j);
    // Memanggil Fungsi Mencari Y Pangkat 2
    NilaiYpangkat2 = MencariY2(data2,j);
    // Memanggil Fungsi Mencari R
    NilaiR = MencariR(NilaiX, NilaiY,NilaiXkaliY,NilaiXpangkat2,NilaiYpangkat2,j);
    // Memanggil Fungsi Mencari Koefisien Determinasi
    NilaiKoefisienDeterminasi = MencariKoefisienDeterminasi(NilaiR);
    // Output
    cout << "===================================================\n";
    cout << "Hasil nilai X : " << NilaiX;
    cout << "\nHasil nilai Y : " << NilaiY;
    cout << "\nHasil nilai X * Y : " << setprecision(2) << NilaiXkaliY;
    cout << "\nHsil X pangkat 2 : " << setprecision(2) << NilaiXpangkat2;
    cout << "\nHasil Y pangkat 2 : " << setprecision(2) << NilaiYpangkat2;
    cout << "\nhasil R : " << setprecision(2) << NilaiR;
    cout << "\nhasil Koefisien Determinasi : " << setprecision(2) << NilaiKoefisienDeterminasi;
    cout << "\n===================================================\n";
    if(NilaiR == 0){
        cout << "Tidak ada hubungan antara variable X dan Y\n";
        cout << "===================================================\n";
    }
    else if((NilaiR >= 0.00)&(NilaiR <= 0.09)){
        cout << "\nHubungan Korelasi Diabaikan\n";
        cout << "Hubungan antara variable X dan Y adalah positif, dimana jika nilai x bertambah, maka nilai Y pun bertambah dan juga sebaliknya\n";
        cout << "===================================================\n";
    }
    else if((NilaiR >= -0.09)&(NilaiR <= -0.00)){
        cout << "Hubungan antara variable X dan Y adalah negatif, dimana jika nilai x akan bertambah, maka nilai Y akan mengecil dan juga sebaliknya\n";
        cout << "===================================================\n";
    }
    else if((NilaiR >= 0.10)&(NilaiR <= 0.29)){
        cout << "Hubungan Korelasi Rendah\n";
        cout << "Hubungan antara variable X dan Y adalah positif, dimana jika nilai x bertambah, maka nilai Y pun bertambah dan juga sebaliknya\n";
        cout << "===================================================\n";
    }
    else if((NilaiR >= -0.29)&(NilaiR <= -0.10)){
        cout << "Hubungan antara variable X dan Y adalah negatif, dimana jika nilai x bertambah, maka nilai Y akan mengecil dan juga sebaliknya\n";
        cout << "===================================================\n";
    }
    else if((NilaiR >= 0.30)&(NilaiR <= 0.49)){
        cout << "Hubungan Korelasi Moderat\n";
        cout << "Hubungan antara variable X dan Y adalah positif, dimana jika nilai x bertambah, maka nilai Y pun bertambah dan juga sebaliknya\n";
        cout << "===================================================\n";
    }
    else if((NilaiR >= -0.49)&(NilaiR <= -0.30)){
        cout << "Hubungan antara variable X dan Y adalah negatif, dimana jika nilai x bertambah, maka nilai Y akan mengecil dan juga sebaliknya\n";
        cout << "===================================================\n";
    }
    else if((NilaiR >= 0.50)&(NilaiR <= 0.70)){
        cout << "Hubungan Korelasi Sedang\n";
        cout << "Hubungan antara variable X dan Y adalah positif, dimana jika nilai x bertambah, maka nilai Y pun bertambah dan juga sebaliknya\n";
        cout << "===================================================\n";
    }
    else if((NilaiR >= -0.70)&(NilaiR <= -0.50)){
        cout << "Hubungan antara variable X dan Y adalah negatif, dimana jika nilai x bertambah, maka nilai Y akan mengecil dan juga sebaliknya\n";
        cout << "===================================================\n";
    }
    else if(NilaiR >= 0.70){
        cout << "Hubungan Korelasi Kuat\n";
        cout << "Hubungan antara variable X dan Y adalah positif, dimana jika nilai x bertambah, maka nilai Y pun bertambah dan juga sebaliknya\n";
        cout << "===================================================\n";
    }
    else if(NilaiR <= -0.70){
        cout << "Hubungan antara variable X dan Y adalah negatif, dimana jika nilai x bertambah, maka nilai Y akan mengecil dan juga sebaliknya\n";
        cout << "===================================================\n";
    }

    return 0;
}