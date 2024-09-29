#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
public:

    Trie(){
        root = new Node();
    }

    void insert(string key) {
        Node* temp = root;

        for (int i=0; i<key.size(); i++) {
            if(!temp->children.count(key[i])) {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }
};

int main (){
    vector<string> words = {"the", "a", "there", "their", "any","three"};
    Trie trie;

    for (int i=0; i<words.size(); i++) {
        trie.insert(words[i]);
    }
}