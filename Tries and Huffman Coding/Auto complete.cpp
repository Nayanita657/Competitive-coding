#include <iostream>
#include <string>
#include <vector>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    void checkwordwithPattern(TrieNode *root,string word)
    {
        if(root->isTerminal == true)
        {
            cout<<word<<"\n";
        }
        for(int i = 0; i < 26; i++)
        {
            if(root->children[i] != NULL)
            {
                TrieNode *child = root->children[i];
                string frw = word + child->data;
                checkwordwithPattern(child,frw);
                    
            }
            else
            {
                continue;
            }
        }
        return;
    }
    
    void doesPatternExist(TrieNode *root, string pattern, string actual_pattern)
    {
        if(pattern.size() == 0)
        {
            checkwordwithPattern(root,actual_pattern);
        }
        else
        {
            int index = pattern[0] - 'a';
            if(root->children[index] != NULL)
            {
                TrieNode *child = root->children[index];
                doesPatternExist(child,pattern.substr(1),actual_pattern);
            }
        }
    }

    void autoComplete(vector<string> input, string pattern) 
    {
        // Write your code here
        //insert words in Trie
        for(int i = 0; i < input.size(); i++)
        {
            insertWord(input[i]);
        }
        doesPatternExist(root,pattern,pattern);
        
        
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}