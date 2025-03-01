/*
Saya Muhammad Hafidh Fadhilah dengan NIM 2305672 mengerjakan Tugas Praktikum 2 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.
*/
#include <iostream>
#include <string>
using namespace std;

class Petshop{
    private:
        // Atribut untuk menyimpan informasi produk
        string ID;            
        string nama_produk;   
        int harga_produk;     
        int stok_produk;     

    public:
        // Konstruktor
        Petshop(){
            this->ID = "";
            this->nama_produk = "";
            this->harga_produk = 0;
            this->stok_produk = 0;
        }

        // Konstruktor parameter
        Petshop(string ID, string nama_produk, int harga_produk, int stok_produk){
            this->ID = ID;
            this->nama_produk = nama_produk;
            this->harga_produk = harga_produk;
            this->stok_produk = stok_produk;
        }

        // Setter atribut
        void set_id(string ID) {this->ID = ID;}
        void set_nama_produk(string nama_produk){this->nama_produk = nama_produk;}
        void set_harga_produk(int harga_produk){ this->harga_produk = harga_produk;}
        void set_stok_produk(int stok_produk){this->stok_produk = stok_produk;}
        
        // Getter atribut
        string get_id(){return this->ID;}
        string get_nama_produk(){return this->nama_produk;}
        int get_harga_produk(){return this->harga_produk;}
        int get_stok_produk(){return this->stok_produk;}

        // Destructor 
        ~Petshop() {}
};
