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

    int countNodes(Node* root) {
        if (!root) {
            return 0;
        }

        int count = 1;
        for (auto it: root->children) {
            count += countNodes(it.second);
        }

        return count;
    }

    int countUniqueSub(string s) {
        for (int i=0; i<s.size(); i++) {
            insert(s.substr(i));
        }

        return countNodes(root);
    }


};

int main (){
    string s = "ababa";
    Trie trie;

    cout << "Total unique substrings are: " << trie.countUniqueSub(s) << endl;
}