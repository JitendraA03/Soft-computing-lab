#include <bits/stdc++.h>
using namespace std;

void water_jug_bfs(int j1, int j2, int cap){
    queue<pair<int, int>> q;
    set<pair<int, int>> st;
    q.push({0, 0});
    st.insert({0, 0});
    while (!q.empty()){
        auto state = q.front();
        q.pop();
        int c1 = state.first, c2 = state.second;
        cout << c1 << "," << c2 << " --> ";
        if ((c1 == 0 && c2 == cap) || (c1 == cap && c2 == 0)){
            break;
        }

        if (st.find({0, c2}) == st.end()){
            q.push({0, c2});
            st.insert({0, c2});
        }
        if (st.find({c1, 0}) == st.end()){
            q.push({c1, 0});
            st.insert({c1, 0});
        }
        if (st.find({j1, c2}) == st.end()){
            q.push({j1, c2});
            st.insert({j1, c2});
        }
        if (st.find({c1, j2}) == st.end()){
            q.push({c1, j2});
            st.insert({c1, j2});
        }

        int tf1 = min(j1, c1 + c2);
        int tf2 = max(0, (c1 + c2) - j1);
        if (st.find({tf1, tf2}) == st.end()){
            q.push({tf1, tf2});
            st.insert({tf1, tf2});
        }

        tf1 = max((c1 + c2) - j2, 0);
        tf2 = min(j2, (c1 + c2));
        if (st.find({tf1, tf2}) == st.end()){
            q.push({tf1, tf2});
            st.insert({tf1, tf2});
        }
    }
}

void water_jug_dfs(int j1, int j2, int cap, int c1, int c2, set<pair<int, int>> &st, bool &done){
    if (done)
        return;
    cout << c1 << "," << c2 << " --> ";
    st.insert({c1, c2});
    if ((c1 == 0 && c2 == cap) || (c1 == cap && c2 == 0)){
        done = true;
        return;
    }

    if (st.find({0, c2}) == st.end()){
        water_jug_dfs(j1, j2, cap, 0, c2, st, done);
    }
    if (st.find({c1, 0}) == st.end()){
        water_jug_dfs(j1, j2, cap, c1, 0, st, done);
    }
    if (st.find({j1, c2}) == st.end()){
        water_jug_dfs(j1, j2, cap, j1, c2, st, done);
    }
    if (st.find({c1, j2}) == st.end()){
        water_jug_dfs(j1, j2, cap, c1, j2, st, done);
    }

    int tf1 = min(j1, c1 + c2);
    int tf2 = max(0, (c1 + c2) - j1);
    if (st.find({tf1, tf2}) == st.end()){
        water_jug_dfs(j1, j2, cap, tf1, tf2, st, done);
    }

    tf1 = max((c1 + c2) - j2, 0);
    tf2 = min(j2, (c1 + c2));
    if (st.find({tf1, tf2}) == st.end()){
        water_jug_dfs(j1, j2, cap, tf1, tf2, st, done);
    }
}

void sample_space(int j1, int j2, int cap){
    queue<pair<int, int>> q;
    set<pair<int, int>> st;
    q.push({0, 0});
    st.insert({0, 0});
    while (!q.empty()){
        int n = q.size();
        for(int i =0; i<n; i++){
            auto state = q.front();
            q.pop();
            int c1 = state.first, c2 = state.second;
            cout << c1 << "," << c2 << "       ";
            if ((c1 == 0 && c2 == cap) || (c1 == cap && c2 == 0)){
                break;
            }

            if (st.find({0, c2}) == st.end()){
                q.push({0, c2});
                st.insert({0, c2});
            }
            if (st.find({c1, 0}) == st.end()){
                q.push({c1, 0});
                st.insert({c1, 0});
            }
            if (st.find({j1, c2}) == st.end()){
                q.push({j1, c2});
                st.insert({j1, c2});
            }
            if (st.find({c1, j2}) == st.end()){
                q.push({c1, j2});
                st.insert({c1, j2});
            }

            int tf1 = min(j1, c1 + c2);
            int tf2 = max(0, (c1 + c2) - j1);
            if (st.find({tf1, tf2}) == st.end()){
                q.push({tf1, tf2});
                st.insert({tf1, tf2});
            }

            tf1 = max((c1 + c2) - j2, 0);
            tf2 = min(j2, (c1 + c2));
            if (st.find({tf1, tf2}) == st.end()){
                q.push({tf1, tf2});
                st.insert({tf1, tf2});
            }
        }
        cout<<"\n";
    }
}
void water_jug_limited_dfs(int j1, int j2, int cap, int c1, int c2, set<pair<int, int>> &st, bool &done, int limit){
    if (done)
        return;
    if(limit < 0){
        cout<<"Can't find from this branch\n";
        return;
    }

    cout << c1 << "," << c2 << " --> ";
    st.insert({c1, c2});
    if ((c1 == 0 && c2 == cap) || (c1 == cap && c2 == 0)){
        done = true;
        return;
    }

    if (st.find({0, c2}) == st.end()){
        water_jug_limited_dfs(j1, j2, cap, 0, c2, st, done, limit - 1);
    }
    if (st.find({c1, 0}) == st.end()){
        water_jug_limited_dfs(j1, j2, cap, c1, 0, st, done, limit - 1);
    }
    if (st.find({j1, c2}) == st.end()){
        water_jug_limited_dfs(j1, j2, cap, j1, c2, st, done, limit - 1);
    }
    if (st.find({c1, j2}) == st.end()){
        water_jug_limited_dfs(j1, j2, cap, c1, j2, st, done, limit - 1);
    }

    int tf1 = min(j1, c1 + c2);
    int tf2 = max(0, (c1 + c2) - j1);
    if (st.find({tf1, tf2}) == st.end()){
        water_jug_limited_dfs(j1, j2, cap, tf1, tf2, st, done, limit - 1);
    }

    tf1 = max((c1 + c2) - j2, 0);
    tf2 = min(j2, (c1 + c2));
    if (st.find({tf1, tf2}) == st.end()){
        water_jug_limited_dfs(j1, j2, cap, tf1, tf2, st, done, limit - 1);
    }
}

int main(){
    set<pair<int, int>> st;
    bool done = false;

    sample_space(4,3,2);

    cout<<"\n\nBFS traversal to solution is : ";
    water_jug_bfs(4, 3, 2);
    cout<<"\n\nDFS traversal to solution is : ";
    st.clear();
    water_jug_dfs(4,3,2,0,0,st,done);
    cout<<"\n\n";
    done = false;
    st.clear();
    cout<<"\n\nDepth limited traversal to solution is : ";
    water_jug_limited_dfs(4,3,2,0,0,st,done, 7);
    cout<<"\n\n";

    cout<<"\n\nIterative deepning solution : ";
    int dep = 1;
    done = false;
    while(true && !done){
        st.clear();
        // cout<<"\n\nDepth limited traversal to solution is : ";
        water_jug_limited_dfs(4,3,2,0,0,st,done, dep);
        cout<<"\n";
        dep++;
    }
    


    return 0;
}