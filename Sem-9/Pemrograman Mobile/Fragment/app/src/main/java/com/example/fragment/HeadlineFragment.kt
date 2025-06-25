package com.example.fragment

import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment

class HeadlineFragment:Fragment {
    var btnHeadline1: Button? = null
    var btnHeadline2: Button? = null


    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(R.layout.headline_layout,
            container, false)

        btnHeadline1 = view.findViewById(R.id.btn_headline1)
        btnHeadline2 = view.findViewById(R.id.btn_headline2)
        btnHeadline1?.setText(News.title[0]))
        btnHeadline2?.setText(News.title[1]))
        btnHeadline1?.setOnClickListener(View.OnClickListener {
            val articleFragment = parentFragmentManager.findFragmentById(R.id.article_fragment) as ArticleFragment
            articleFragment?.txtArticle1?.setText(News.title[0])
            articleFragment?.txtArticle2?.setText(News.article[0])
        })
        btnHeadline2?.setOnClickListener(View.OnClickListener {
            val articleFragment = parentFragmentManager.findFragmentById(R.id.article_fragment) as ArticleFragment
            articleFragment?.txtArticle1?.setText(News.title[0])
            articleFragment?.txtArticle2?.setText(News.article[0])

            val isLandscape = resources.getBoolean(R.bool.is_landscape))
            if (!isLandscape){
                val articleFragment = ArticleFragment()
                articleFragment?.txtArticle1?.setText(News.title[1])
                articleFragment?.txtArticle2?.setText(News.title[1])
            }

        return view
    }

    }
}