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
};	penduduk data_penduduk;

//function menu

void dataFileCheck(fstream &data);
char menu();

void inputData(fstream &data);

// void editData();
// void deleteData();
// void searchData();

main(){
	
	fstream data;
	dataFileCheck(data);

	char pil = menu();
	char lanjut;


	while (pil != '5'){
		switch(pil){
			case '1' : 
				inputData(data);
				break;
			case '2' : cout << "Menampilkan Data";
			break;
			case '3' : cout << "Ubah Data";
			break;
			case '4' : cout << "Cari Data";
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
	cout << "3. Ubah Data\n";
	cout << "4. Cari Data\n";
	cout << "5. Keluar\n";
	cout << "Pilih <1-5> : "; 
	char pil;
	cin >> pil;
	return pil;
}

//input data
void inputData(fstream &data){
	system("cls");
	cout << "=====Tambah Data=====\n";
	cout << "Nomor KK\t: ";
	cin >> data_penduduk.no_kk;
	cin.ignore();
	cout << "Kepala Keluarga\t: ";
	getline(cin, data_penduduk.nama_kepala);
	cout << "\tAlamat\t: ";
	getline(cin, data_penduduk.alamat);
	cout << "\tRT\t: ";
	cin >> data_penduduk.rtrw.rt;
	cout << "\tRW\t: ";
	cin >> data_penduduk.rtrw.rw;
	cout << "Jumlah Anggota Keluarga\t: ";
	cin >> data_penduduk.jml_anggota;

	data.open("data.txt", ios::app);
		data << data_penduduk.no_kk;
		// << " " << data_penduduk.nama_kepala << " "<< data_penduduk.alamat << " "
		//  << data_penduduk.rtrw.rt << " " << data_penduduk.rtrw.rw << " " << data_penduduk.jml_anggota;
	data.close();
	
	cout << "\n\nInput data selesai!";
}


