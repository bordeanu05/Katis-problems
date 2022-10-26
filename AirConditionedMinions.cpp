#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stdio.h>
#include <string.h>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<std::pair<int, int>> preferences;

    int n; std::cin >> n;
    for(int i = 0; i<n; ++i)
    {
        int x, y; std::cin >> x >> y;
        preferences.push_back({x, y});
    }

    sort(preferences.begin(), preferences.end(),
        [](std::pair<int, int> a, std::pair<int, int> b) {
            if(a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });

    unsigned rooms = 1;
    unsigned actualTemp = preferences[0].second;
    for(int i = 1; i<preferences.size(); ++i)
    {
        if(preferences[i].first > actualTemp){
            ++rooms;
            actualTemp = preferences[i].second;
        }
    }

    std::cout << rooms;
}
