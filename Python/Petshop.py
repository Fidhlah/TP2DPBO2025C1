class Petshop:
    # Konstruktor
    def __init__(self, ID="", nama_produk="", harga_produk=0, stok_produk=0):
        self.ID = ID               
        self.nama_produk = nama_produk  
        self.harga_produk = harga_produk    
        self.stok_produk = stok_produk     
    
    # Setter 
    def set_id(self, ID):
        self.ID = ID
        
    def set_nama_produk(self, nama_produk):
        self.nama_produk = nama_produk
        
    def set_harga_produk(self, harga_produk):
        self.harga_produk = harga_produk
        
    def set_stok_produk(self, stok_produk):
        self.stok_produk = stok_produk
    
    # Getter 
    def get_id(self):
        return self.ID
        
    def get_nama_produk(self):
        return self.nama_produk
        
    def get_harga_produk(self):
        return self.harga_produk
        
    def get_stok_produk(self):
        return self.stok_produk