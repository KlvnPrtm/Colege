package com.example.packageregister

import android.content.Context
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.packageregister.databinding.ActivityLandingBinding


class LandingActivity : AppCompatActivity() {

    private lateinit var binding: ActivityLandingBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityLandingBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val sharedPref = getSharedPreferences("UserData", MODE_PRIVATE)
        val fullName = sharedPref.getString("fullname", "User")

        binding.tvWelcome.text = "Welcome, $fullName!"
    }
}
