package com.example.tugas2

import android.content.Intent
import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.tugas2.databinding.ActivitySignInBinding


class SignInScreen : AppCompatActivity() {
    private lateinit var view: ActivitySignInBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        view = ActivitySignInBinding.inflate(layoutInflater)
        setContentView(view.root)

        val sharedPref = getSharedPreferences("account_data", MODE_PRIVATE)

        view.btnSignIn.setOnClickListener {
            val username = view.inputUsername.text.toString()
            val password = view.inputPassword.text.toString()

            val savedUser = sharedPref.getString("acc_username", "")
            val savedPass = sharedPref.getString("acc_password", "")

            if (username == savedUser && password == savedPass) {
                startActivity(Intent(this, Dashboard::class.java))
                finish()
            } else {
                Toast.makeText(this, "Akun tidak ditemukan atau password salah!", Toast.LENGTH_SHORT).show()
            }
        }

        view.textRegister.setOnClickListener {
            startActivity(Intent(this, SignUpScreen::class.java))
        }
    }
}
