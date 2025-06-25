package com.example.tugas2

//import com.example.tugas2.SignInScreen

import android.content.Intent
import android.os.Bundle
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.tugas2.databinding.ActivitySignUpBinding

class SignUpScreen : AppCompatActivity() {
    private lateinit var view: ActivitySignUpBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        view = ActivitySignUpBinding.inflate(layoutInflater)
        setContentView(view.root)

        view.btnCreateAccount.setOnClickListener {
            val name = view.inputName.text.toString()
            val username = view.inputNewUsername.text.toString()
            val password = view.inputNewPassword.text.toString()
            val confirm = view.inputConfirmPassword.text.toString()

            if (name.isBlank() || username.isBlank() || password.isBlank() || confirm.isBlank()) {
                Toast.makeText(this, "Semua kolom wajib diisi", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            if (!username.matches(Regex("^[a-zA-Z0-9_.-]{4,}\$"))) {
                Toast.makeText(this, "Username minimal 4 karakter, hanya huruf dan angka", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            if (password.length < 6) {
                Toast.makeText(this, "Password minimal 6 karakter", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            if (password != confirm) {
                Toast.makeText(this, "Konfirmasi password tidak cocok", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }

            val sharedPref = getSharedPreferences("account_data", MODE_PRIVATE)
            with(sharedPref.edit()) {
                putString("acc_name", name)
                putString("acc_username", username)
                putString("acc_password", password)
                apply()
            }

            Toast.makeText(this, "Akun berhasil dibuat!", Toast.LENGTH_SHORT).show()
            startActivity(Intent(this, SignInScreen::class.java))
            finish()
        }
    }
}
