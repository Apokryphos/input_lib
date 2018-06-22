#pragma once

#include "input_lib/key.hpp"
#include <map>

namespace InputLib
{
template <typename K, typename V>
class Map
{
    std::map<V, K> mKeyByValue;
    std::map<K, V> mValuesByKey;

public:
    void clear() {
        mKeyByValue.clear();
        mValuesByKey.clear();
    }

    K getKey(const V value) const {
        return mKeyByValue.at(value);
    }

    K getKey(const V value, const K defaultKey) const {
        const auto& find = mKeyByValue.find(value);
        if (find == mKeyByValue.end()) {
            return defaultKey;
        }

        return find->second;
    }

    V getValue(const K key) const {
        return mValuesByKey.at(key);
    }

    V getValue(const K key, const V defaultValue) const {
        const auto& find = mValuesByKey.find(key);
        if (find == mValuesByKey.end()) {
            return defaultValue;
        }

        return find->second;
    }

    void map(const K key, const V value) {
        mKeyByValue.emplace(value, key);
        mValuesByKey.emplace(key, value);
    }
};
}
