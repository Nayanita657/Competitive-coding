#include <iostream>
#include <string>
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
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) 
    {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) 
    { 
        insertWord(root, word); 
    }

    bool helper_search(TrieNode *root,string word) 
    {
        // Base case
        if(word.size() == 0)
        {
             if(root->isTerminal == true)
             {
                 return true;
             }
            else
            {
                return false;
            }
        }
        else
        {
            int index = word[0] - 'a';
            if(root->children[index] == NULL)
            {
                return false;
            }
            else
            {
                TrieNode *child = root->children[index];
                return helper_search(child,word.substr(1));
            }
        }
    }   
    bool search(string word)
    {
        return helper_search(root,word);
    }
    
    void remove_helper(TrieNode *root, string word)
    {
        //Base case
        if(word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        //small Calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            return;
        }
        remove_helper(child,word.substr(1));
        //Remove child node if it is useless
        if(child->isTerminal == false)
        {
            for(int i = 0; i < 26; i++)
            {
                if(child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    
    void removeWord(string word)
    {
        remove_helper(root,word);
    }
    
};

int main() 
{
    Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");

	cout << t.search("and") << endl;

	t.removeWord("and");
	cout << t.search("and") << endl;

    return 0;
}