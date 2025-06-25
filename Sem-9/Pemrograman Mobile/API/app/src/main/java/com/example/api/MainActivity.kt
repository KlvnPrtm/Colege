package com.example.api

import android.os.Bundle
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import androidx.lifecycle.ViewModelProvider
import com.bumptech.glide.Glide
import com.example.api.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var viewModel: MyViewModel
    private val allUsers = mutableListOf<User>()
    private var currentIndex = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        viewModel = ViewModelProvider(this).get(MyViewModel::class.java)

        setupUserObservers()
        setupProductObservers()
    }

    private fun setupUserObservers() {
        viewModel.users.observe(this) { users ->
            if (users.isNotEmpty()) {
                allUsers.clear()
                allUsers.addAll(users)
                currentIndex = 0
                displayUser()

                // Aktifkan tombol navigasi dan produk setelah user didapat
                binding.btnNext.isEnabled = true
                binding.btnPrev.isEnabled = true
                binding.btnGetProducts.isEnabled = true
            }
        }

        viewModel.errorMessage.observe(this) { errorMessage ->
            binding.txtFirstName.text = errorMessage
            binding.txtLastName.text = ""
            binding.txtUniversity.text = ""
        }

        binding.btnGetUsers.setOnClickListener {
            viewModel.fetchUsers()
        }

        binding.btnNext.setOnClickListener {
            if (allUsers.isNotEmpty()) {
                currentIndex = (currentIndex + 1) % allUsers.size
                displayUser()
            }
        }

        binding.btnPrev.setOnClickListener {
            if (allUsers.isNotEmpty()) {
                currentIndex = if (currentIndex > 0) currentIndex - 1 else allUsers.size - 1
                displayUser()
            }
        }
    }

    private fun setupProductObservers() {
        // Observer untuk menampilkan harga produk yang didapat dari ViewModel
        viewModel.productPrice.observe(this) { priceText ->
            binding.txtAveragePrice.text = priceText
        }

        // Ubah fungsi tombol ini
        binding.btnGetProducts.setOnClickListener {
            // Pastikan ada user yang ditampilkan sebelum mencari harga
            if (allUsers.isNotEmpty()) {
                val currentUserId = allUsers[currentIndex].id
                viewModel.fetchProductById(currentUserId)
            }
        }
    }

    private fun displayUser() {
        if (allUsers.isNotEmpty()) {
            val user = allUsers[currentIndex]
            binding.txtFirstName.text = user.firstName
            binding.txtLastName.text = user.lastName
            binding.txtUniversity.text = user.university

            Glide.with(this)
                .load(user.image)
                .placeholder(R.mipmap.ic_launcher)
                .error(R.mipmap.ic_launcher_round)
                .into(binding.imgUser)

            // KOSONGKAN HARGA LAMA SETIAP GANTI USER
            // agar pengguna tahu harga perlu dicari ulang
            binding.txtAveragePrice.text = "Klik tombol di bawah untuk cek harga"
        }
    }
}