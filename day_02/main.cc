#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> parse_input();
vector<int> get_invalids(vector<pair<int, int>> ranges);
int get_start(string range);
int get_finish(string range);

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

vector<pair<int, int>> parse_input() {
    vector<<pair<int, int>> result;

    string range;
    while (getline(cin, range, ',')) {
        result.pushback(
            make_pair(get_start(range), get_finish(range))
        );
    }

    return result;
}

// TODO
int get_start(string range) {
    return 0;
}

// TODO
int get_finish(string range) {
    return 0;
}

// TODO
vector<int> get_invalids(vector<pair<int, int>> ranges) {
    return {};
}
