#include <set>
#include "Graph.h"
void Graph::push_edge(int first, int second, string mark) {
    Graph::Edge tmp;
    tmp.first=first;
    tmp.second=second;
    tmp.mark=mark;
    ans.push_back(tmp);
}

void Graph:: disjuction(){
    pair<int,int> first_last;
    int flag_1=0,flag_2=0,flag_3=0,flag_4=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i].first ==num[num.size()-2].first && ans[i].second==num[num.size()-2].first)
            flag_1=1;
        if(ans[i].first ==num[num.size()-1].first && ans[i].second==num[num.size()-1].first)
            flag_2=1;
        if(ans[i].first ==num[num.size()-2].second && ans[i].second==num[num.size()-2].second)
            flag_3=1;
        if(ans[i].first ==num[num.size()-1].second && ans[i].second==num[num.size()-1].second)
            flag_4=1;
    }
    if(flag_1 || flag_2 ||flag_3 || flag_4){
        if(flag_1 == 1 && flag_2 !=1){
            push_edge(num[num.size()-1].first,num[num.size()-2].first,"E");
        }
        else if(flag_1 != 1 && flag_2 == 1){
            push_edge(num[num.size()-2].first,num[num.size()-1].first,"E");
        }
        else if(flag_1 == 1 && flag_2 ==1 ){
            push_edge(num_states,num[num.size()-2].first,"E");
            num[num.size()-2].first=num_states;
            push_edge(num_states,num[num.size()-1].first,"E");
            num_states++;
        }
        else{
            for(int i=0;i<ans.size();i++)
                if(ans[i].first == num[num.size()-1].first)
                    ans[i].first=num[num.size()-2].first;
        }
        if(flag_3 == 1 && flag_4 != 1){
            push_edge(num[num.size()-2].second,num[num.size()-1].second,"E");
            num[num.size()-2].second=num[num.size()-1].second;
        }
        else if(flag_3 != 1 && flag_4 == 1){
            push_edge(num[num.size()-1].second,num[num.size()-2].second,"E");
        }
        else if(flag_3 == 1 && flag_4 == 1){
            push_edge(num[num.size()-2].second,num_states,"E");
            push_edge(num[num.size()-1].second,num_states,"E");
            num[num.size()-2].second=num_states;
            num_states++;
        }
        else{
            for(int i=0;i<ans.size();i++)
                if(ans[i].second == num[num.size()-1].second)
                    ans[i].second=num[num.size()-2].second;
        }
        num.pop_back();
    }
    else{
        for(int i=0;i<ans.size();i++){
            if(ans[i].first == num[num.size()-1].first)
                ans[i].first=num[num.size()-2].first;
            if(ans[i].second == num[num.size()-1].second)
                ans[i].second=num[num.size()-2].second;
        }
        num.pop_back();
    }
}

void Graph::positive_iter(Edge test) {
    push_edge(test.second,test.first,"E");
}



void Graph:: klini(){ //Клини
    if(num[num.size()-1].first == num[num.size()-1].second-1) {
        ans[ans.size() - 1].first = ans[ans.size() - 1].second;
        num[num.size()-1].first=num[num.size()-1].second;
    }
    else
        push_edge(num[num.size()-1].second,num[num.size()-1].first,"E");
}


void Graph::conjunction(){  //умнож

    int flag=0;

    for(int i=0;i<ans.size();i++)
        if(ans[i].first == num[num.size()-2].second && ans[i].second == num[num.size()-2].second)
            flag=1;
    if(flag) {
        push_edge(num[num.size() - 2].second,num[num.size() - 1].first,"E");
        num[num.size() - 2].second = num[num.size() - 1].second;
        flag=0;
    }
    else{
        for(int i=0;i<ans.size();i++) {
            if (ans[i].first == num[num.size() - 2].second)
                ans[i].first = num[num.size() - 1].first;
            if (ans[i].second == num[num.size() - 2].second)
                ans[i].second = num[num.size() - 1].first;
        }
        num[num.size()-2].second=num[num.size()-1].second;
    }
    num.pop_back();

}




void Graph::construction(vector<string> path){
    string mark_1="None",mark_2="None";
    pair<int,int> first_last;
    Edge tmp;
    num_states=0;
    for(int i=0;i<path.size();i++){
        if(path[i] == "*"){                        //Клини
            klini();
        }
        else if(path[i] == "+"){
            if(num[num.size()-1].first == num[num.size()-1].second-1) {
                push_edge(num_states, num_states + 1, ans[ans.size() - 1].mark);
                first_last.first=num_states;
                first_last.second=num_states+1;
                num.push_back(first_last);
                num_states+=2;
                klini();
                conjunction();
            }
            else
                klini();
        }
        else if(path[i] == "|"){
            disjuction();
        }
        else if(path[i] == "."){
            conjunction();
        }
        else{
            push_edge(num_states,num_states+1,path[i]);
            first_last.first=num_states;
            first_last.second=num_states+1;
            num.push_back(first_last);
            num_states+=2;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<" "<<ans[i].mark<<endl;
        print(ans);
    }

}
void Graph::print(vector<Edge> path) {
    ofstream out;
    out.open("Graph.gv");
    out<<"digraph automate {"<<endl;
    out<<"rankdir=LR;"<<endl;
    out<<"size=\"8,5\";"<<endl;
    for(int i=0;i<path.size();i++){
        out<<"\""<<path[i].first<<"\""<<"->"<<"\""<<path[i].second<<"\""<<"[label = \""<<path[i].mark<<"\"];"<<endl;
    }
    out<<"}"<<endl;
    out.close();
}
