Bawah = int(input ("Masukan Batas Bawah: "))
Atas = int(input ("Masukan Batas Atas: "))

for i in range(Bawah,Atas):
    if(i % 2 != 0):
        print(i)