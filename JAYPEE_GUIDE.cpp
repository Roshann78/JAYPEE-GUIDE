#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    pair<int, int> data;
    Node* next;

    Node(const pair<int, int>& value) : data(value), next(nullptr) {}
};
//QUEUE IMPLEMENTATION
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void push(const pair<int, int>& value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    pair<int, int> frontNode(){
        if (isEmpty()) {
            cout << "Queue is empty, no front element." << endl;
            return make_pair(-1, -1);
        }

        return front->data;
    }

    // Clear the queue by deallocating memory
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    ~Queue() {
        clear();
    }
};
class PriorityQueue1 // class to implement min priority queue
{
    vector<pair<int,int>> pq;

public:
    bool isEmpty() // checks if the priority queue is empty
    {
        return pq.size() == 0;
    }

    int getSize() // gives the size of priority queue
    {
        return pq.size();
    }

    pair<int,int> getMin() // find the minimum element from the priority queue
    {
        if (isEmpty())
        {
            return {0,-1};
        }

        return pq[0];
    }

    void insert(int dist,int element) // inserting element in a priority queue
    {
        pq.push_back({dist,element});

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex].first < pq[parentIndex].first)
            {
                auto temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else if(pq[childIndex].first == pq[parentIndex].first && pq[childIndex].second < pq[parentIndex].second ){
                auto temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    pair<int,int> removeMin() // removing minimum element from a priority queue
    {
        // Write your code here
        if (isEmpty())
            return {0,-1};
        int temp, minIndex;

        auto ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        // heap order property-down heapify

        while (leftChildIndex < pq.size()) // if left index is greater then right will be greater for sure
        {

            minIndex = parentIndex;
            if (pq[leftChildIndex].first < pq[minIndex].first)
            {
                minIndex = leftChildIndex;
            }
            if(pq[leftChildIndex].first == pq[minIndex].first && pq[leftChildIndex].second < pq[minIndex].second){
                minIndex=leftChildIndex;
            }
            if (rightChildIndex < pq.size() && pq[rightChildIndex].first < pq[minIndex].first)
            {
                minIndex = rightChildIndex;
            }
            else if(rightChildIndex < pq.size() && pq[rightChildIndex].first < pq[minIndex].first){
                minIndex=rightChildIndex;
            }
            if (minIndex == parentIndex)
                break;

            auto temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
};
//GRAPH IMPLEMENTATION
class graph{
public:
    unordered_map<int,list<pair<int,int>>>adjList;
    //node:{(nbr,wt)}
    //ADJACENCY MATRIX FORMATION
    void addEdge(int u,int v,int wt,bool direction,vector<vector<int>>&adjMatrix){

        //adjacencyMatrix[u][v] = wt;
        adjMatrix[u][v] = wt;
        if(direction==0){
            adjMatrix[v][u] = wt;
        }

    }
    //ADJACENCY LIST FORMATION
    void createAdjList(vector<vector<int>>&adjMatrix,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adjMatrix[i][j]){
                    adjList[i].push_back({j,adjMatrix[i][j]});
                }
            }
        }
    }
    //PRINTING THE ADJACENCY LIST
    void printAdjList(){
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto nbr:node.second){
                cout<<"("<<nbr.first<<","<<nbr.second<<") ";
            }
            cout<<endl;
        }
    }
    vector<int> dijkstraQueue(int S, int D, int V, map<int, string>& mapping)
    {
        // Queue-based implementation
        Queue q;
        vector<int> parent(V);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;
        q.push({0, S});

        // BFS-based shortest path algorithm
        while (!q.isEmpty())
        {
            auto topEle = q.frontNode();
            int node = topEle.second;
            int dis = topEle.first;
            q.pop();

            for (auto it : adjList[node])
            {
                int v = it.first;
                int w = it.second;

                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    q.push({dis + w, v});
                    parent[v] = node;
                }
            }
        }

        // Extracting the shortest path
        vector<pair<int, int>> path;
        int node = D;

        while (parent[node] != node)
        {
            path.push_back({node, distTo[node]});
            node = parent[node];
        }
        path.push_back({S, distTo[node]});
        reverse(path.begin(), path.end());

        // Displaying the shortest path in tabular format
        cout << "\n\n\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t          SHORTEST PATH (QUEUE)";
        cout << "\n\t\t\t\t\t\t===========================================\n\n";

        cout << "\t\t\t+---------------------------------------+\n";
        cout << "\t\t\t|  Step  |    Node    |    Distance     |\n";
        cout << "\t\t\t+---------------------------------------+\n";

        for (size_t i = 0; i < path.size(); i++)
        {
            cout << "\t\t\t|   " << setw(4) << i + 1 << "   |  "
                << setw(9) << mapping[path[i].first] << "   |     "
                << setw(8) << path[i].second << "|\n";
            cout << "\t\t\t+---------------------------------------+\n";
        }

        cout << "\n\t\t\t\t\t\t  Destination Reached\n";
        cout << "\t\t\t\t\t\t===========================================\n\n";

        // Displaying the path in vertical arrow format
        cout << "\t\t\t\t\t\t     PATH (VERTICAL FORMAT)\n";
        cout << "\t\t\t\t\t\t===========================================\n";
        for (size_t i = 0; i < path.size(); i++)
        {
            cout << "\t\t\t\t\t\t  " << mapping[path[i].first] << " (Distance: " << path[i].second << ")";
            if (i != path.size() - 1)
            {
                cout << "\n\t\t\t\t\t\t        |\n\t\t\t\t\t\t        \n";
            }
        }
        cout << "\n\t\t\t\t\t\t===========================================\n";

        return distTo;
    }

    //DIJKSTRA USING PRIORITY QUEUE
    vector<int> dijkstraPQ(int S, int D, int V, map<int, string>& mapping)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> parent(V);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;
        pq.push({0, S});

        // Dijkstra's Algorithm
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adjList[node])
            {
                int v = it.first;
                int w = it.second;

                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    parent[v] = node;
                    pq.push({dis + w, v});
                }
            }
        }

        // Extracting the shortest path
        vector<pair<int, int>> path;
        int node = D;

        while (parent[node] != node)
        {
            path.push_back({node, distTo[node]});
            node = parent[node];
        }
        path.push_back({S, distTo[node]});
        reverse(path.begin(), path.end());

        // Displaying the shortest path in tabular format
        cout << "\n\n\n\n\t\t\t\t\t\t===========================================";
        cout << "\n\t\t\t\t\t\t          SHORTEST PATH (PRIORITY QUEUE)";
        cout << "\n\t\t\t\t\t\t===========================================\n\n";

        cout << "\t\t\t+---------------------------------------+\n";
        cout << "\t\t\t|  Step  |    Node    |    Distance     |\n";
        cout << "\t\t\t+---------------------------------------+\n";

        for (size_t i = 0; i < path.size(); i++)
        {
            cout << "\t\t\t|   " << setw(4) << i + 1 << "   |  "
                << setw(9) << mapping[path[i].first] << "   |     "
                << setw(8) << path[i].second << "|\n";
            cout << "\t\t\t+---------------------------------------+\n";
        }

        cout << "\n\t\t\t\t\t\t  Destination Reached\n";
        cout << "\t\t\t\t\t\t===========================================\n\n";

        // Displaying the path in vertical arrow format
        cout << "\t\t\t\t\t\t     PATH (VERTICAL FORMAT)\n";
        cout << "\t\t\t\t\t\t===========================================\n";
        for (size_t i = 0; i < path.size(); i++)
        {
            cout << "\t\t\t\t\t\t  " << mapping[path[i].first] << " (Distance: " << path[i].second << ")";
            if (i != path.size() - 1)
            {
                cout << "\n\t\t\t\t\t\t        |\n\t\t\t\t\t\t        \n";
            }
        }
        cout << "\n\t\t\t\t\t\t===========================================\n";

        return distTo;
    }

};
void print1()
{
    system("Color 0A");
    cout<<"\n\n\n\t\t\t\t\t       WELCOME TO JAYPEE MAPS";
    cout<<"\n\n\t\t\t\t\t\t EXPLORE OUR CAMPUS";
    cout<<"\n\n\t\t\t\t\t\tFIND YOUR WAY AROUND";
    cout<<"\n\n\t\t\t\t\t\t DISCOVER MORE!!!";
//system("Color 0A");
    cout<<"\n\n\n\n\n\t\t\t\t Press 1 to continue\t\t Press 0 to exit";
    cout<<"\n\n\t\t\t\t\t\tENTER YOUR CHOICE:- ";
}

void print2(map<int,string>&mapping,string &src, string &dest)
{
    system("cls");
    system("Color 03");
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t LOCATION";
    int i=1;
    for(auto it: mapping)
    {
        cout<<"\n\t\t\t\t\t\t\t"<<i<<". "<<it.second;
        i++;
    }
    cout<<"\n\n\t\t\t\t\t\t ENTER YOUR CURRENT LOCATION";
    cout<<"\n\n\t\t\t\t\t\t\t";
    cin>>src;

    cout<<"\n\n\t\t\t\t\t\t ENTER YOUR DESTINATION";
    cout<<"\n\n\t\t\t\t\t\t\t";
    cin>>dest;

}

void print3(int &choice)
{
    system("cls");
    system("Color 03");

    cout<<"\n\n\n\n\t\t\t\t\t\t Tell Us How Do You want To Implement it";
    cout<<"\n\n\t\t\t\t\t\t\t 1. QUEUE";
    cout<<"\n\t\t\t\t\t\t\t 2. PRIORITY QUEUE";

    cout<<"\n\n\n\t\t\t\t\t\t Enter Your Choice:";

    cin>>choice;

}
int main(){

    graph g;
    int n=6;
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    //PUTTING ALL DATA SET INTO ADJ MATRIX
    g.addEdge(0,1,100,0,adjMatrix);
    g.addEdge(1,2,80,0,adjMatrix);
    g.addEdge(2,4,70,0,adjMatrix);
    g.addEdge(2,3,50,0,adjMatrix);
    g.addEdge(1,3,20,0,adjMatrix);
    g.addEdge(0,5,20,0,adjMatrix);
    g.addEdge(5,4,60,0,adjMatrix);
    g.addEdge(3,5,40,0,adjMatrix);
    g.addEdge(0,4,80,0,adjMatrix);
    //PUTTING DATA SET INTO ADJ LIST
    g.createAdjList(adjMatrix,n);


    g.printAdjList();

    //MAPPING FOR VARIOUS LOCATION OF COLLEGE
    map<int,string>mapping;
    mapping.insert({0,"Gate-1"});
    mapping.insert({1,"Gate-2"});
    mapping.insert({2,"Gate-3"});
    mapping.insert({4,"JBS"});
    mapping.insert({3,"ABB-1"});
    mapping.insert({5,"Cafe"});

    map<string,int>maping;
    maping.insert({"Gate-1",0});
    maping.insert({"Gate-2",1});
    maping.insert({"Gate-3",2});
    maping.insert({"JBS",4});
    maping.insert({"ABB-1",3});
    maping.insert({"Cafe",5});


    print1();
    int ch;
    cin>>ch;
    switch(ch)
    {

    case 1:  break;
    default: exit(0);
    }

    string s,d;

    print2(mapping,s,d);



    while((s!="Gate-1"&&s!="Gate-2"&&s!="Gate-3"&&s!="JBS"&&s!="ABB-1"&&s!="Cafe")||(d!="Gate-1"&&d!="Gate-2"&&d!="Gate-3"&&d!="JBS"&&d!="ABB-1"&&d!="Cafe"))
    {

        system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t INVALID LOCATION";
        cout<<"\n\n\t\t\t\t\t\t Press 1 to renter the choices\n\t\t\t\t\t\t Press 0 to exit";
        cout<<"\n\n\t\t\t\t\t\t\t      ";
        int cho;
        cin>>cho;
        switch(cho)
       {
          case 1:  print2(mapping,s,d);
                   break;

          default: exit(0);
       }

    }


    int choice;
    print3(choice);

    while(choice!=1 &&choice!=2 &&choice!=3 &&choice!=4 &&choice!=5 )
    {

        system("cls");
        cout<<"\n\n\n\n\n\n\t\t\t\t\t\t INVALID METHOD CHOICE";
        cout<<"\n\n\t\t\t\t\t\t Press 1 to renter the choices\n\t\t\t\t\t\t Press 0 to exit";
        cout<<"\n\n\t\t\t\t\t\t\t      ";
        int cho;
        cin>>cho;
        switch(cho)
       {
          case 1:  print3(choice);
                   break;

          default: exit(0);
       }

    }

    /*cout<<"Enter Source"<<endl;
    string s;
    cin>>s;

    cout<<"Enter Destination"<<endl;
    string d;
    cin>>d;*/
    vector<int>dist;
        switch(choice){
        case 1:  system("cls");
        dist=g.dijkstraQueue(maping[s],maping[d],n,mapping);

                system("Color 04");
                for(int i=0;i<n;i++){
                if(i==maping[d]){
                    cout<<"\n\n\t\t\t\t\tShortest Distance to reach "<<d<<" from "<<s<<" is: "<<dist[i];
                }
                cout<<endl;
                }
     break;
        case 2:system("cls");
            dist=g.dijkstraPQ(maping[s],maping[d],n,mapping);

    system("Color 06");
    for(int i=0;i<n;i++){
        if(i==maping[d]){
            cout<<"\n\n\t\tShortest Distance to reach "<<d<<" from "<<s<<" is: "<<dist[i];
        }
        cout<<endl;
    }
    break;
        default:
            cout<<"Thanks for visiting"<<endl;
        }
     cout<<"\n\n\t\t\t\t\t\t\tThanks for visiting"<<endl;
}
