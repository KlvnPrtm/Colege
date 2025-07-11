// package main

// import "fmt"

// func main() {
// 	array := [5]int{5, 9, 985, 35, 55}
	
// 	var i int
// 	var inputan int
	
// 	fmt.Print("Masukan Array Yang Ingin Diambil: ")
// 	fmt.Scan(&inputan)

// 	for i = 0; i <= array[i]; i++{
// 		if inputan == i{
// 			fmt.Print("array yang anda ambil adalah: ", array [i])
// 			break
// 		}
// 	}
// }



//buat 1 array, isinya ada gunting batu kertas, disitu ada player 1 dan 2 ada batas array, tidak boleh input lebih //dari 3

package main

import "fmt"

func main(){
	pingsutPlayer1 := [3] string {"Gunting", "Batu", "Kertas"}
	pingsutPlayer2 := [3] string {"Gunting", "Batu", "Kertas"}

	fmt.Print("Masukan Bahan Pingsut Player 1 (1-3): ")
	fmt.Scan(&pingsutPlayer1[])

	fmt.Print("Masukan Bahan Pingsut Player 2 (1-3): ")
	fmt.Scan(&pingsutPlayer2[])

	if pingsutPlayer1[0] == pingsutPlayer2[0]{
		fmt.Print("Seri")
		
	} 
	

}