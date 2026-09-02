#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

vector<pair<long, long>> parse_input();
vector<long> get_invalids(vector<pair<long, long>> ranges);
long get_start(string range);
long get_finish(string range);
void test_case();

int main()
{
    test_case();

    vector<pair<long, long>> ranges = parse_input();

    vector<long> invalids = get_invalids(ranges);

    long long invalid_sum = accumulate(
        invalids.begin(),
        invalids.end(),
        0LL
    );

    cout << "result: " << invalid_sum << endl;

    return 0;
}

void test_case()
{
    assert(get_start("0-0") == 0LL);
    assert(get_start("123-222") == 123LL);
    assert(get_finish("0-0") == 0LL);
    assert(get_finish("123-222") == 222LL);

    vector<pair<long, long>> ex_input = {
        pair<long, long>(11LL, 22LL),
        pair<long, long>(95LL, 115LL),
        pair<long, long>(998LL, 1012LL),
    };
    vector<long> ex_output = {11LL, 22LL, 99LL, 1010LL};

    assert(get_invalids(ex_input) == ex_output);

    cout << "tests passed!" << endl;
}

vector<pair<long, long>> parse_input()
{
    vector<pair<long, long>> result;

    string range;
    while (getline(cin, range, ',')) {
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

    return stol(range.substr(start, range.length() - 1));
}

vector<long> get_invalids(vector<pair<long, long>> ranges)
{
    vector<long> invalids = {};
    for (pair<long, long> range: ranges) {
        long start = range.first;
        long end = range.second;
        for (long id = start; id <= end; id++) {
            string current_id = to_string(id);
            int id_length = current_id.length();

            if (id_length % 2 == 0) {
                int split_postion = id_length / 2;
                string x = current_id.substr(0, split_postion);
                string y = current_id.substr(split_postion, id_length - 1);

                if (x == y) {
                    invalids.push_back(id);
                }
            }
        }
    }

    return invalids;
}
