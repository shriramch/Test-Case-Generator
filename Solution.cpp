# include <bits/stdc++.h>

using namespace std;

class City
{
    int n, m, inf;
    vector <vector <int> > dis;
public:
    City();
    City(int, int);
    void setDis(vector <string>&);
    void solve();
    void printDis();
};

City :: City()
{}

City :: City(int N, int M)
{
    n = N;
    m = M;
    inf = 1000000007;
    dis.resize(n);
    for(int i = 0; i < n; i++)
        dis[i].assign(m, inf);
}

void City :: setDis(vector <string> &s)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(s[i][j] == 'H')
                dis[i][j] = 0;
}

void City :: solve()
{
    priority_queue <pair <int, pair <int, int> >, vector <pair <int, pair <int, int> > >, greater <pair <int, pair <int, int> > > > pq;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(dis[i][j] == 0)
                pq.push(make_pair(0, make_pair(i, j)));
    while(!pq.empty())
    {
        auto x = pq.top();
        pq.pop();
        int curr_dis = x.first, i = x.second.first, j = x.second.second;
        if(i != 0)
        {
            if(dis[i - 1][j] > curr_dis + 1)
            {
                dis[i - 1][j] = curr_dis + 1;
                pq.push(make_pair(dis[i - 1][j], make_pair(i - 1, j)));
            }
        }
        if(i != n - 1)
        {
            if(dis[i + 1][j] > curr_dis + 1)
            {
                dis[i + 1][j] = curr_dis + 1;
                pq.push(make_pair(dis[i + 1][j], make_pair(i + 1, j)));
            }
        }
        if(j != 0)
        {
            if(dis[i][j - 1] > curr_dis + 1)
            {
                dis[i][j - 1] = curr_dis + 1;
                pq.push(make_pair(dis[i][j - 1], make_pair(i, j - 1)));
            }
        }
        if(j != m - 1)
        {
            if(dis[i][j + 1] > curr_dis + 1)
            {
                dis[i][j + 1] = curr_dis + 1;
                pq.push(make_pair(dis[i][j + 1], make_pair(i, j + 1)));
            }
        }
    }
}

void City :: printDis()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << dis[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        City c1(n, m);
        vector <string> s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        c1.setDis(s);
        c1.solve();
        c1.printDis();
    }
    return 0;
}