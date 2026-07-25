#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> parse_input();
vector<int> get_invalids(vector<pair<int, int>> ranges);

int main()
{
    vector<pair<int, int>> ranges = parse_input();

    vector<int> invalids = get_invalids(ranges);

    int invalid_sum = accumulate(
        invalids.begin(),
        invalids.end(),
        0
    );

    cout << "result: " << invalid_sum << endl;

    return 0;
}

// TODO
vector<pair<int, int>> parse_input() {
    return {};
}

// TODO
vector<int> get_invalids(vector<pair<int, int>> ranges) {
    return {};
}
