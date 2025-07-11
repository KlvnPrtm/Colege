// package main

// import "fmt"

// func main() {
// 	fmt.Println("Hello World!")
// }

// buat array ambil inputan ke 2 dari user inputan ke 2

// func main() {
// 	reader := bufio.NewReader(os.Stdin) // harus dideklarasikan dulu

// 	var umur int
// 	var tahunSekarang int
// 	var tahunTujuan int

// 	fmt.Print("Masukkan nama lengkap kamu: ")
// 	nama, _ := reader.ReadString('\n')
// 	nama = strings.TrimSpace(nama)

// 	fmt.Print("Masukkan umur kamu: ")
// 	fmt.Scan(&umur)

// 	if umur < 0 {
// 		fmt.Println("Umur tidak boleh negatif!")
// 		return
// 	}

// 	fmt.Print("Masukkan tahun sekarang: ")
// 	fmt.Scan(&tahunSekarang)

// 	fmt.Print("Masukkan tahun tujuan: ")
// 	fmt.Scan(&tahunTujuan)

// 	if tahunTujuan < tahunSekarang {
// 		fmt.Println("Tahun tujuan tidak boleh lebih kecil dari tahun sekarang!")
// 		return
// 	}

// 	selisihTahun := tahunTujuan - tahunSekarang
// 	umurNanti := umur + selisihTahun

// 	if umurNanti > 100 {
// 		fmt.Println("Halo", nama+"!")
// 		fmt.Println("Wow, kamu sudah lebih dari 100 tahun!")
// 	} else {
// 		fmt.Println("Halo", nama+"!")
// 		fmt.Println("Pada tahun", tahunTujuan, "kamu akan berumur", umurNanti, "tahun.")
// 	}
// }

// Masukkan nama kamu: Kelvin
// Masukkan umur kamu sekarang: 20
// Masukkan tahun sekarang: 2025
// Masukkan tahun tujuan: 2030

// Halo Kelvin!
// Pada tahun 2030, kamu akan berumur 25 tahun.

// selisihTahun := tahunTujuan - tahunSekarang
// umurNanti := umur + selisihTahun
