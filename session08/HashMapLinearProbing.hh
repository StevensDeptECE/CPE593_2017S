#ifndef HASHMAP_LINEAR_PROBING_HH_
#define HASHMAP_LINEAR_PROBING_HH_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class HashMapLinearProbing {
private:
  class Node {
	public:
 		string key;
		int    val;
	};

	Node* table;
	size_t used;
	size_t size;
	int hist[12];
	void grow() {

	}
	/*
		   x mod n,, n = 8     0...7
			 x mod n, n = 1024   0...1023     10000000000
			                                  01111111111


	 */

	
	size_t hash(const string& s) const {
		size_t sum = s.length();
		for (int i = 0; i < s.length(); i++)
			sum = (sum + s[i]) ^ (sum >> 13) ^ (sum << 17);
		return sum & (size-1);
	}
public:
	HashMapLinearProbing(size_t sz) : table(new Node[sz]), used(0), size(sz) {
		for (int i = 0; i < 12; i++)
			hist[i] = 0;
	}
	~HashMapLinearProbing() {
		delete [] table;
	}
 
	void add(const string& s, const int v) {
    if (used+used >= size)
			grow();
    uint32_t pos = hash(s);
 		int count = 1;
		while (table[pos].key.length() != 0) {
			if (table[pos].key == s) {
				table[pos].val = v;
				if (count > 10)
					count = 11;
				hist[count]++;
				return;
			}
			count++;
			pos++;
			if (pos == size)
				pos = 0;
		}
		used++;
		if (count > 10)
			count = 11;
		hist[count]++;
		table[pos].key = s;
		table[pos].val = v;
	}

	bool contains(const string& s) const {
    uint32_t pos = hash(s);
		while (table[pos].key.length() != 0) {
			if (table[pos].key == s) {
				return true;
			}
			pos++;
			if (pos == size)
				pos = 0;
		}
    return false;
	}
	const int* get(const string& s) const {
    uint32_t pos = hash(s);
		while (table[pos].key.length() != 0) {
			if (table[pos].key == s) {
				return &table[pos].val;
			}
			pos++;
			if (pos == size)
				pos = 0;
		}
    return nullptr;
	}
	void printHist() const {
		for (int i = 1; i < 12; i++) {
			cout << i << "\t" << hist[i] << '\n';
		}
	}
	void load(const char filename[]) {
		ifstream dict(filename);
		string word;
		int count = 0;
		while (!dict.eof()) {
			dict >> word;
			add(word, count++);			
		}
		
	}

};

#endif
