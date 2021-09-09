//
// Created by Samheeta Mistry on 9/4/21.
//

#include <iostream>
#include <vector>
using namespace std;

void permutationsHelperFunc(string in, int startIndex, int endIndex) {
    if (startIndex == endIndex) {
        cout << in << endl;
    }
    else {
        for (int i = startIndex; i < endIndex; i++) {
            char temp = in[startIndex];
            in[startIndex] = in[i];
            in[i] = temp;
            permutationsHelperFunc(in, startIndex + 1, endIndex);
            char temp2 = in[i];
            in[i] = in[startIndex];
            in[startIndex] = temp2;
        }
    }
}

void permutations(string in) {
    permutationsHelperFunc(in, 0, (int)in.length());
}


