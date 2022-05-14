#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
#include <cstring>

using namespace std;

struct rinci_alamat {
	int rt;
	int rw;
};

struct penduduk {
	int no_kk;
	string nama_kepala;
	string alamat;
	rinci_alamat rtrw;
	int jml_anggota; 
	string no_hp;
};	penduduk data_penduduk;

string replaceSpasi(string a){
    for(int i=0; a[i];i++){
		if(a[i]==' '){
			a[i]='_';
		}
	}
	return a;
}

string replaceGaris(string a){
    for(int i=0; a[i];i++){
		if(a[i]=='_'){
			a[i]=' ';
		}
	}
	return a;
}

void dataFileCheck(fstream &data);
char menu();

void inputData();
void outputData();
// void searchData();
// void deleteData();

main(){
	
	fstream data;
	dataFileCheck(data);

	char pil = menu();
	char lanjut;


	while (pil != '4'){
		switch(pil){
			case '1' : 
				inputData();
				break;
			case '2' : 
				outputData();
			break;
			case '3' : cout << "Cari Data";
			break;
			default: cout << "Pilihan Salah";
			break;
		}
		
		cout << "\nLanjutkan [y/n]? : "; cin >> lanjut;
		
		if (toupper(lanjut) == 'Y'){
			pil = menu();
		}
		else if (toupper(lanjut) == 'N'){
			break;
		}
		else {
			cout << "Pilihan Salah" << endl;
			pil = menu();
		}
		
	}

	cout << "Program Selesai";

}

//cek eksistensi file penyimpanan data
void dataFileCheck(fstream &data) {
	data.open("data.txt", ios::out | ios::in | ios::app);
	if (!data.is_open()){
		data.close();
		data.open("data.txt", ios::trunc | ios::out | ios::in | ios::app);
		data.close();
	}
}

//halaman menu
char menu(){
	system("cls");
	cout << "Program Pendataan Penduduk\n";
	cout << "1. Tambah Data\n";
	cout << "2. Lihat Data\n";
	cout << "3. Cari Data\n";
	cout << "4. Keluar\n";
	cout << "Pilih [1-4] : "; 
	char pil;
	cin >> pil;
	return pil;
}

//input data
void inputData(){
	system("cls");
	cout << "=====Tambah Data=====\n";
	cout << "Nomor KK\t: ";
	cin >> data_penduduk.no_kk;
	cin.ignore();
	cout << "Kepala Keluarga\t: ";
	getline(cin, data_penduduk.nama_kepala);
		data_penduduk.nama_kepala = replaceSpasi(data_penduduk.nama_kepala);
	cout << "Jumlah Anggota Keluarga\t: ";
	cin >> data_penduduk.jml_anggota;
	cin.ignore();
	cout << "\tAlamat\t: ";
	getline(cin, data_penduduk.alamat);
		data_penduduk.alamat = replaceSpasi(data_penduduk.alamat);
	cout << "\tRT\t: ";
	cin >> data_penduduk.rtrw.rt;
	cout << "\tRW\t: ";
	cin >> data_penduduk.rtrw.rw;
	cin.ignore();
	cout << "Nomor HP\t: ";
	getline(cin, data_penduduk.no_hp);
    
    ofstream data;
	data.open("data.txt", ios::app);
		data << data_penduduk.no_kk
			<< " " << data_penduduk.nama_kepala << " "<< data_penduduk.alamat << " "
			<< data_penduduk.rtrw.rt << " " << data_penduduk.rtrw.rw
			<< " " << data_penduduk.jml_anggota << " " << data_penduduk.no_hp << endl;
	data.close();
	
	cout << "\n\nInput data selesai!";
}

// output data resmi tamat
void outputData(){
	penduduk temp[128];
	int i = 0;
	cout << "=====Menampilkan Data=====\n\n";
	ifstream data;
	data.open("data.txt");

	while(!data.eof()) {

	data >> data_penduduk.no_kk
			>> data_penduduk.nama_kepala >> data_penduduk.alamat
			>> data_penduduk.rtrw.rt >> data_penduduk.rtrw.rw
			>> data_penduduk.jml_anggota >> data_penduduk.no_hp;
    	
	temp[i].no_kk = data_penduduk.no_kk;
	temp[i].nama_kepala = data_penduduk.nama_kepala;
	temp[i].alamat = data_penduduk.alamat;
	temp[i].rtrw.rt = data_penduduk.rtrw.rt;
	temp[i].rtrw.rw = data_penduduk.rtrw.rw;	
		 i++;
	}

	for(int j = 0; j < i-1; j++){
		cout << "Nomor KK\t: " << temp[j].no_kk << endl;
		cout << "Kepala Keluarga\t: " << replaceGaris(temp[j].nama_kepala) << endl;
		cout << "\tAlamat\t: " << replaceGaris(temp[j].alamat) << " " 
			<< "RT" << temp[j].rtrw.rt << "/" 
			<< "RW" << temp[j].rtrw.rw <<endl;

		cout << "=======================================\n\n";
	}

	data.close();
}