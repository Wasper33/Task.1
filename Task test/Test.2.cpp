#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./task2 <file1> <file2>" << endl;
        return 1;
    }

   
    ifstream file1(argv[1]);
    float cx, cy, r;
    if (file1.is_open()) {
        file1 >> cx >> cy >> r;
        file1.close();
    } else {
        cout << "Unable to open file: " << argv[1] << endl;
        return 1;
    }

    
    ifstream file2(argv[2]);
    float x, y;
    vector<int> positions;
    if (file2.is_open()) {
        while (file2 >> x >> y) {
            
            float dist = sqrt(pow(x - cx, 2) + pow(y - cy, 2));
            if (dist == r) {
                positions.push_back(0);
            } else if (dist < r) {
                positions.push_back(1);
            } else {
                positions.push_back(2);
            }
        }
        file2.close();
    } else {
        cout << "Unable to open file: " << argv[2] << endl;
        return 1;
    }

    
    for (int i = 0; i < positions.size(); i++) {
        cout << positions[i] << endl;
    }

    return 0;
}