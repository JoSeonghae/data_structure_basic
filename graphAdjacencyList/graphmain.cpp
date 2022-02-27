#include "graph.h"

/*
Graph is always traversed once at one level, 
so the low level elements(close to starting point) always enter 
into data structure(stack or queue) earlier(first in) than the higher level elements.

Queue is FIFO, so the low level is dequeued earlier than higher level elements.
It makes breadth first search possible.

Stack is LIFO, so the highest level element is popped the earliest.
It makes depth first search possible. 
*/

string bfsTraverse(Graph g){
  string result = "";
  bool visited[g.getVertices()];
  for(int i = 0; i < g.getVertices(); i++){
    visited[i] = false;
  }
  MyQueue queue;
  Node *temp;
  for(int i = 0; i < g.getVertices(); i++){
    if(!visited[i]){
      visited[i] = true;
      queue.enqueue(i);
      while(!queue.isEmpty()){
        result += (to_string(queue.getFront()) + "\n");
        temp = g.getArray()[queue.dequeue()].getHead();
        while(temp != nullptr){
          if(!visited[temp->data]){
            queue.enqueue(temp->data);
            visited[temp->data] = true;
          }
          temp = temp->nextElement;
        }
      }
    }
  }
  return result;
}

string dfsTraverse(Graph g){
  string result = "";
  return result;
}

int main(){
  Graph g(15);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(1,3);
  g.addEdge(1,4);
  g.addEdge(4,5);
  g.addEdge(4,6);
  g.addEdge(6,7);
  g.addEdge(2,8);
  g.addEdge(8,9);
  g.addEdge(8,10);
  g.addEdge(9,11);
  g.addEdge(9,12);
  g.addEdge(12,14);
  g.addEdge(10,13);
  cout << "BFS\n";
  cout << bfsTraverse(g) << "\n";
  cout << "DFS\n";
  // cout << dfsTraverse(g) << "\n";
}