#include <iostream>
#include <fstream>
#include <vector>
#include <json/json.h>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./task3 <tests_file> <values_file>" << endl;
        return 1;
    }

    ifstream tests_file(argv[1]);
    Json::Value tests_data;
    if (tests_file.is_open()) {
        tests_file >> tests_data;
        tests_file.close();
    } else {
        cout << "Unable to open file: " << argv[1] << endl;
        return 1;
    }

    ifstream values_file(argv[2]);
    Json::Value values_data;
    if (values_file.is_open()) {
        values_file >> values_data;
        values_file.close();
    } else {
        cout << "Unable to open file: " << argv[2] << endl;
        return 1;
    }
 
    for (int i = 0; i < tests_data.size(); i++) {
        Json::Value& test = tests_data[i];
        if (test.isMember("id")) {
            int test_id = test["id"].asInt();
            for (int j = 0; j < values_data.size(); j++) {
                Json::Value& value = values_data[j];
                if (value.isMember("id") && value["id"].asInt() == test_id) {
                    test["value"] = value["value"];
                    break;
                }
            }
        }
    }

   n
    ofstream report_file("report.json");
    if (report_file.is_open()) {
        report_file << tests_data;
        report_file.close();
    } else {
        cout << "Unable to create file: report.json" << endl;
        return 1;
    }

    return 0;
}