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

    bool search(string key) {
        Node* temp = root;

        for (int i=0; i<key.size(); i++) {
            if (temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }

        return temp->endOfWord;
    }
};

bool helper(Trie &trie, string key) {
    if (key.size()==0) {
        return true;
    }

    for (int i=0; i<key.size(); i++) {
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if (trie.search(first) && helper(trie, second)) {
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string> dic, string key) {
    Trie trie;

    for (int i=0; i<dic.size(); i++) {
        trie.insert(dic[i]);
    }

    return helper(trie, key);
}

int main (){
    vector<string> dic = {"i", "like", "sam", "samsung", "mobile","ice"};
    string word = "ilikesung";
    Trie trie;

    cout << wordBreak(dic,word);

}