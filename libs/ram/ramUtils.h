#pragma once

#include "ofMain.h"

#include <tr1/unordered_map>

#pragma mark - ramCompoundContainer

template <typename T>
class ramCompoundContainer
{
	typedef std::tr1::unordered_map<string, T> MapType;
	typedef vector<T*> ArrayType;

public:

	void add(const string &key, T &o)
	{
		hash[key] = o;
		updateIndexCache();
	}

	void remove(const string &key)
	{
		hash.erase(key);
		updateIndexCache();
	}

	size_t size() { return array.size(); }

	// array

	T& operator[](size_t index)
	{
		return *array[index];
	}

	// map

	const vector<string>& keys() { return hash_keys; }

	T& operator[](const string& key)
	{
		return hash[key];
	}

	bool hasKey(const string& key)
	{
		return hash.find(key) != hash.end();
	}

	void updateIndexCache()
	{
		array.clear();
		hash_keys.clear();
		
		typename MapType::iterator it = hash.begin();
		while (it != hash.end())
		{
			hash_keys.push_back(it->first);
			array.push_back(&it->second);
			it++;
		}
	}

private:

	MapType hash;
	ArrayType array;

	vector<string> hash_keys;

};