#include <iostream>
using namespace std;
int adj[20][20], n;
void create(int);
void bfs(int);
void dfs(int);

int main()
{
    int op;
    do
    {
        cout << "1.Create\n2.BFS\n3.DFS\n4.Exit\n";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Enter the number of nodes" << endl;
            cin >> n;
            create(n);
            break;
        case 2:
            bfs(n);
            break;
        case 3:
            dfs(n);
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid option" << endl;
        }
    } while (op <= 4);
    return 0;
}

void create(int n)
{
    int max, s, d, flag;
    cout << "0=>Undirected \t 1=>Directed\n";
    cin >> flag;
    if (flag == 0)
        max = n * (n - 1) / 2;
    else
        max = n * (n - 1);
    for (int i = 0; i < max; i++)
    {
        cout << "Enter the source and destination" << endl;
        cin >> s >> d;
        if (s == 0 && d == 0)
            break;
        adj[s][d] = 1;
        if (flag == 0)
            adj[d][s] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << "\t";
        }
        cout << endl;
    }
}

void bfs(int n)
{
    int q[20], front = 0, rear = 0, v, visited[20] = {0};
    cout << "Enter the starting vertex" << endl;
    cin >> v;
    visited[v] = 1;
    q[rear] = v;
    while (front <= rear)
    {
        cout << v << "\t";
        for (int i = 1; i <= n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                rear++;
                q[rear] = i;
                visited[i] = 1;
            }
        }
        front++;
        v = q[front];
        // cout << "front: " << front << "\trear: " << rear << endl;
    }
    cout << endl;
}
void dfs(int n)
{
    int st[20], top = 0, v, flag = 1, visited[20] = {0};
    cout << "Enter the starting vertex" << endl;
    cin >> v;
    visited[v] = 1;
    st[top] = v;
    while (top != -1)
    {
        if (flag == 1)
            cout << v << "\t";
        flag = 0;
        for (int i = 1; i <= n; i++)
        {
            // cout << adj[v][i] << "\t visited:" << visited[i] << endl;
            if ((adj[v][i] == 1) && (visited[i] == 0))
            {
                top += 1;
                st[top] = i;
                visited[i] = 1;
                v = i;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            v = st[top];
            top--;
        }
        // cout << "top: " << top << endl;
    }
    cout << endl;
}
