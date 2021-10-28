package com.example.cookingbythebook.strategypackage

import com.example.cookingbythebook.compositepackage.Page
import com.example.cookingbythebook.compositepackage.Recipe
import com.example.cookingbythebook.iteratorpackage.PreorderIterator

open class CompileStrategy() {
    open fun compileList(titlePage: Page?, input: String): ArrayList<Page> {return ArrayList<Page>()}
}

class TagCompileStrategy() : CompileStrategy() {

    override fun compileList(titlePage: Page?, _tagInput: String): ArrayList<Page> {
        //create a new list with the user's input for tags
        var tagRecipeList = ArrayList<Page>()

        //initialize temporary tagInput
        var tagInput: String = _tagInput

        //to lower tagInput string
        tagInput = tagInput.toLowerCase()

        //create iterator (return a page)
        var it = PreorderIterator(titlePage)
        it.first()

        //iterate through each page in the cookbook to grab information
        while (!it.isDone()) {
            //check if page is a recipe
            if (it.current() is Recipe) {

                //get size of recipe's tagsList
                val tagsListCount: Int = (it.current() as Recipe).returnTagsCount();

                //iterate through tag vector in a recipe page
                for (i in 0 until tagsListCount) {
                    // get tag at an index
                    var tag: String = (it.current() as Recipe).returnTag(i)

                    //to lower tag string
                    tag = tag.toLowerCase()

                    //compare recipe's tag to user's input
                    if (tag == tagInput) {
                        tagRecipeList.add(it.current() as Recipe)
                    }
                }
            }

            it.getNext(); //get next page
        }

        return tagRecipeList
    }
}

class TitleCompileStrategy() : CompileStrategy() {
    override fun compileList(titlePage: Page?, _titleInput: String): ArrayList<Page> {
        //create a new list with the user's input for title
        var titleRecipeList = ArrayList<Page>()

        //initialize temporary titleInput
        var titleInput = _titleInput

        //to lower titleInput
        titleInput = titleInput.toLowerCase()

        //create iterator
        var it = PreorderIterator(titlePage)
        it.first()

        //iterate through each page in the cookbook to grab information
        while (!it.isDone()) {
            //check if page is a recipe
            if (it.current() is Recipe) {

                //page's recipe's title
                var title: String = (it.current() as Recipe).returnTitle()

                //to lower title
                title = title.toLowerCase()

                //compare recipe's title to user's input
                if (title.contains(titleInput)) {
                    titleRecipeList.add(it.current() as Recipe)
                }
            }

            it.getNext(); //get next page
        }

        return titleRecipeList
    }
}

class IngredientsCompileStrategy() : CompileStrategy() {
    override fun compileList(titlePage: Page?, _ingredientInput: String): ArrayList<Page> {
        //create a new list with the user's input for ingredients
        var ingredientRecipeList = ArrayList<Page>()

        //initialize temporary ingredient
        var ingredientInput: String = _ingredientInput

        //to lower ingredientInput string
        ingredientInput = ingredientInput.toLowerCase()

        //create iterator
        var it = PreorderIterator(titlePage)
        it.first()

        //iterate through each page in the cookbook to grab information
        while (!it.isDone()) {
            //check if page is a recipe
            if (it.current() is Recipe) {

                //get size of recipe's ingredientsList
                var ingredientsListCount: Int = (it.current() as Recipe).returnIngredientsCount();

                //iterate through each ingredients in the recipe
                for (i in 0 until ingredientsListCount) {
                    //get ingredient at an index
                    var ingredient: String = (it.current() as Recipe).returnIngredient(i)

                    //to lower ingredient string
                    ingredient = ingredient.toLowerCase()

                    //compare recipe's ingredients to user's input
                    if (ingredient == ingredientInput) {
                        ingredientRecipeList.add(it.current() as Recipe)
                    }
                }

                it.getNext()
            }
        }

        return ingredientRecipeList
    }
}