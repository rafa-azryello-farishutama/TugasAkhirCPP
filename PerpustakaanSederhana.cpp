#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct anggota{
    string idanggota;
    string nama;
    string alamat;
    int tanggal;
    int bulan;
    int tahun;
    string email;
    int status;
};

struct buku{
    string idbuku;
    string isbn;
    string judul;
    string pengarang;
    string penerbit;
    int tahunTerbit;
    int stok;
};

struct petugas{

};

int HitungUrutan(string Tahun,string Bulan,string Tanggal){
    ifstream file("anggota.txt"); 
    string line;
    int count = 0;
    string pencarian = Tahun + Bulan + Tanggal;

    while (getline(file, line)) { 
        if (line.find(pencarian) != string::npos) { 
            count++; 
        }
    }

    file.close();
    return count + 1; 
}


void TambahAnggota(){

anggota x;
while(true){
    cout << "Masukkan ID Anggota : ";
    getline(cin,x.idanggota);

    if(x.idanggota.length() > 6){
        cout << "ID Anggota hanya bisa berjumlah 6 Digit!" << endl;
    }
    else if(x.idanggota.length() == 0){
        cout << "ID Anggota tidak kosong!" << endl;
    }
    else{
        break;
    }
}
    cout << "Masukkan Nama : ";
    getline(cin,x.nama);
    cout << "Masukkan Alamat : ";
    getline(cin,x.alamat);
    cout << "Masukkan Tanggal Lahir : ";
    cin >> x.tanggal;
    cout << "Masukkan Bulan Lahir : ";
    cin >> x.bulan;
    cout << "Masukkan Tahun Lahir : ";
    cin >> x.tahun;
    cout << "Masukkan Email : ";
    cin.ignore();
    getline(cin,x.email);
    cout << "Apakah Siswa masih aktif (1=aktif, 0=tidak aktif) : ";
    cin >> x.status;

    string strTahun = to_string(x.tahun);

    string strBulan, strTanggal;
    if (x.bulan < 10) {
        strBulan = "0" + to_string(x.bulan);
    }
    else {
        strBulan=to_string(x.bulan);
    }

    if(x.tanggal < 10) {
        strTanggal = "0" + to_string(x.tanggal);
    }
    else{
        strTanggal = to_string(x.tanggal);
    }

    int urutan= HitungUrutan(strTahun,strBulan,strTanggal);

    string urutanString = to_string(urutan); 
    while (urutanString.length() < 3) {
    urutanString = "0" + urutanString;
}
string kodeanggota = strTahun + strBulan + strTanggal + urutanString;

ofstream fileOutput("anggota.txt",ios::app);
fileOutput << x.idanggota << ";"<< kodeanggota << ";" << x.nama << ";" << x.tanggal << "-" << x.bulan << 
             "-" << x.tahun << ";" << x.alamat << ";" << x.email << ";" << x.status<<endl;
fileOutput.close();
cout << "Data Siswa berhasil ditambahkan!";

}

void TambahBuku(){
    buku a;
    cout << "Judul Buku : ";
    getline(cin,a.judul);
    
    while(true) {
    cout << "ID Buku : ";
    getline(cin,a.idbuku);

    if(a.idbuku.length() > 6){
        cout << "ID Buku harus berjumlah 6 Digit" << endl;
    }
    else if(a.idbuku.length() == 0){
        cout << "ID Buku tidak boleh kosong!" << endl;
    }
    else{
        break;
    }
}

while(true) {
    cout << "ISBN : ";
    getline(cin,a.isbn);

    if(a.isbn.length() > 13){
        cout << "ISBN harus berjumlah 13 Digit!" << endl;
    }
    else if(a.isbn.length() == 0){
        cout << "ISBN tidak boleh kosong!" << endl;
    }
    else{
        break;
    }
}
    cout << "Pengarang : ";
    getline(cin,a.pengarang);
    cout << "Penerbit : ";
    getline(cin,a.penerbit);
    cout << "Tahun Terbit : ";
    cin.ignore();
    cin >> a.tahunTerbit;
    cout << "Stok Awal : ";
    cin >> a.stok;

    ofstream fileOutput("buku.txt",ios::app);
    fileOutput << a.idbuku << ";" << a.isbn << ";" << a.judul << ";" << a.pengarang 
               << ";" << a.penerbit << ";" << a.tahunTerbit << ";" << a.stok << endl;
    fileOutput.close();
    cout << "Data Buku berhasil ditambahkan!";

}

void CariAnggota() {
    string katakunci;
    cout << "Masukkan Anggota Kode : ";
    getline(cin,katakunci);

    ifstream fileOutput("anggota.txt");
    string line;
    while(getline(fileOutput,line)){
        if(line.find(katakunci)!= string::npos){
            cout << "Data Ditemukan : " << line;

            fileOutput.close();
            return;
        }
    }
    cout << "Data tidak ditemukan!";
    fileOutput.close();
}

int main(){
    TambahBuku();
}


