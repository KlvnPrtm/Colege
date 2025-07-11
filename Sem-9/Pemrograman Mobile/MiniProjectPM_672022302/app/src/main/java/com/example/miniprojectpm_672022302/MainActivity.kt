package com.example.miniprojectpm_672022302

import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        // Langsung redirect ke LoginActivity
        startActivity(Intent(this, LoginActivity::class.java))
        finish()
    }
}
