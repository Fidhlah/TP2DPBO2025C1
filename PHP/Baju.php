<?php
require_once 'Aksesoris.php'; // Mengimpor kelas Aksesoris

class Baju extends Aksesoris {
    private $untuk;
    private $size;
    private $merk;

    // Konstruktor default
    public function __construct(
        $id = "", 
        $nama_produk = "", 
        $harga_produk = 0, 
        $stok_produk = 0, 
        $foto_produk = "",
        $jenis = "", 
        $bahan = "", 
        $warna = "",
        $untuk = "", 
        $size = "", 
        $merk = ""
    ) {
        parent::__construct($id, $nama_produk, $harga_produk, $stok_produk, $foto_produk, $jenis, $bahan, $warna); // Konstruktor Aksesoris
        $this->untuk = $untuk;
        $this->size = $size;
        $this->merk = $merk;
    }

    // Setter
    public function set_untuk(string $untuk) { $this->untuk = $untuk; }
    public function set_size(string $size) { $this->size = $size; }
    public function set_merk(string $merk) { $this->merk = $merk; }

    // Getter
    public function get_untuk(){ return $this->untuk; }
    public function get_size(){ return $this->size; }
    public function get_merk(){ return $this->merk; }
}
?>
