#include <vector>
#include <string>
#include <iostream>
#include <fstream>


class Graph {
public:
    struct Edge{
        int first;
        int second;
        std::string mark;
    };

    explicit Graph() = delete;
    explicit Graph(std::vector<std::string> expr);

    // auto get

private:
    void klini();
    void conjunction();
    void disjuction();
    void print(std::vector<Graph::Edge>);
    void dfa(std::vector<Graph::Edge>);
    int num_states;
    void push_edge(int,int,std::string);

    std::vector<Edge> ans;
    std::vector<std::pair<int,int>> num;
    std::vector<int> state_out;

};



