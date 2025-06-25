package com.example.tts_672022302

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import android.widget.RadioButton
import android.widget.RadioGroup
import android.widget.TextView
import android.widget.Toast
import androidx.fragment.app.Fragment

class FragmentPertanyaan : Fragment() {

    private lateinit var questionTextView: TextView
    private lateinit var optionsRadioGroup: RadioGroup
    private lateinit var checkAnswerButton: Button

    private var currentPertanyaan: Pertanyaan? = null
    private var selectedAnswer: String? = null

    private var onAnswerCheckedListener: ((Boolean) -> Unit)? = null

    fun setOnAnswerCheckedListener(listener: (Boolean) -> Unit) {
        onAnswerCheckedListener = listener
    }

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.fragment_pertanyaan, container, false)

        questionTextView = view.findViewById(R.id.questionTextView)
        optionsRadioGroup = view.findViewById(R.id.optionsRadioGroup)
        checkAnswerButton = view.findViewById(R.id.checkAnswerButton)

        optionsRadioGroup.setOnCheckedChangeListener { group, checkedId ->
            if (checkedId != -1) {
                val radioButton = view.findViewById<RadioButton>(checkedId)
                selectedAnswer = radioButton.text.toString()
            } else {
                selectedAnswer = null
            }
        }

        checkAnswerButton.setOnClickListener {
            checkAnswer()
        }

        return view
    }

    fun displayPertanyaan(question: Pertanyaan) {
        currentPertanyaan = question
        questionTextView.text = question.questionText
        optionsRadioGroup.removeAllViews()

        question.options.forEach { option ->
            val radioButton = RadioButton(context)
            radioButton.text = option
            optionsRadioGroup.addView(radioButton)
        }
        optionsRadioGroup.clearCheck()
        selectedAnswer = null
    }

    private fun checkAnswer() {
        if (selectedAnswer == null) {
            Toast.makeText(context, getString(R.string.select_answer_first), Toast.LENGTH_SHORT).show()
            return
        }

        currentPertanyaan?.let {
            val isCorrect = selectedAnswer == it.correctAnswer
            if (isCorrect) {
                Toast.makeText(context, getString(R.string.answer_correct), Toast.LENGTH_SHORT).show()
            } else {
                Toast.makeText(context, getString(R.string.answer_wrong), Toast.LENGTH_SHORT).show()
            }
            onAnswerCheckedListener?.invoke(isCorrect)
        }
    }
}