from Aksesoris import Aksesoris

class Baju(Aksesoris):
    # Konstruktor
    def __init__(self, ID="", nama="", hargaProduk=0, stokProduk=0, jenis="", bahan="", warna="", untuk="", size="", merk=""):
        super().__init__(ID, nama, hargaProduk, stokProduk, jenis, bahan, warna) # Konstruktor Aksesoris
        
        self.untuk = untuk
        self.size = size
        self.merk = merk
    
    # Setter
    def set_untuk(self, untuk):
        self.untuk = untuk
        
    def set_size(self, size):
        self.size = size
        
    def set_merk(self, merk):
        self.merk = merk
    
    # Getter
    def get_untuk(self):
        return self.untuk
        
    def get_size(self):
        return self.size
        
    def get_merk(self):
        return self.merk