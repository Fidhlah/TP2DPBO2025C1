public class Aksesoris extends Petshop{
    private String jenis;
    private String bahan;
    private String warna;

    // Konstruktor default
    public Aksesoris() {
        super(); // Konstruktor Petshop
        this.jenis = "";
        this.bahan = "";
        this.warna = "";
    }

    // Konstruktor dengan parameter
    public Aksesoris(String ID, String nama, int hargaProduk, int stokProduk, String jenis, String bahan, String warna) {
        super(ID, nama, hargaProduk, stokProduk); // Konstruktor Petshop
        this.jenis = jenis;
        this.bahan = bahan;
        this.warna = warna;
    }

    // Setter
    public void set_jenis(String jenis) { this.jenis = jenis; }
    public void set_bahan(String bahan) { this.bahan = bahan; }
    public void set_warna(String warna) { this.warna = warna; }

    // Getter
    public String get_jenis() { return this.jenis; }
    public String get_bahan() { return this.bahan; }
    public String get_warna() { return this.warna; }
}
