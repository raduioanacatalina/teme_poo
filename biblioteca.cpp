//
// Created by Catalina on 10.11.2020.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "biblioteca.h"

biblioteca::biblioteca() {
    std::cout<<"apel constructor" <<'\n';
}

void biblioteca::citire() {
    std::ifstream in("in.txt");
    int n; //n = nr carti
    in >> n;
    std::cout<<n<<'\n'; // nu citeste n, de ce?
    carte c;
    for (int i= 0; i < n; ++i){
        in >> c.nume >> c.id;
        nr_carti.push_back(c);
    }
}
void biblioteca::afisare() {
    for (auto & i : nr_carti) {
        std::cout<<i.nume<<" "<<i.id<<'\n';
    }
}
void biblioteca::sortare_id() {
    std::sort(nr_carti.begin(), nr_carti.end(), [](const carte &a, const carte &b) { return a.id < b.id; });
    std::cout<<"Sortare dupa id"<<'\n';
    for (auto& i : nr_carti)
        std::cout<<i.id<<" "<<'\n';
}

std::ostream& operator << (std::ostream& out, biblioteca& b)
{
    out<<"nr carti: " << b.nr_carti.size();
    return out;
}