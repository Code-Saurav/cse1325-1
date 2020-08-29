#include <iostream>

using namespace std;

int main(){
    string name;
    cout << "Please enter your name \t";
    getline(cin,name);
    cout << "\nHello, "<<name <<"!\n";
    return 1;
}