<?php
// require_once 'Petshop.php';
// require_once 'Aksesoris.php';
require_once 'Baju.php';
session_start();

if (!isset($_SESSION['created'])) {
    $_SESSION['created'] = time();
} elseif (time() - $_SESSION['created'] > 1) { // Reset setiap 1 detik
    session_unset();
    session_destroy();
    session_start();
    $_SESSION['created'] = time();
}

// Inisialisasi Produk
if (!isset($_SESSION['products'])) {
    $_SESSION['products'] = [
        new Baju("ID001", "Kaos Kaki Anjing", 50000, 10, "kaoskakianjing.jpg", "Pakaian", "Katun", "Merah", "Anjing", "M", "PetFashion"),
        new Baju("ID002", "Baju Pertamina Kucing", 45000, 15, "bajupertaminakucing.jpg", "Pakaian", "Poliester", "Biru", "Kucing", "S", "PetStyle"),
        new Baju("ID003", "Baju KPK Kucing", 30000, 8, "bajukpkkucing.jpg", "Pakaian", "Wol", "Hijau", "Kucing", "L", "CingCong"),
        new Baju("ID004", "Jubah Superman Kucing", 60000, 5, "jubahsupermankucing.jpg", "Pakaian", "Poliester", "Merah", "Kucing", "M", "HeroPet"),
        new Baju("ID005", "Topeng Batman Anjing", 35000, 7, "topengbatmananjing.jpg", "Aksesoris", "Plastik", "Hitam", "Anjing", "L", "HeroPet")
    ];
    
}

$petshop = &$_SESSION['products'];                              
$uploadDir = 'uploads/';                                        
if (!file_exists($uploadDir)) mkdir($uploadDir, 0777, true);

// Function untuk format harga
function formatRupiah($angka) {
    return "Rp " . number_format($angka, 0, ',', '.');
}

$message = '';                      

// Menambahkan produk
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['action']) && $_POST['action'] === 'add') {
    $newId = $_POST['id'] ?? '';
    $newName = $_POST['nama'] ?? '';
    $newPrice = $_POST['harga'] ?? 0;
    $newStock = $_POST['stok'] ?? 0;
    $newType = $_POST['jenis'] ?? '';
    $newMaterial = $_POST['bahan'] ?? '';
    $newColor = $_POST['warna'] ?? '';
    $newFor = $_POST['untuk'] ?? '';
    $newSize = $_POST['size'] ?? '';
    $newBrand = $_POST['merk'] ?? '';
    $imageName = 'default.jpg';

    $idExists = false;
    foreach ($petshop as $product) {
        if ($product->get_ID() === $newId) {
            $idExists = true;
            break;
        }
    }

    if ($idExists) {
        $message = '<div class="alert alert-danger">ID Produk sudah digunakan!</div>';
    } elseif (empty($newId) || empty($newName) || empty($newType) || $newPrice <= 0 || $newStock < 0) {
        $message = '<div class="alert alert-danger">Semua field harus diisi!</div>';
    } else {
        if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] === UPLOAD_ERR_OK) {
            $tempFile = $_FILES['gambar']['tmp_name'];
            $fileType = strtolower(pathinfo($_FILES['gambar']['name'], PATHINFO_EXTENSION));
            if (in_array($fileType, ['jpg', 'jpeg', 'png'])) {
                $imageName = $newId . '_' . time() . '.' . $fileType;
                move_uploaded_file($tempFile, $uploadDir . $imageName);
            }
        }
        $petshop[] = new Baju($newId, $newName, $newPrice, $newStock, $imageName, $newType, $newMaterial, $newColor, $newFor, $newSize, $newBrand);
        $message = '<div class="alert alert-success">Produk berhasil ditambahkan!</div>';
    }
}

// Menghapus produk
if ($_SERVER['REQUEST_METHOD'] === 'GET' && isset($_GET['action']) && $_GET['action'] === 'delete') {
    $deleteId = $_GET['id'] ?? '';
    foreach ($petshop as $key => $product) {
        if ($product->get_ID() === $deleteId) {
            unset($petshop[$key]);
            $message = '<div class="alert alert-success">Produk berhasil dihapus!</div>';
            break;
        }
    }
}

?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Petshop Management</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">
    <style>
        body { background-color: #f8f9fa; padding: 15px 0; }
        .product-image { width: 50px; height: 50px; object-fit: cover; border-radius: 4px; }
        .form-container { 
            position: fixed; 
            left: 0; 
            top: 0; 
            width: 300px; 
            height: 100%; 
            padding: 15px; 
            background-color: #f8f9fa; 
            border-right: 1px solid #dee2e6; 
            overflow-y: auto;
            z-index: 1000;
        }
        .main-content {
            margin-left: 310px;
            width: calc(100% - 320px);
        }
        @media (max-width: 768px) {
            .form-container {
                position: relative;
                width: 100%;
                height: auto;
                border-right: none;
                border-bottom: 1px solid #dee2e6;
                margin-bottom: 15px;
            }
            .main-content {
                margin-left: 0;
                width: 100%;
            }
        }
        .table-container {
            overflow-x: auto;
            width: 100%;
        }
    </style>
</head>
<body>
    <!-- Menampilkan pesan notifikasi -->
    <div class="container-fluid">
        <?= $message ?>
    </div>
    
    <!-- Form Tambah Produk (Fixed Left Side) -->
    <div class="form-container">
        <div class="card shadow-sm">
            <div class="card-header bg-primary text-white">
                <i class="fas fa-plus-circle me-1"></i> Tambah Produk
            </div>
            <div class="card-body">
                <form method="post" action="" enctype="multipart/form-data">
                    <input type="hidden" name="action" value="add">
                    <div class="mb-2">
                        <label for="id" class="form-label">ID</label>
                        <input type="text" class="form-control" id="id" name="id" required>
                    </div>
                    <div class="mb-2">
                        <label for="nama" class="form-label">Nama Produk</label>
                        <input type="text" class="form-control" id="nama" name="nama" required>
                    </div>
                    
                    <div class="row">
                        <div class="col-md-6 mb-2">
                            <label for="harga" class="form-label">Harga (Rp)</label>
                            <input type="number" class="form-control" id="harga" name="harga" required>
                        </div>
                        <div class="col-md-6 mb-2">
                            <label for="stok" class="form-label">Stok</label>
                            <input type="number" class="form-control" id="stok" name="stok" required>
                        </div>
                    </div>


                    <div class="mb-2">
                        <label for="jenis" class="form-label">Jenis</label>
                        <input type="text" class="form-control" id="jenis" name="jenis" required>
                    </div>
                    <div class="row">
                        <div class="col-md-6 mb-2">
                            <label for="bahan" class="form-label">Bahan</label>
                            <input type="text" class="form-control" id="bahan" name="bahan" required>
                        </div>
                        <div class="col-md-6 mb-2">
                            <label for="warna" class="form-label">Warna</label>
                            <input type="text" class="form-control" id="warna" name="warna" required>
                        </div>
                    </div>

                    <div class="row">
                        <div class="col-md-6 mb-2">
                            <label for="untuk" class="form-label">Untuk</label>
                            <input type="text" class="form-control" id="untuk" name="untuk" required>
                        </div>
    
                        <div class="col-md-6 mb-2">
                            <label for="size" class="form-label">Size</label>
                            <input type="text" class="form-control" id="size" name="size" required>
                        </div>
                    </div>

                    <div class="mb-2">
                        <label for="merk" class="form-label">Merk</label>
                        <input type="text" class="form-control" id="merk" name="merk" required>
                    </div>

                    <div class="mb-3">
                        <label for="gambar" class="form-label">Gambar</label>
                        <input type="file" class="form-control" id="gambar" name="gambar" accept="image/*">
                    </div>
                    <button type="submit" class="btn btn-primary w-100">
                        <i class="fas fa-save me-1"></i>Simpan
                    </button>
                </form>
            </div>
        </div>
    </div>

    <div class="main-content">
        <div class="card shadow-sm">
            <div class="card-header bg-dark text-white d-flex justify-content-between align-items-center">
                <span><i class="fas fa-list me-1"></i>Daftar Produk</span>
                <span><i class="fas me-1"></i>TEKAN BARIS YANG INGIN DIHAPUS</span>
            </div>
            
            <!-- Tabel List Produk -->
            <div class="table-container">
                <table class="table table-hover mb-0">
                    <thead class="table-primary">
                        <tr>
                            <th>ID</th>
                            <th>Gambar</th>
                            <th>Nama</th>
                            <th>Harga</th>
                            <th>Stok</th>
                            <th>Jenis</th>
                            <th>Bahan</th>
                            <th>Warna</th>
                            <th>Untuk</th>
                            <th>Size</th>
                            <th>Merk</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach($petshop as $product): ?>
                        <tr data-id="<?= $product->get_ID() ?>">
                            <td><?= $product->get_ID() ?></td>
                            <td>
                                <?php if(file_exists($uploadDir . $product->get_foto_produk())): ?>
                                    <img src="<?= $uploadDir . $product->get_foto_produk() ?>" class="product-image" alt="">
                                <?php else: ?>
                                    <i class="fas fa-image text-muted"></i>
                                <?php endif; ?>
                            </td>
                            <td><?= $product->get_nama_produk() ?></td>
                            <td><?= formatRupiah($product->get_harga_produk()) ?></td>
                            <td><?= $product->get_stok_produk() ?></td>
                            <td><?= $product->get_jenis() ?></td>
                            <td><?= $product->get_bahan() ?></td>
                            <td><?= $product->get_warna() ?></td>
                            <td><?= $product->get_untuk() ?></td>
                            <td><?= $product->get_size() ?></td>
                            <td><?= $product->get_merk() ?></td>
                        </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/js/bootstrap.bundle.min.js"></script>
    <script>
        document.querySelectorAll('table tbody tr').forEach(row => {
            row.addEventListener('click', function() {
                const id = this.getAttribute('data-id');
                if (confirm('Hapus produk dengan ID: ' + id + '?')) {
                    window.location.href = '?action=delete&id=' + id;
                }
            });
        });
    </script>
</body>
</html>
