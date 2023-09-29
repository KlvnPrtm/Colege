from hewan import Hewan

class Mamalia(Hewan):
    def __init__(self, hewan,TempatHidup,Makanan):
        super().__init__(hewan,TempatHidup,Makanan)
        self.hewan = hewan
    def cara_bergerak(self):
        return "Bergerak Dengan Kaki Atau Sirip"
    def cara_berkembang_biak(self):
        return "Berkembang Biak Dengan Melahirkan"
    def print(self):
        print(f"Nama: {self.hewan}")
        print(f"Tempat Hidup: {self.TempatHidup}")
        print(f"Makanan: {self.Makanan}")
        print(f"{self.cara_bergerak()}")
        print(f"{self.cara_berkembang_biak()}")