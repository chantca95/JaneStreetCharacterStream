//
//  main.cpp
//  JaneStreetCharacterStream
//
//  Created by Alex Chan on 5/13/23.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string next;
    string chars;
    while (true) {
        cin >> next;
        if (next == "end") {
            break;
        }
        if (next.size() > 1) {
            cout << "Enter characters one at a time" << endl;
        } else {
            chars += next[0];
        }
    }
    cout << chars << endl;
    
    return 0;
}
