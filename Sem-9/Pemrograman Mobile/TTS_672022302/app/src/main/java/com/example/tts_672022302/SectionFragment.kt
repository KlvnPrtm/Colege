package com.example.tts_672022302

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import androidx.fragment.app.Fragment

class SectionFragment : Fragment() {

    private var onSectionSelectedListener: ((Int) -> Unit)? = null

    fun setOnSectionSelectedListener(listener: (Int) -> Unit) {
        onSectionSelectedListener = listener
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_section, container, false)

        val btnSection1: Button = view.findViewById(R.id.btnSection1)
        val btnSection2: Button = view.findViewById(R.id.btnSection2)
        val btnSection3: Button = view.findViewById(R.id.btnSection3)

        btnSection1.setOnClickListener { onSectionSelectedListener?.invoke(0) }
        btnSection2.setOnClickListener { onSectionSelectedListener?.invoke(1) }
        btnSection3.setOnClickListener { onSectionSelectedListener?.invoke(2) }

        return view
    }
}