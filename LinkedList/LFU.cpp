#include <bits/stdc++.h>
using namespace std;

class LFUCache {
   public:
    int size;
    int cap;

    unordered_map<int, list<vector<int>>::iterator> mp;
    map<int, list<vector<int>>> freq;

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void makeMostUsedFrequentlyUsed(int key) {
        auto it = mp[key];
        int value = (*it)[1];
        int f = (*it)[2];

        freq[f].erase(it);
        if (freq[f].empty()) freq.erase(f);

        f++;
        freq[f].push_front({key, value, f});
        mp[key] = freq[f].begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        auto it = mp[key];
        int value = (*it)[1];

        makeMostUsedFrequentlyUsed(key);
        return value;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (mp.find(key) != mp.end()) {
            auto it = mp[key];
            (*it)[1] = value;
            makeMostUsedFrequentlyUsed(key);
        } else if (size < cap) {
            size++;
            freq[1].push_front(vector<int>{key, value, 1});
            mp[key] = freq[1].begin();
        } else {
            auto& kaun_se_list = freq.begin()->second;
            int ket_to_delete = kaun_se_list.back()[0];

            kaun_se_list.pop_back();
            if (kaun_se_list.empty()) {
                freq.erase(freq.begin()->first);
            }

            mp.erase(ket_to_delete);

            freq[1].push_front(vector<int>{key, value, 1});
            mp[key] = freq[1].begin();
        }
    }
};

int main() {
    int capacity, q;
    cin >> capacity >> q;

    LFUCache obj(capacity);

    while (q--) {
        string op;
        cin >> op;

        if (op == "put") {
            int key, value;
            cin >> key >> value;
            obj.put(key, value);
        } else if (op == "get") {
            int key;
            cin >> key;
            cout << obj.get(key) << endl;
        }
    }

    return 0;
}