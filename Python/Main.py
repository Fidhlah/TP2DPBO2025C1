from Petshop import Petshop
from Aksesoris import Aksesoris
from Baju import Baju

def display_baju_table(list_baju):
    # inisialisasi
    id_width = 4
    nama_width = 6
    harga_width = 7
    stok_width = 6
    jenis_width = 7
    bahan_width = 7
    warna_width = 7
    untuk_width = 7
    size_width = 6
    merk_width = 6
    
    # Cari terpanjang
    for baju in list_baju:
        if len(baju.get_id()) > id_width - 2:
            id_width = len(baju.get_id()) + 2
        
        if len(baju.get_nama_produk()) > nama_width - 2:
            nama_width = len(baju.get_nama_produk()) + 2
        
        harga_str = str(baju.get_harga_produk())  # Convert ke string
        if len(harga_str) > harga_width - 2:
            harga_width = len(harga_str) + 2
        
        stok_str = str(baju.get_stok_produk())    # Convert ke string
        if len(stok_str) > stok_width - 2:
            stok_width = len(stok_str) + 2
        
        if len(baju.get_jenis()) > jenis_width - 2:
            jenis_width = len(baju.get_jenis()) + 2
        
        if len(baju.get_bahan()) > bahan_width - 2:
            bahan_width = len(baju.get_bahan()) + 2
        
        if len(baju.get_warna()) > warna_width - 2:
            warna_width = len(baju.get_warna()) + 2
        
        if len(baju.get_untuk()) > untuk_width - 2:
            untuk_width = len(baju.get_untuk()) + 2
        
        if len(baju.get_size()) > size_width - 2:
            size_width = len(baju.get_size()) + 2
        
        if len(baju.get_merk()) > merk_width - 2:
            merk_width = len(baju.get_merk()) + 2
    
    # Hitung total
    total_width = (1 + id_width + nama_width + harga_width + stok_width +
                  jenis_width + bahan_width + warna_width + untuk_width +
                  size_width + merk_width + 10)
    
    # Print garis atas
    print("-" * total_width)
    
    print("|", end="")
    
    # ID
    id_header = " ID"
    print(id_header, end="")
    print(" " * (id_width - len(id_header)), end="")
    
    print("|", end="")
    
    # Nama
    nama_header = " Nama"
    print(nama_header, end="")
    print(" " * (nama_width - len(nama_header)), end="")
    
    print("|", end="")
    
    # Harga
    harga_header = " Harga"
    print(harga_header, end="")
    print(" " * (harga_width - len(harga_header)), end="")
    
    print("|", end="")
    
    # Stok
    stok_header = " Stok"
    print(stok_header, end="")
    print(" " * (stok_width - len(stok_header)), end="")
    
    print("|", end="")
    
    # Jenis
    jenis_header = " Jenis"
    print(jenis_header, end="")
    print(" " * (jenis_width - len(jenis_header)), end="")
    
    print("|", end="")
    
    # Bahan
    bahan_header = " Bahan"
    print(bahan_header, end="")
    print(" " * (bahan_width - len(bahan_header)), end="")
    
    print("|", end="")
    
    # Warna
    warna_header = " Warna"
    print(warna_header, end="")
    print(" " * (warna_width - len(warna_header)), end="")
    
    print("|", end="")
    
    # Untuk
    untuk_header = " Untuk"
    print(untuk_header, end="")
    print(" " * (untuk_width - len(untuk_header)), end="")
    
    print("|", end="")
    
    # Size
    size_header = " Size"
    print(size_header, end="")
    print(" " * (size_width - len(size_header)), end="")
    
    print("|", end="")
    
    # Merk
    merk_header = " Merk"
    print(merk_header, end="")
    print(" " * (merk_width - len(merk_header)), end="")
    
    print("|")
    
    # Print garis setelah header
    print("-" * total_width)
    
    # Print data
    for baju in list_baju:
        print("|", end="")
        
        # ID
        id_str = " " + baju.get_id()
        print(id_str, end="")
        print(" " * (id_width - len(id_str)), end="")
        
        print("|", end="")
        
        # Nama
        nama_str = " " + baju.get_nama_produk()
        print(nama_str, end="")
        print(" " * (nama_width - len(nama_str)), end="")
        
        print("|", end="")
        
        # Harga
        harga_str = " " + str(baju.get_harga_produk())
        print(harga_str, end="")
        print(" " * (harga_width - len(harga_str)), end="")
        
        print("|", end="")
        
        # Stok
        stok_str = " " + str(baju.get_stok_produk())
        print(stok_str, end="")
        print(" " * (stok_width - len(stok_str)), end="")
        
        print("|", end="")
        
        # Jenis
        jenis_str = " " + baju.get_jenis()
        print(jenis_str, end="")
        print(" " * (jenis_width - len(jenis_str)), end="")
        
        print("|", end="")
        
        # Bahan
        bahan_str = " " + baju.get_bahan()
        print(bahan_str, end="")
        print(" " * (bahan_width - len(bahan_str)), end="")
        
        print("|", end="")
        
        # Warna
        warna_str = " " + baju.get_warna()
        print(warna_str, end="")
        print(" " * (warna_width - len(warna_str)), end="")
        
        print("|", end="")
        
        # Untuk
        untuk_str = " " + baju.get_untuk()
        print(untuk_str, end="")
        print(" " * (untuk_width - len(untuk_str)), end="")
        
        print("|", end="")
        
        # Size
        size_str = " " + baju.get_size()
        print(size_str, end="")
        print(" " * (size_width - len(size_str)), end="")
        
        print("|", end="")
        
        # Merk
        merk_str = " " + baju.get_merk()
        print(merk_str, end="")
        print(" " * (merk_width - len(merk_str)), end="")
        
        print("|")
    
    # Print garis bawah
    print("-" * total_width)

def main():
    list_baju = []
    
    # Data dummy
    list_baju.append(Baju("ID001", "Kaos Kaki Anjing", 50000, 10, "Pakaian", "Katun", "Merah", "Anjing", "M", "PetFashion"))
    list_baju.append(Baju("ID002", "Baju Pertamina Kucing", 45000, 15, "Pakaian", "Poliester", "Biru", "Kucing", "S", "PetStyle"))
    list_baju.append(Baju("ID003", "Baju KPK Kucing", 30000, 8, "Pakaian", "Wol", "Hijau", "Kucing", "L", "CingCong"))
    list_baju.append(Baju("ID004", "Jubah Superman Kucing", 60000, 5, "Pakaian", "Poliester", "Merah", "Kucing", "M", "HeroPet"))
    list_baju.append(Baju("ID005", "Topeng Batman Anjing", 35000, 7, "Aksesoris", "Plastik", "Hitam", "Anjing", "L", "HeroPet"))
    
    while True:
        display_baju_table(list_baju)
        tambah_data = input("Apakah kamu mau menambahkan data? (y/n): ")
        if tambah_data.lower() != 'y':
            print("Terima kasih!")
            break
        
        # Input data
        id = input("Masukkan ID: ")
        nama = input("Masukkan Nama: ")
        harga = int(input("Masukkan Harga: "))
        stok = int(input("Masukkan Stok: "))
        jenis = input("Masukkan Jenis: ")
        bahan = input("Masukkan Bahan: ")
        warna = input("Masukkan Warna: ")
        untuk = input("Masukkan Untuk: ")
        size = input("Masukkan Size: ")
        merk = input("Masukkan Merk: ")
        
        # Masukkan ke dalam list
        list_baju.append(Baju(id, nama, harga, stok, jenis, bahan, warna, untuk, size, merk))
        print()

if __name__ == "__main__":
    main()