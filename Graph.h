#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Graph {
public:
    typedef struct {
        int first;
        int second;
        string mark;
    }edge;
    void construction(vector<string>);
    vector <edge> ans;

private:
    void klini(edge);
    void conjunction(string,string);
    void disjuction(string,string);
    int num_states;//,first_1,first_2,first_3,last_1,last_2,last_3,first_4,last_4;
    vector<pair<int,int>> num;

};



