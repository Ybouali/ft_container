#include "../map.hpp"
#include <map>

int     main()
{

    int arrint[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30  };
    std::string arrstr[30] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30" }; 

    std::pair<int, std::string> arr[29];

    for (int i = 0; i < 30; i++)
    {
        arr[i].first = arrint[i];
        arr[i].second = arrstr[i];
    }

    std::map<int, std::string> map(arr, arr + 29);
    std::map<int, std::string> map1;

    map1 = map;
    
}