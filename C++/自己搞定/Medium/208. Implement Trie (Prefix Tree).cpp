#include<iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Trie {
    std::vector<Trie*>* trieVec ;
    std::vector<Trie*>* nowTrieVec;
    Trie* nowTrie ;
    bool flag = false;
public:
    Trie() {        
        this->trieVec = new std::vector<Trie*>(26,nullptr);
    }   
    void insert(string word) {  
        nowTrieVec= this->trieVec;    
        for(char w : word){ 
            nowTrie = (*nowTrieVec)[int(w-'a')];           
            if(!nowTrie){
                nowTrie = new Trie();
            }                    
            nowTrieVec = nowTrie->trieVec;      
        }
        nowTrie->flag = true;       
    }  
    bool search(string word) {
        nowTrieVec=this->trieVec; 
        for(char w : word){
            nowTrie = (*nowTrieVec)[int(w-'a')];
            if(!nowTrie)
                return false;
            nowTrieVec = nowTrie->trieVec;
        }
        return nowTrie->flag;
    }   
    bool startsWith(string prefix) {
        nowTrieVec=this->trieVec; 
        for(char w : prefix){
            nowTrie = (*nowTrieVec)[int(w-'a')];
            if(!nowTrie)
                return false;
            nowTrieVec = nowTrie->trieVec;
        }
        return true;
    }
};