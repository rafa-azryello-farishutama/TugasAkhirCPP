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
    string idpetugas;
    string username;
    string password;
    string nama;
    int noadmin;
};

int HitungUrutan(string Tahun,string Bulan,string Tanggal){
    ifstream file("anggota.txt"); 
    if (file.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
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
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
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
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
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
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
    }
fileOutput << x.idanggota << ";"<< kodeanggota << ";" << x.nama << ";" << x.tanggal << "-" << x.bulan << 
             "-" << x.tahun << ";" << x.alamat << ";" << x.email << ";" << x.status<<endl;
fileOutput.close();
cout << "Data Siswa berhasil ditambahkan!";

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
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
    }
    fileOutput << a.idbuku << ";" << a.isbn << ";" << a.judul << ";" << a.pengarang 
               << ";" << a.penerbit << ";" << a.tahunTerbit << ";" << a.stok << endl;
    fileOutput.close();
    cout << "Data Buku berhasil ditambahkan!";

}

int MenghasilkanIDadmin(){
    ifstream file("petugas.txt");
    if (file.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
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
    int ID = MenghasilkanIDadmin();
    string nomer = to_string(ID); 
    while (nomer.length() < 4) {
        nomer = "0" + nomer;
    }
    b.idpetugas = "AD" + nomer;


    ofstream fileOutput("petugas.txt",ios::app);
    if (fileOutput.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
    }
    fileOutput << b.idpetugas << ";" << b.username << ";" << b.noadmin << ";"
               << b.password << ";" << b.nama << endl;
    fileOutput.close();
    cout << "Data Admin berhasil ditambahkan!";
}

void CariAnggota() {
    string katakunci;
    cout << "Masukkan Anggota Kode : ";
    getline(cin,katakunci);

    ifstream fileOutput("anggota.txt");
    if (fileOutput.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
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
            cout << "Status Siswa : "<<status;
            fileOutput.close();
            return;
        }
    }
    cout << "Data tidak ditemukan!";
    fileOutput.close();
}

void CariBuku(){
    string katakunci;
    cout << "Masukkan Judul Buku : ";
    getline(cin,katakunci);

    ifstream file("buku.txt");
    if (file.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
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
            cout << "Stok : "<<stok;
            file.close();
            return;
        }
    }
    cout << "Data tidak ditemukan!";
    file.close();
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

void RequestPeminjaman(){
    peminjaman m;
    string idanggota,idbuku;
    while(true){ 
    cout << "Masukkan ID Anggota: ";
    getline(cin,idanggota);

    ifstream file("anggota.txt");
    if (file.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
    }
    string line;
    bool found = false;
    while(getline(file,line)){
        if(line.find(idanggota)!= string::npos){
            found = true;
            break;
        }
    }
    file.close();

    if(found){
        break;
    } else {
        cout << "ID tidak ditemukan" << endl;
    }
    }

    while(true){
        cout << "Masukkan ID Buku : ";
        getline(cin,idbuku);

        ifstream File("buku.txt");
        if (File.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
    }
        string line;
        bool found = false;
        while(getline(File,line)){
            if(line.find(idbuku)!=string::npos){
                found = true;
                break;
            }
        }
        File.close();

        if(found){
            break;
        } else {
            cout << "ID Tidak ditemukan" << endl;
        }
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

    ofstream fileOutput("requestpeminjaman.txt",ios::app);
    if (fileOutput.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
    }
fileOutput << idbuku << ";"<< idanggota << ";" << m.tanggalPinjam << "-" << m.bulanPinjam <<
             "-" << m.tahunPinjam << ";" << m.tanggalKembali << "-" << m.bulanKembali << "-" <<
             m.tahunKembali << endl;
cout << "Request telah dikirim!";

    }

void InterfaceAdminUtama(){
    string menu;
    int pilih;
    cout << "Menu Admin Utama" << endl;
    cout << "1. Tambah Anggota" << endl;
    cout << "2. Tambah Buku" << endl;
    cout << "3. Cari Anggota" << endl;
    cout << "4. Cari Buku" << endl;
    cout << "5. Tambah Admin" << endl;
    
    while(true){
    cout << "Masukkan Pilihan : ";
    getline(cin,menu);
    pilih = stoi(menu);

    if(pilih > 5){
        cout << "Tolong Pilih sesuai angka!";
    }
    else if(pilih == 0){
        cout << "Menu tidak boleh kosong!";
    }
    else{
        break;
    }
    }

    if(pilih==1){
        TambahAnggota();
    }
    else if(pilih==2){
        TambahBuku();
    }
    else if(pilih==3){
        CariAnggota();
    }
    else if(pilih==4){
        CariBuku();
    }
    else if(pilih==5){
        TambahAdmin();
    }
}

void InterfaceAdminBiasa(){
    string menu;
    int pilih;
    cout << "Menu Admin Utama" << endl;
    cout << "1. Tambah Anggota" << endl;
    cout << "2. Tambah Buku" << endl;
    cout << "3. Cari Anggota" << endl;
    cout << "4. Cari Buku" << endl;
    
    while(true){
    cout << "Masukkan Pilihan : ";
    getline(cin,menu);
    pilih = stoi(menu);

    if(pilih > 5){
        cout << "Tolong Pilih sesuai angka!";
    }
    else if(pilih == 0){
        cout << "Menu tidak boleh kosong!";
    }
    else{
        break;
    }
    }

    if(pilih==1){
        TambahAnggota();
    }
    else if(pilih==2){
        TambahBuku();
    }
    else if(pilih==3){
        CariAnggota();
    }
    else if(pilih==4){
        CariBuku();
    }
}

void InterfaceAnggota(){
    string menu;
    int pilihan;
    cout << endl << "Daftar Menu" << endl;
    cout << "1. Cari Buku" << endl;
    cout << "2. Request Peminjaman" << endl;
    while(true){
    cout << "Pilihan Menu : ";
    getline(cin,menu);

    pilihan = stoi(menu);
    if(pilihan>2){
        cout << "Tolong pilih menu yang disediakan" << endl;
    }
    else{
        break;
    }
}   
if(pilihan==1){
    CariBuku();
}
else if(pilihan==2){
    RequestPeminjaman();
}
else{
    return;
}
    
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
    cin.ignore();

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
        if (file.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
    }
        string line;
        bool ketemu = false;

        while(getline(file,line)){
            int posisi1 = line.find(';');
            int posisi2 = line.find(';',posisi1 + 1);
            int posisi3 = line.find(';',posisi2 + 1);
            int posisi4 = line.find(';',posisi3 + 1);

            string idAdmin = line.substr(0,posisi1);
            string usernameAdmin = line.substr(posisi1 + 1, posisi2-posisi1-1);
            string statusAdmin = line.substr(posisi2 + 1, posisi3-posisi2-1);
            string passwordAdmin = line.substr(posisi3 + 1,posisi4-posisi3-1);

            if(username == usernameAdmin){
                ketemu = true;
                if(password == passwordAdmin){
                    if(statusAdmin == "1"){
                        InterfaceAdminUtama();
                    }
                    else{
                        InterfaceAdminBiasa();
                    }
                }
                else{
                    cout << "Password tidak terdeteksi!";
                }
                break;
            }

        }
        file.close();

        if(!ketemu){
            cout << "Data tidak ditemukan";
        }
    }
    
    else if(menu==2){
        string nama, kode;
        cout << "Masukkan Username : ";
        getline(cin,nama);
        cout << "Masukkan Kode Anggota : ";
        getline(cin,kode);

        ifstream file("anggota.txt");
        if (file.is_open()){
        cout << "File telah sukses dibuka!\n";
    }
    else {
        cout << "File gagal dibuka\n";
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


