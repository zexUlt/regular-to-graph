#include "Graph.h"

void Graph:: disjuction(const string& first, const string& second){
    Graph::Edge tmp;
    pair<int,int> first_last;
    int flag_1=0,flag_2=0,flag_3=0,flag_4=0;
    if(first != "None" && second!= "None"){
        tmp.first=num_states;
        tmp.second=num_states+1;
        tmp.mark=first;
        ans.push_back(tmp);
        tmp.first=num_states;
        tmp.second=num_states+1;
        tmp.mark=second;
        ans.push_back(tmp);
        num_states+=2;
        first_last.first=tmp.first;
        first_last.second=tmp.second;
        num.push_back(first_last);

    }
    else if(first != "None" && second== "None"){
        for(int i=0;i<ans.size();i++){
            if(ans[i].first ==num[num.size()-1].first && ans[i].second==num[num.size()-1].first)
                flag_1=1;
            if(ans[i].first ==num[num.size()-1].second && ans[i].second==num[num.size()-1].second)
                flag_2=1;
        }
        if(flag_1 || flag_2){
            if(flag_1 == 1 && flag_2 != 1){
                tmp.first=num_states;
                tmp.second=num[num.size()-1].first;
                tmp.mark="E";
                ans.push_back(tmp);
                num[num.size()-1].first=tmp.first;
                tmp.second=num[num.size()-1].second;
                tmp.mark=first;
                num_states++;
                ans.push_back(tmp);
            }
            else if(flag_1 != 1 && flag_2 == 1){
                tmp.first=num[num.size()-1].first;
                tmp.second=num_states;
                tmp.mark=first;
                ans.push_back(tmp);
                tmp.first=num[num.size()-1].second;
                tmp.mark="E";
                ans.push_back(tmp);
                num[num.size()-1].second=tmp.second;
                num_states++;
            }
            else{
                tmp.first=num_states;
                tmp.second=num[num.size()-1].first;
                tmp.mark="E";
                ans.push_back(tmp);
                tmp.second=num_states+1;
                tmp.mark=first;
                ans.push_back(tmp);
                tmp.first=num[num.size()-1].second;
                tmp.mark="E";
                ans.push_back(tmp);
                num[num.size()-1].first=num_states;
                num[num.size()-1].second=num_states+1;
                num_states+=2;
            }

        }
        else{
            tmp.first=num[num.size()-1].first;
            tmp.second=num[num.size()-1].second;
            tmp.mark=first;
            ans.push_back(tmp);
        }


    }
    else {
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
                tmp.first=num[num.size()-1].first;
                tmp.second=num[num.size()-2].first;
                tmp.mark="E";
                ans.push_back(tmp);
            }
            else if(flag_1 != 1 && flag_2 == 1){
                tmp.first=num[num.size()-2].first;
                tmp.second=num[num.size()-1].first;
                tmp.mark="E";
                ans.push_back(tmp);
            }
            else if(flag_1 == 1 && flag_2 ==1 ){
                tmp.first = num_states;
                tmp.second=num[num.size()-2].first;
                tmp.mark="E";
                ans.push_back(tmp);
                num[num.size()-2].first=tmp.first;
                tmp.second=num[num.size()-1].first;
                tmp.mark="E";
                num_states++;
                ans.push_back(tmp);
            }
            else{
                for(int i=0;i<ans.size();i++)
                    if(ans[i].first == num[num.size()-1].first)
                        ans[i].first=num[num.size()-2].first;
            }

            if(flag_3 == 1 && flag_4 != 1){
                tmp.first=num[num.size()-2].second;
                tmp.second=num[num.size()-1].second;
                tmp.mark="E";
                ans.push_back(tmp);
                num[num.size()-2].second=tmp.second;
            }
            else if(flag_3 != 1 && flag_4 == 1){
                tmp.first=num[num.size()-1].second;
                tmp.second=num[num.size()-2].second;
                tmp.mark="E";
                ans.push_back(tmp);

            }
            else if(flag_3 == 1 && flag_4 == 1){
                tmp.first=num[num.size()-2].second;
                tmp.second=num_states;
                tmp.mark="E";
                ans.push_back(tmp);
                tmp.first=num[num.size()-1].second;
                ans.push_back(tmp);
                num[num.size()-2].second=tmp.second;
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
}







void Graph::klini(const Edge& test){ //Клини
    Graph::Edge tmp;
    pair<int,int> first_last;
    if(test.mark != "None"){
        tmp.first=num_states;
        tmp.second=num_states;
        tmp.mark=test.mark;
        num_states++;
        ans.push_back(tmp);
        first_last.first=tmp.first;
        first_last.second=tmp.second;
        num.push_back(first_last);
    }
    else{
        tmp.first=test.second;
        tmp.second=test.first;
        tmp.mark="E";
        ans.push_back(tmp);
    }
}


void Graph::conjunction(const string& first, const string& second){  //умнож
    Graph::Edge tmp;
    pair<int,int> first_last;
    int flag=0;
    if(first != "None" && second != "None") {
        tmp.first = num_states;
        tmp.second = num_states + 1;
        tmp.mark = first;
        ans.push_back(tmp);
        num_states++;
        first_last.first = tmp.first;
        tmp.first = num_states;
        tmp.second = num_states + 1;
        tmp.mark = second;
        ans.push_back(tmp);
        num_states += 2;
        first_last.second = tmp.second;
        num.push_back(first_last);
    }

    else if(first != "None" && second == "None"){
        if(num[num.size()-1].first == num[num.size()-1].second){
            tmp.first=num[num.size()-1].first;
            for(int i=0;i<ans.size();i++){
                if(ans[i].first == num[num.size()-1].first)
                    ans[i].first=num_states;
                if(ans[i].second == num[num.size()-1].first)
                    ans[i].second=num_states;
            }
            tmp.second=num_states;
            tmp.mark=first;
            num[num.size()-1].second=num_states;
        }
        else {
            tmp.first = num[num.size() - 1].second;
            tmp.second = num_states;
            tmp.mark = first;
            num[num.size()-1].second=tmp.second;
        }

        ans.push_back(tmp);
        num_states++;
    }

    else{
        for(int i=0;i<ans.size();i++)
            if(ans[i].first == num[num.size()-2].second && ans[i].second == num[num.size()-2].second)
                flag=1;
        if(flag) {
            tmp.first = num[num.size() - 2].second;
            tmp.second = num[num.size() - 1].first;
            tmp.mark = "E";
            ans.push_back(tmp);
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
        }
        num.pop_back();
    }
}




void Graph::construction(vector<string> path){
    string mark_1="None",mark_2="None";
    pair<int,int> first_last;
    Edge tmp;
    num_states=0;
    for(int i=0;i<path.size();i++){
        if(path[i] == "*"){                         //Клини
            if(mark_1!="None" && mark_2 == "None"){
                tmp.mark=mark_1;
                klini(tmp);
                mark_1="None";
            }
            else if(mark_2 != "None"){
                tmp.mark=mark_2;
                klini(tmp);
                mark_2="None";
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
            if(mark_1 == "None")
                mark_1 = path[i];
            else
                mark_2 = path[i];
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<" "<<ans[i].mark<<endl;
    }

}