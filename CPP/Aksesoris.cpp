#include <iostream>
#include <string>
#include "Petshop.cpp"

class Aksesoris : public Petshop
{
    private:
        std::string jenis;
        std::string bahan;
        std::string warna;
    
    public:
        // Konstruktor
        Aksesoris() : Petshop(){
            this->jenis = "";
            this->bahan = "";
            this->warna = "";
        }

        // Konstruktor dengan parameter
        Aksesoris(std::string ID, std::string nama, int harga_produk, int stok_produk, std::string jenis, std::string bahan, std::string warna) 
        : Petshop(ID, nama, harga_produk, stok_produk){
            this->jenis = jenis;
            this->bahan = bahan;
            this->warna = warna;
        }

        // Setter
        void set_jenis(std::string jenis) {this->jenis = jenis;}
        void set_bahan(std::string bahan) {this->bahan = bahan;}
        void set_warna(std::string warna) {this->warna = warna;}

        // Getter
        std::string get_jenis() {return this->jenis;}
        std::string get_bahan() {return this->bahan;}
        std::string get_warna() {return this->warna;}

};