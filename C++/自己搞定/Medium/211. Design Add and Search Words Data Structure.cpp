#include<iostream>
#include <bits/stdc++.h>
#include <vector>
#include <array>
using namespace std;

class WordDictionary {
    std::array<WordDictionary*,26> words;
    bool flag;
public:
    WordDictionary() :flag(false),words{} {
    }
    void addWord(string word) {
        WordDictionary* nowTrie = this;
        for (char w:word){
            if(!nowTrie->words[int(w-'a')])
                nowTrie->words[int(w-'a')] = new WordDictionary();
            nowTrie = nowTrie->words[int(w-'a')];
        }
        nowTrie->flag = true;
    }

    bool search(string word) {
        WordDictionary* nowTrie = this;
        for (int index=0;index<word.size();index++){
            if(word[index]=='.'){
                for(WordDictionary* nextTrie : nowTrie->words){
                    if(!nextTrie)
                        continue;
                    if(nextTrie->search(std::string(word.begin()+index+1,word.end())))
                        return true;
                }
                return false;
            }          
            else {
                if(!nowTrie->words[int(word[index]-'a')])
                    return false;
                 nowTrie = nowTrie->words[int(word[index]-'a')];
            }
        }
        return nowTrie->flag;
    }
};