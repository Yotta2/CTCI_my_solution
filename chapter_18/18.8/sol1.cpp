#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <vector>
#include <list>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <time.h>

#define EPS 1e-6
#define SIZE 10000100

using namespace std;

//lowercase only
class SuffixTrie {
public:
    SuffixTrie(string str) {
        root = new Node('R');
        string suffix;
        for (int i = 0; i < str.size(); i++) {
            suffix = str.substr(i);
            insert(root, suffix);
        }
    }

    bool find(string str) {
        Node *curr = root;
        for (int i = 0; i < str.size(); i++) {
            curr = curr->children[str[i] - 'a'];
            if (curr == NULL)
                return false;
        }
        return true;
    }
private:
    struct Node {
        char letter;
        Node *children[26];
        Node(char l) {
            letter = l;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };
    Node *root;

    void insert(Node *node, string str) {
        char firstLetter = str[0];
        if (node->children[firstLetter - 'a'] == NULL)
            node->children[firstLetter - 'a'] = new Node(firstLetter);
        if (str.size() > 1)
            insert(node->children[firstLetter - 'a'], str.substr(1));
    }
};



int main() {
    ofstream fout("sol.out");
    ifstream fin("sol.in");

    vector<string> words;
    string word;
    while (fin >> word) {
        words.push_back(word);
        //cout << word << endl;
    }
    string s = "catbananadognanawalkwalkerdogwalker";
    SuffixTrie suffixTrie(s);
    for (string word : words)
        cout << suffixTrie.find(word) << endl;
    return 0;
}
