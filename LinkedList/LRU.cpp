#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int cap;

    // Doubly linked list: stores {key, value}
    list<pair<int, int>> cacheList;

    // Map: key -> iterator of list
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    // Constructor
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        // Key not found
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        // Move accessed node to front (most recently used)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);

        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        // If key already exists
        if (cacheMap.find(key) != cacheMap.end()) {
            // Move to front
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);

            // Update value
            cacheMap[key]->second = value;
            return;
        }

        // If capacity full → remove least recently used (back)
        if (cacheList.size() == cap) {
            int lruKey = cacheList.back().first;

            cacheList.pop_back();        // remove from list
            cacheMap.erase(lruKey);      // remove from map
        }

        // Insert new element at front
        cacheList.push_front({key, value});
        // Store iterator in map
        cacheMap[key] = cacheList.begin();
    }
};