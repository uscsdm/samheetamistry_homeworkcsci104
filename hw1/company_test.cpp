//
//  company_test.cpp
//  csci104hw1
//
//  Created by Samheeta Mistry on 9/8/21.
//

#include "company.hpp"
#include "company.cpp"
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // test 1: all commands should work
    CompanyTracker* c = new CompanyTracker(6);
    c->merge(0,1);
    c->merge(2,3);
    c->merge(0,3);
    c->split(2);
    c->split(2);
    c->merge(2,4);
    c->split(0);
    return 0;
}
