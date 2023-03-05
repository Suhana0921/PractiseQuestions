#include <iostream>
#include <queue>
using namespace std;
 
struct queueEntry {
    int v; // Vertex number
    int dist; // Distance of this vertex from source
};
 
int getMinDiceThrows(int move[], int N)
{

    bool* visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    queue<queueEntry> q;
 
    visited[0] = true;
    queueEntry s
        = { 0, 0 }; // distance of 0't vertex is also 0
    q.push(s); // Enqueue 0'th vertex

    queueEntry qe; // A queue entry (qe)
    while (!q.empty()) {
        qe = q.front();
        int v = qe.v; // vertex no. of queue entry
 
        if (v == N - 1)
            break;

        q.pop();
        for (int j = v + 1; j <= (v + 6) && j < N; ++j) {
            // If this cell is already visited, then ignore
            if (!visited[j]) {

                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;
 
                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }

    return qe.dist;
}
 
// Driver program to test methods of graph class
int main()
{
    // Let us construct the board given in above diagram
    int N = 30;
    int moves[N];
    for (int i = 0; i < N; i++)
        moves[i] = -1;
 
    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;
 
    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
 
    cout << "Min Dice throws required is "
         << getMinDiceThrows(moves, N);
    return 0;
}
