package com.example.fragment

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment

class ArticleFragment: Fragment {

    var txtArticle1: Textview? = null
    var txtArticle2: Textview? = null


    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.article_layout,
            container, false)
        txtArticle1 = view.findViewById(R.id.txt_article1)
        txtArticle2 = view.findViewById(R.id.txt_article2)
        return view
    }
}