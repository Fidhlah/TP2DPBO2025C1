#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <vector>
#include "Baju.cpp"

void displayBajuTable(const std::list<Baju>& listBaju) {
    // Inisialisasi panjang tiap kolom
    int idWidth = 4;         
    int namaWidth = 6;       
    int hargaWidth = 7;      
    int stokWidth = 6;       
    int jenisWidth = 7;      
    int bahanWidth = 7;      
    int warnaWidth = 7;      
    int untukWidth = 7;      
    int sizeWidth = 6;       
    int merkWidth = 6;       
    
    // Periksa semua data untuk mencari yang terpanjang
    for (auto baju : listBaju) {
        if (baju.get_id().length() > idWidth - 2) { idWidth = baju.get_id().length() + 2;}
        if (baju.get_nama_produk().length() > namaWidth - 2) {namaWidth = baju.get_nama_produk().length() + 2;}
        
        std::string hargaStr = std::to_string(baju.get_harga_produk()); // Convert ke string
        if (hargaStr.length() > hargaWidth - 2) {hargaWidth = hargaStr.length() + 2;}
        
        std::string stokStr = std::to_string(baju.get_stok_produk());   // Convert ke string
        if (stokStr.length() > stokWidth - 2) {stokWidth = stokStr.length() + 2;}
        
        if (baju.get_jenis().length() > jenisWidth - 2) {jenisWidth = baju.get_jenis().length() + 2;}
        if (baju.get_bahan().length() > bahanWidth - 2) {bahanWidth = baju.get_bahan().length() + 2;}
        if (baju.get_warna().length() > warnaWidth - 2) {warnaWidth = baju.get_warna().length() + 2;}
        if (baju.get_untuk().length() > untukWidth - 2) {untukWidth = baju.get_untuk().length() + 2;}
        if (baju.get_size().length() > sizeWidth - 2) {sizeWidth = baju.get_size().length() + 2;}
        if (baju.get_merk().length() > merkWidth - 2) {merkWidth = baju.get_merk().length() + 2;}
    }
    
    // Hitung total lebar tabel
    int totalWidth = 1 + idWidth + namaWidth + hargaWidth + stokWidth + 
                    jenisWidth + bahanWidth + warnaWidth + untukWidth + 
                    sizeWidth + merkWidth + 10;
    
    // Cetak garis atas
    for(int i = 0; i < totalWidth; i++){std::cout << "-";}
    std::cout << std::endl;
    
    std::cout << "|";
    
    // ID header
    std::string idHeader = " ID";
    std::cout << idHeader;
    for(int i = idHeader.length(); i < idWidth; i++){std::cout << " ";}
    
    std::cout << "|";
    
    // Nama header
    std::string namaHeader = " Nama";
    std::cout << namaHeader;
    for(int i = namaHeader.length(); i < namaWidth; i++){std::cout << " ";}
    
    std::cout << "|";
    
    // Harga header
    std::string hargaHeader = " Harga";
    std::cout << hargaHeader;
    for(int i = hargaHeader.length(); i < hargaWidth; i++){std::cout << " ";}
    
    std::cout << "|";
    
    // Stok header
    std::string stokHeader = " Stok";
    std::cout << stokHeader;
    for(int i = stokHeader.length(); i < stokWidth; i++){std::cout << " ";}
    
    std::cout << "|";
    
    // Jenis header
    std::string jenisHeader = " Jenis";
    std::cout << jenisHeader;
    for(int i = jenisHeader.length(); i < jenisWidth; i++){std::cout << " ";}
    
    std::cout << "|";
    
    // Bahan header
    std::string bahanHeader = " Bahan";
    std::cout << bahanHeader;
    for(int i = bahanHeader.length(); i < bahanWidth; i++){std::cout << " ";}
    
    std::cout << "|";
    
    // Warna header
    std::string warnaHeader = " Warna";
    std::cout << warnaHeader;
    for(int i = warnaHeader.length(); i < warnaWidth; i++){std::cout << " ";}
    
    std::cout << "|";
    
    // Untuk header
    std::string untukHeader = " Untuk";
    std::cout << untukHeader;
    for(int i = untukHeader.length(); i < untukWidth; i++){std::cout << " ";}
    
    std::cout << "|";
    
    // Size header
    std::string sizeHeader = " Size";
    std::cout << sizeHeader;
    for(int i = sizeHeader.length(); i < sizeWidth; i++){std::cout << " ";}
    
    std::cout << "|";
    
    // Merk header
    std::string merkHeader = " Merk";
    std::cout << merkHeader;
    for(int i = merkHeader.length(); i < merkWidth; i++){std::cout << " ";}
    
    std::cout << "|" << std::endl;
    
    // Cetak garis pemisah setelah header
    for(int i = 0; i < totalWidth; i++){std::cout << "-";}
    std::cout << std::endl;
    
    // Cetak data
    for(auto baju : listBaju){
        std::cout << "|";
        
        // ID
        std::string idStr = " " + baju.get_id();
        std::cout << idStr;
        for(int i = idStr.length(); i < idWidth; i++){std::cout << " ";}
        
        std::cout << "|";
        
        // Nama
        std::string namaStr = " " + baju.get_nama_produk();
        std::cout << namaStr;
        for(int i = namaStr.length(); i < namaWidth; i++){std::cout << " ";}
        
        std::cout << "|";
        
        // Harga
        std::string hargaStr = " " + std::to_string(baju.get_harga_produk());
        std::cout << hargaStr;
        for(int i = hargaStr.length(); i < hargaWidth; i++){std::cout << " ";}
        
        std::cout << "|";
        
        // Stok
        std::string stokStr = " " + std::to_string(baju.get_stok_produk());
        std::cout << stokStr;
        for(int i = stokStr.length(); i < stokWidth; i++){std::cout << " ";}
        
        std::cout << "|";
        
        // Jenis
        std::string jenisStr = " " + baju.get_jenis();
        std::cout << jenisStr;
        for(int i = jenisStr.length(); i < jenisWidth; i++){std::cout << " ";}
        
        std::cout << "|";
        
        // Bahan
        std::string bahanStr = " " + baju.get_bahan();
        std::cout << bahanStr;
        for(int i = bahanStr.length(); i < bahanWidth; i++){std::cout << " ";}
        
        std::cout << "|";
        
        // Warna
        std::string warnaStr = " " + baju.get_warna();
        std::cout << warnaStr;
        for(int i = warnaStr.length(); i < warnaWidth; i++){std::cout << " ";}
        
        std::cout << "|";
        
        // Untuk
        std::string untukStr = " " + baju.get_untuk();
        std::cout << untukStr;
        for(int i = untukStr.length(); i < untukWidth; i++) {std::cout << " ";}
        
        std::cout << "|";
        
        // Size
        std::string sizeStr = " " + baju.get_size();
        std::cout << sizeStr;
        for (int i = sizeStr.length(); i < sizeWidth; i++) {std::cout << " ";}
        
        std::cout << "|";
        
        // Merk
        std::string merkStr = " " + baju.get_merk();
        std::cout << merkStr;
        for(int i = merkStr.length(); i < merkWidth; i++){std::cout << " ";}
        
        std::cout << "|" << std::endl;
    }
    
    // Cetak garis pemisah bawah
    for(int i = 0; i < totalWidth; i++){std::cout << "-";}
    std::cout << std::endl;
}

int main(){
    std::list<Baju> listBaju;

    // Data Dummy
    //                       ID, Nama, Harga, Stok, Jenis, Bahan, Warna, Untuk, Size, Merk
    listBaju.push_back(Baju("ID001", "Kaos Kaki Anjing", 50000, 10, "Pakaian", "Katun", "Merah", "Anjing", "M", "PetFashion"));
    listBaju.push_back(Baju("ID002", "Baju Pertamina Kucing", 45000, 15, "Pakaian", "Poliester", "Biru", "Kucing", "S", "PetStyle"));
    listBaju.push_back(Baju("ID003", "Baju KPK Kucing", 30000, 8, "Pakaian", "Wol", "Hijau", "Kucing", "L", "CingCong"));
    listBaju.push_back(Baju("ID004", "Jubah Superman Kucing", 60000, 5, "Pakaian", "Poliester", "Merah", "Kucing", "M", "HeroPet"));
    listBaju.push_back(Baju("ID005", "Topeng Batman Anjing", 35000, 7, "Aksesoris", "Plastik", "Hitam", "Anjing", "L", "HeroPet"));

    // Tempat penampungan sementara
    std::string tempString;
    int tempInt;            

    std::string tambahdata; // Simpan input
    do{
        displayBajuTable(listBaju);
        std::cout << "Apakah kamu mau menambahkan data? (y/n)" << endl;
        std::getline(cin, tambahdata);
        if(tambahdata != "y" && tambahdata != "Y"){ // Jika jawabannya bukan y/Y maka program berhenti
            std::cout << "Terima kasih !" <<std::endl;
            return 0;
        }
        
        Baju tempBaju;  // Tempat penampungan sementara

        std::cout << "Masukkan ID: ";
        std::getline(cin, tempString);
        tempBaju.set_id(tempString);

        std::cout << "Masukkan Nama: ";
        std::getline(cin, tempString);
        tempBaju.set_nama_produk(tempString);

        std::cout << "Masukkan Harga: ";
        std::cin >> tempInt;
        cin.ignore();  
        tempBaju.set_harga_produk(tempInt);
        
        std::cout << "Masukkan Stok: ";
        std::cin >> tempInt;
        cin.ignore();  
        tempBaju.set_stok_produk(tempInt);

        std::cout << "Masukkan Jenis: ";
        std::getline(cin, tempString);
        tempBaju.set_jenis(tempString);
        
        std::cout << "Masukkan Bahan: ";
        std::getline(cin, tempString);
        tempBaju.set_bahan(tempString);

        std::cout << "Masukkan Warna: ";
        std::getline(cin, tempString);
        tempBaju.set_warna(tempString);

        std::cout << "Masukkan Untuk: ";
        std::getline(cin, tempString);
        tempBaju.set_untuk(tempString);

        std::cout << "Masukkan Size: ";
        std::getline(cin, tempString);
        tempBaju.set_size(tempString);

        std::cout << "Masukkan Merk: ";
        std::getline(cin, tempString);
        tempBaju.set_merk(tempString);
        
        listBaju.push_back(tempBaju);
        
        std::cout << std::endl;
    } while (1);

    return 0;
}
