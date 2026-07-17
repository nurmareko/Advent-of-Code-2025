#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rotation {
    private:
        char parse_direction(string str)
        {
            return str[0];
        }

        int parse_distance(string str)
        {
            return stoi(str.substr(1));
        }

    public:
        char direction;
        int distance;

        Rotation(string str)
        {
            direction = parse_direction(str);
            distance = parse_distance(str);
        }
};

vector<Rotation> collect_rotation()
{
    vector<Rotation> result;
    string str;

    while (getline(cin, str)) {
        result.push_back(Rotation(str));
    }

    return result;
}

int turn_dial(int dial, Rotation rotation)
{
    char direction = rotation.direction;
    int distance = rotation.distance;

    if (distance == 0) {
        return dial;
    }

    if (direction == 'L') {
        while (distance > 0) {
            if (dial == 0) {
                dial = 99;
            } else {
                --dial;
            }
            --distance;
        }
    } else {
        while (distance > 0) {
            if (dial == 99) {
                dial = 0;
            } else {
                ++dial;
            }
            --distance;
        }
    }

    return dial;
}

int crack_password(vector<Rotation> puzzle)
{
    int dial = 50;
    int result = 0;

    for (Rotation rotation : puzzle) {
        dial = turn_dial(dial, rotation);

        if (dial == 0) {
            ++result;
        }
    }

    return result;
}

void test_case()
{
    assert(turn_dial(50, Rotation("L0")) == 50);
    assert(turn_dial(50, Rotation("L15")) == 35);
    assert(turn_dial(50, Rotation("R10")) == 60);
    assert(turn_dial(50, Rotation("L50")) == 0);
    assert(turn_dial(50, Rotation("L51")) == 99);
    assert(turn_dial(50, Rotation("R49")) == 99);
    assert(turn_dial(50, Rotation("L50")) == 0);
    vector<Rotation> puzzle1;
    vector<Rotation> puzzle2 = {Rotation("L35")};
    vector<Rotation> puzzle3 = {Rotation("L50")};
    vector<Rotation> puzzle4 = {Rotation("R50")};
    vector<Rotation> puzzle5 = {Rotation("L40"), Rotation("L10")};
    assert(crack_password(puzzle1) == 0);
    assert(crack_password(puzzle2) == 0);
    assert(crack_password(puzzle3) == 1);
    assert(crack_password(puzzle4) == 1);
    assert(crack_password(puzzle5) == 1);

    cout << "tests passed!" << endl;
}

int main()
{
    // test_case();

    vector<Rotation> puzzle = collect_rotation();
    cout << "password: " << crack_password(puzzle) << endl;

    return 0;
}
