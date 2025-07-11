package com.example.miniprojectpm_672022302

import android.os.Bundle
import android.view.View
import android.widget.CheckBox
import android.widget.LinearLayout
import androidx.appcompat.app.AppCompatActivity
import com.example.miniprojectpm_672022302.databinding.ActivityMahasiswaBinding
import com.google.firebase.database.*

class MahasiswaActivity : AppCompatActivity() {
    private lateinit var binding: ActivityMahasiswaBinding
    private lateinit var database: FirebaseDatabase
    private lateinit var refMahasiswa: DatabaseReference
    private lateinit var refMatkul: DatabaseReference
    private lateinit var refTranskrip: DatabaseReference

    private var nim: String = ""
    private val checkboxMap = mutableMapOf<String, CheckBox>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMahasiswaBinding.inflate(layoutInflater)
        setContentView(binding.root)

        database = FirebaseDatabase.getInstance()
        refMahasiswa = database.getReference("Mahasiswa")
        refMatkul = database.getReference("MataKuliah")
        refTranskrip = database.getReference("Transkrip")

        binding.btnValidasiNIM.setOnClickListener {
            nim = binding.etNimMahasiswa.text.toString()
            if (nim.length == 10) {
                refMahasiswa.child(nim).child("matkulDiambil").get().addOnCompleteListener {
                    binding.tvStatusNIM.text = "NIM tervalidasi."
                    tampilkanMataKuliah()
                }
            } else {
                binding.tvStatusNIM.text = "NIM harus 10 digit."
            }
        }

        binding.btnAmbilMatkul.setOnClickListener {
            val selectedMatkul = checkboxMap.filterValues { it.isChecked }.keys
            if (selectedMatkul.isEmpty()) {
                binding.tvStatusNIM.text = "Pilih minimal satu mata kuliah."
                return@setOnClickListener
            }
            val updates = selectedMatkul.associateWith { true }
            refMahasiswa.child(nim).child("matkulDiambil").updateChildren(updates).addOnSuccessListener {
                binding.tvStatusNIM.text = "Mata kuliah berhasil diambil."
                tampilkanNilaiMahasiswa()
            }
        }

        binding.btnLihatTranskrip.visibility = View.VISIBLE
        binding.btnLihatTranskrip.setOnClickListener {
            tampilkanTranskripMahasiswa()
        }
    }

    private fun tampilkanTranskripMahasiswa() {
        val nimRef = refMahasiswa.child(nim)
        nimRef.child("matkulDiambil").get().addOnSuccessListener { matkulSnapshot ->
            if (!matkulSnapshot.exists()) {
                binding.tvTranskrip.text = "Belum mengambil mata kuliah."
                return@addOnSuccessListener
            }

            val matkulList = mutableListOf<String>()
            for (child in matkulSnapshot.children) {
                matkulList.add(child.key ?: "")
            }

            refTranskrip.child(nim).get().addOnSuccessListener { transkripSnapshot ->
                if (!transkripSnapshot.exists()) {
                    binding.tvTranskrip.text = "Belum ada nilai diinputkan."
                    return@addOnSuccessListener
                }

                val result = StringBuilder("Transkrip Nilai:\n")
                for (kode in matkulList) {
                    val nilai = transkripSnapshot.child(kode).child("nilai").getValue(Int::class.java)
                }
                binding.tvTranskrip.text = result.toString()
            }
        }
    }


    private fun tampilkanMataKuliah() {
        binding.tvPilihMatkul.visibility = View.VISIBLE
        binding.layoutMatkulCheckbox.visibility = View.VISIBLE
        binding.btnAmbilMatkul.visibility = View.VISIBLE
        binding.layoutMatkulCheckbox.removeAllViews()
        checkboxMap.clear()

        refMatkul.get().addOnSuccessListener { snapshot ->
            for (child in snapshot.children) {
                val kode = child.child("kode").getValue(String::class.java) ?: continue
                val nama = child.child("nama").getValue(String::class.java) ?: "Mata Kuliah"
                val cb = CheckBox(this)
                cb.text = "$kode - $nama"
                checkboxMap[kode] = cb
                binding.layoutMatkulCheckbox.addView(cb)
            }
        }
    }

    private fun tampilkanNilaiMahasiswa() {
        binding.tvNilaiMahasiswa.text = ""
        refTranskrip.child(nim).get().addOnSuccessListener { snapshot ->
            if (snapshot.exists()) {
                val builder = StringBuilder()
                for (matkulSnapshot in snapshot.children) {
                    val kode = matkulSnapshot.key ?: continue
                    val nilai = matkulSnapshot.child("nilai").getValue(Int::class.java)
                    builder.append("Mata Kuliah: $kode, Nilai: $nilai\n")
                }
                binding.tvNilaiMahasiswa.text = builder.toString()
            }
        }
    }
}
