#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;
    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
    
public:

    Trie(){
        root = new Node();
        root->freq = -1;
    }

    void insert(string key) {
        Node* temp = root;

        for (int i=0; i<key.size(); i++) {
            if(!temp->children.count(key[i])) {
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1;
            } else {
                temp->children[key[i]]->freq++;
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool startWith(string pref) {
        Node* temp = root;
        for (int i =0; i<pref.size();i++) {
            if(temp->children.count(pref[i])) {
                temp = temp->children[pref[i]];
            } else {
                return false;
            }
        }

        return true;
    }
};

int main (){
    vector<string> dic = {"app", "man", "woman", "apple"};
    Trie trie;

    for (int i=0; i<dic.size(); i++) {
        trie.insert(dic[i]);
    }

    cout << trie.startWith("man");

}