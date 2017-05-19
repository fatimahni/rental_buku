#include<iostream>
#include<string.h>
#include <sstream>

using namespace std;

class Buku {

	protected:
		string isbn, tgl_terbit, nama;
		float harga, harga_pinjam, nilai_denda;
		
	public:
		Buku(string newIsbn, string newTglTerbit, string newNama, float newHarga){
			isbn = newIsbn;
			tgl_terbit = newTglTerbit;
			nama = newNama;
			harga = newHarga;
			
			if (harga >= 10000 && harga <= 100000){
				harga_pinjam = 1500;
				nilai_denda = 500;
			} else if (harga > 100000 && harga <= 500000){
				harga_pinjam = 5000;
				nilai_denda = 1000;
			} else if (harga > 500000){
				harga_pinjam = 10000;
				nilai_denda = 2000;
			} else {
				// harga di bawah 10000
				harga_pinjam = 1000;
				nilai_denda = 500;
			}
		}
		
		string getNama(){
			return nama;
		}
		
		float getHargaPinjam(){
			return harga_pinjam;
		}
		
		float getTotalnilaiDenda(int jml_terlambat){
			return nilai_denda*jml_terlambat;
		}
};


class Novel:public Buku {
	protected:
		string author, genre;
		
	public:
		Novel(string newIsbn, string newTglTerbit, string newNama, float newHarga, string newAuthor, string newGenre):Buku(newIsbn, newTglTerbit, newNama, newHarga){
			author = newAuthor;
			genre = newGenre;
		}
};


class Komik:public Buku {
	protected:
		string author, genre;
		int volume;
		
	public:
		Komik(string newIsbn, string newTglTerbit, string newNama, float newHarga, string newAuthor, string newGenre, int newVolume):Buku(newIsbn, newTglTerbit, newNama, newHarga){
			author = newAuthor;
			genre = newGenre;
			volume = newVolume;
		}
};


class Majalah:public Buku {
	protected:
		string edisi_bulan;
		
	public:
		Majalah(string newIsbn, string newTglTerbit, string newNama, float newHarga, string newEdisi):Buku(newIsbn, newTglTerbit, newNama, newHarga){
			edisi_bulan  = newEdisi;
		}
};


class Anggota {
	protected:
		string no_anggota, nama, alamat, no_hp;
		
	public:
		Anggota(string no, string newNama, string newAlamat, string newNoHp){
			no_anggota = no;
			nama = newNama;
			alamat = newAlamat;
			no_hp = newNoHp;
		}
		
		string getNama(){
			return nama;
		}
		
		string getNoAnggota(){
			return no_anggota;
		}
};


int main(){
	Novel novel1 = Novel("11111", "13/03/2017", "Curhatan Seorang Istri", 300000, "Vivit Kumalasari", "Kesehatan");
	Novel novel2 = Novel("22222", "13/05/2016", "Kiamat Sudah Dekat", 50000, "Sri Wahyuni", "Rohani");
	Komik komik1 = Komik("33333", "03/12/2014", "Naruto Shipudden", 75000, "Fatimah Nurul Insani", "Anime", 3);
	Majalah majalah1 = Majalah("44444", "14/12/2013", "Majalah Ibu Hamil", 550000, "Sabtu");
	
	Anggota m1 = Anggota("001", "Fatimah Nurul Insani", "Jl. Antasari", "087987677876");
	Anggota m2 = Anggota("002", "Iis Anisa", "Jl. Tegalega", "08798767786");
	Anggota m3 = Anggota("003", "Vivit Kumalasari", "Jl. Cimahi", "08765644543");
	
	string num;
	while (num != "1"){
		cout << "Pilih 1 untuk exit atau Masukkan no anggota\n";
		cin >> num;
		Anggota *m = NULL;
		if (num == "001"){
			m = &m1;
		} else if (num == "002"){
			m = &m2;
		} else if (num == "003"){
			m = &m3;
		}
		
		if (m != NULL){
			system("CLS");
			string book;
			int qty = 0;
			float total = 0;
			
			stringstream stream;
			while (book != "1"){
				cout << "Pilih 1 untuk selesai atau masukan kode buku\n";
				cin >> book;
				system("CLS");
				
				if (book != "11111" && book != "22222" && book != "33333" && book != "44444"){
					cout << "buku tidak terdaftar!\n";
				} else if (book != "1"){
					cout << "masukan qty :";
					cin >> qty;
					if (book == "11111"){
						total += novel1.getHargaPinjam()*qty;
						stream << novel1.getNama() << "\tRp. " << novel1.getHargaPinjam() << "\t" << qty <<"\tRp. " << novel1.getHargaPinjam()*qty << "\n";
					} else if (book == "22222"){
						total += novel2.getHargaPinjam()*qty;
						stream << novel2.getNama() << "\tRp. " << novel2.getHargaPinjam() << "\t" << qty << "\tRp. " << novel2.getHargaPinjam()*qty << "\n";
					} else if (book == "33333"){
						total += komik1.getHargaPinjam()*qty;
						stream << komik1.getNama() << "\tRp. " << komik1.getHargaPinjam() << "\t" << qty << "\tRp. " << komik1.getHargaPinjam()*qty << "\n";
					} else if (book == "44444"){
						total += majalah1.getHargaPinjam()*qty;
						stream << majalah1.getNama() << "\tRp. " << majalah1.getHargaPinjam() << "\t" << qty << "\tRp. " << majalah1.getHargaPinjam()*qty << "\n";
					} else {
						cout << "Buku tidak ada di database.\n";
					}
					system("CLS");
					cout << "No Anggota : " << m->getNoAnggota() + "\tNama : " << m->getNama();
					cout << "\nNama Buku\t\tHarga\t\tQty\tSub Total" << endl;					
					cout << stream.str();
				}
			}
			
			if (total > 0){
				float bayar;
				while (bayar < total){
					
					cout << "Masukkan jumlah bayar :";
					cin >> bayar;
					
					cout << "No Anggota : " << m->getNoAnggota() + "\tNama : " << m->getNama();
					cout << "\nNama Buku\t\tHarga\t\tQty\tSub Total" << endl;					
					cout << stream.str();
					cout << "\t\t\t\tTotal\t\tRp. " << total << endl;
					cout << "\t\t\t\tPembayaran\tRp. " << bayar << endl;
					cout << "\t\t\t\tKembalian\tRp. " << bayar - total << endl;
				}
			}
		} else {
			cout << "member tidak terdaftar\n";
		}
	}
	return 0;
}


