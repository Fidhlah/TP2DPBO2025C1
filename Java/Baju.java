public class Baju extends Aksesoris {
    private String untuk;
    private String size;
    private String merk;

    // Konstruktor default
    public Baju() {
        super(); // Konstruktor Aksesoris
        this.untuk = "";
        this.size = "";
        this.merk = "";
    }

    // Konstruktor dengan parameter
    public Baju(String ID, String nama, int hargaProduk, int stokProduk, String jenis, String bahan, String warna, String untuk, String size, String merk) {
        super(ID, nama, hargaProduk, stokProduk, jenis, bahan, warna); // Konstruktor Aksesoris
        this.untuk = untuk;
        this.size = size;
        this.merk = merk;
    }

    // Setter
    public void set_untuk(String untuk) { this.untuk = untuk; }
    public void set_size(String size) { this.size = size; }
    public void set_merk(String merk) { this.merk = merk; }

    // Getter
    public String get_untuk() { return this.untuk; }
    public String get_size() { return this.size; }
    public String get_merk() { return this.merk; }
}
