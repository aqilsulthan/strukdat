#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct pelanggan
{
    int noPembeli;
    char nama[10];
    char menu[15];
    float total;
};

int main(){
    pelanggan plg;
    int i;
    struct pelanggan jumlah[19];
    
    jumlah[0].noPembeli=1;
    strcpy(jumlah[0].nama, "Sulthan");
    strcpy(jumlah[0].menu, "Ayam Bakar");
    jumlah[0].total=15000;
    
    jumlah[1].noPembeli=2;
    strcpy(jumlah[1].nama, "Bedul");
    strcpy(jumlah[1].menu, "Sapi Bakar");
    jumlah[1].total=25000;
    
    jumlah[2].noPembeli=3;
    strcpy(jumlah[2].nama, "Toni");
    strcpy(jumlah[2].menu, "Ikan Goreng");
    jumlah[2].total=20000;

    jumlah[3].noPembeli=4;
    strcpy(jumlah[3].nama, "Rifki");
    strcpy(jumlah[3].menu, "Sate Kambing");
    jumlah[3].total=27000;

    jumlah[4].noPembeli=5;
    strcpy(jumlah[4].nama, "Fitra");
    strcpy(jumlah[4].menu, "Siomay Bakar");
    jumlah[4].total=17000;

    jumlah[5].noPembeli=6;
    strcpy(jumlah[5].nama, "Faiq");
    strcpy(jumlah[5].menu, "Jeroan Saus Tiram");
    jumlah[5].total=16000;

    jumlah[6].noPembeli=7;
    strcpy(jumlah[6].nama, "Andi");
    strcpy(jumlah[6].menu, "Kerang Balado");
    jumlah[6].total=18000;

    jumlah[7].noPembeli=8;
    strcpy(jumlah[7].nama, "Faisal");
    strcpy(jumlah[7].menu, "Sapi Bakar");
    jumlah[7].total=25000;

    jumlah[8].noPembeli=9;
    strcpy(jumlah[8].nama, "Donny");
    strcpy(jumlah[8].menu, "Kerang Balado");
    jumlah[8].total=18000;

    jumlah[9].noPembeli=10;
    strcpy(jumlah[9].nama, "Hanifa");
    strcpy(jumlah[9].menu, "Siomay Bakar");
    jumlah[9].total=17000;

    jumlah[10].noPembeli=11;
    strcpy(jumlah[10].nama, "Yoga");
    strcpy(jumlah[10].menu, "Sate Kambing");
    jumlah[10].total=27000;

    jumlah[11].noPembeli=12;
    strcpy(jumlah[11].nama, "Tulus");
    strcpy(jumlah[11].menu, "Kerang Balado");
    jumlah[11].total=18000;

    jumlah[12].noPembeli=13;
    strcpy(jumlah[12].nama, "Raihan");
    strcpy(jumlah[12].menu, "Bubur Manado");
    jumlah[12].total=14000;

    jumlah[13].noPembeli=14;
    strcpy(jumlah[13].nama, "Fikri");
    strcpy(jumlah[13].menu, "Ayam Geprek");
    jumlah[13].total=19000;

    jumlah[14].noPembeli=15;
    strcpy(jumlah[14].nama, "Bejo");
    strcpy(jumlah[14].menu, "Soto Lamongan");
    jumlah[14].total=16000;

    jumlah[15].noPembeli=16;
    strcpy(jumlah[15].nama, "Tio");
    strcpy(jumlah[15].menu, "Ayam Geprek");
    jumlah[15].total=19000;

    jumlah[16].noPembeli=17;
    strcpy(jumlah[16].nama, "Budi");
    strcpy(jumlah[16].menu, "Bakso Urat");
    jumlah[16].total=15000;

    jumlah[17].noPembeli=18;
    strcpy(jumlah[17].nama, "Koko");
    strcpy(jumlah[17].menu, "Sop Buntut");
    jumlah[17].total=14000;

    jumlah[18].noPembeli=19;
    strcpy(jumlah[18].nama, "Bahari");
    strcpy(jumlah[18].menu, "Bakso Telur");
    jumlah[18].total=16000;

    jumlah[19].noPembeli=20;
    strcpy(jumlah[19].nama, "Tulus");
    strcpy(jumlah[19].menu, "Ayam Mozzarela");
    jumlah[19].total=20000;

    for(i=0; i<20; i++){
        cout<<"No. Pembeli: "<<i+1<<endl;
        cout<<"Nama Pembeli: "<<jumlah[i].nama<<endl;
        cout<<"Menu Pesanan: "<<jumlah[i].menu<<endl;
        cout<<"Total: "<<jumlah[i].total<<endl;
        cout<<endl;
    }
}