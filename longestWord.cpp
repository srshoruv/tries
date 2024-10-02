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

    void longestHelper(Node* root, string &ans, string temp) {
        for (pair<char, Node*> child : root->children) {
            if (child.second->endOfWord) {
                temp += child.first;

                if ((temp.size()==ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }

                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }

    string longestWordEW() {
        string ans = "";
        longestHelper(root, ans, " ");
        return ans;
    }


};

string longestWord(vector<string> words) {
    Trie trie;
    for (int i=0; i<words.size(); i++) {
        trie.insert(words[i]);
    }

    return trie.longestWordEW();
}

int main (){
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << longestWord(words);
}