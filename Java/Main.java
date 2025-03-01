import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    
    public static void displayBajuTable(ArrayList<Baju> listBaju) {
        // Inisialisasi
        int idWidth = 4;
        int namaWidth = 6;
        int hargaWidth = 7;
        int stokWidth = 6;
        int jenisWidth = 7;
        int bahanWidth = 7;
        int warnaWidth = 7;
        int untukWidth = 7;
        int sizeWidth = 6;
        int merkWidth = 6;
        
        // Cari yang terpanjang
        for (Baju baju : listBaju) {
            if (baju.get_id().length() > idWidth-2) { idWidth = baju.get_id().length() + 2;}

            if (baju.get_nama_produk().length() > namaWidth-2) {namaWidth = baju.get_nama_produk().length() + 2;}
            
            if (String.valueOf(baju.get_harga_produk()).length() > hargaWidth-2) {hargaWidth = String.valueOf(baju.get_harga_produk()).length() + 2;}

            if (String.valueOf(baju.get_stok_produk()).length() > stokWidth-2) {stokWidth = String.valueOf(baju.get_stok_produk()).length() + 2;}

            if (baju.get_jenis().length() > jenisWidth-2) {jenisWidth = baju.get_jenis().length() + 2;}

            if (baju.get_bahan().length() > bahanWidth-2) {bahanWidth = baju.get_bahan().length() + 2;}

            if (baju.get_warna().length() > warnaWidth-2) {warnaWidth = baju.get_warna().length() + 2;}

            if (baju.get_untuk().length() > untukWidth-2) {untukWidth = baju.get_untuk().length() + 2;}

            if (baju.get_size().length() > sizeWidth-2) { sizeWidth = baju.get_size().length() + 2;
            }
            if (baju.get_merk().length() > merkWidth -2) {merkWidth = baju.get_merk().length() + 2;}
        }
        
        // Hitung total lebar tabel
        int totalWidth =  1 + idWidth + namaWidth + hargaWidth + stokWidth + 
        jenisWidth + bahanWidth + warnaWidth + untukWidth + 
        sizeWidth + merkWidth + 10;
        
        // Cetak garis pemisah atas
        System.out.println("-".repeat(totalWidth));
        
        // Cetak header
        System.out.printf("| %-" + (idWidth-1) + "s| %-" + (namaWidth-1) + "s| %-" + (hargaWidth-1) + "s| %-" + (stokWidth-1) + "s| %-" + (jenisWidth-1) + "s| %-" + (bahanWidth-1) + "s| %-" + (warnaWidth-1) + "s| %-" + (untukWidth-1) + "s| %-" + (sizeWidth-1) + "s| %-" + (merkWidth-1) + "s|%n", 
                          "ID", "Nama", "Harga", "Stok", "Jenis", "Bahan", "Warna", "Untuk", "Size", "Merk");
        
        // Cetak garis pemisah setelah header
        System.out.println("-".repeat(totalWidth));
        
        // Cetak data
        for (Baju baju : listBaju) {
            System.out.printf("| %-" + (idWidth-1) + "s| %-" + (namaWidth-1) + "s| %-" + (hargaWidth-1) + "d| %-" + (stokWidth-1) + "d| %-" + (jenisWidth-1) + "s| %-" + (bahanWidth-1) + "s| %-" + (warnaWidth-1) + "s| %-" + (untukWidth-1) + "s| %-" + (sizeWidth-1) + "s| %-" + (merkWidth-1) + "s|%n", 
                              baju.get_id(), baju.get_nama_produk(), baju.get_harga_produk(), baju.get_stok_produk(), 
                              baju.get_jenis(), baju.get_bahan(), baju.get_warna(), baju.get_untuk(), 
                              baju.get_size(), baju.get_merk());
        }
        
        // Cetak garis pemisah bawah
        System.out.println("-".repeat(totalWidth));
    }
    

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Baju> listBaju = new ArrayList<>();

        // Data Dummy
        listBaju.add(new Baju("ID001", "Kaos Kaki Anjing", 50000, 10, "Pakaian", "Katun", "Merah", "Anjing", "M", "PetFashion"));
        listBaju.add(new Baju("ID002", "Baju Pertamina Kucing", 45000, 15, "Pakaian", "Poliester", "Biru", "Kucing", "S", "PetStyle"));
        listBaju.add(new Baju("ID003", "Baju KPK Kucing", 30000, 8, "Pakaian", "Wol", "Hijau", "Kucing", "L", "CingCong"));
        listBaju.add(new Baju("ID004", "Jubah Superman Kucing", 60000, 5, "Pakaian", "Poliester", "Merah", "Kucing", "M", "HeroPet"));
        listBaju.add(new Baju("ID005", "Topeng Batman Anjing", 35000, 7, "Aksesoris", "Plastik", "Hitam", "Anjing", "L", "HeroPet"));

        while (true) {
            displayBajuTable(listBaju);

            System.out.print("Apakah kamu mau menambahkan data? (y/n): ");
            String tambahData = scanner.nextLine();
            if (!tambahData.equalsIgnoreCase("y")) {
                System.out.println("Terima kasih!");
                break;
            }

            System.out.print("Masukkan ID: ");
            String id = scanner.nextLine();
            System.out.print("Masukkan Nama: ");
            String nama = scanner.nextLine();
            System.out.print("Masukkan Harga: ");
            int harga = scanner.nextInt();
            System.out.print("Masukkan Stok: ");
            int stok = scanner.nextInt();
            scanner.nextLine(); 
            System.out.print("Masukkan Jenis: ");
            String jenis = scanner.nextLine();
            System.out.print("Masukkan Bahan: ");
            String bahan = scanner.nextLine();
            System.out.print("Masukkan Warna: ");
            String warna = scanner.nextLine();
            System.out.print("Masukkan Untuk: ");
            String untuk = scanner.nextLine();
            System.out.print("Masukkan Size: ");
            String size = scanner.nextLine();
            System.out.print("Masukkan Merk: ");
            String merk = scanner.nextLine();

            listBaju.add(new Baju(id, nama, harga, stok, jenis, bahan, warna, untuk, size, merk));
            System.out.println();
        }

        scanner.close();
    }
}
