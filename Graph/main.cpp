#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Map of Romania with cities and distances between them
//Put in a city and then add every other city with their distance
map<string, vector<pair<string, int>>> romaniaMap = {
    {"Arad", {{"Zerind", 75}, {"Sibiu", 140}, {"Timisoara", 118}}},
    {"Zerind", {{"Arad", 75}, {"Oradea", 71}}},
    {"Oradea", {{"Zerind", 71}, {"Sibiu", 151}}},
    {"Sibiu", {{"Arad", 140}, {"Oradea", 151}, {"Fagaras", 99}, {"Rimnicu Vilcea", 80}}},
    {"Fagaras", {{"Sibiu", 99}, {"Bucharest", 211}}},
    {"Rimnicu Vilcea", {{"Sibiu", 80}, {"Pitesti", 97}, {"Craiova", 146}}},
    {"Pitesti", {{"Rimnicu Vilcea", 97}, {"Bucharest", 101}, {"Craiova", 138}}},
    {"Craiova", {{"Rimnicu Vilcea", 146}, {"Pitesti", 138}, {"Dobreta", 120}}},
    {"Timisoara", {{"Arad", 118}, {"Lugoj", 111}}},
    {"Lugoj", {{"Timisoara", 111}, {"Mehadia", 70}}},
    {"Mehadia", {{"Lugoj", 70}, {"Dobreta", 75}}},
    {"Dobreta", {{"Mehadia", 75}, {"Craiova", 120}}},
    {"Bucharest", {{"Fagaras", 211}, {"Pitesti", 101}, {"Giurgiu", 90}, {"Urziceni", 85}}},
    {"Giurgiu", {{"Bucharest", 90}}},
    {"Urziceni", {{"Bucharest", 85}, {"Hirsova", 98}, {"Vaslui", 142}}},
    {"Hirsova", {{"Urziceni", 98}, {"Eforie", 86}}},
    {"Eforie", {{"Hirsova", 86}}},
    {"Vaslui", {{"Urziceni", 142}, {"Iasi", 92}}},
    {"Iasi", {{"Vaslui", 92}, {"Neamt", 87}}},
    {"Neamt", {{"Iasi", 87}}}
};

// BFS algorithm to find the shortest path between two cities
int bfs(string startCity, string endCity) {
    map<string, bool> visited;
    map<string, int> distances;
    queue<string> q;
    visited[startCity] = true;
    q.push(startCity);
    while (!q.empty()) {
        string currentCity = q.front();
        q.pop();
        if (currentCity == endCity) {
            return distances[currentCity];
        }
        for (auto& neighbor : romaniaMap[currentCity]) {
            string neighborCity = neighbor.first;
            int distance = neighbor.second;
            if (!visited[neighborCity]) {
                visited[neighborCity] = true;
                distances[neighborCity] = distances[currentCity] + distance;
                q.push(neighborCity);
            }
        }
    }
}


main(){
    string startCity;
    string endCity;
    int distance = 0;
    cout << "Give start city: ";
    cin >> startCity;
    cout << "Give end city: ";
    cin >> endCity;
    distance = bfs(startCity,endCity);
    cout << distance;
    return 0;
}