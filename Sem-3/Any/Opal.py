import os #Untuk bisa mengakses apa yg os bisa lakukan, seperti contoh mengakses suatu file, mengedit dll
def pr(): #fungsi supaya mempermudah dan supaya rapih
    os.system("cls")
    print("JENIS-JENIS SEGITIGA")
    print("--------------------")
    print("1. Segitiga Siku-Siku")
    print("2. Segitiga Siku-Siku Terbalik")
    print("3. Segitiga Sama Sisi")
    print("4. Segitiga Sama Sisi Terbalik")
    print("x. Exit")

    #hal diatas untuk mengeluarkan output print

def menu(): #fungsi supaya mempermudah dan supaya rapih
    while True: #Jika keadaan dibawah benar maka akan melanjutkan apa yg diinginkan
        pr() #fungsi supaya mempermudah dan supaya rapih
        Pilihan = (input("Masukan pilihan segitiga: ")) #untuk input pilihan segitiga menggunakan nama variabel pilihan

        if Pilihan == 'x': #jika input x maka pilihan akan keluar
            exit("program selesai, terimakasih")
        elif Pilihan == '1': #jika pilihan 1 maka akan membuat siku2
            Tinggi = int (input("Masukan tinggi segitiga: ")) #untuk menginput tinggi yang kita inginkan
            for i in range(0, Tinggi): #0 dalam range tinggi sesuai yang kita input (anggap saja input 4), maka ada 4 perulangan
                for j in range(0, i + 1): #0 dalam range i yang akan bertambah setiap kondisi sudah tidak sesuai
                    print('* ' , end='') #akan mengeluarkan output '* ' dalam for j karna i dalam posisi awal adalah 0 maka i+1 supaya 0 in range 1 maka akan print '* ' 1 kali, dan seterusnya
                print('') #print kosong supaya bisa turun kebawah
            while True: #Jika keadaan dibawah benar maka akan melanjutkan apa yg diinginkan
                Lanjut = input("Apakah Lanjut? [y/n]: ") #untuk menginput lanjut atau tidak, jika input 'y' maka lanjut ke menu awal jika input 'n' keluar dr program
                if Lanjut == 'y':
                    pr() #untuk ke menu pilihan diatas
                    menu() #untuk kembali ke menu ini
                elif Lanjut == 'n': #exit
                    exit("Terimakasih")
                else: #proteksi jika pilihan bukan 'y' atau 'n'
                    print("Tidak ada pilihan, Ulangi!")
                continue #untuk melanjutkan seterusnya jika keadaan diatas bernilai True

        elif Pilihan == '2': #jika pilihan 2 maka akan membuat siku2 terbalik
            Tinggi = int (input("Masukan tinggi segitiga: ")) #untuk menginput tinggi yang kita inginkan
            for i in range(0, Tinggi): #for in range 0 (misal tinggi kita input 5). Maka jadi in range 0, 5
                for j in range(0, Tinggi - i): #for in range 0, Tinggi=5, 5-i, i=0. Maka jadi in range 0, 5
                    print('* ' , end='') #print 5  '* 'karna 0,1,2,3,4,5 karna Tinggi masih 5, jika posisi i=1 maka in range 0, Tinggi-i (i=1) Tinggi-1=4 maka print '* ' 4 kali
                print('') #print kosong supaya bisa turun kebawah
            while True: #Jika keadaan dibawah benar maka akan melanjutkan apa yg diinginkan
                Lanjut = input("Apakah Lanjut? [y/n]: ") #untuk menginput lanjut atau tidak, jika input 'y' maka lanjut ke menu awal jika input 'n' keluar dr program
                if Lanjut == 'y':
                    pr() #untuk ke menu pilihan diatas
                    menu() #untuk kembali ke menu ini
                elif Lanjut == 'n': #exit
                    exit("Terimakasih")
                else: #proteksi jika pilihan bukan 'y' atau 'n'
                    print("Tidak ada pilihan, Ulangi!")
                continue #untuk melanjutkan seterusnya jika keadaan diatas bernilai True

        elif Pilihan == '3': #jika pilihan 3 maka akan membuat segitiga sama sisi
            Tinggi = int (input("Masukan tinggi segitiga: ")) #untuk menginput tinggi yang kita inginkan
            s = Tinggi - 1 #mendeklarasikan s = Tinggi -1, misal input tinggi 5, maka s=4
            for i in range(0, Tinggi): #for in range 0 (misal tinggi kita input 5). Maka jadi in range 0, 5
                for j in range(0, s): #for in range 0, 4. Karna kita sudah mendeklarasikan s=Tinggi-1
                    print(' ', end='') #maka akan print spasi 4 kali supaya bisa membuat segitiga
                s -= 1 #s akan dikurangi 1 setiap perulangan, jika tadi 4 maka sekarang 3
                for j in range(0, i + 1): #for in range 0, i+1. i awalnya adalahh 0, i+1 maka i menjadi 1, jadi for in range 0, 1
                    print('* ', end='') #maka akan print * 1 kali saja karna in range 0, 1
                print('') #print kosong supaya bisa turun kebawah
            while True: #Jika keadaan dibawah benar maka akan melanjutkan apa yg diinginkan
                Lanjut = input("Apakah Lanjut? [y/n]: ") #untuk menginput lanjut atau tidak, jika input 'y' maka lanjut ke menu awal jika input 'n' keluar dr program
                if Lanjut == 'y':
                    pr() #untuk ke menu pilihan diatas
                    menu() #untuk kembali ke menu ini
                elif Lanjut == 'n': #exit
                    exit("Terimakasih")
                else: #proteksi jika pilihan bukan 'y' atau 'n'
                    print("Tidak ada pilihan, Ulangi!")
                continue #untuk melanjutkan seterusnya jika keadaan diatas bernilai True
            
        elif Pilihan == '4': #jika pilihan 3 maka akan membuat segitiga sama sisi
            Tinggi = int (input("Masukan tinggi segitiga: ")) #untuk menginput tinggi yang kita inginkan
            s = 0 #mendeklrasikan s=0
            for i in range(0, Tinggi): #for in range 0 (misal tinggi kita input 5). Maka jadi in range 0, 5
                for j in range(0, s): #for in range 0, 0. karna s sudah dideklarasikan menjadi 0
                    print(' ',end='') #print kosong, karna  for in range 0,0 maka tidak terjadi apa2, jika for in range 0,1 maka akan print 1 kali
                s += 1 #tiap perulangan s akan bertambah 1
                for j in range(0, Tinggi): #for in range 0 (misal tinggi kita input 5). Maka jadi in range 0, 5
                    print('* ' , end='') # karna in range 0,5 maka akan print * 5 kali
                Tinggi -= 1 #tiap perulangan tinggi akan dikurangi 1
                print('') #print kosong supaya bisa turun kebawah
            while True: #Jika keadaan dibawah benar maka akan melanjutkan apa yg diinginkan
                Lanjut = input("Apakah Lanjut? [y/n]: ") #untuk menginput lanjut atau tidak, jika input 'y' maka lanjut ke menu awal jika input 'n' keluar dr program
                if Lanjut == 'y':
                    pr() #untuk ke menu pilihan diatas
                    menu() #untuk kembali ke menu ini
                elif Lanjut == 'n': #exit
                    exit("Terimakasih")
                else:#proteksi jika pilihan bukan 'y' atau 'n'
                    print("Tidak ada pilihan, Ulangi!")
                continue #untuk melanjutkan seterusnya jika keadaan diatas bernilai True
        else: # jika pilihan bukan  1, 2, 3, 4, dan x
            os.system("cls") #system akan mengclear terminal supaya terlihat rapih
            input("Tidak ada pilihan, Ulangi!") #input supaya kita memencet keyboard dan mengulangi pilihan
            continue #untuk melanjutkan seterusnya jika keadaan diatas bernilai True
pr() #untuk mengeluarkan informasi yg ada di fungsi yg bernama pr
menu()  #untuk mengeluarkan informasi yg ada di fungsi yg bernama menu