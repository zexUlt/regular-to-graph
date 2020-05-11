#include "Graph.h"

void Graph:: disjuction(const string& first, const string& second){
    Graph::Edge tmp;
    pair<int,int> first_last;
    if(first != "None" && second!= "None"){
        tmp.first=num[0].first;
        tmp.second=num[0].second;
        tmp.mark=first;
        ans.push_back(tmp);
        tmp.first=num[0].first;
        tmp.second=num[0].second;
        tmp.mark=second;
        ans.push_back(tmp);
        first_last.first=num[0].first;
        first_last.second=num[0].second;
        num.push_back(first_last);
        num[0].first=-1;
        num[0].second=-1;
        num[1].first=-1;
        num[1].second=-1;
    }
    else if(first != "None" && second== "None"){
        tmp.first = num[num.size()-1].first;
        tmp.second = num[num.size()-1].second;
        tmp.mark = first;
        ans.push_back(tmp);
        num[0].first=-1;
        num[0].second=-1;
    }
    else {
        for(int i = 0; i < ans.size(); i++) {
            if (ans[i].first == num[num.size()-1].first) {
                ans[i].first = num[num.size()-2].first;
            }
            if (ans[i].second == num[num.size()-1].first) {
                ans[i].second = num[num.size()-2].first;
            }
            if (ans[i].first == num[num.size()-1].second) {
                ans[i].first = num[num.size()-2].second;
            }
            if (ans[i].second == num[num.size()-1].second) {
                ans[i].second = num[num.size()-2].second;
            }
        }
        num.pop_back();
    }
}



void Graph::klini(const Edge& first_last){ //Клини
    Graph::Edge tmp;

    if(first_last.mark != "None"){
        tmp.first=first_last.first;
        tmp.second=first_last.second;
        tmp.mark=first_last.mark;
    }
    ans.push_back(tmp);

}


void Graph::conjunction(const string& first, const string& second){  //умнож
    Graph::Edge tmp;
    pair<int,int> first_last;
    if(first != "None" && second != "None") {
        if(num[0].first !=num[0].second) {
            tmp.first = num[0].first;
            tmp.second = num[1].first;
            tmp.mark = first;
            ans.push_back(tmp);
        }
        for(int i=0;i<ans.size();i++) {
            if (ans[i].first == num[0].second) {
                ans[i].first = num[1].first;
            }
            if (ans[i].second == num[0].second) {
                ans[i].second = num[1].first;
            }
        }
        if(num[1].first !=num[1].second) {
            tmp.first = num[1].first;
            tmp.second = num[1].second;
            tmp.mark = second;
            ans.push_back(tmp);
        }
        first_last.first =num[0].first;
        first_last.second=num[1].second;
        num.push_back(first_last);
        num[0].first=-1;
        num[0].second=-1;
        num[1].first=-1;
        num[1].second=-1;
    }

    else if(first != "None" && second == "None"){
        tmp.first =num[num.size()-1].second;
        tmp.second =num[0].second;
        tmp.mark = first;
        ans.push_back(tmp);
        num[num.size()-1].second=num[0].second;
        num[0].first=-1;
        num[0].second=-1;
    }
    else{
        for(int i=0;i<ans.size();i++){
            if(ans[i].first == num[num.size()-1].first ){
                ans[i].first=num[num.size()-2].second;
            }
            if(ans[i].second == num[num.size()-1].first ){
                ans[i].second=num[num.size()-2].second;
            }
        }
        num[num.size()-2].second=num[num.size()-1].second;
        num.pop_back();
    }
}




void Graph::construction(vector<string> path){
    string mark_1="None",mark_2="None";
    pair<int,int> first_last;
    Edge tmp;
    first_last.first=-1;
    first_last.second=-1;
    num.push_back(first_last);
    num.push_back(first_last);
    num_states=0;
    for(int i=0;i<path.size();i++){
        if(path[i] == "*"){                         //Клини
            if(mark_1!="None" && mark_2 == "None"){
                tmp.mark=mark_1;
                tmp.first=num[0].second;
                tmp.second=num[0].second;
                klini(tmp);
                num[0].first=num[0].second;
            }
            else if(mark_2 != "None"){
                tmp.mark=mark_2;
                tmp.first=num[1].first;
                tmp.second=num[1].first;
                klini(tmp);
                num[1].second=num[1].first;
            }
            else{
                tmp.mark="None";
                tmp.first=num[num.size()-1].first;
                tmp.second=num[num.size()-1].second;
                klini(tmp);
            }




        }
        else if(path[i] == "|"){
            disjuction(mark_1,mark_2);
            mark_1="None";
            mark_2="None";
        }
        else if(path[i] == "+"){
            conjunction(mark_1, mark_2);
            mark_1 = "None";
            mark_2 = "None";

        }
        else{
            if(mark_1 == "None") {
                mark_1 = path[i];
                num[0].first=num_states;
                num[0].second=num_states+1;
                num_states+=2;
            }

            else {
                mark_2 = path[i];
                num[1].first=num_states;
                num[1].second=num_states+1;
                num_states+=2;
            }

        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<" "<<ans[i].mark<<endl;

    }

}