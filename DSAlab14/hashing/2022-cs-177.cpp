#include "hashing.h"
#include<iostream>
#include <vector>
#include<list>
#include <unordered_map>
using namespace std;
///////////////////////////Chaining method//////////////////
int hashFunction(int key,int tableSize=5) {
	return key % tableSize;
}
void insert(int key, const string& value,vector<list<pair<int,string>>> &table) {
	int index = hashFunction(key);
	table[index].push_back(make_pair(key, value));
}
void printHashTable(vector<list<pair<int, string>>>& hashTable) {
	for (int i = 0; i < 5; ++i) {
		std::cout << "Index " << i << ": ";
		for (const auto& pair : hashTable[i]) {
			std::cout << "[" << pair.first << ", " << pair.second << "] ";
		}
		std::cout << std::endl;
	}
}
///////////////////////chaining end///////////////////////
//////////////////////Linear probing//////////////////////
void insertProbing(int key, const string& value, vector<pair<int, string>>& table) {
	int index = hashFunction(key);
	while (table[index].first != -1) {
		index = (index + 1) % 5;
	}
	table[index] = make_pair(key, value);
}
void printLinearProbingTable(vector<pair<int, string>>& table) {
	for (int i = 0; i < 5; ++i) {
		cout << "Index " << i << ": ";
		if (table[i].first != -1) {
			cout << "[" << table[i].first << ", " << table[i].second << "] ";
		}
		cout << endl;
	}
}
///////////////////Linear probing end////////////////////////
///////////////////////////Quadratic Probing//////////////////////////
void insertQuadratic(int key, const string& value, vector<pair<int, string>>& table) {
	int index = hashFunction(key, table.size());
	int i = 0;

	// Quadratic probing until an empty slot is found
	while (table[index].first != -1) {
		index = (index + i * i) % table.size();
		i++;
	}

	// Insert at the found empty slot
	table[index] = make_pair(key, value);
}
//////////////////////problem 1 dna sequencing////////////////
vector<string> findRepeatedDnaSequences(string s) {
	string curr = "";
	vector<string>str;
	unordered_map<string, int>m;
	for (int i = 0; i < s.size(); i++)
	{
		curr = s.substr(i, 10);
		if (m.find(curr) == m.end())
		{
			m.insert({ curr,0 });
		}
		else if (!m[curr])
		{
			str.push_back(curr);
			m[curr]++;
		}
	}
	return str;
}
//////////////////////Problem 2 anagram///////////////////

int main()
{
	vector<list<pair<int,string>>> table(5);
	vector <pair<int, string>>probingtable(5, make_pair(-1, ""));
	insertQuadratic(1, "val1", probingtable);
	insertQuadratic(11, "val2", probingtable);
	insertQuadratic(111, "val3", probingtable);
	insertQuadratic(30, "val4", probingtable);
	insertQuadratic(31, "val5", probingtable);
	printLinearProbingTable(probingtable);
	return 0;
}