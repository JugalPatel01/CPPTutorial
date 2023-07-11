/*

    * Expedi ( Expedition )
    Q. A group of cows grabbed a truck and ventured on an expedition deep into the jungle. The truck leak one unit of fuel every
       unit of distnace it travels.To repair the truck, the cows need to drive to the nearest town. on this road, between the town and the current location.There are N fuel stations where the cows can stop to acquire additional fuel(1...100 units at each stop).The cows want to make the minimum possible number of stops for fuel on the way to town.
       Capacity of the tank is sufficiently large to hold any amount of fuel.
       Initial units of fuel : P
       Initial distance from town : L
       Determine the minimum number of stops to reach the town.
    i/p :   L = 25km        P = 10L
        distance from the town(km.) | 4  |  5  |  11  |  15  |
        fuel available(litre)       | 4  |  2  |  5   |  10  |
    o/p : 2
         15 | 11 |
         10 | 5  |

    approaches :
    1) bruteforce : find all the subsequences of stops and calculate which is feasible and has minimum stops
        Time complexity : O(2ⁿ)

    2) greedy aproach : calculate pump's distance from truck
        distance from the truck(km.) | 25-4  | 25-5  |  25-11  |  25-15  |
                                     | 21    |  20   |   14    |   10    |
        fuel available(litre)        | 4     |  2    |   5     |   10    |
        a) sort stops basis on distance from truck
        b) create a maxheap for fuels available at stop
        c) go through stops and when fuel becomes empty take the fuel from the maxheap and add it
        d) maintain count variable for stops

 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct fuel_cmp
{
    bool operator()(pair<int, int> const &a, pair<int, int> const &b)
    {
        return a.second < b.second;
    }
};

int find_stop(vector<pair<int, int>> stops, int distance_to_town, int init_fuel, vector<pair<int, int>> &ans)
{
    int count = 0;
    for (int i = 0; i < stops.size(); i++)
    {
        stops[i].first = distance_to_town - stops[i].first;
    }
    sort(stops.begin(), stops.end());

    int fuel = init_fuel;
    priority_queue<pair<int, int>, vector<pair<int, int>>, fuel_cmp> max_heap_for_fuel;
    for (int i = 0; i < stops.size(); i++)
    {
        if (fuel >= distance_to_town)
        {
            break;
        }

        while (fuel < stops[i].first)
        {
            if (max_heap_for_fuel.empty())
            {
                ans.clear();
                return -1;
            }
            fuel += max_heap_for_fuel.top().second;
            ans.push_back(max_heap_for_fuel.top());
            max_heap_for_fuel.pop();
            count++;
        }

        max_heap_for_fuel.push(stops[i]);
    }

    while (!max_heap_for_fuel.empty() && fuel < distance_to_town)
    {
        fuel += max_heap_for_fuel.top().second;
        ans.push_back(max_heap_for_fuel.top());
        max_heap_for_fuel.pop();
        count++;
    }

    if (fuel < distance_to_town)
    {
        ans.clear();
        return -1;
    }

    return count;
}

int main()
{
    int n, init_fuel, distance_to_town;
    cout << "total no. of stops avaiable in a way : ";
    cin >> n;
    vector<pair<int, int>> stops(n);
    for (int i = 0; i < n; i++)
    {
        cout << "distance of pump from town : ";
        cin >> stops[i].first;
        cout << "available fuel at pump : ";
        cin >> stops[i].second;
    }

    cout << "distance of the truck from town : ";
    cin >> distance_to_town;
    cout << "initial fuel in the truck : ";
    cin >> init_fuel;

    vector<pair<int, int>> ans;
    cout << "minimum stops required to fill fuel in truck to reach town is : " << find_stop(stops, distance_to_town, init_fuel, ans) << endl;

    for (auto i : ans)
    {
        cout << distance_to_town - i.first << " -> " << i.second << endl;
    }
    return 0;
}