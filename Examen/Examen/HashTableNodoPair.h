#pragma once

template<class K, class V>
class HashTableNodoPair
{

public:
	K Key;
	V Value;

	HashTableNodoPair(K key, V value) : Key(key), Value(value) {};
	bool operator==(K const& key) const
	{
		return Key == key;
	};
};

