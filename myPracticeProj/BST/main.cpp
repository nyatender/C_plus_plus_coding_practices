// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include "..\BST\treeNode.h"

using namespace std;

//void insertInMap(map<int, list<int>> adsList, int item, int toInsert);
//int sumOfDistance(vector<vector<int>>& arr) {
//
//    map<int, list<int>> adsList;
//    for (int i = 0; i < arr.size(); i++) {
//        for (int j = 0; j < arr[i].size(); j++) {
//            insertInMap(adsList, arr[i][j], arr[i][(j + 1) % arr[i].size()]);
//        }
//    }
//    
//}
//
//void insertInMap(map<int, list<int>> adsList, int index, int indexToInsert) {
//    if (!adsList.contains(index)) {
//        adsList.insert(index, indexToInsert);
//    }
//    else {
//        adsList[index].push_back(indexToInsert);
//    }
//}

int main()
{

    unordered_map<int, int> muMap;

    int arr[] = { 10,2,3,0,-1 };
    //cout << sizeof(arr) << "\n";
    for (int i = 0; i < 5; i++) {
        muMap.insert({ arr[i], i });
    }

    for (auto& pair : muMap) {
        cout << pair.first << " " << pair.second;
        cout << "\n";
    }

    std::cout << "Hello World!\n";
}
