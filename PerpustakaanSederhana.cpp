#include <iostream>
#include <fstream>
#include <string>
#include <limits>
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
    string idpetugas;
    string username;
    string password;
    string nama;
    int noadmin;
    string status;
};

string idLoginSiswa = "";

int HitungUrutan(string Tahun,string Bulan,string Tanggal){
    ifstream file("anggota.txt"); 
    if (file.is_open()){
    }
    else {
    }
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

int MenghasilkanID(){
    ifstream file("anggota.txt");
    if (file.is_open()){
    }
    else {
    }
    string line;
    int count = 0;

    while(getline(file,line)){
        count++;
    }
    file.close();
    return count+1;
}

int MenghasilkanIDbuku(){
    ifstream file("buku.txt");
    if (file.is_open()){
    }
    else {
    }
    string line;
    int count = 0;

    while(getline(file,line)){
        count++;
    }
    file.close();
    return count+1;
}

void TambahAnggota(){    
anggota x;
cout << endl;
cout << "Masukkan Nama : ";
getline(cin,x.nama);
cout << "Masukkan Alamat : ";
getline(cin,x.alamat);

while(true){
    cout << "Masukkan Tahun : ";
    cin >> x.tahun;
    if(x.tahun>2025) {
        cout << "Tolong memilih Tahun yang benar"<<endl;
        }
    else{
        break;
    }
}

while(true){
    cout << "Masukkan Bulan : ";
    cin >> x.bulan;
    if(x.bulan>12){
        cout << "Tolong memilih bulan yang benar"<<endl;
    }
    else if(x.bulan == 0){
        cout << "Bulan tidak boleh kosong" << endl;
    }
    else{
        break;
    }
}

if(x.bulan == 1 || x.bulan == 3 || x.bulan == 5 || x.bulan == 7 ||
   x.bulan == 8 || x.bulan == 10 || x.bulan == 12 ){
    while(true){
        cout << "Masukkan Tanggal : ";
        cin >> x.tanggal;

        if(x.tanggal > 31){
            cout << "Tanggal Tidak boleh melebihi batas bulan" << endl;
        }
        else if(x.tanggal == 0){
            cout << "Tanggal Tidak boleh kosong" << endl;
        }
        else{
            break;
        }
    }
}

if(x.bulan == 4 || x.bulan == 6 || x.bulan == 9 || x.bulan == 11){
    while(true){
        cout << "Masukkan Tanggal : ";
        cin >> x.tanggal;

        if(x.tanggal > 30){
            cout << "Tanggal tidak boleh melebihi batas bulan" << endl;
        }
        else if(x.tanggal == 0){
            cout << "Tanggal tidak boleh kosong" << endl;
        }
        else{
            break;
        }


    }
}

if(x.bulan == 2){
    if((x.tahun%400 == 0) || (x.tahun%4==0 && x.tahun%100!=0)){
        while(true){
            cout << "Masukkan Tanggal : ";
            cin >> x.tanggal;

            if(x.tanggal > 29){
                cout << "Tanggal tidak boleh melebihi batas bulan" << endl;
            }
            else if(x.tanggal == 0){
                cout << "Tanggal tidak boleh kosong";
            }
            else{
                break;
            }
        }

            
    }
    else{
        while(true){
        cout << "Masukkan Tanggal : ";
        cin >> x.tanggal;

        if(x.tanggal > 28){
            cout << "Tanggal tidak boleh melebihi batas" << endl;
            }
        else if(x.tanggal == 0){
            cout << "Tanggal tidak boleh kosong";
            }
        else{
            break;
            }
        }
    }
}
    
cout << "Masukkan Email : ";
cin.ignore();
getline(cin,x.email);
x.status = 1;

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

int nomorID=MenghasilkanID();

string id=to_string(nomorID);
while(id.length() < 6){
    id = "0" + id; 
}

x.idanggota = id;

ofstream fileOutput("anggota.txt",ios::app);
if (fileOutput.is_open()){
    }
    else {
    }
fileOutput << x.idanggota << ";"<< kodeanggota << ";" << x.nama << ";" << x.tanggal << "-" << x.bulan << 
             "-" << x.tahun << ";" << x.alamat << ";" << x.email << ";" << x.status<<endl;
fileOutput.close();
cout << "Data Siswa berhasil ditambahkan!";

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Menu Kembali (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;;
}

void TambahBuku(){
    buku a;
    cout << "Judul Buku : ";
    getline(cin,a.judul);
    while(true){
        cout << "Masukkan ISBN : ";
        getline(cin,a.isbn);

        if(a.isbn.length() > 13){
            cout << "Digit harus berjumlah 13" << endl;
        }
        else if(a.isbn.length() < 13){
            cout << "Digit harus berjumlah 13" << endl;
        }
        else if(a.isbn.length() == 0){
            cout << "ISBN tidak boleh kosong" << endl;
        }
        else{
            break;
        }
    }

    cout << "Pengarang : ";
    getline(cin,a.pengarang);
    cout << "Penerbit : ";
    getline(cin,a.penerbit);
    cin.ignore();
while(true){
    cout << "Tahun Terbit : ";
    cin >> a.tahunTerbit;

    if(a.tahunTerbit > 2025){
        cout << "Tahun tidak boleh melebihi 2025!" << endl;
    }
    else{
        break;
    }
}

int nomorIDbuku=MenghasilkanIDbuku();

string idBuku=to_string(nomorIDbuku);
while(idBuku.length() < 4){
    idBuku = "0" + idBuku; 
}

a.idbuku = "BK" + idBuku;

    cout << "Stok Awal : ";
    cin >> a.stok;

    ofstream fileOutput("buku.txt",ios::app);
    if (fileOutput.is_open()){
    }
    else {
    }
    fileOutput << a.idbuku << ";" << a.isbn << ";" << a.judul << ";" << a.pengarang 
               << ";" << a.penerbit << ";" << a.tahunTerbit << ";" << a.stok << endl;
    fileOutput.close();
    cout << "Data Buku berhasil ditambahkan!" << endl;

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Menu Kembali (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}


int MenghasilkanIDadmin(){
    ifstream file("petugas.txt");
    if (file.is_open()){
    }
    else {
    }
    string line;
    int count = 0;

    while(getline(file,line)){
        count++;
    }
    file.close();
    return count+1;
}

void TambahAdmin(){
    petugas b;
    cout << "Masukkan Username : ";
    getline(cin,b.username);
    cout << "Masukkan Nama Lengkap Petugas : ";
    getline(cin,b.nama);
    cout << "Buat Password : ";
    getline(cin,b.password);
    b.noadmin = 0;
    b.status = "AKTIF";
    int ID = MenghasilkanIDadmin();
    string nomer = to_string(ID); 
    while (nomer.length() < 4) {
        nomer = "0" + nomer;
    }
    b.idpetugas = "AD" + nomer;



    ofstream fileOutput("petugas.txt",ios::app);
    fileOutput << b.idpetugas << ";" << b.username << ";" << b.noadmin << ";"
               << b.password << ";" << b.nama << ";" << b.status << endl;
    fileOutput.close();
    cout << "Data Admin berhasil ditambahkan!" << endl;

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Menu Kembali (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}


void CariAnggota() {
    string katakunci;
    cout << "Masukkan Anggota Kode : ";
    getline(cin,katakunci);

    ifstream fileOutput("anggota.txt");
    if (fileOutput.is_open()){
    }
    else {
    }
    string line;
    while(getline(fileOutput,line)){
        if(line.find(katakunci)!= string::npos){
            int posisi1 = line.find(';');
            int posisi2 = line.find(';',posisi1 + 1);
            int posisi3 = line.find(';',posisi2 + 1);
            int posisi4 = line.find(';',posisi3 + 1);
            int posisi5 = line.find(';',posisi4 + 1);
            int posisi6 = line.find(';',posisi5 + 1);

            string id = line.substr(0,posisi1);
            string kode = line.substr(posisi1 + 1, posisi2-posisi1-1);
            string nama = line.substr(posisi2 + 1, posisi3-posisi2-1);
            string tanggal = line.substr(posisi3 + 1, posisi4-posisi3-1);
            string alamat = line.substr(posisi4 + 1, posisi5-posisi4-1);
            string email = line.substr(posisi5 + 1, posisi6-posisi5-1);
            string status = line.substr(posisi6 + 1);

            cout << "Data dari siswa yang dicari" << endl;
            cout << "Nama : " << nama << endl;
            cout << "ID Anggota : "<<id<<endl;
            cout << "Kode Anggota : "<<kode<<endl;
            cout << "Tanggal : "<<tanggal<<endl;
            cout << "Alamat : "<<alamat<<endl;
            cout << "Email : "<<email<<endl;
            cout << "Status Siswa : "<<status<<endl;
            fileOutput.close();
            return;
        }
    }
    cout << "Data tidak ditemukan!";
    fileOutput.close();

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Menu Kembali (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}

void CariBuku(){
    string katakunci;
    cout << "Masukkan Judul Buku : ";
    getline(cin,katakunci);

    ifstream file("buku.txt");
    if (file.is_open()){
    }
    else {
    }
    string line;
    while(getline(file,line)){
        if(line.find(katakunci)!=string::npos){
            int posisi1 = line.find(';');
            int posisi2 = line.find(';',posisi1 + 1);
            int posisi3 = line.find(';',posisi2 + 1);
            int posisi4 = line.find(';',posisi3 + 1);
            int posisi5 = line.find(';',posisi4 + 1);
            int posisi6 = line.find(';',posisi5 + 1);

            string id = line.substr(0,posisi1);
            string isbn = line.substr(posisi1+1, posisi2-posisi1-1);
            string nama = line.substr(posisi2+1,posisi3-posisi2-1);
            string pengarang = line.substr(posisi3+1,posisi4-posisi3-1);
            string penerbit = line.substr(posisi4+1,posisi5-posisi4-1);
            string tahunTerbit = line.substr(posisi5+1,posisi6-posisi5-1);
            string stok = line.substr(posisi6+1);

            cout << "Nama : " << nama << endl;
            cout << "Pengarang : "<<pengarang << endl;
            cout << "ID Buku : " << id << endl;
            cout << "ISBN : "<<isbn<<endl;
            cout << "Penerbit : "<<penerbit<<endl;
            cout << "Tahun Terbit : "<<tahunTerbit<<endl;
            cout << "Stok : "<<stok << endl << endl;
            file.close();
            return;
        }
    }
    cout << "Data tidak ditemukan!";
    file.close();

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Menu Kembali (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}


struct peminjaman{
    int tanggalPinjam;
    int bulanPinjam;
    int tahunPinjam;
    int tanggalKembali;
    int bulanKembali;
    int tahunKembali;
    string idpeminjaman;
    int status;
    int denda;
};

int MenghasilkanIDpeminjaman(){
    ifstream file("peminjaman.txt");
    if (file.is_open()){
    }
    else {
    }
    string line;
    int count = 0;

    while(getline(file,line)){
        count++;
    }
    file.close();
    return count+1;
}

void UpdateStok(string idbuku){
    ifstream file("buku.txt");
    ofstream temp("temporarybuku.txt");

    string line;
    bool ketemu = false;

    while(getline(file,line)){
        int pos1 = line.find(';');
        int pos2 = line.find(';',pos1+1);
        int pos3 = line.find(';',pos2+1);
        int pos4 = line.find(';',pos3+1);
        int pos5 = line.find(';',pos4+1);
        int pos6 = line.find(';',pos5+1);

        string id = line.substr(0,pos1);
        string isbn = line.substr(pos1+1,pos2-pos1-1);
        string nama = line.substr(pos2+1,pos3-pos2-1);
        string pengarang = line.substr(pos3+1,pos4-pos3-1);
        string penerbit = line.substr(pos4+1,pos5-pos4-1);
        string tahunTerbit = line.substr(pos5+1,pos6-pos5-1);
        string stokString = line.substr(pos6+1);

        if(id==idbuku){
            int stok = stoi(stokString);

            if(stok>0) stok--;
            ketemu = true;

            temp << id << ";" << isbn << ";" << nama << ";"
                 << pengarang << ";" << penerbit << ";" << 
                 tahunTerbit << ";" << stok << endl;
        } else {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("buku.txt");
    rename("temporarybuku.txt", "buku.txt");

    if(ketemu){
        cout << "Stok Buku " << idbuku << " berhasil dikurangi 1" << endl << endl;
    } else {
        cout << "ID buku tiddak ditemukan!" << endl;
    }
}

void Peminjaman(){
    peminjaman m;
    string idanggota,idbuku;
    while(true){ 
    cout << "Masukkan ID Anggota: ";
    getline(cin,idanggota);

    ifstream file("anggota.txt");
    if (file.is_open()){
    }
    else {
    }
    string line;
    bool found = false;
    bool aktif = false;
    while(getline(file,line)){
        int nomor1 = line.find(';');
        string ID = line.substr(0,nomor1);
        if(ID == idanggota){
            found = true;
            int nomor2 = line.find(';',nomor1+1);
            int nomor3 = line.find(';',nomor2+1);
            int nomor4 = line.find(';',nomor3+1);
            int nomor5 = line.find(';',nomor4+1);
            int nomor6 = line.find(';',nomor5+1);

            string statusSiswa = line.substr(nomor6+1);
            int statusFinal = stoi(statusSiswa);
            if(statusFinal == 1){
                aktif = true;
            } else if(statusFinal == 0){
                cout << "Akun Siswa tidak aktif!" << endl; 
            }
            break;


        }
    }
    file.close();

    if(!found){
        cout << "ID Anggota tidak ditemukan!" << endl;
        continue;
     }
     if(aktif){
        break;
     } else {
    cout << "Akun Siswa tidak aktif!" << endl;
    continue;
}
    }
    

    while(true){
        cout << "Masukkan ID Buku : ";
        getline(cin,idbuku);

        ifstream File("buku.txt");
        if (File.is_open()){
    }
    else {
    }
        string baris;
        bool found = false;
        bool tersedia = false;
        while(getline(File,baris)){
            int pos1 = baris.find(';');
            string idBuku = baris.substr(0,pos1);
            if(idBuku == idbuku){
                found = true;
                int pos2 = baris.find(';',pos1+1);
                int pos3 = baris.find(';',pos2+1);
                int pos4 = baris.find(';',pos3+1);
                int pos5 = baris.find(';',pos4+1);

                string cekStok = baris.substr(pos5+1);
                int stok = stoi(cekStok);
                if(stok>0){
                    tersedia = true;
                } else if(stok==0){
                    cout << "Buku tidak tersedia!" << endl;
                }
                break;
                
            }
        }
        File.close();

    if(!found){
        cout << "ID Buku tidak ditemukan!" << endl;
        continue;
     }

     if(!tersedia){
        continue;
     }
     break;
    }
    

    cout << endl << "Masukkan Tanggal Pinjam" << endl;
    while(true){
    cout << "Masukkan Tahun : ";
    cin >> m.tahunPinjam;
    if(m.tahunPinjam>2025) {
        cout << "Tolong jangan melebihi batas Tahun"<<endl;
       }
    else if(m.tahunPinjam==0){
        cout << "Tolong jangan mengkosongi tahun"<<endl;
       }   
    else{
        break;
    }
}

while(true){
    cout << "Masukkan Bulan : ";
    cin >> m.bulanPinjam;
    if(m.bulanPinjam>12){
        cout << "Tolong memilih bulan yang benar"<<endl;
    }
    else if(m.bulanPinjam == 0){
        cout << "Bulan tidak boleh kosong" << endl;
    }
    else{
        break;
    }
}

if(m.bulanPinjam == 1 || m.bulanPinjam == 3 || m.bulanPinjam == 5 || m.bulanPinjam == 7 ||
   m.bulanPinjam == 8 || m.bulanPinjam == 10 || m.bulanPinjam == 12 ){
    while(true){
        cout << "Masukkan Tanggal : ";
        cin >> m.tanggalPinjam;

        if(m.tanggalPinjam > 31){
            cout << "Tanggal Tidak boleh melebihi batas bulan" << endl;
        }
        else if(m.tanggalPinjam == 0){
            cout << "Tanggal Tidak boleh kosong" << endl;
        }
        else{
            break;
        }
    }
}

if(m.bulanPinjam == 4 || m.bulanPinjam == 6 || m.bulanPinjam == 9 || m.bulanPinjam == 11){
    while(true){
        cout << "Masukkan Tanggal : ";
        cin >> m.tanggalPinjam;

        if(m.tanggalPinjam > 30){
            cout << "Tanggal tidak boleh melebihi batas bulan" << endl;
        }
        else if(m.tanggalPinjam == 0){
            cout << "Tanggal tidak boleh kosong" << endl;
        }
        else{
            break;
        }


    }
}

if(m.bulanPinjam == 2){
    if((m.tahunPinjam%400 == 0) || (m.tahunPinjam%4==0 && m.tahunPinjam%100!=0)){
        while(true){
            cout << "Masukkan Tanggal : ";
            cin >> m.tanggalPinjam;

            if(m.tanggalPinjam > 29){
                cout << "Tanggal tidak boleh melebihi batas bulan" << endl;
            }
            else if(m.tanggalPinjam == 0){
                cout << "Tanggal tidak boleh kosong";
            }
            else{
                break;
            }
        }

            
    }
    else{
        while(true){
        cout << "Masukkan Tanggal : ";
        cin >> m.tanggalPinjam;

        if(m.tanggalPinjam > 28){
            cout << "Tanggal tidak boleh melebihi batas" << endl;
            }
        else if(m.tanggalPinjam == 0){
            cout << "Tanggal tidak boleh kosong";
            }
        else{
            break;
            }
        }
    }
}

m.tanggalKembali = m.tanggalPinjam;
m.bulanKembali = m.bulanPinjam;
m.tahunKembali = m.tahunPinjam;

int hariBulan;

if(m.bulanKembali == 1 || m.bulanKembali == 3 || m.bulanKembali == 5 || m.bulanKembali == 7 ||
   m.bulanKembali == 8 || m.bulanKembali == 10 || m.bulanKembali == 12 ){
    hariBulan = 31;
   }
else if(m.bulanKembali == 4 || m.bulanKembali == 6 || m.bulanKembali == 9 || m.bulanKembali == 11){
    hariBulan = 30;
}
else{
    if((m.tahunKembali%400 == 0) || (m.tahunKembali%4==0 && m.tahunKembali%100!=0)){
        hariBulan = 29;
    }
    else{
        hariBulan = 28;
    }
}

m.tanggalKembali = m.tanggalKembali + 7;

if(m.tanggalKembali > hariBulan){
    m.tanggalKembali = m.tanggalKembali - hariBulan;
    m.bulanKembali = m.bulanKembali + 1;
    if(m.bulanKembali > 12){
        m.bulanKembali = 1;
        m.tahunKembali = m.tahunKembali + 1;
    }
}

int nomorReq=MenghasilkanIDpeminjaman();

string req=to_string(nomorReq);
while(req.length() < 4){
    req = "0" + req; 
}

string angka = "PM" + req;
int status = 1;

    ofstream fileOutput("Peminjaman.txt",ios::app);
    if (fileOutput.is_open()){
    }
    else {
    }
fileOutput << angka << ";" << idbuku << ";"<< idanggota << ";" << m.tanggalPinjam << "-" << m.bulanPinjam <<
             "-" << m.tahunPinjam << ";" << m.tanggalKembali << "-" << m.bulanKembali << "-" <<
             m.tahunKembali << ";" << status << endl;
cout << "Request telah dikirim!" << endl;
fileOutput.close();

UpdateStok(idbuku);

string nol;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
while(true){
    cout << "Menu Kembali (ketik 0) : ";
    getline(cin,nol);
    if(nol == "0"){
    break;
    } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
}
system("cls");
return;
    }

void UpdateStokTambah(string idBuku){
    ifstream buku("buku.txt");
    ofstream sementara("temporarybuku.txt");

    string garis;
    bool ketemu = false;

    while(getline(buku,garis)){
        int no1 = garis.find(';');
        int no2 = garis.find(';',no1+1);
        int no3 = garis.find(';',no2+1);
        int no4 = garis.find(';',no3+1);
        int no5 = garis.find(';',no4+1);
        int no6 = garis.find(';',no5+1);

        string IDBUKU = garis.substr(0,no1);
        string isbnBuku = garis.substr(no1+1,no2-no1-1);
        string namaBuku = garis.substr(no2+1,no3-no2-1);
        string pengarangBuku = garis.substr(no3+1,no4-no3-1);
        string penerbit = garis.substr(no4+1,no5-no4-1);
        string tahunTerbit = garis.substr(no5+1,no6-no5-1);
        string stokString = garis.substr(no6+1);

        if(IDBUKU==idBuku){
            int stok = stoi(stokString);

            if(stok>0) stok++;
            ketemu = true;

            sementara << IDBUKU << ";" << isbnBuku << ";" << namaBuku << ";"
                 << pengarangBuku << ";" << penerbit << ";" << 
                 tahunTerbit << ";" << stok << endl;
        } else {
            sementara << garis << endl;
        }
    }

    buku.close();
    sementara.close();

    remove("buku.txt");
    rename("temporarybuku.txt", "buku.txt");

    if(ketemu){
        cout << "Stok Buku " << idBuku << " berhasil ditambah 1" << endl << endl;
    } else {
        cout << "ID buku tiddak ditemukan!" << endl;
    }
}

string cariNama(string nama){
    ifstream file2("anggota.txt");
    string baris;
    string NamaAnggota;
        while(getline(file2,baris)){
            int posisiID = baris.find(';');
            string idAnggota = baris.substr(0,posisiID);
            if(idAnggota == nama){
            int posisiKode = baris.find(';',posisiID+1);
            int posisiNama = baris.find(';',posisiKode+1);

            NamaAnggota = baris.substr(posisiKode+1,posisiNama-posisiKode-1);
            break;
            }
        }
        file2.close();
        return NamaAnggota;
}

string NamaBuku(string buku){ 
    ifstream file3("buku.txt");
    string baris2;
    string namaBuku;
        while(getline(file3,baris2)){
        int posisi1=baris2.find(';');
        string IDbook = baris2.substr(0,posisi1);
        if(IDbook == buku){
            int posisiISBN=baris2.find(';',posisi1+1);
            int posisiName=baris2.find(';',posisiISBN+1);

            namaBuku = baris2.substr(posisiISBN+1,posisiName-posisiISBN-1);
            break;
            }
        }
        file3.close();
        return namaBuku;
    }

void cariPeminjaman(){
    string menu;
    while(true){
    cout << "Masukkan ID Peminjaman yang ingin di cari : ";
    getline(cin,menu);

    if(menu.length() > 6 && menu.length() == 0){
        cout << "Masukkan ID yang benar!" << endl;
    } else { break; }   
    }

    ifstream file("Peminjaman.txt");
    string line, baris, baris2;
    string Anggota = "";
    string Buku = "";
    string keadaan = "";

    while(getline(file,line)){
        if(line.find(menu)!=string::npos){
            int pos1 = line.find(';');
            int pos2 = line.find(';',pos1+1);
            int pos3 = line.find(';',pos2+1);
            int pos4 = line.find(';',pos3+1);
            int pos5 = line.find(';',pos4+1);

            string IDpinjam = line.substr(0,pos1);
            string IDbuku = line.substr(pos1+1,pos2-pos1-1);
            string IDanggota = line.substr(pos2+1,pos3-pos2-1);
            string tanggalPinjam = line.substr(pos3+1,pos4-pos3-1);
            string tanggalKembali = line.substr(pos4+1,pos5-pos4-1);
            string status = line.substr(pos5+1);

            Anggota = cariNama(IDanggota);
            Buku = NamaBuku(IDbuku);

            if(status=="1"){
                keadaan = "MASIH DIPINJAM";
            } else if(status=="0"){
                keadaan = "SUDAH DIKEMBALIKAN";
            }

            cout << endl << "INFORMASI PEMINJAMAN" << endl
                 << "ID Peminjaman : " << IDpinjam << endl
                 << "Nama Anggota : " << Anggota << endl
                 << "ID Anggota : " << IDanggota << endl
                 << "Nama Buku : " << Buku << endl
                 << "ID Buku : " << IDbuku << endl
                 << "Tanggal Pinjam : " << tanggalPinjam << endl
                 << "Tanggal Kembali : " << tanggalKembali << endl
                 << "Status : " << status << " (" << keadaan << ")" << endl << endl;
                break;
        }
    }
    file.close();

   string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Menu Kembali (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}

void UbahStatus(string peminjam){
    ifstream pinjam("Peminjaman.txt");
    ofstream output("temporary.txt");

    string line;
    bool ketemu = false;

    while(getline(pinjam,line)){
        int pos1 = line.find(';');
        int pos2 = line.find(';',pos1+1);
        int pos3 = line.find(';',pos2+1);
        int pos4 = line.find(';',pos3+1);
        int pos5 = line.find(';',pos4+1);

        string idPinjam = line.substr(0,pos1);
        string idBuku = line.substr(pos1+1,pos2-pos1-1);
        string idAnggota = line.substr(pos2+1,pos3-pos2-1);
        string tanggalPinjam = line.substr(pos3+1,pos4-pos3-1);
        string tanggalKembali = line.substr(pos4+1,pos5-pos4-1);
        string statusPinjam = line.substr(pos5+1);

        if(peminjam == idPinjam){
            ketemu = true;

            string statusPeminjaman = "0";

            output << idPinjam << ";" << idBuku << ";" << idAnggota << ";"
                 << tanggalPinjam << ";" << tanggalKembali << ";" << 
                 statusPeminjaman << endl;
        } else {
            output << line << endl;
        }
    }

    pinjam.close();
    output.close();

    remove("Peminjaman.txt");
    rename("temporary.txt", "Peminjaman.txt");

    if(ketemu){
        cout << "Status Peminjam berhasil diupdate!" << endl;
    } else{}
}

void pecahTanggal(string tanggal, int &day, int &month, int &year){
    int posisi1 = tanggal.find('-');
    int posisi2 = tanggal.find('-',posisi1+1);

    day = stoi(tanggal.substr(0,posisi1));
    month = stoi(tanggal.substr(posisi1+1,posisi2-posisi1-1));
    year = stoi(tanggal.substr(posisi2+1));
}

int hitungTanggal(int d, int m, int y){
    return y * 365 + m * 30 + d;
}

int selisih(string tanggal1, int d2, int m2, int y2){
    int d1,m1,y1;

    pecahTanggal(tanggal1,d1,m1,y1);

    int hari1 = hitungTanggal(d1,m1,y1);
    int hari2 = hitungTanggal(d2,m2,y2);

    return hari2-hari1;
}

int hitungDenda(string batas, int hari2, int bulan2, int tahun2){
    int terlambat = selisih(batas, hari2, bulan2, tahun2);

    if(terlambat > 0){
        return terlambat * 1000; 
    }
    return 0;
}

void pengembalian(){
    string idanggota;
    int tahun,bulan,tanggal;
    while(true){
    cout << "Masukkan ID Anggota : ";
    cin >> idanggota;

    ifstream file("anggota.txt");
    string line;
    bool ketemu = false;
    bool aktif = false;
    while(getline(file,line)){
        int pos1 = line.find(';');
        string id = line.substr(0,pos1);

        if(idanggota == id){
            ketemu = true;
            int pos2 = line.find(';',pos1+1);
            int pos3 = line.find(';',pos2+1);
            int pos4 = line.find(';',pos3+1);
            int pos5 = line.find(';',pos4+1);
            int pos6 = line.find(';',pos5+1);

            string status = line.substr(pos6+1);
            if(status == "1"){
                aktif = true;
                file.close();
            } else{
                cout << "Akun Siswa tidak aktif!" << endl;
            }
            break;
        }
    }
     file.close();
     if(!ketemu){
        cout << "ID Anggota tidak ditemukan!" << endl;
        continue;
     }

     if(!aktif){
        continue;
     }

    ifstream cek("Peminjaman.txt");
    string barisCek;
    bool meminjam = false;
    while(getline(cek,barisCek)){
       int kolom1 = barisCek.find(';');
       int kolom2 = barisCek.find(';',kolom1+1);
       int kolom3 = barisCek.find(';',kolom2+1);
       int kolom4 = barisCek.find(';',kolom3+1);
       int kolom5 = barisCek.find(';',kolom4+1);

       string idPinjam = barisCek.substr(0,kolom1);
       string cekBuku = barisCek.substr(kolom1+1,kolom2-kolom1-1);
       string cekAnggota = barisCek.substr(kolom2+1,kolom3-kolom2-1);
       string tanggalPinjam = barisCek.substr(kolom3+1,kolom4-kolom3-1);
       string tanggalKembali = barisCek.substr(kolom4+1,kolom5-kolom4-1);
       string status = barisCek.substr(kolom5+1);

       if(idanggota == cekAnggota){
        string f = cariNama(cekAnggota);
        string g = NamaBuku(cekBuku);
        cout << "Nama : " << f << endl
             << "ID Anggota : " << cekAnggota << endl
             << "Buku yang sedang dipinjam : " << g << endl
             << "ID Buku : " << cekBuku << endl
             << "Tanggal Meminjam : " << tanggalPinjam << endl
             << "Batas Pengembalian : " << tanggalKembali << endl << endl;
        meminjam = true;
        break;
       }
    }
    cek.close();
    if(!meminjam){
        cout << "Siswa tidak meminjam apapun!" << endl;
        continue;
    }
    break;
}

    while(true) {
    cout << "Masukkan Tanggal Siswa Mengembalikan buku (DD-MM-YY)" << endl;
    cout << "Masukkan Tahun : ";
    cin >> tahun;

    if(tahun > 2025){
        cout << "Tolong input Tahun yang benar!" << endl;
    } else if(tahun==0){
        cout << "Tahun tidak boleh kosong" << endl;
    } else { break; }
    }

    while(true) {
        cout << "Masukkan Bulan : ";
        cin >> bulan;

        if(bulan > 12){
            cout << "Tolong masukkan Bulan yang benar!" << endl;
        } else if(bulan==0){
            cout << "Bulan tidak boleh kosong!" << endl;
        } else { break; }
    }

    if(bulan==1 || bulan == 3 || bulan == 5 || bulan == 7 || bulan == 8 || 
       bulan == 10 || bulan == 12){
        while(true){
            cout << "Masukkan Tanggal : ";
            cin >> tanggal;
            if(tanggal > 31 || tanggal == 0){
                cout << "Masukkan Tanggal dengan benar dan sesuai batas bulan" << endl;
            } else { break; }
        }
    }

    else if(bulan==4 || bulan == 6 || bulan==9 || bulan==11 ){
        while(true){
            cout << "Masukkan Tanggal : ";
            cin >> tanggal;
            if(tanggal > 30 || tanggal == 0){
                cout << "Masukkan Tanggal dengan benar dan sesuai batas bulan" << endl;
            } else { break; }
        }
    }

    else if(bulan==2){
        if((tahun%400 == 0) || (tahun%4==0 && tahun%100!=0)){
            while(true){
                cout << "Masukkan Tanggal : ";
                cin >> tanggal;
                if(tanggal > 29 || tanggal == 0){
                    cout << "Masukkan Tanggal dengan benar dan sesuai atas bulan" << endl;
                } else { break; }
            }
        }
        else {
            while(true){
                cout << "Masukkan Tanggal : ";
                cin >> tanggal;
                if(tanggal > 28 || tanggal == 0){
                    cout << "Masukkan Tanggal dengan benar dan sesuai atas bulan" << endl;
                } else { break; }
            }
        }
    }

    string baris;
    ifstream file1("Peminjaman.txt");
    ofstream file2("pengembalian.txt", ios::app);
    string finalStatus = "";
    string finalIDpinjam = "";

    while(getline(file1,baris)){

        int posisi1 = baris.find(';');
        int posisi2 = baris.find(';',posisi1+1);
        int posisi3 = baris.find(';',posisi2+1);
        int posisi4 = baris.find(';',posisi3+1);
        int posisi5 = baris.find(';',posisi4+1);

        string idpinjam = baris.substr(0,posisi1);
        string idBuku = baris.substr(posisi1+1,posisi2-posisi1-1);
        string idAnggota = baris.substr(posisi2+1,posisi3-posisi2-1);
        string tanggalPinjam = baris.substr(posisi3+1,posisi4-posisi3-1);
        string tanggalKembali = baris.substr(posisi4+1,posisi5-posisi4-1);
        string status = baris.substr(posisi5+1);

        if(idanggota == idAnggota){
            int keterlambatan = selisih(tanggalKembali,tanggal,bulan,tahun);
            int denda = 0;
            if (keterlambatan > 0)
            denda = keterlambatan * 1000;

        file2 << idBuku << ";"
              << idAnggota << ";"
              << tanggalKembali << ";"
              << tanggalPinjam << ";"
              << tanggal << "-" << bulan << "-" << tahun << ";"
              << denda << endl;
        
        string Judul = NamaBuku(idBuku);
        string Nickname = cariNama(idAnggota);
        
        cout << endl << "Buku : " << Judul << endl
             << "ID Buku : " << idBuku << endl
             << "Dipinjam oleh : " << Nickname << " ( " << idAnggota << " ) " << endl 
             << "Tanggal Meminjam : " << tanggalPinjam << endl
             << "Tanggal Kembali : " << tanggalKembali << endl
             << "Terlambat : " << keterlambatan << endl
             << "Denda : " << denda << endl << endl;
        
        finalStatus = idpinjam;
        finalIDpinjam = idBuku;

        }
    }

    file1.close();
    file2.close();
    UbahStatus(finalStatus); 
    UpdateStokTambah(finalIDpinjam);   
    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Menu Kembali (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}

void NonaktifAdmin(){
    string menu;
    cout << "Masukkan ID Admin yang ingin di input : ";
    getline(cin,menu);

    ifstream adminFile("petugas.txt");
    ofstream tempoFile("temporaryAdmin.txt");

        string baris;
        bool ketemu = false;
        string UpdateStatus = "TIDAKAKTIF";

        while(getline(adminFile,baris)){
            int pos1 = baris.find(';');
            int pos2 = baris.find(';',pos1+1);
            int pos3 = baris.find(';',pos2+1);
            int pos4 = baris.find(';',pos3+1);
            int pos5 = baris.find(';',pos4+1);

            string id = baris.substr(0,pos1);
            string username = baris.substr(pos1+1,pos2-pos1-1);
            string ADMIN = baris.substr(pos2+1,pos3-pos2-1);
            string password = baris.substr(pos3+1,pos4-pos3-1);
            string nama = baris.substr(pos4+1,pos5-pos4-1);
            string status = baris.substr(pos5+1);


            if(id == menu){
               ketemu = true;

               if(ADMIN == "1"){
                cout << "ID adalah milik Admin Utama, Tolong input ID yang benar!" << endl;
                tempoFile << baris << endl; 
               } 
                else if (status == "TIDAKAKTIF") {
                cout << "Admin ini sudah nonaktif sebelumnya." << endl;
                tempoFile << baris << endl;
                }
               else {
                tempoFile << id << ";" << username << ";" << ADMIN << ";" << password << ";" << nama << ";" << UpdateStatus << endl;
                cout << "Admin berhasil dinonaktifkan!" << endl;
               }
            }
            else{
            tempoFile << baris << endl;
            }
    }
    adminFile.close();
    tempoFile.close();

    remove("petugas.txt");
    rename("temporaryAdmin.txt", "petugas.txt");

    if (!ketemu) {
        cout << "ID Admin tidak ditemukan!" << endl;
    }

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Menu Kembali (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}

void NonaktifAnggota(){
    string in;
    cout << "Masukkan ID Anggota yang ingin di input : ";
    getline(cin,in);

    ifstream file("anggota.txt");
    ofstream tempo("temporaryAnggota.txt");

        string baris;
        bool ketemu = false;
        string UpdateStatus = "0";

        while(getline(file,baris)){
            int pos1 = baris.find(';');
            int pos2 = baris.find(';',pos1+1);
            int pos3 = baris.find(';',pos2+1);
            int pos4 = baris.find(';',pos3+1);
            int pos5 = baris.find(';',pos4+1);
            int pos6 = baris.find(';',pos5+1);

            string id = baris.substr(0,pos1);
            string kode = baris.substr(pos1+1,pos2-pos1-1);
            string nama = baris.substr(pos2+1,pos3-pos2-1);
            string tanggal = baris.substr(pos3+1,pos4-pos3-1);
            string alamat = baris.substr(pos4+1,pos5-pos4-1);
            string gmail = baris.substr(pos5+1,pos6-pos5-1);
            string status = baris.substr(pos6+1);


            if(id == in){
               ketemu = true;

                if (status == "1") {
                tempo << id << ";" << kode << ";" << nama << ";" << tanggal << ";" << alamat << ";" << gmail << ";" << UpdateStatus << endl;
                cout << "Anggota berhasil di non-aktifkan" << endl;
                }
               else {
                cout << "Anggota sudah dinon-aktifkan" << endl;
               }
            }
            else{
            tempo << baris << endl;
            }
    }
    file.close();
    tempo.close();

    remove("anggota.txt");
    rename("temporaryAnggota.txt", "anggota.txt");

    if (!ketemu) {
        cout << "ID Anggota tidak ditemukan!" << endl;
    }

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Menu Kembali (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}

void HapusBuku(){
    string id;
    cout << "Masukkan ID Buku yang ingin dihapus : ";
    getline(cin,id);

    ifstream buku("buku.txt");
    ofstream sementara("temporarybuku.txt");

    string garis;
    bool ketemu = false;

    while(getline(buku,garis)){
        int no1 = garis.find(';');
        int no2 = garis.find(';',no1+1);
        int no3 = garis.find(';',no2+1);
        int no4 = garis.find(';',no3+1);
        int no5 = garis.find(';',no4+1);
        int no6 = garis.find(';',no5+1);

        string IDBUKU = garis.substr(0,no1);
        string isbnBuku = garis.substr(no1+1,no2-no1-1);
        string namaBuku = garis.substr(no2+1,no3-no2-1);
        string pengarangBuku = garis.substr(no3+1,no4-no3-1);
        string penerbit = garis.substr(no4+1,no5-no4-1);
        string tahunTerbit = garis.substr(no5+1,no6-no5-1);
        string stokString = garis.substr(no6+1);

        if(IDBUKU!=id){
            sementara << garis << endl;
        } else {
            ketemu = true;
        }
    }

    buku.close();
    sementara.close();

    remove("buku.txt");
    rename("temporarybuku.txt", "buku.txt");

    if(ketemu){
        cout << "Buku dengan ID " << id << " berhasil dihapus" << endl << endl;
    } else {
        cout << "ID buku tiddak ditemukan!" << endl;
    }
}

void InterfaceAdminUtama(){
    int pilih;
    do{
    cout << "Menu Admin Utama" << endl;
    cout << "1. Tambah Anggota" << endl;
    cout << "2. Tambah Buku" << endl;
    cout << "3. Cari Anggota" << endl;
    cout << "4. Cari Buku" << endl;
    cout << "5. Tambah Admin" << endl;
    cout << "6. Peminjaman" << endl;
    cout << "7. Cari Peminjaman" << endl;
    cout << "8. Pengembalian" << endl;
    cout << "9. Non-Aktif Admin" << endl;
    cout << "10. Non-Aktif Anggota" << endl;
    cout << "11. Hapus Buku" << endl;
    cout << "0. Berhenti" << endl;
    
    cout << "Masukkan Menu : ";
    cin >> pilih;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    if(pilih==0){
        cout << "Anda memilih berhenti dari program!";
        break;
    }
    else if(pilih==1){
        system("cls");
        TambahAnggota();
    }
    else if(pilih==2){
        system("cls");
        TambahBuku();
    }
    else if(pilih==3){
        system("cls");
        CariAnggota();
    }
    else if(pilih==4){
        system("cls");
        CariBuku();
    }
    else if(pilih==5){
        system("cls");
        TambahAdmin();
    }
    else if(pilih==6){
        system("cls");
        Peminjaman();
    }
    else if(pilih==7){
        system("cls");
        cariPeminjaman();
    }
    else if(pilih==8){
        system("cls");
        pengembalian();
    }
    else if(pilih==9){
        system("cls");
        NonaktifAdmin();
    }
    else if(pilih==10){
        system("cls");
        NonaktifAnggota();
    }
    else if(pilih==11){
        system("cls");
        HapusBuku();
    }
} while(true);
}

void AdminBiasa(){
    int pilih;
    
    do { 
    cout << "Menu Admin Utama" << endl;
    cout << "1. Tambah Anggota" << endl;
    cout << "2. Tambah Buku" << endl;
    cout << "3. Cari Anggota" << endl;
    cout << "4. Cari Buku" << endl;
    cout << "5. Peminjaman" << endl;
    cout << "6. Cari Peminjaman" << endl;
    cout << "7. Pengembalian" << endl;
    cout << "8. Non-Aktif Admin" << endl;
    cout << "9. Hapus Buku" << endl;
    cout << "0. Berhenti" << endl;
    
    cout << "Masukkan Pilihan : ";
    cin >> pilih;
    cin.ignore();
    cout << endl;

    if(pilih==0){
        break;
    }
    else if(pilih==1){
        system("cls");
        TambahAnggota();
    }
    else if(pilih==2){
        system("cls");
        TambahBuku();
    }
    else if(pilih==3){
        system("cls");
        CariAnggota();
    }
    else if(pilih==4){
        system("cls");
        CariBuku();
    }
    else if(pilih==5){
        system("cls");
        Peminjaman();
    }
    else if(pilih==6){
        system("cls");
        cariPeminjaman();
    }
    else if(pilih==7){
        system("cls");
        pengembalian();
    }
    else if(pilih==8){
        system("cls");
        NonaktifAnggota();
    }
    else if(pilih==9){
        system("cls");
        HapusBuku();
    }
} while(true);
}

void InterfaceAnggota(){
    int pilihan;
    do {
    cout << endl << "Daftar Menu" << endl;
    cout << "1. Cari Buku" << endl;
    cout << "0. Berhenti" << endl;
    
    cout << "Masukkan Menu : ";
    cin >> pilihan;
    cin.ignore();
    cout << endl;

if(pilihan==0){
    break;
}
else if(pilihan==1){
    system("cls");
    CariBuku();
}
} while(true);
}


void login(){
    int menu;
    cout << "Menu Perpustakaan Sederhana"<<endl;
    cout << "==========================="<<endl;
    cout << "1. Login sebagai Petugas"<<endl;
    cout << "2. Login sebagai Siswa"<<endl; 
    
    while(true) { 
    cout << "Pilihan Menu : ";
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(menu > 2) {
        cout << "Tolong pilih sesuai menu!" << endl;
    }
    else if(menu == 0){
        cout << "Tolong pilih sesuai menu!" << endl;
    }
    else{
        break;
    }
    }
    

    if(menu==1){
        string username;
        string password;
        cout << "Masukkan Username : ";
        getline(cin,username);
        cout << "Masukkan Password : ";
        getline(cin,password);

        ifstream file("petugas.txt");
        if (!file.is_open()) {
        cout << "File petugas.txt tidak bisa dibuka!" << endl;
        return;
        }
        string line;
        bool ketemu = false;

        while(getline(file,line)){
            int posisi1 = line.find(';');
            int posisi2 = line.find(';',posisi1 + 1);
            int posisi3 = line.find(';',posisi2 + 1);
            int posisi4 = line.find(';',posisi3 + 1);
            int posisi5 = line.find(';',posisi4+1);

            string idAdmin = line.substr(0,posisi1);
            string usernameAdmin = line.substr(posisi1 + 1, posisi2-posisi1-1);
            string statusAdmin = line.substr(posisi2 + 1, posisi3-posisi2-1);
            string passwordAdmin = line.substr(posisi3 + 1,posisi4-posisi3-1);
            string nama = line.substr(posisi4+1,posisi5-posisi4-1);
            string status = line.substr(posisi5+1);

            if(username == usernameAdmin){
                ketemu = true;
                if(password == passwordAdmin){
                    file.close();
                    if(statusAdmin == "1"){
                        cout << "Login berhasil!" << endl;
                        system("cls");
                        InterfaceAdminUtama();
                    }
                    else if(statusAdmin == "0" && status == "AKTIF"){
                        cout << "Login berhasil!" << endl;
                        system("cls");
                        AdminBiasa();
                    } else { cout << "Akun tidak aktif!" << endl; } return;
                }
                else{
                    cout << "Password tidak terdeteksi!";
                    file.close();
                    return;
                }
            }

        }
        file.close();
        cout << "Data tidak ditemukan";

    }
    
    else if(menu==2){
        string nama, kode;
        string idLoginSiswa = "";
        cout << "Masukkan Username : ";
        getline(cin,nama);
        cout << "Masukkan Kode Anggota : ";
        getline(cin,kode);

        ifstream file("anggota.txt");
        if (file.is_open()){
    }
    else {
    }
        string line;
        bool ketemu = false;

        while(getline(file,line)){
            int posisi1 = line.find(';');
            int posisi2 = line.find(';',posisi1 + 1);
            int posisi3 = line.find(';',posisi2 + 1);
            int posisi4 = line.find(';',posisi3 + 1);
            int posisi5 = line.find(';',posisi4 + 1);
            int posisi6 = line.find(';',posisi5 + 1);

            string id = line.substr(0,posisi1);
            string kodeSiswa = line.substr(posisi1 + 1, posisi2-posisi1-1);
            string namaSiswa = line.substr(posisi2 + 1, posisi3-posisi2-1);
            string tanggal = line.substr(posisi3 + 1, posisi4-posisi3-1);
            string alamat = line.substr(posisi4 + 1, posisi5-posisi4-1);
            string email = line.substr(posisi5 + 1, posisi6-posisi5-1);
            string statusSiswa = line.substr(posisi6 + 1);

        if(nama == namaSiswa) {
            ketemu = true;
            if(kode == kodeSiswa){
                if(statusSiswa == "0"){
                    cout << "Akun Tidak Aktif";
                }
                else{
                    cout << "Login berhasil!" << endl;
                    system("cls");
                    InterfaceAnggota();
                }
            }
            else{
                cout << "Kode Berbeda";
            }
            break;
        }
    }
    file.close();

    if(!ketemu){
        cout << "Data tidak ketemu" << endl;
    }
         
    }
    else{
    cout << "Tolong pilih sesuai inputan";
    }

}

int main(){
    login();
}


