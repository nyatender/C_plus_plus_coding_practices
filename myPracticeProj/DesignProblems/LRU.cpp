
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

class LRUCache {
    int capacity;
    unordered_map<int, list<std::pair<int, int>>::iterator> map;
    list<std::pair<int, int>> cacheItemList;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        int value = -1;
        if (map.find(key) != map.end()) {
            value = map[key]->second;
            cacheItemList.erase(map[key]);

            cacheItemList.push_front(std::pair<int, int>(key, value));
            map[key] = cacheItemList.begin();
        }

        return value;
    }

    void put(int key, int value) {
        cacheItemList.push_front(std::pair<int, int>(key, value));
        if (map.find(key) != map.end()) {
            auto itr = map[key];
            cacheItemList.erase(itr);
            map[key] = cacheItemList.begin();
        }
        else {
            map.insert(std::pair<int, list<std::pair<int, int>>::iterator>(key, cacheItemList.begin()));
        }
        if (cacheItemList.size() > capacity) {
            map.erase(cacheItemList.crbegin()->first);
            cacheItemList.pop_back();

        }
    }
};

int main() {
    LRUCache *obj = new LRUCache(2);

    obj->put(1, 1);
    obj->put(2, 2);

   cout << obj->get(1);

    return 0;
}
