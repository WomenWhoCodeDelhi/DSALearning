vector<int> parent;

// returns leader element of the set to which node a belongs
int find_set(int a) {   // worst case T.C = O(n)
    if(parent[a] == a) {
        return a;
    }
    return find_set(parent[a]); // <- bottleneck
}

// merges the sets of node a and b
void union_sets(int a, int b) {    // worst case T.C = O(n)
    int leader_a = find_set(a);
    int leader_b = find_set(b);
    if(leader_a != leader_b) {
        parent[leader_b] = leader_a; // <- bottleneck
    }
}

int main() {
    int n, e;
    cin>>n>>e;
    for(int node=0; node<=n; node++) {
        parent.push_back(node);
    }
    for(int i=1; i<=e; i++) {
        int a, b;
        cin>>a>>b;
        union_sets(a,b);
    }
    for(int i=1; i<=n; i++) {
        cout<<parent[i]<<" ";
    }
    int components = 0;
    // O(n) 
    for(int i=1;i<=n;i++){
        if(parent[i] == i) {
            components++;
        }
    }
    cout<<"\n"<<components<<"\n";
    // if node a is reachble from node b
    // O(1) time avg - for optimised impl of DSU
    
    return 0;
}
 
// Example input :
// 4 3
// 1 2
// 3 4
