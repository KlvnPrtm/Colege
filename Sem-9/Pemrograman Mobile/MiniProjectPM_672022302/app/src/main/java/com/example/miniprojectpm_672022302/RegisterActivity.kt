package com.example.miniprojectpm_672022302

import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.miniprojectpm_672022302.databinding.ActivityRegisterBinding
import com.google.firebase.database.FirebaseDatabase

class RegisterActivity : AppCompatActivity() {
    private lateinit var binding: ActivityRegisterBinding
    private lateinit var db: FirebaseDatabase

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityRegisterBinding.inflate(layoutInflater)
        setContentView(binding.root)

        db = FirebaseDatabase.getInstance()

        binding.btnRegister.setOnClickListener {
            val kode = binding.etKodeRegister.text.toString().trim()
            val password = binding.etPasswordRegister.text.toString().trim()

            val role = when {
                kode.length == 4 && kode.startsWith("67") -> "kaprogdi"
                kode.length == 5 && kode.startsWith("67") -> "dosen"
                kode.length == 10 && kode.startsWith("67") -> "mahasiswa"
                else -> null
            }

            if (role == null || password.length > 10 || password.isEmpty()) {
                binding.tvStatusRegister.text = "Kode tidak valid atau password kosong."
                return@setOnClickListener
            }

            val userRef = db.getReference("Users").child(kode)
            val data = mapOf("password" to password, "role" to role)

            userRef.setValue(data).addOnSuccessListener {
                binding.tvStatusRegister.text = "Register berhasil sebagai $role"
                startActivity(Intent(this, LoginActivity::class.java))
                finish()
            }.addOnFailureListener {
                binding.tvStatusRegister.text = "Gagal daftar: ${it.message}"
            }
        }
    }
}
