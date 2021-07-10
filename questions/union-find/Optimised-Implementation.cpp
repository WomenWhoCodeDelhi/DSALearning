vector<int> parent;
vector<int> Size;

// returns leader element of the set to which node a belongs
int find_set(int a) {     // average case T.C = O(1)
    if(parent[a] == a) {
        return a;
    }
    return parent[a] = find_set(parent[a]);  // PATH COMPRESSION (ensures next lookup are O(1) on average)
}

// merges the sets of node a and b
void union_sets(int a, int b) {     // average case T.C = O(1)
    int leader_a = find_set(a);
    int leader_b = find_set(b);
    if(leader_a != leader_b) {
        if(Size[leader_a] < Size[leader_b]) {     // UNION BY SIZE (prevents long chains in tree)
            swap(leader_a, leader_b);
        }
        parent[leader_b] = leader_a;
        Size[leader_a] += Size[leader_b];
    }
}

int main() {
    int n, e;
    cin>>n>>e;
    for(int node=0; node<=n; node++) {
        parent.push_back(node);
        Size.push_back(1);
    }
    for(int i=1; i<=e; i++) {
        int a, b;
        cin>>a>>b;
        union_sets(a,b);
    }
    cout<<"Parent array: ";
    for(int i=1; i<=n; i++) {
        cout<<parent[i]<<" ";
    }
    cout<<"\nSize array: ";
    for(int i=1; i<=n; i++) {
        cout<<Size[i]<<" ";
    }
    
    // O(V)
    int connectedComps = 0;
    for(int node=1; node<=n; node++) {
         if(parent[node] == node) {
             connectedComps++;
         }
    }
    cout<<"\n"<<connectedComps;
    return 0;
}
 
// Example Input :
// 4 3
// 1 2
// 3 4
