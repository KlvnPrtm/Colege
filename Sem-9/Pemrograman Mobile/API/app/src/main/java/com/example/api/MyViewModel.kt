package com.example.api

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.launch
import java.text.NumberFormat
import java.util.Locale

class MyViewModel : ViewModel() {

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

    private val _productPrice = MutableLiveData<String>()
    val productPrice: LiveData<String> = _productPrice

    fun fetchProductById(productId: Int) {
        _productPrice.value = "Mencari harga produk..."
        viewModelScope.launch {
            try {
                val product = RetrofitInstance.api.getProductById(productId)
                _productPrice.value = formatPrice(product.price)
            } catch (e: Exception) {
                _productPrice.value = "Harga untuk produk ini tidak ditemukan."
                e.printStackTrace()
            }
        }
    }

    private fun formatPrice(price: Double): String {
        val localeID = Locale("in", "ID")
        val numberFormat = NumberFormat.getCurrencyInstance(localeID)
        return "Harga Produk: ${numberFormat.format(price)}"
    }
}