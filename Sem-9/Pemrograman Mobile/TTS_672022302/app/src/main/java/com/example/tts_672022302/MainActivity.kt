package com.example.tts_672022302

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

    private lateinit var fragmentPertanyaan: FragmentPertanyaan
    private lateinit var sectionFragment: SectionFragment

    private val questions = listOf(
        Pertanyaan("1 + 1 =", listOf("5", "6", "7", "2"), "2"),
        Pertanyaan("Game apakah yang memenangkan award Game Of The Year (GOTY) 2024?", listOf("God Of War", "Assassin's Creed", "Cooking Mama", "Astro Bot"), "Astro Bot"),
        Pertanyaan("Berapa All Time High (ATH) Bitcoin?", listOf("$31.542", "$71.244", "$11.097", "$111.814"), "$111.814")
    )

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        fragmentPertanyaan = supportFragmentManager.findFragmentById(R.id.questionFragmentContainer) as FragmentPertanyaan
        sectionFragment = supportFragmentManager.findFragmentById(R.id.sectionFragmentContainer) as SectionFragment

        sectionFragment.setOnSectionSelectedListener { sectionIndex ->
            if (sectionIndex >= 0 && sectionIndex < questions.size) {
                fragmentPertanyaan.displayPertanyaan(questions[sectionIndex])
            }
        }
    }
}