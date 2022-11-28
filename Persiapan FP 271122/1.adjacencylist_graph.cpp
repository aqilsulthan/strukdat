#include <iostream>
#include <list>
#include <graphics.h>


using namespace std;

// mendefiniskan class vertex
class Vertex
{
private:
    int nomor;
    int x;
    int y;
    string nama;

public:
    // membuat constructor vertex
    // constructor ini akan dijalankan secara otomatis saat objek dibuat
    Vertex(int _nomor, int _x, int _y, string _nama)
    {
        nomor = _nomor;
        x = _x;
        y = _y;
        nama = _nama;
    }

    string getNama()
    {
        return nama;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

// mendefiniskan class myGraph
class myGraph
{
private:
    int JV;                   // jumlah vertex
    list<Vertex> *infoVertex; // mendefiniskan pointer ke list vertex
                              //  yang menunjuk list dari vertex
    list<int> *adj;           // membuat pointer ke list
    // membuat konstraktor
public:
    myGraph(int jumlahvertex)
    {
        JV = jumlahvertex;
        // membuat list vertex
        infoVertex = new list<Vertex>;
        adj = new list<int>[jumlahvertex];
    }

    // membuat function sambung
    void sambung(int dari, int ke)
    {
        adj[dari].push_back(ke);
    }

    // membuat function simpan vertex
    void simpanVertex(int _nomor, int _x, int _y, string _nama)
    {
        // membuat vertex x yang akan ditambahkan ke list
        Vertex x = Vertex(_nomor, _x, _y, _nama);
        // menambhakn x ke list infoVertex
        infoVertex[0].push_back(x);
    }

    // mendapatkan vertex
    list<Vertex>::iterator getVertex(int v)
    {

        list<Vertex>::iterator vx;
        vx = infoVertex->begin();

        if (v < 0 || v >= JV)
            v = 0;

        for (int i = v; i > 0; i--)
            vx++;

        return vx;
    }

    // menampilkan edge
    void tampilEdge()
    {
        list<int> la;
        list<int>::iterator i;
        list<Vertex>::iterator asal;
        list<Vertex>::iterator tujuan;
        int x1, x2, y1, y2;
        // Vertex asal = Vertex(0, 0, 0, "");
        // Vertex tujuan = Vertex(0, 0, 0, "");

        for (int v = 0; v < JV; v++)
        {
            cout << v; // titik awal
            // mendapatkan titik awal
            asal = getVertex(v);
            x1 = asal->getX();
            y1 = asal->getY();
            for (i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                cout << "-> " << (*i); // titik tujuan
                tujuan = getVertex(*i);
                x2 = tujuan->getX();
                y2 = tujuan->getY();
                line(x1, y1, x2, y2);
            }
            cout << ("\n");
        }
    }

    // menampilkan vertex
    void tampilVertex()
    {
        list<int> la;
        list<Vertex>::iterator i;
        Vertex myV = Vertex(0, 0, 0, "");
        int x, y;
        string nama;

        initwindow(900, 700, "My Graph");

        // menampilkan vertex V
        for (i = infoVertex[0].begin(); i != infoVertex[0].end(); ++i)
        {
            char snama[80];
            nama = i->getNama();
            // sprintf(snama, "%s", nama);
            strcpy(snama, nama.c_str());
            x = i->getX();
            y = i->getY();
            circle(x , y , 20);
            outtextxy(x+20, y-30, snama);
        }

        // lakukan modifikasi di bagian setelah ini untuk menambahkan instruksi yang
        // digunakan untuk menampilkan Edge E
        tampilEdge();

        while (!kbhit())
        {
            delay(200);
        }
    }
};

int main()
{

    // membuat graph dengan jumlah 20
    myGraph g(20); // ini membuat objek dengan nmaa g berjenis graf

    // mendefinisikan vertex
    g.simpanVertex(0, 450, 420, "Rumah (0)");
    g.simpanVertex(1, 390, 600, "Gerbang Blok EF(1)");
    g.simpanVertex(2, 330, 600, "Warung Toserba Lemuel (2)");
    g.simpanVertex(3, 240, 600, "Gerbang Blok G (3)");
    g.simpanVertex(4, 180, 510, "Selera Resto (4)");
    g.simpanVertex(5, 180, 420, "KooolKost (5)");
    g.simpanVertex(6, 180, 330, "Masjid At-Taufiq (6)");
    g.simpanVertex(7, 180, 210, "Salon Beauty (7)");
    g.simpanVertex(8, 210, 90, "Bundaran Taman Sentosa (8)");
    g.simpanVertex(9, 300, 60, "Indomaret Taman Sentosa (9)");
    g.simpanVertex(10, 510, 60, "Apartemen OneSentosa (10)");
    g.simpanVertex(11, 630, 90, "Klub Sentosa (11)");
    g.simpanVertex(12, 720, 180, "Gerbang Blok C (12)");
    g.simpanVertex(13, 720, 240, "Warkop Sehati (13)");
    g.simpanVertex(14, 720, 330, "Kebun Anggur Alphabet's' (14)");
    g.simpanVertex(15, 720, 510, "Masjid Nurul Yaqin (15)");
    g.simpanVertex(16, 660, 570, "SDIT Annida (16)");
    g.simpanVertex(17, 600, 600, "SMPN 2 Cikarang Selatan (17)");
    g.simpanVertex(18, 540, 570, "Gerbang Blok F (18)");
    g.simpanVertex(19, 480, 510, "Lapangan Voli (19)");

//     membuat edge ke x
	g.sambung(0, 19);
    g.sambung(0, 1);
    g.sambung(1, 0);
    g.sambung(1, 2);
    g.sambung(2, 1);
    g.sambung(2, 3);
    g.sambung(3, 2);
    g.sambung(3, 4);
    g.sambung(4, 3);
    g.sambung(4, 5);
    g.sambung(5, 4);
    g.sambung(5, 6);
    g.sambung(6, 5);
    g.sambung(6, 7);
    g.sambung(6, 14);
    g.sambung(7, 6);
    g.sambung(7, 8);
    g.sambung(8, 7);
    g.sambung(8, 9);
    g.sambung(9, 8);
    g.sambung(9, 10);
    g.sambung(10, 9);
    g.sambung(10, 11);
    g.sambung(11, 10);
    g.sambung(11, 12);
    g.sambung(12, 11);
    g.sambung(12, 13);
    g.sambung(13, 12);
    g.sambung(13, 14);
    g.sambung(14, 6);
    g.sambung(14, 13);
    g.sambung(14, 15);
    g.sambung(15, 14);
    g.sambung(15, 16);
    g.sambung(16, 15);
    g.sambung(16, 17);
    g.sambung(17, 16);
    g.sambung(17, 18);
    g.sambung(18, 17);
    g.sambung(18, 19);
    g.sambung(19, 18);
    g.sambung(19, 0);
    
    // menampilkakn vertex
    g.tampilVertex();

    // menampilkan edge
    // g.tampilEdge();
}
