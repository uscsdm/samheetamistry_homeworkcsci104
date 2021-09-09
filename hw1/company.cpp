//
//  company1.cpp
//  csci104hw1
//
//  Created by Samheeta Mistry on 9/8/21.
//

#include "company1.hpp"
#include <vector>
#include <typeinfo>
using namespace std;
// Initializes the tracker with n students and their 1-person companies.
CompanyTracker::CompanyTracker(int n)
{
    numCompanies = n;
    companies = new Company* [numCompanies];
    for (int i = 0; i < numCompanies; ++i)
        companies[i] = new Company ();
}

// Deallocates all dynamically allocated memory.
CompanyTracker::~CompanyTracker()
{
    for (int i = 0; i < numCompanies; ++i)
        delete companies[i];
    delete companies;
}

void CompanyTracker::merge(int i, int j)
{
    if (inSameCompany(i,j)) {
        return;
    }
    // each int is the index
    // do it recursively?
    // function will exit based on inSameCompany
    // create new company (should be 1 company? or "array" of 2?)
    // something happens where i = j
    // merge i and j? and then check condition

    Company** companyToMerge = new Company*[2];
    companyToMerge[0] = largestCompany(i);
    companyToMerge[1] = largestCompany(j);
    companies[i] = *companyToMerge;
    // how to get rid of companies[j]?
    for (int a = j; a < numCompanies-1; a++) {
        companies[a] = companies[a+1];
    }
//    delete [] companies[-1];
    numCompanies -=1;
}

void CompanyTracker::split(int i)
{
    if (i > numCompanies) {
        return;
    }
    if (tot > 1) {
        companies[-1] = &largestCompany(i)[1];
        companies[i] = &largestCompany(i)[0];
        numCompanies += 1;
    }
    else {
        return;
    }
}

bool CompanyTracker::inSameCompany(int i, int j)
{
    if (i < 0 || j < 0) {
        return false;
    }
    else if (i==j || largestCompany(i) == largestCompany(j)) {
        return true;
    }
    else if (i > numCompanies || j > numCompanies) {
        return false;
    }

    // how do we accommodate for the remaining control paths
}

Company* CompanyTracker::largestCompany(int i) {
    tot = 0;
    int max_tot = 0;
    for (int a = 0; a < numCompanies; a++) {
        if (a == i){
            while (companies[i]->parent != nullptr) {
                companies[i] = companies[i]->parent;
                tot += 1;
            }
        }
        if (tot > max_tot) {
            max_tot = i;
        }
    }
    return companies[max_tot];
}
//bool CompanyTracker::is_company(Company company) {
//    if (typeid(company) == typeid(*companies[0])) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//
//largest companies:
//
//int CompanyTracker::pointerSize(Company *company) {
//    int size = 0;
//    for (Company** pointer = &company; pointer != nullptr; pointer++){
//            size +=1;
//        }
//    return size;
//}
//int CompanyTracker::largestCompanyIndex(Company ** companies){
//    int largeSize = 0;
//    int index = 0;
//    // how TF do we access the number of subcompanies within one company-- parsing through company without knowing its size
//    for (int i = 0; i < numCompanies; i++) {
//        int compare = pointerSize(companies[i]);
//        if (compare > largeSize) {
//            largeSize = compare;
//            index = i;
//        }
//    }
//    return index;
//}


