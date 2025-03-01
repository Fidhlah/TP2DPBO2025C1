public class Petshop {
    // Atribut untuk menyimpan informasi produk
    private String ID;          
    private String namaProduk;  
    private int hargaProduk;    
    private int stokProduk;     

    // Konstruktor default (inisialisasi tanpa nilai awal)
    public Petshop() {
        this.ID = "";
        this.namaProduk = "";
        this.hargaProduk = 0;
        this.stokProduk = 0;
    }

    // Konstruktor dengan parameter
    public Petshop(String ID, String namaProduk, int hargaProduk, int stokProduk) {
        this.ID = ID;
        this.namaProduk = namaProduk;
        this.hargaProduk = hargaProduk;
        this.stokProduk = stokProduk;
    }

    // Setter atribut
    public void set_id(String ID){this.ID = ID;}
    public void set_nama_produk(String namaProduk) {this.namaProduk = namaProduk;}
    public void set_harga_produk(int hargaProduk) {this.hargaProduk = hargaProduk;}
    public void set_stok_produk(int stokProduk) {this.stokProduk = stokProduk;}

    // Getter atribut
    public String get_id() {return this.ID;}
    public String get_nama_produk() {return this.namaProduk;}
    public int get_harga_produk() {return this.hargaProduk;}
    public int get_stok_produk() {return this.stokProduk;}
}
