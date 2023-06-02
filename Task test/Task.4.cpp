#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./task4 <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    vector<int> nums;
    int num;
    if (file.is_open()) {
        while (file >> num) {
            nums.push_back(num);
        }
        file.close();
    } else {
        cout << "Unable to open file: " << argv[1] << endl;
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    int avg = sum / nums.size();

    int steps = 0;
    for (int i = 0; i < nums.size(); i++) {
        steps += abs(nums[i] - avg);
    }
    
    cout << steps << endl;

    return 0;
}