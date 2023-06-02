#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./task1 <n> <m>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    vector<int> circle_array(n);
    for (int i = 0; i < n; i++) {
        circle_array[i] = i + 1;
    }

    int index = 0;
    vector<int> path;
    while (!circle_array.empty()) {
        index = (index + m - 1) % circle_array.size();
        path.push_back(circle_array[index]);
        circle_array.erase(circle_array.begin() + index);
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
    }
    cout << endl;

    return 0;
}