#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<pair<long, long>> parse_input();
vector<int> get_invalids(vector<pair<long, long>> ranges);
long get_start(string range);
long get_finish(string range);
void test_case();

int main()
{
    test_case();

    vector<pair<long, long>> ranges = parse_input();

    vector<int> invalids = get_invalids(ranges);

    long invalid_sum = accumulate(
        invalids.begin(),
        invalids.end(),
        0
    );

    cout << "result: " << invalid_sum << endl;

    return 0;
}

void test_case()
{
    assert(0 == 0);
}

vector<pair<long, long>> parse_input()
{
    vector<pair<long, long>> result;

    string range;
    while (getline(cin, range, ',')) {
        // DEBUG
        // cout << "range: " << range << endl;
        result.push_back(
            make_pair(get_start(range), get_finish(range))
        );
    }

    return result;
}

long get_start(string range)
{
    size_t end;

    for (long i = 0; true; i++) {
        if (range[i] == '-') {
            end = i;
            break;
        }
    }

    // DEBUG
    // cout << "get_start: " << range.substr(0, end) << endl;
    return stol(range.substr(0, end));
}

long get_finish(string range)
{
    size_t start;

    for (long i = 0; true; i++) {
        if (range[i] == '-') {
            start = i + 1;
            break;
        }
    }

    // DEBUG
    // cout << "get finish: " << range.substr(start, range.length() - 1) << endl;
    return stol(range.substr(start, range.length() - 1));
}

// TODO
vector<int> get_invalids(vector<pair<long, long>> ranges)
{
    for (pair<long, long> id_range: ranges) {
        cout << "from: " << id_range.first << "to: " << id_range.second << endl;
    }

    return {};
}
