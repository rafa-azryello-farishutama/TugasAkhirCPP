#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

struct anggota{
    string idanggota;
    string nama;
    string alamat;
    string kodeAnggota1;
    int tanggal;
    int bulan;
    int tahun;
    string email;
    int status;
    string strStatus;
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
       cout << "Kembali ke menu tampilan (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
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
       cout << "Kembali ke menu tampilan (ketik 0) : ";
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
       cout << "Kembali ke menu tampilan (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}


void CariAnggota() {
    while(true) { 
    string katakunci;
    bool ketemu = false;
    cout << "Masukkan ID Anggota : ";
    getline(cin,katakunci);

    ifstream fileOutput("anggota.txt");
    if (fileOutput.is_open()){
    }
    else {
    }
    string line;
    while(getline(fileOutput,line)){
            int posisi1 = line.find(';');
            int posisi2 = line.find(';',posisi1 + 1);
            int posisi3 = line.find(';',posisi2 + 1);
            int posisi4 = line.find(';',posisi3 + 1);
            int posisi5 = line.find(';',posisi4 + 1);
            int posisi6 = line.find(';',posisi5 + 1);

            string id = line.substr(0,posisi1);
            if(id==katakunci){
            ketemu = true;
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
            break;
            }
        
    }
    if(!ketemu){
    cout << "Data tidak ditemukan!" << endl;
    cout << "Apakah anda ingin mencari Anggota yang lain? (1 = ya, 0=tidak) : ";
    string opsi;
    getline(cin,opsi);
    if(opsi=="1"){
        system("cls");
        continue;
    } else if(opsi=="0"){
        break;
    } else { 
        cout << "Anda harus ketik 0 jika ingin kembali" << endl;
    }
    }
    
    cout << endl << "Cari anggota lain? (1 = ya, 0 = tidak): ";
        string pilihan;
        getline(cin, pilihan);

        if(pilihan == "1"){
            system("cls");
            continue;
        } else if(pilihan=="0"){
            break;
        } 
}

    string nol;
    while(true){
       cout << "Kembali ke menu tampilan (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}

void CariBuku(){
    while(true) { 
    string katakunci;
    bool ketemu = false;
    cout << "Masukkan Judul Buku : ";
    getline(cin,katakunci);

    ifstream file("buku.txt");
    if (file.is_open()){
    }
    else {
    }
    string line;
    while(getline(file,line)){
            int posisi1 = line.find(';');
            int posisi2 = line.find(';',posisi1 + 1);
            int posisi3 = line.find(';',posisi2 + 1);
            int posisi4 = line.find(';',posisi3 + 1);
            int posisi5 = line.find(';',posisi4 + 1);
            int posisi6 = line.find(';',posisi5 + 1);

            string id = line.substr(0,posisi1);
            string isbn = line.substr(posisi1+1, posisi2-posisi1-1);
            string nama = line.substr(posisi2+1,posisi3-posisi2-1);
            if(nama == katakunci){
            ketemu = true;
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
            break;
            }
        
    }
    if(!ketemu){
    cout << "Data tidak ditemukan!" << endl;
    cout << "Apakah anda ingin mencari buku yang lain? (1 = ya, 0=tidak) : ";
    string opsi;
    getline(cin,opsi);
    if(opsi=="1"){
        system("cls");
        continue;
    } else if(opsi=="0"){
        break;
    } else { 
        cout << "Anda harus ketik 0 jika ingin kembali" << endl;
    }
    }
    
    cout << endl << "Cari buku lain? (1 = ya, 0 = tidak): ";
        string pilihan;
        getline(cin, pilihan);

        if(pilihan == "1"){
            system("cls");
            continue;
        } else if(pilihan=="0"){
            break;
        } 
}

    string nol;
    while(true){
       cout << "Kembali ke menu tampilan (ketik 0) : ";
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
    while(true){
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

string pilih;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (true) {
            cout << "Pinjam lagi? (1 = Ya, 0 = Kembali ke menu): ";
            getline(cin, pilih);

            if (pilih == "1") {
                system("cls");
                break; 
            }
            else if (pilih == "0") {
                string nol;
                while (true) {
                    cout << "Kembali ke menu tampilan (ketik 0) : ";
                    getline(cin, nol);

                    if (nol == "0") {
                        system("cls");
                        return;   
                    }
                    else {
                        cout << "Anda harus ketik 0 jika ingin kembali" << endl;
                    }
                }

            }
            else {
                cout << "Input tidak valid! Pilih 1 atau 0." << endl;
            }
        }

    }
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
    

    ifstream file("Peminjaman.txt");
    string line, baris, baris2;
    string Anggota = "";
    string Buku = "";
    string keadaan = "";
    bool ketemu = false;

    while(getline(file,line)){
            int pos1 = line.find(';');
            int pos2 = line.find(';',pos1+1);
            int pos3 = line.find(';',pos2+1);
            int pos4 = line.find(';',pos3+1);
            int pos5 = line.find(';',pos4+1);

            string IDpinjam = line.substr(0,pos1);
            if(menu==IDpinjam){
            ketemu = true;
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
   if(!ketemu){
    cout << "Data tidak ditemukan!" << endl;
    cout << "Apakah anda ingin mencari peminjaman yang lain? (1 = ya, 0=tidak) : ";
    string opsi;
    getline(cin,opsi);
    if(opsi=="1"){
        system("cls");
        continue;
    } else if(opsi=="0"){
        break;
    } else { 
        cout << "Anda harus ketik 0 jika ingin kembali" << endl;
    }
    }
    
    cout << endl << "Cari id lain? (1 = ya, 0 = tidak): ";
        string pilihan;
        getline(cin, pilihan);

        if(pilihan == "1"){
            system("cls");
            continue;
        } else if(pilihan=="0"){
            break;
        } 
}

    string nol;
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

bool masihAdaPinjaman(string idanggota) {
    ifstream file("Peminjaman.txt");
    string baris;

    while (getline(file, baris)) {
        int p1 = baris.find(';');
        int p2 = baris.find(';', p1 + 1);
        int p3 = baris.find(';', p2 + 1);
        int p4 = baris.find(';', p3 + 1);
        int p5 = baris.find(';', p4 + 1);

        string idAnggota = baris.substr(p2 + 1, p3 - p2 - 1);
        string status = baris.substr(p5 + 1);

        if (idAnggota == idanggota && status == "1") {
            file.close();   
            return true;
        }
    }

    file.close();          
    return false;
}


void pengembalian() {
    cout << "MENU PENGEMBALIAN" << endl << endl;
    string idanggota, idkonfirmasi;
    int tahun, bulan, tanggal;
    int hariP = 0, bulanP = 0, tahunP = 0;
    while (true) {
        cout << "Masukkan ID Anggota : ";
        cin >> idanggota;

        ifstream file("anggota.txt");
        string line;
        bool ketemu = false;
        bool aktif = false;

        while (getline(file, line)) {
            int pos1 = line.find(';');
            string id = line.substr(0, pos1);

            if (idanggota == id) {
                ketemu = true;
                int pos2 = line.find(';', pos1 + 1);
                int pos3 = line.find(';', pos2 + 1);
                int pos4 = line.find(';', pos3 + 1);
                int pos5 = line.find(';', pos4 + 1);
                int pos6 = line.find(';', pos5 + 1);

                string status = line.substr(pos6 + 1);
                if (status == "1") {
                    aktif = true;
                } else {
                    cout << "Akun Siswa tidak aktif!" << endl;
                }
                break;
            }
        }

        file.close();

        if (!ketemu) {
            cout << "ID Anggota tidak ditemukan!" << endl;
            continue;
        }

        if (!aktif) {
            continue;
        }

        break;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        ifstream cekSisa("Peminjaman.txt");
        string barisSisa;
        bool AdaPinjaman = false;

        while (getline(cekSisa, barisSisa)) {
            int s1 = barisSisa.find(';');
            int s2 = barisSisa.find(';', s1 + 1);
            int s3 = barisSisa.find(';', s2 + 1);
            int s4 = barisSisa.find(';', s3 + 1);
            int s5 = barisSisa.find(';', s4 + 1);

            string idPinjam = barisSisa.substr(0, s1);
            string idbook = barisSisa.substr(s1 + 1, s2 - s1 - 1);
            string idAnggotaSisa = barisSisa.substr(s2 + 1, s3 - s2 - 1);
            string TanggalPinjam = barisSisa.substr(s3 + 1, s4 - s3 - 1);
            string TanggalKembali = barisSisa.substr(s4 + 1, s5 - s4 - 1);
            string statusSisa = barisSisa.substr(s5 + 1);

            if (idanggota == idAnggotaSisa && statusSisa == "1") {
                AdaPinjaman = true;

                string namaAnggota = cariNama(idAnggotaSisa);
                string namaBuku = NamaBuku(idbook);

                cout << "Nama : " << namaAnggota << " ( " << idAnggotaSisa << " )\n"
                     << "Buku yang sedang dipinjam : " << namaBuku << " ( " << idbook << " )\n"
                     << "ID Peminjaman : " << idPinjam << "\n"
                     << "Tanggal Pinjam : " << TanggalPinjam << "\n"
                     << "Tanggal Kembali : " << TanggalKembali << "\n\n";
            }
        }

        cekSisa.close();

        if (!AdaPinjaman) {
            cout << endl << "Anggota " << idanggota << " sudah tidak memiliki pinjaman aktif lagi.\n";
            break;
        }

        break;
    }

    while (true) {
        cout << endl << "Id Buku mana yang ingin anda dikembalikan : ";
        getline(cin, idkonfirmasi);

        ifstream file1("Peminjaman.txt");
        string baris;
        bool ditemukan = false;
        string finalpinjam, kembali, pinjamstr;

        while (getline(file1, baris)) {
            int p1 = baris.find(';');
            int p2 = baris.find(';', p1 + 1);
            int p3 = baris.find(';', p2 + 1);
            int p4 = baris.find(';', p3 + 1);
            int p5 = baris.find(';', p4 + 1);

            string idpinjam = baris.substr(0, p1);
            string idBuku = baris.substr(p1 + 1, p2 - p1 - 1);
            string idAnggota = baris.substr(p2 + 1, p3 - p2 - 1);
            string tanggalPinjam = baris.substr(p3 + 1, p4 - p3 - 1);
            string tanggalKembali = baris.substr(p4 + 1, p5 - p4 - 1);
            string status = baris.substr(p5 + 1);

            if (idBuku == idkonfirmasi && status == "1" && idanggota == idAnggota) {
                ditemukan = true;
                finalpinjam = idpinjam;
                kembali = tanggalKembali;
                pinjamstr = tanggalPinjam;

                int kolom1 = pinjamstr.find('-');
                int kolom2 = pinjamstr.find('-', kolom1 + 1);

                hariP = stoi(pinjamstr.substr(0, kolom1));
                bulanP = stoi(pinjamstr.substr(kolom1 + 1, kolom2 - kolom1 - 1));
                tahunP = stoi(pinjamstr.substr(kolom2 + 1));

                break;
            }
        }

        file1.close();

        if (!ditemukan) {
            cout << "ID Buku tidak ditemukan atau tidak sedang dipinjam oleh anggota ini.\n";
            continue;
        }

        bool TanggalBenar = false;

        while (!TanggalBenar) {

            while (true) {
                cout << "Masukkan Tahun : ";
                cin >> tahun;
                if (tahun > 2025 || tahun == 0) cout << "Tolong input Tahun yang benar!\n";
                else break;
            }

            while (true) {
                cout << "Masukkan Bulan : ";
                cin >> bulan;
                if (bulan > 12 || bulan == 0) cout << "Tolong masukkan Bulan yang benar!\n";
                else break;
            }

            if (bulan == 1 || bulan == 3 || bulan == 5 || bulan == 7 ||
                bulan == 8 || bulan == 10 || bulan == 12) {

                while (true) {
                    cout << "Masukkan Tanggal : ";
                    cin >> tanggal;
                    if (tanggal > 31 || tanggal == 0) cout << "Tanggal salah!\n";
                    else break;
                }
            }
            else if (bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) {

                while (true) {
                    cout << "Masukkan Tanggal : ";
                    cin >> tanggal;
                    if (tanggal > 30 || tanggal == 0) cout << "Tanggal salah!\n";
                    else break;
                }
            }
            else if (bulan == 2) {

                bool kabisat = (tahun % 400 == 0) || (tahun % 4 == 0 && tahun % 100 != 0);

                while (true) {
                    cout << "Masukkan Tanggal : ";
                    cin >> tanggal;
                    if ((kabisat && tanggal > 29) || (!kabisat && tanggal > 28) || tanggal == 0)
                        cout << "Tanggal salah!\n";
                    else break;
                }
            }

            if (tahun < tahunP ||
                (tahun == tahunP && bulan < bulanP) ||
                (tahun == tahunP && bulan == bulanP && tanggal < hariP)) {

                cout << "\nTanggal pengembalian TIDAK BOLEH sebelum tanggal pinjam!\n";
                continue;
            }

            TanggalBenar = true;
        }

        int keterlambatan = selisih(kembali, tanggal, bulan, tahun);
        if (keterlambatan < 0) keterlambatan = 0;
        int denda = keterlambatan * 1000;

        ofstream file2("pengembalian.txt", ios::app);
        file2 << idkonfirmasi << ";"
              << idanggota << ";"
              << kembali << ";"
              << pinjamstr << ";"
              << tanggal << "-" << bulan << "-" << tahun << ";"
              << denda << endl;
        file2.close();

        cout << "\nTerlambat : " << keterlambatan << endl
             << "Denda : " << denda << endl << endl;

        UbahStatus(finalpinjam);
        UpdateStokTambah(idkonfirmasi);

        if (!masihAdaPinjaman(idanggota)) {
          cout << endl << "Semua buku sudah dikembalikan. Tidak ada pinjaman aktif lagi.\n";
           break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string lagi;
        while (true) {
        cout << endl << "Apakah ingin mengembalikan buku lagi? (1 = ya, 0 = tidak) : ";
        getline(cin, lagi);

       if (lagi == "1" || lagi == "0") break;
         cout << "Input harus 1 atau 0!" << endl;
       }

       if (lagi == "0") break;

    }

    string nol;
    while (true) {
        cout << "Menu Kembali (ketik 0) : ";
        getline(cin, nol);
        if (nol == "0") break;
        else cout << "Anda harus ketik 0 jika ingin kembali\n";
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

void AktifAdmin(){
    string menu;
    cout << "Masukkan ID Admin yang ingin di input : ";
    getline(cin,menu);

    ifstream adminFile("petugas.txt");
    ofstream tempoFile("temporaryAdmin.txt");

        string baris;
        bool ketemu = false;
        string UpdateStatus = "AKTIF";

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
                else if (status == "AKTIF") {
                cout << "Admin ini sudah nonaktif sebelumnya." << endl;
                tempoFile << baris << endl;
                }
               else {
                tempoFile << id << ";" << username << ";" << ADMIN << ";" << password << ";" << nama << ";" << UpdateStatus << endl;
                cout << "Admin berhasil diaktifkan!" << endl;
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

void AktifAnggota(){
    string in;
    cout << "Masukkan ID Anggota yang ingin di input : ";
    getline(cin,in);

    ifstream file("anggota.txt");
    ofstream tempo("temporaryAnggota.txt");

        string baris;
        bool ketemu = false;
        string UpdateStatus = "1";

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

                if (status == "0") {
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

void tampilanAktif(){
    string pilihan;
    do{
    cout << "1. Non-Aktifkan Admin" << endl;
    cout << "2. Aktifkan Admin" << endl;
    cout << "3. Non-Aktifkan Anggota" << endl;
    cout << "4. Aktifkan Anggota" << endl;
    cout << "0. Kembali ke menu utama" << endl;
    cout << "Masukkan Menu : ";
    getline(cin,pilihan);
    if(pilihan=="0") {system("cls"); return; }
    else if(pilihan=="1"){ system("cls"); NonaktifAdmin(); }
    else if(pilihan=="2") { system("cls"); AktifAdmin(); }
    else if(pilihan=="3") { system("cls"); NonaktifAnggota(); }
    else if(pilihan=="4") { system("cls"); AktifAnggota(); }
    } while(true);
}

void biasatampilanAktif(){
    string pilihan;
    do{
    cout << "1. Non-Aktifkan Anggota" << endl;
    cout << "2. Aktifkan Anggota" << endl;
    cout << "0. Kembali ke menu utama" << endl;
    cout << "Masukkan Menu : ";
    getline(cin,pilihan);
    
    if(pilihan=="0") {system("cls"); return; }
    else if(pilihan=="1") { system("cls"); NonaktifAnggota(); }
    else if(pilihan=="2") { system("cls"); AktifAnggota(); }
    } while(true);
}

void HapusBuku(){
    string id;
    cout << "Masukkan ID Buku yang ingin dihapus : ";
    getline(cin,id);

    ifstream cekPinjaman("Peminjaman.txt");
    string barisPinjam;
    bool masihDipinjam = false;

    while(getline(cekPinjaman, barisPinjam)){
        int pos1 = barisPinjam.find(';');
        int pos2 = barisPinjam.find(';', pos1 + 1);
        int pos3 = barisPinjam.find(';',pos2+1);
        int pos4 = barisPinjam.find(';',pos3+1);
        int pos5 = barisPinjam.find(';', pos4+1);

        string idBukuPinjam = barisPinjam.substr(pos1 + 1, pos2 - pos1 - 1);
        string status = barisPinjam.substr(pos5 + 1);

        if(idBukuPinjam == id && status == "1"){
            masihDipinjam = true;
            break; 
        }
    }
    cekPinjaman.close();

    if(masihDipinjam){
        cout << endl << "Buku dengan ID " << id << " TIDAK BISA dihapus." << endl;
        cout << "Buku tersebut masih dalam status pinjaman aktif oleh seorang anggota." << endl;
        cout << "Minta siswa mengembalikan buku terlebih dahulu!" << endl << endl;
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
         remove("buku.txt");
         rename("temporarybuku.txt", "buku.txt");
        cout << "Buku dengan ID " << id << " berhasil dihapus" << endl << endl;
    } else {
        cout << "ID buku tiddak ditemukan!" << endl;
    }
}

void TampilPinjam(){
    cout << "Daftar yang belum mengembalikan" << endl << endl;
    
    ifstream output("peminjaman.txt");
    string baris;
    int nomor = 1;

    while(getline(output,baris)){
        int pos1 = baris.find(';');
        int pos2 = baris.find(';',pos1+1);
        int pos3 = baris.find(';',pos2+1);
        int pos4 = baris.find(';',pos3+1);
        int pos5 = baris.find(';',pos4+1);

        string idPinjam = baris.substr(0,pos1);
        string idBuku = baris.substr(pos1+1,pos2-pos1-1);
        string idAnggota = baris.substr(pos2+1,pos3-pos2-1);
        string tanggalPinjam = baris.substr(pos3+1,pos4-pos3-1);
        string tanggalKembali = baris.substr(pos4+1,pos5-pos4-1);
        string status = baris.substr(pos5+1);

        string namaBuku = NamaBuku(idBuku);
        string namaAnggota = cariNama(idAnggota);

        if(status=="1"){
            cout << nomor++ << ". "
                 << "ID Pinjam: " << idPinjam << endl
                 << "   Buku       : " << namaBuku << " (ID: " << idBuku << ")" << endl
                 << "   Anggota    : " << namaAnggota << " (ID: " << idAnggota << ")" << endl
                 << "   Tgl Pinjam : " << tanggalPinjam << endl
                 << "   Tgl Kembali: " << tanggalKembali << endl
                 << "   Status     : Belum kembali" << endl << endl;
        }
    }
    output.close();

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Kembali ke menu tampilan (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}

void TampilBuku(){
    vector <buku> kolom;
    buku v;
    int nomor = 1;
    cout << "Daftar Buku" << endl;

    ifstream file("buku.txt");
    string line;

    while(getline(file,line)){
        int pos1 = line.find(';');
        int pos2 = line.find(';',pos1+1);
        int pos3 = line.find(';',pos2+1);
        int pos4 = line.find(';',pos3+1);
        int pos5 = line.find(';',pos4+1);
        int pos6 = line.find(';',pos5+1);

        v.idbuku = line.substr(0,pos1);
        v.isbn = line.substr(pos1+1,pos2-pos1-1);
        v.judul = line.substr(pos2+1,pos3-pos2-1);
        v.pengarang = line.substr(pos3+1,pos4-pos3-1);
        v.penerbit = line.substr(pos4+1,pos5-pos4-1);
        v.tahunTerbit = stoi(line.substr(pos5+1,pos6-pos5-1));
        v.stok = stoi(line.substr(pos6+1));

        kolom.push_back(v);
    }
    file.close();

    sort(kolom.begin(), kolom.end(), 
    [](const buku &x,const buku &y) {
         return x.judul < y.judul;
    });

    for(int i = 0;i < kolom.size();i++){
        buku w = kolom[i];
        cout << nomor++ << ". " 
             << "Nama : " << w.judul << " ( Id Buku : " << w.idbuku << " , ISBN : " << w.isbn << ")" << endl << "- Dikarang oleh " << w.pengarang
             << " dan diterbitkan oleh " << w.penerbit << " pada tahun " << w.tahunTerbit << "." << endl 
             << "Stok sekarang : " << w.stok << endl << endl;
    }

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Kembali ke menu tampilan (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}

void TampilAnggota(){
    vector <anggota> daftar;
    anggota h;
    int nomor = 1;
    cout << "Daftar Anggota" << endl;

    ifstream file("anggota.txt");
    string line;

    while(getline(file,line)){
        int pos1 = line.find(';'); 
        int pos2 = line.find(';',pos1+1);
        int pos3 = line.find(';',pos2+1);
        int pos4 = line.find(';',pos3+1);
        int pos5 = line.find(';',pos4+1);
        int pos6 = line.find(';',pos5+1);

        h.idanggota = line.substr(0,pos1);
        h.kodeAnggota1 = line.substr(pos1+1,pos2-pos1-1);
        h.nama = line.substr(pos2+1,pos3-pos2-1);

        string tgl = line.substr(pos3+1,pos4-pos3-1);
        int garis = tgl.find('-');
        int garis2 = tgl.find('-',garis+1);
        h.tanggal = stoi(tgl.substr(0,garis));
        h.bulan = stoi(tgl.substr(garis+1,garis2-garis-1));
        h.tahun = stoi(tgl.substr(garis2+1));

        h.alamat = line.substr(pos4+1,pos5-pos4-1);
        h.email = line.substr(pos5+1,pos6-pos5-1);
        string kataStatus = line.substr(pos6+1);

        if(kataStatus == "1"){
            h.strStatus = "Aktif";
        } else { h.strStatus = "Tidak Aktif"; }

        daftar.push_back(h);
    }
    file.close();

    sort(daftar.begin(), daftar.end(), 
    [](const anggota &w,const anggota &y) {
         return w.nama < y.nama;
    });

    for(int i = 0;i < daftar.size();i++){
        anggota p = daftar[i];
        cout << nomor++ << ". " 
             << "Nama : " << p.nama << " ( ID : " << p.idanggota << ", Kode : " << p.kodeAnggota1 << ")" << endl
             << "Tanggal Lahir : " << p.tanggal << "-" << p.bulan << "-" << p.tahun << endl
             << "Alamat : " << p.alamat << endl
             << "Email : " << p.email << endl
             << "Status : " << p.strStatus << endl << endl;
    }

    string nol;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(true){
       cout << "Kembali ke menu tampilan (ketik 0) : ";
       getline(cin,nol);
       if(nol == "0"){
        break;
        } else { cout << "Anda harus ketik 0 jika ingin kembali" << endl; }
    }
    system("cls");
    return;
}

void MenuTampilan(){
    int nomor;
    do{ 
    cout << "1. Tampilkan Buku" << endl;
    cout << "2. Tampilkan Anggota" << endl;
    cout << "3. Tampilkan Anggota yang belum mengembalikan" << endl;
    cout << "0. Kembali ke Menu Utama" << endl;
    cout << "Masukkan sesuai Menu : ";
    cin >> nomor;

    if(nomor==0){
        system("cls");
        return;
    }
    else if(nomor==1){
        system("cls");
        TampilBuku();
    }
    else if(nomor==2){
        system("cls");
        TampilAnggota();
    }
    else if(nomor==3){
        system("cls");
        TampilPinjam();
    }
    } while(true);

}

void GantiPasswordUtama() {
    string pilihan;
    while(true){
        cout << "1. Ganti Password Admin Utama" << endl;
        cout << "2. Ganti Password Admin Lain" << endl;
        cout << "0. Kembali" << endl;
        cout << "Masukkan Menu : ";
        getline(cin,pilihan);

        if(pilihan=="0") { system("cls"); return; }
        else if(pilihan=="1" || pilihan=="2"){ break; }
        else { cout << "Tolong input menu yang benar!" << endl; }
    }

    if(pilihan=="1"){
        while(true){
            string sandi1, sandi2;
            system("cls");
            cout << "Masukkan Sandi lama : ";
            getline(cin,sandi1);
            cout << "Masukkan Sandi Baru : ";
            getline(cin,sandi2);

            ifstream file1("petugas.txt");
            ofstream temp("tempPetugas.txt");
            string line;
            bool ketemu = false;

            while(getline(file1,line)){
                int pos1 = line.find(';');
                int pos2 = line.find(';',pos1+1);
                int pos3 = line.find(';',pos2+1);
                int pos4 = line.find(';',pos3+1);
                int pos5 = line.find(';',pos4+1);

                string idadmin = line.substr(0,pos1);
                string nickname = line.substr(pos1+1,pos2-pos1-1);
                string level = line.substr(pos2+1,pos3-pos2-1);
                string password = line.substr(pos3+1,pos4-pos3-1);
                string nama = line.substr(pos4+1,pos5-pos4-1);
                string status = line.substr(pos5+1);

                if(password==sandi1 && level=="1"){
                    password = sandi2;
                    ketemu = true;
                }

                temp << idadmin << ";" << nickname << ";" << level << ";" << password << ";" << nama << ";" << status << endl;
            }
            file1.close();
            temp.close();
            remove("petugas.txt");
            rename("tempPetugas.txt", "petugas.txt");

            if(ketemu){
                cout << "Password berhasil diganti!" << endl;
                break;
            } else {
                cout << "Password lama salah!" << endl;
                while(true){
                    cout << "Apakah ingin mencoba lagi? (1 = ya, 0 = kembali ke menu) : ";
                    string opsi;
                    getline(cin, opsi);
                    if(opsi=="1"){ break; }  
                    else if(opsi=="0"){ return; } 
                    else { cout << "Input salah, masukkan 1 atau 0!" << endl; }
                }
            }
        }
    }
    else if(pilihan=="2"){
        while(true){
            string adminBiasa, sandiBaru;
            cout << "Masukkan ID Admin Biasa yang akan diganti : ";
            getline(cin, adminBiasa);
            cout << "Sandi Baru : ";
            getline(cin, sandiBaru);

            ifstream file2("petugas.txt");
            ofstream temp("tempPetugas.txt");
            string line;
            bool ditemukan = false;

            while(getline(file2,line)){
                int pos1 = line.find(';');
                int pos2 = line.find(';',pos1+1);
                int pos3 = line.find(';',pos2+1);
                int pos4 = line.find(';',pos3+1);
                int pos5 = line.find(';',pos4+1);

                string idadmin = line.substr(0,pos1);
                string nickname = line.substr(pos1+1,pos2-pos1-1);
                string level = line.substr(pos2+1,pos3-pos2-1);
                string password = line.substr(pos3+1,pos4-pos3-1);
                string nama = line.substr(pos4+1,pos5-pos4-1);
                string status = line.substr(pos5+1);

                if(idadmin==adminBiasa){
                    password = sandiBaru;
                    ditemukan = true;
                }

                temp << idadmin << ";" << nickname << ";" << level << ";" << password << ";" << nama << ";" << status << endl;
            }
            file2.close();
            temp.close();
            remove("petugas.txt");
            rename("tempPetugas.txt", "petugas.txt");

            if(ditemukan){
                cout << "Password berhasil diganti!" << endl;
                break;
            } else {
                cout << "ID Admin tidak ditemukan!" << endl;
                while(true){
                    cout << "Apakah ingin mencoba lagi? (1 = ya, 0 = kembali ke menu) : ";
                    string opsi;
                    getline(cin, opsi);
                    if(opsi=="1"){ break; } 
                    else if(opsi=="0"){ return; } 
                    else { cout << "Input salah, masukkan 1 atau 0!" << endl; }
                }
            }
        }
    }

    string nol;
    while(true){
        cout << "Kembali ke menu tampilan (ketik 0) : ";
        getline(cin,nol);
        if(nol=="0") break;
        else cout << "Anda harus ketik 0 jika ingin kembali" << endl;
    }
    system("cls");
}

void GantiPasswordAdminBiasa(string idLogin) { 
    while (true) {
        string sandiBaru;
        cout << "Masukkan Sandi Baru : ";
        getline(cin, sandiBaru);

        ifstream file("petugas.txt");
        if (!file.is_open()) {
            cout << "File petugas.txt tidak bisa dibuka!" << endl;
            return;
        }

        ofstream temp("tempPetugas.txt");
        string line;
        bool ditemukan = false;

        while (getline(file, line)) {
            int pos1 = line.find(';');
            int pos2 = line.find(';', pos1 + 1);
            int pos3 = line.find(';', pos2 + 1);
            int pos4 = line.find(';', pos3 + 1);
            int pos5 = line.find(';', pos4 + 1);

            string idadmin = line.substr(0, pos1);
            string username = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string level = line.substr(pos2 + 1, pos3 - pos2 - 1);
            string password = line.substr(pos3 + 1, pos4 - pos3 - 1);
            string nama = line.substr(pos4 + 1, pos5 - pos4 - 1);
            string status = line.substr(pos5 + 1);

            if (username == idLogin) { 
                password = sandiBaru;
                ditemukan = true;
            }

            temp << idadmin << ";" << username << ";" << level << ";" << password << ";" << nama << ";" << status << endl;
        }

        file.close();
        temp.close();

        remove("petugas.txt");
        rename("tempPetugas.txt", "petugas.txt");

        if (ditemukan) {
            cout << "Password berhasil diganti!" << endl;
            break;
        } else {
            cout << "Terjadi kesalahan, password gagal diganti!" << endl;
            return;
        }
    }

    string nol;
    while (true) {
        cout << "Kembali ke menu tampilan (ketik 0) : ";
        getline(cin, nol);
        if (nol == "0") break;
        else cout << "Anda harus ketik 0 jika ingin kembali" << endl;
    }
    system("cls");
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
    cout << "9. Aktif & Non-aktifkan (Admin & Anggota)" << endl;
    cout << "10. Hapus Buku" << endl;
    cout << "11. Tampilkan Buku, Anggota dan Peminjam"<<endl;
    cout << "12. Ganti Password" << endl;
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
        tampilanAktif();
    }
    else if(pilih==10){
        system("cls");
        HapusBuku();
    }
    else if(pilih==11){
        system("cls");
        MenuTampilan();
    }
    else if(pilih==12){
        system("cls");
        GantiPasswordUtama();
    }
} while(true);
}

void AdminBiasa(string admin){
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
    cout << "8. Non-Aktif & Aktifkan Anggota" << endl;
    cout << "9. Hapus Buku" << endl;
    cout << "10. Tampilkan Buku, Anggota atau Peminjam" << endl;
    cout << "11. Ganti Password" << endl;
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
        biasatampilanAktif();
    }
    else if(pilih==9){
        system("cls");
        HapusBuku();
    }
    else if(pilih==10){
        system("cls");
        MenuTampilan();
    }
    else if(pilih==11){
        system("cls");
        GantiPasswordAdminBiasa(admin);
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


void login() {
    int menu;
    cout << "Menu Perpustakaan Sederhana" << endl;
    cout << "===========================" << endl;
    cout << "1. Login sebagai Petugas" << endl;
    cout << "2. Login sebagai Siswa" << endl;

    while (true) {
        cout << "Pilihan Menu : ";
        cin >> menu;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (menu > 2 || menu == 0)
            cout << "Tolong pilih sesuai menu!" << endl;
        else
            break;
    }

    if (menu == 1) { 
        while (true) {
            string username, password;
            cout << "Masukkan Username (atau ketik 0 untuk kembali) : ";
            getline(cin, username);
            if (username == "0") return;

            cout << "Masukkan Password : ";
            getline(cin, password);

            ifstream file("petugas.txt");
            if (!file.is_open()) {
            }

            string line;
            bool ketemu = false;
            while (getline(file, line)) {
                int pos1 = line.find(';');
                int pos2 = line.find(';', pos1 + 1);
                int pos3 = line.find(';', pos2 + 1);
                int pos4 = line.find(';', pos3 + 1);
                int pos5 = line.find(';', pos4 + 1);

                string idAdmin = line.substr(0, pos1);
                string usernameAdmin = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string level = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string passwordAdmin = line.substr(pos3 + 1, pos4 - pos3 - 1);
                string nama = line.substr(pos4 + 1, pos5 - pos4 - 1);
                string status = line.substr(pos5 + 1);

                if (username == usernameAdmin) {
                    ketemu = true;
                    if (password == passwordAdmin) {
                        file.close();
                        if (level == "1") {
                            cout << "Login berhasil!" << endl;
                            system("cls");
                            InterfaceAdminUtama();
                            return;
                        } else if (level == "0" && status == "AKTIF") {
                            cout << "Login berhasil!" << endl;
                            system("cls");
                            AdminBiasa(idAdmin);
                            return;
                        } else {
                            cout << "Akun tidak aktif!" << endl;
                            return;
                        }
                    } else {
                        cout << "Password salah! Coba lagi." << endl;
                        ketemu = true;
                        break; 
                    }
                }
            }

            file.close();
            if (!ketemu) {
                cout << "Username tidak ditemukan! Coba lagi." << endl;
            }
        }
    } 
    else if (menu == 2) {
        while (true) {
            string nama, kode;
            cout << "Masukkan Username (atau ketik 0 untuk kembali) : ";
            getline(cin, nama);
            if (nama == "0") return;

            cout << "Masukkan Kode Anggota : ";
            getline(cin, kode);

            ifstream file("anggota.txt");
            if (!file.is_open()) {
                return;
            }

            string line;
            bool ketemu = false;

            while (getline(file, line)) {
                int pos1 = line.find(';');
                int pos2 = line.find(';', pos1 + 1);
                int pos3 = line.find(';', pos2 + 1);
                int pos4 = line.find(';', pos3 + 1);
                int pos5 = line.find(';', pos4 + 1);
                int pos6 = line.find(';', pos5 + 1);

                string id = line.substr(0, pos1);
                string kodeSiswa = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string namaSiswa = line.substr(pos2 + 1, pos3 - pos2 - 1);
                string tanggal = line.substr(pos3 + 1, pos4 - pos3 - 1);
                string alamat = line.substr(pos4 + 1, pos5 - pos4 - 1);
                string email = line.substr(pos5 + 1, pos6 - pos5 - 1);
                string statusSiswa = line.substr(pos6 + 1);

                if (nama == namaSiswa) {
                    ketemu = true;
                    if (kode == kodeSiswa) {
                        if (statusSiswa == "0") {
                            cout << "Akun Tidak Aktif" << endl;
                            break;
                        } else {
                            cout << "Login berhasil!" << endl;
                            system("cls");
                            InterfaceAnggota();
                            return;
                        }
                    } else {
                        cout << "Kode berbeda! Coba lagi." << endl;
                        break;
                    }
                }
            }

            file.close();
            if (!ketemu) {
                cout << "Data tidak ketemu! Coba lagi." << endl;
            }
        }
    }
}


int main(){
    login();
}


