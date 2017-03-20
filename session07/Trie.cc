#include <iostream>

/*
4
AEMS
NROP
NTAR
EIUM


 */



class Trie {
private:
	class Node {
		Node* next[26];  //next[c - 'a']
		bool isWord; 
	};
	Node root;
public:
	void add(const string& word) {}
	bool isWord(const string& word) {}
	bool containsPrefix(const string& pref) {}
	
};


int main() {
	string words[] = {
		"a", "as", "intellectual", "intellectuals", "intellectually",
		"cat", "cats", "dog"
	};
	string s = "word";
