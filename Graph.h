#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class Graph {
public:
    struct Edge{
        int first;
        int second;
        string mark;
    };
    void construction(vector<string>);

    vector <Edge> ans;

private:
    void klini();
    void conjunction();
    void disjuction();
    void print(vector<Edge>);
    void dfa(vector<Edge>);
    int num_states;
    void push_edge(int,int,string);
    vector<pair<int,int>> num;
    vector<int> state_out;

};



