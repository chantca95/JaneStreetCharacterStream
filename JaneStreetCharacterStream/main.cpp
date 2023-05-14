//
//  main.cpp
//  JaneStreetCharacterStream
//
//  Created by Alex Chan on 5/13/23.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class TrieNode {
public:
    TrieNode* edges[26];
    string wordFormed = "";
};

void populateTrieRoot(TrieNode* root, string word) {
    TrieNode* current = root;
    for (char c : word) {
        int index = c - 'a';
        if (!current->edges[index]) {
            current->edges[index] = new TrieNode();
        }
        current = current->edges[index];
    }
    current->wordFormed = word;
}

string parseNewChar(char c, TrieNode* root, queue<TrieNode*>& pending) {
    int index = c - 'a';
    auto qSize = pending.size();
    TrieNode* current;
    // parse from the existing pending nodes first
    for (int i=0; i<qSize; i++) {
        current = pending.front();
        pending.pop();
        if (current->edges[index]) {
            current = current->edges[index];
            if (current->wordFormed != "") {
                return current->wordFormed;
            }
            pending.push(current);
        }
    }
    // parse the root
    if (root->edges[index]) {
        current = root->edges[index];
        if (current->wordFormed != "") {
            return current->wordFormed;
        }
        pending.push(current);
    }
    return "";
}

int main(int argc, const char * argv[]) {
    TrieNode* root = new TrieNode();
    vector<string> input = {"abcd", "bcde", "cdef", "abcge", "ice", "ffff"};
    for (string word : input) {
        populateTrieRoot(root, word);
    }

    cout << "Enter characters:" << endl;
    queue<TrieNode*> pending;
    string next;
    while (true) {
        cin >> next;
        if (next == "end") {
            cout << "Terminating early" << endl;
            break;
        }
        if (next.size() > 1) {
            cout << "Enter characters one at a time" << endl;
        } else {
            string result = parseNewChar(next[0], root, pending);
            if (result != "") {
                cout << "The character stream has matched the word " << result << endl;
                return 0;
            }
        }
    }
    
    return 0;
}
