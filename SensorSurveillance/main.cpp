#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <chrono>

using namespace std;

auto *sensorValues = new unsigned char[30];

bool isNumber(const string &s) {
    if(s.empty()) return false;
    for(char i : s) {
        if(!(i >= '0' && i <= '9')) {
            return false;
        }
    }
    return true;
}

void initiateFirstValues() {
    string wordIn;
    ifstream myFile;
    myFile.open(("../statusOne.txt" ));

    if (myFile.is_open()) {
        auto *res = new string("");
        int *i = new int;
        int *j = new int;
        *i = 0, *j = 0;

        while (getline(myFile, wordIn, ';')) {
            if (!isNumber(wordIn)) {
                if (wordIn != "false") {
                    *res += '1';
                } else {
                    *res += '0';
                }
                *i += 1;
            }
            if (*i == 8) {
                sensorValues[*j] = bitset<8>(*res).to_ulong();
                cout << "[Heap] sensorValues[" << *j << "] string: " << bitset<8>(sensorValues[*j]).to_string() << ", dec: " << bitset<8>(sensorValues[*j]).to_ulong() << endl;
                *res = "";
                *j += 1;
                *i = 0;
            }
        }
        for (int x = *i; x < 8; x++) {
            *res += '0';
        }
        sensorValues[*j] = bitset<8>(*res).to_ulong();
        cout << "[Heap] sensorValues[" << *j << "] string: " << bitset<8>(sensorValues[*j]).to_string() << ", dec: " << bitset<8>(sensorValues[*j]).to_ulong() << endl;
        delete res, delete i, delete j;

    } else {
        cout << "Something went wrong with opening the file...";
    }
    cout << endl;
}

void initiateSecondValues() {
    string wordIn;
    ifstream myFileTwo;
    myFileTwo.open(("../statusTwo.txt" ));

    if (myFileTwo.is_open()) {
        auto *res = new string("");
        int *i = new int;
        int *j = new int;
        *i = 0, *j = 0;

        while (getline(myFileTwo, wordIn, ';')) {
            if (!isNumber(wordIn)) {
                if (wordIn != "false") {
                    *res += '1';
                } else {
                    *res += '0';
                }
                *i += 1;
            }
            if (*i == 8) {
                if (bitset<8>(sensorValues[*j]).to_string() != *res) {
                    for (int y = 0; y < 8; y++) {
                        if (res->at(y) !=  bitset<8>(sensorValues[*j]).to_string().at(y)) {
                            if (res->at(y) == '1') {
                                cout << "Sensor nr[" << y + (*j * 8) +1 << "] changed from [false] to [true]" << endl;
                            } else {
                                cout << "Sensor nr[" << y + (*j * 8) +1 << "] changed from [true] to [false]" << endl;
                            }
                        }
                    }
                }
                *res = "";
                *j += 1;
                *i = 0;
            }
        }
        for (int x = *i; x < 8; x++) {
            *res += '0';
        }
        for (int y = 0; y < 8; y++) {
            if (res->at(y) !=  bitset<8>(sensorValues[*j]).to_string().at(y)) {
                if (res->at(y) == '1') {
                    cout << "Sensor nr[" << y + (*j * 8) +1 << "] changed from [false] to [true]" << endl;
                } else {
                    cout << "Sensor nr[" << y + (*j * 8) +1 << "] changed from [true] to [false]" << endl;
                }
            }
        }
        delete res, delete i, delete j;
    } else {
        cout << "Something went wrong with opening the file...";
    }
}

int main() {
    initiateFirstValues();

    auto start = std::chrono::high_resolution_clock::now();

    initiateSecondValues();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << endl;
    cout << (double) duration.count() / 1000 / 1000 << " seconds" << endl; //microseconds -> seconds

    return 0;
}