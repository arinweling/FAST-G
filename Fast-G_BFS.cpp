#include<iostream>
#include<list>
using namespace std ;
class Node{
    public:
    int layer=0;
    int node_name;


};
void bfs(int root_node,list<int> adj_list[],int Discovered[],int layer,Node layer_array[],int counter);
void displayAdjList(list<int> adj_list[], int v) {
   for(int i = 0; i<v; i++) {
      cout << i << "--->";
      list<int> :: iterator it;
      for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
         cout << *it << " ";
      }
      cout << endl;
   }
}

void add_edge(list<int> adj_list[], int u, int v) {    //add v into the list u, and u into list v
   adj_list[u].push_back(v);
   adj_list[v].push_back(u);
}

int main(){
    int v;
    int root_node;
    int layer=0;
    int counter=0;
    
    cout<<"Enter number of vertices: \n";
    cin>>v;
    Node layer_array[v];
    
    
    
        
    int Discovered[v]={0};
    list<int> adj_list[v];
    string answer="Y";
    while(answer=="Y"){
        
        
        cout<<"Enter vertex1 and vertex2 \n";
        int vertex1,vertex2;
        cin>>vertex1;
        cin>>vertex2;
        add_edge(adj_list,vertex1,vertex2);
        cout<<"Enter new edge?(Y/N)";
        cin>>answer;
        

    }
       
   displayAdjList(adj_list, v);
   cout<<"\n Enter the root node for breadth first search: \n";
   cin>>root_node;
   layer_array[root_node].layer=v+1;
   int root=root_node;
   bfs(root_node,adj_list,Discovered,layer,layer_array,counter);
   for(int i=0;i<v;i++){
    if(i!=root){
        if((layer_array[i].layer)!=0){
        cout<<i<<" found in layer "<<(layer_array[i].layer)<<"\n";
        }
        else{
            cout<<i<<" not found in bfs tree \n";
        }
   }
   else{
    cout<<i<<" found in layer "<<"0\n";
   }
   }
}
void bfs(int root_node,list<int> adj_list[],int Discovered[],int layer,Node layer_array[],int counter){
    // Discovered[root_node]=1;
    // layer_array[counter]=root_node;


    list<int> :: iterator it;
      for(it = adj_list[root_node].begin(); it != adj_list[root_node].end(); ++it) {
        if((layer_array[*it].layer)==0){
            layer_array[*it].layer=layer+1;
            
            }

      }
      for(it = adj_list[root_node].begin(); it != adj_list[root_node].end(); ++it){
        if((layer_array[*it].layer)==(layer+1)){
            bfs(*it,adj_list,Discovered,layer+1,layer_array,counter);

            
        }

      }

      
      return;




}
