<?php
require_once 'Petshop.php'; // Mengimpor kelas Petshop

class Aksesoris extends Petshop {
    private $jenis;
    private $bahan;
    private $warna;

    // Konstruktor default
    public function __construct(
        $id = "", 
        $nama_produk = "", 
        $harga_produk = 0, 
        $stok_produk = 0, 
        $foto_produk = "",
        $jenis = "", 
        $bahan = "", 
        $warna = ""
    ) {
        parent::__construct($id, $nama_produk, $harga_produk, $stok_produk, $foto_produk); // Konstruktor Petshop
        $this->jenis = $jenis;
        $this->bahan = $bahan;
        $this->warna = $warna;
    }

    // Setter
    public function set_jenis(string $jenis){ $this->jenis = $jenis; }
    public function set_bahan(string $bahan){ $this->bahan = $bahan; }
    public function set_warna(string $warna){ $this->warna = $warna; }

    // Getter
    public function get_jenis() { return $this->jenis; }
    public function get_bahan() { return $this->bahan; }
    public function get_warna() { return $this->warna; }
}
?>
