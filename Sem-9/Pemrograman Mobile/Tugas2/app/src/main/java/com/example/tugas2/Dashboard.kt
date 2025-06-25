package com.example.tugas2

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.tugas2.databinding.ActivityDashboardBinding

class Dashboard : AppCompatActivity() {
    private lateinit var view: ActivityDashboardBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        view = ActivityDashboardBinding.inflate(layoutInflater)
        setContentView(view.root)

        val sharedPref = getSharedPreferences("account_data", MODE_PRIVATE)
        val fullname = sharedPref.getString("acc_name", "Pengguna")

        view.textGreeting.text = "Hi, $fullname 👋\nSelamat datang di aplikasi kami!"
    }
}
