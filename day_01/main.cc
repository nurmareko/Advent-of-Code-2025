#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rotation {
    private:
        char direction;
        int distance;

        // TODO
        char get_direction(string str)
        {
            return 'L';
        }

        // TODO
        int get_distance(string str)
        {
            return 1;
        }

    public:
        // TODO
        Rotation(string str)
        {
            direction = get_direction(str);
            distance = get_distance(str);
        }
};

// TODO
vector<Rotation> collect_rotation()
{
    vector<Rotation> result;
    string str;

    while (getline(cin, str)) {
        result.push_back(Rotation(str));
    }

    return result;
}

// TODO
int crack_password(vector<Rotation>)
{
    return 0;
}

int main()
{
    vector<Rotation> puzzle = collect_rotation();

    cout << "password: " << crack_password(puzzle) << endl;

    return 0;
}
