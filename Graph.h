#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Graph {
public:
    class Edge{
    public:
        int first;
        int second;
        string mark;
    };

    void construction(vector<string> regexpr);
    vector<Edge> ans;

private:
    void klini(const Edge& target);
    void conjunction(const string& _first, const string& _second);
    void disjuction(const string&, const string&);
    int num_states;
    vector<pair<int,int>> num;

};



