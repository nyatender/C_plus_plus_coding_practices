
#include<unordered_map>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class LFUCache {
    int capacity;
    unordered_map<int, int> map;
    unordered_map<int, int> frequencyMap;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        int value = -1;
        if (map.find(key) != map.end()) {
            value = map[key];

            frequencyMap[key]++;
        }

        return value;
    }

    void put(int key, int value) {
        //cacheItemList.push_front(std::pair<int, int>(key, value));
        if (map.size() == capacity) {
            auto itr = frequencyMap.begin();
            frequencyMap.erase(itr);
            map.erase(itr);
        }
        if (map.find(key) == map.end()) {
            map.insert(key, value);
            frequencyMap.insert(key, 1);
        }

    }
};

int main() {
    LRUCache* obj = new LFUCache(2);

    obj->put(1, 1);
    obj->put(2, 2);

    cout << obj->get(1);

    return 0;
}
