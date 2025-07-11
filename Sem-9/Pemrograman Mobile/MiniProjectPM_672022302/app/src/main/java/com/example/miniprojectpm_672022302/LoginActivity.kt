package com.example.miniprojectpm_672022302

import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.miniprojectpm_672022302.databinding.ActivityLoginBinding
import com.google.firebase.database.FirebaseDatabase

class LoginActivity : AppCompatActivity() {
    private lateinit var binding: ActivityLoginBinding
    private lateinit var db: FirebaseDatabase

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityLoginBinding.inflate(layoutInflater)
        setContentView(binding.root)

        db = FirebaseDatabase.getInstance()

        binding.btnLogin.setOnClickListener {
            val kode = binding.etKodeLogin.text.toString().trim()
            val password = binding.etPasswordLogin.text.toString().trim()

            if (kode.isEmpty() || password.isEmpty()) {
                binding.tvStatusLogin.text = "Mohon isi kode dan password."
                return@setOnClickListener
            }

            val userRef = db.getReference("Users").child(kode)

            userRef.get().addOnSuccessListener { snapshot ->
                if (snapshot.exists()) {
                    val passDb = snapshot.child("password").getValue(String::class.java)
                    val role = snapshot.child("role").getValue(String::class.java)

                    if (password == passDb) {
                        when (role) {
                            "kaprogdi" -> startActivity(Intent(this, KaprogdiActivity::class.java))
                            "dosen" -> startActivity(Intent(this, DosenActivity::class.java))
                            "mahasiswa" -> startActivity(Intent(this, MahasiswaActivity::class.java))
                            else -> binding.tvStatusLogin.text = "Role tidak valid."
                        }
                        finish()
                    } else {
                        binding.tvStatusLogin.text = "Password salah."
                    }
                } else {
                    binding.tvStatusLogin.text = "Kode tidak ditemukan."
                }
            }.addOnFailureListener {
                binding.tvStatusLogin.text = "Gagal login: ${it.message}"
            }
        }
        binding.btnKeRegister.setOnClickListener {
            startActivity(Intent(this, RegisterActivity::class.java))
        }
    }
}
