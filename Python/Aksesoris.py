from Petshop import Petshop

class Aksesoris(Petshop):
    # Konstruktor
    def __init__(self, ID="", nama="", hargaProduk=0, stokProduk=0, jenis="", bahan="", warna=""):
        super().__init__(ID, nama, hargaProduk, stokProduk) # Konstruktor Petshop
        
        self.jenis = jenis
        self.bahan = bahan
        self.warna = warna
    
    # Setter
    def set_jenis(self, jenis):
        self.jenis = jenis
        
    def set_bahan(self, bahan):
        self.bahan = bahan
        
    def set_warna(self, warna):
        self.warna = warna
    
    # Getter
    def get_jenis(self):
        return self.jenis
        
    def get_bahan(self):
        return self.bahan
        
    def get_warna(self):
        return self.warna