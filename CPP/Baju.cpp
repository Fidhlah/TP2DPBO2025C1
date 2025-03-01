#include <iostream>
#include <string>
#include "Aksesoris.cpp"

class Baju : public Aksesoris{
    private:
        std::string untuk;
        std::string size;
        std::string merk;
    
    public:
        // Konstruktor
        Baju() : Aksesoris(){
            this->untuk = "";
            this->size = "";
            this->merk = "";
        }

        // Konstruktor dengan parameter
        Baju(std::string ID, std::string nama, int harga_produk, int stok_produk, std::string jenis, std::string bahan, std::string warna, std::string untuk, std::string size, std::string merk) 
        : Aksesoris(ID, nama, harga_produk, stok_produk, jenis, bahan, warna){
            this->untuk = untuk;
            this->size = size;
            this->merk = merk;
        }

        // Setter
        void set_untuk(std::string untuk) {this->untuk = untuk;}
        void set_size(std::string size) {this->size = size;}
        void set_merk(std::string merk) {this->merk = merk;}

        // Getter
        std::string get_untuk() {return this->untuk;}
        std::string get_size() {return this->size;}
        std::string get_merk() {return this->merk;}

};