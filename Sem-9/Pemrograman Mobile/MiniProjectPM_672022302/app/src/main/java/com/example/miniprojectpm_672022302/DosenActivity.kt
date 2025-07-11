package com.example.miniprojectpm_672022302

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.miniprojectpm_672022302.databinding.ActivityDosenBinding
import com.google.firebase.database.*

class DosenActivity : AppCompatActivity() {
    private lateinit var binding: ActivityDosenBinding
    private lateinit var database: FirebaseDatabase
    private lateinit var refMahasiswa: DatabaseReference
    private lateinit var refTranskrip: DatabaseReference

    private var dosenValid = true

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityDosenBinding.inflate(layoutInflater)
        setContentView(binding.root)

        database = FirebaseDatabase.getInstance()
        refMahasiswa = database.getReference("Mahasiswa")
        refTranskrip = database.getReference("Transkrip")

        // Simpan Nilai dengan Proteksi
        binding.btnSimpanNilai.setOnClickListener {
            if (!dosenValid) {
                binding.tvStatusDosen.text = "Dosen belum tervalidasi!"
                return@setOnClickListener
            }

            val nim = binding.etNimDosen.text.toString().trim()
            val kodeMatkul = binding.etKodeMatkulDosen.text.toString().trim()
            val nilai = binding.etNilaiDosen.text.toString().toIntOrNull()

            if (nim.length != 10 || kodeMatkul.isEmpty() || nilai == null) {
                binding.tvStatusDosen.text = "Lengkapi NIM, Kode Matkul, dan Nilai."
                return@setOnClickListener
            }

            // Proteksi: Cek apakah NIM dan matkulnya valid
            refMahasiswa.child(nim).child("matkulDiambil").child(kodeMatkul)
                .get()
                .addOnSuccessListener { snapshot ->
                    if (snapshot.exists() && snapshot.getValue(Boolean::class.java) == true) {
                        val data = mapOf("nilai" to nilai)
                        refTranskrip.child(nim).child(kodeMatkul).setValue(data)
                            .addOnSuccessListener {
                                binding.tvStatusDosen.text = "Nilai berhasil disimpan."
                                binding.etNimDosen.text.clear()
                                binding.etKodeMatkulDosen.text.clear()
                                binding.etNilaiDosen.text.clear()
                            }
                            .addOnFailureListener { e ->
                                binding.tvStatusDosen.text = "Gagal menyimpan: ${e.message}"
                            }
                    } else {
                        binding.tvStatusDosen.text =
                            "Tidak dapat input nilai. Mahasiswa tidak ambil matkul ini atau NIM tidak terdaftar."
                    }
                }.addOnFailureListener {
                    binding.tvStatusDosen.text = "Gagal membaca data mahasiswa."
                }
        }
    }
}
