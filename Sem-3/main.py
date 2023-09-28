from mamalia import Mamalia
from reptil import Reptil
import os

list = ["Mamalia", "Reptil"]
DataList=[]
def Menu():
    while True:
        os.system("cls")
        print("===Menu===")
        print("1. Input Hewan")
        print("2. Lihat Data Hewan")
        print("3. Exit")
        Pilih = int(input("Pilihan:"))
        print(Pilih)
        os.system("cls")
        if Pilih == 1:
            Input()
        elif Pilih == 2:
            if not DataList:
                print("Data Kosong")
            for i in DataList:
                print(f"{i.urutan+1}")
                i.print()
                print()
            input()
            Menu()
        elif Pilih == 3:
            exit("Terimakasih")
        else:
            input("Tidak Ada Pilihan!!!")
        continue

def Input():
    while True:
        os.system("cls")

        print("Input Menu")
        print("1.", list[0])
        print("2.", list[1])
        print("3. Kembali Ke Menu")
        Input = int(input("Pilihan: "))
        if Input == 1:
            hewan = input("Masukan Nama " + list[0] + ": ")
            TempatHidup = input("Masukan Tempat Hidup: ")
            Makanan = input("Masukan Makanan: ")
            Data = Mamalia(hewan,TempatHidup,Makanan)
            input("Data Telah Terinput")
            urutan=len(DataList)
            Data.urutan=urutan
            DataList.append(Data)
            # DataList.append(DataList)
        elif Input == 2:
            hewan = input("Masukan Nama " + list[1] + ": ")
            TempatHidup = input("Masukan Tempat Hidup: ")
            Makanan = input("Masukan Makanan: ")
            Data = Reptil(hewan,TempatHidup,Makanan)
            input("Data Telah Terinput")
            urutan=len(DataList)
            Data.urutan=urutan
            DataList.append(Data)
        elif Input == 3:
                Menu()
        else:
            input("Tidak Ada Pilihan!!!")
            os.system("cls")
        continue
Menu()