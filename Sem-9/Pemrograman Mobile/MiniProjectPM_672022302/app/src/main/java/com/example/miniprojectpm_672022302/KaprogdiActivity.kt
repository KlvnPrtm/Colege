package com.example.miniprojectpm_672022302

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.miniprojectpm_672022302.databinding.ActivityKaprogdiBinding
import com.google.firebase.database.*

class KaprogdiActivity : AppCompatActivity() {
    private lateinit var binding: ActivityKaprogdiBinding
    private lateinit var database: FirebaseDatabase
    private lateinit var refMatkul: DatabaseReference

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityKaprogdiBinding.inflate(layoutInflater)
        setContentView(binding.root)

        database = FirebaseDatabase.getInstance()
        refMatkul = database.getReference("MataKuliah")

        // Simpan Mata Kuliah
        binding.btnSimpanMatkul.setOnClickListener {
            val kode = binding.etKodeMatkul.text.toString().trim()
            val nama = binding.etNamaMatkul.text.toString().trim()
            val sks = binding.etSKS.text.toString().toIntOrNull()

            if (kode.isNotEmpty() && nama.isNotEmpty() && sks != null) {
                val matkul = mapOf(
                    "kode" to kode,
                    "nama" to nama,
                    "sks" to sks
                )
                refMatkul.child(kode).setValue(matkul).addOnSuccessListener {
                    binding.tvStatusKaprogdi.text = "Mata kuliah berhasil disimpan."
                    binding.etKodeMatkul.text.clear()
                    binding.etNamaMatkul.text.clear()
                    binding.etSKS.text.clear()
                }.addOnFailureListener {
                    binding.tvStatusKaprogdi.text = "Gagal menyimpan mata kuliah."
                }
            } else {
                binding.tvStatusKaprogdi.text = "Mohon lengkapi semua data mata kuliah."
            }
        }
    }
}
