package com.example.packageregister

import android.content.Intent
import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.packageregister.databinding.ActivityLoginBinding


class LoginActivity : AppCompatActivity() {

    private lateinit var binding: ActivityLoginBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityLoginBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val sharedPref = getSharedPreferences("UserData", MODE_PRIVATE)

        binding.btnLogin.setOnClickListener {
            val inputUsername = binding.etLoginUsername.text.toString()
            val inputPassword = binding.etLoginPassword.text.toString()

            val savedUsername = sharedPref.getString("username", "")
            val savedPassword = sharedPref.getString("password", "")

            if (inputUsername == savedUsername && inputPassword == savedPassword) {
                val intent = Intent(this, LandingActivity::class.java)
                startActivity(intent)
                finish()
            } else {
                Toast.makeText(this, "Login failed: Incorrect credentials", Toast.LENGTH_SHORT).show()
            }
        }
    }
}
