import os
os.system("cls")
# my_list = [ 231231, 12312, [1, 2, 3,[4,142,849], 4, 5]]
# alfabet=[1,2,3,4,5,6,7,8,9,0]
# alfabet.append(1)
# alfabet.extend([234324])
# alfabet.insert(-2,5)

# # alfabet.remove(6)
# # print(alfabet)

# # print(alfabet.pop(7))
# # print(alfabet)

# alfabet.sort(reverse=True)
# print(alfabet)
# alfabet.sort()
# print(alfabet)
# my_list.sort(reverse=True)

# print(my_list[3][3][-3:])
# my_list[3][2]=5
# print(my_list)

def sapa(nama):
    """Nothin Here"""
    print("Halo, " + nama + ", Km Apa Kabar?")
    return nama
    
sapa('Umar')
sapa('Diva')
sapa('Aziz')

keluaran=sapa('Kisa')
print(keluaran)

print(sapa.__doc__)