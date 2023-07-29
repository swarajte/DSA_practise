#include <bits/stdc++.h> 
using namespace std;

class graph{
    public:
        unordered_map<int,list<int>> adj;
        void addedge(int u,int v,bool direction){
            adj[u].push_back(v);
            // undirected graphs
            if(direction==0){
                adj[v].push_back(u);
            }
        }

        void Printedjlist(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }

        vector<int> BFS_traversal(int n,vector<int> adj[]){
            vector<int> bfs_vec;
            int visi[n]={0}; // 0 bases index if 1 based then visi[n+1]
            visi[0]=1;  //marking starting node as true;

            queue<int> q; //creating queue for pushing ad poping element

            q.push(0);// pushing starting node ka data

            while(!q.empty()){
                int frontnode=q.front();
                q.pop();
                bfs_vec.push_back(frontnode);

                // now check for neighbours of frontnode
                for(auto i:adj[frontnode]){
                    if(visi[i]!=1){  //if not visited 
                        visi[i]=1;  // marking them as visited now
                        q.push(i);
                    }
                }
            }

            return bfs_vec;
        }

        void DFS_traversal(int ind,vector<int> adj[],vector<bool> &visi,vector<int> &ans){
            visi[ind]=true;
            ans.push_back(ind);
            
        
    
        for(auto i:adj[ind]){
            if(!visi[i]){
                DFS_traversal(i,adj,visi,ans);
            }
        }
        
        }
};

int main()
{
    graph g;
    int n=0,m=0;
    cout<<"enter number of nodes"<<endl;
    cin>>n;
    // cout<<"enter number of edges"<<endl;
    // cin>>m;

    // cout<<"enter edge connected nodes in pair"<<endl;

    // for(int i=0; i<m; i++){
    //     int u,v;
    //     cin>>u>>v;
    //     g.addedge(u,v,0);
    // }

    // g.Printedjlist();

    vector<int> adjlist[n]={{},{2,6},{1,3,4},{2},{2,5},{4},{1,7,9},{6,8},{7},{6}};
    // vector<int> bfs_vec=g.BFS_traversal(n,adjlist);
    // cout<<"bfs tarversal : ";
    // for (int i = 0; i < bfs_vec.size(); i++)
    // {
    //     cout<<bfs_vec[i]<<" ";
    // }
    // cout<<endl;

    vector<bool> visi(n,false);

    vector<int> dfs_vec;
    g.DFS_traversal(0,adjlist,visi,dfs_vec);
    
    for (int i = 0; i < n; i++)
    {
      cout<<dfs_vec[i]<<" ";  
    }
    cout<<endl;
    return 0;
}