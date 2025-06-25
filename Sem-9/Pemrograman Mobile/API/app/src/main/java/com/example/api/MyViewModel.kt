package com.example.api

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.launch
import java.text.NumberFormat
import java.util.Locale

class MyViewModel : ViewModel() {

    // --- Bagian User (Tidak ada perubahan signifikan) ---
    private val _users = MutableLiveData<List<User>>()
    val users: LiveData<List<User>> = _users

    private val _errorMessage = MutableLiveData<String>()
    val errorMessage: LiveData<String> = _errorMessage

    fun fetchUsers() {
        viewModelScope.launch {
            try {
                val response = RetrofitInstance.api.getUsers()
                _users.value = response.users
            } catch (e: Exception) {
                _errorMessage.value = "Gagal memuat data user: ${e.message}"
            }
        }
    }

    // --- BAGIAN PRODUK DIUBAH TOTAL ---
    // LiveData untuk menyimpan harga produk yang sudah diformat
    private val _productPrice = MutableLiveData<String>()
    val productPrice: LiveData<String> = _productPrice

    // Fungsi baru untuk mengambil satu produk berdasarkan ID
    fun fetchProductById(productId: Int) {
        // Tampilkan pesan loading
        _productPrice.value = "Mencari harga produk..."
        viewModelScope.launch {
            try {
                val product = RetrofitInstance.api.getProductById(productId)
                // Jika berhasil, format harganya dan tampilkan
                _productPrice.value = formatPrice(product.price)
            } catch (e: Exception) {
                // Jika produk tidak ditemukan (misal User ID 101, tapi produk hanya 100)
                // atau ada error lain.
                _productPrice.value = "Harga untuk produk ini tidak ditemukan."
                e.printStackTrace()
            }
        }
    }

    // Fungsi format harga (bisa kita gunakan kembali)
    private fun formatPrice(price: Double): String {
        val localeID = Locale("in", "ID")
        val numberFormat = NumberFormat.getCurrencyInstance(localeID)
        // Kita ubah labelnya agar lebih sesuai
        return "Harga Produk: ${numberFormat.format(price)}"
    }
}