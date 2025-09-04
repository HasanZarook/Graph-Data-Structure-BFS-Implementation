#include <string>
#include <fstream>
#include "linklist.h"

#include <iostream>
#include "object.h"
#include <map>

#include <queue>
using namespace::std;

using namespace std;
      
      class Neighbour:public object
      {
         public:
               string name;
               float distance;    
               Neighbour()
               {
                          }
               Neighbour(string d,float w)    //neighbour vertices
               {
                  name=d;
                  distance=w;    //yethnaavathu node aa irukkanum from source vertex      
               }
               
               void input()   //this input for neighbour vertex to any source
               {
               		cout<<"Enter the new neighbour vertex :"<<endl;
               		cin>>name;
               		cout<<"Enter the distance from source :"<<endl;
               		cin>>distance;
               }
               
               void print()
               {
                  cout<<" "<<name<<"  "<<distance<<"  ";  
                }
            };
      
      class Vertix:public object
      {
         public:
               string name;
               LL neighbourList;
               int noNbrs;
               string nbrName;
               float dist;
               bool done;
         public:               
               Vertix()
               { done=false; }
               
               Vertix(string n)    //source vertex
               {
                 name=n;
                 done=false;
               }
               
               void addNeighbour(string d, float weight)
               {
                    Neighbour* n=new Neighbour(d,weight); 
                    neighbourList.insert(n);                    
                }
               void input()  //input the new vertex
               {
			   		cout<<"Enter the new vertex :"<<endl;
					cin>>name;
					cout<<"How many neighbour vertex do u want to add :"<<endl;
					cin>>noNbrs;
					for(int i=0; i<noNbrs ; i++){
						cout<<"Enter the neighbour name :"<<endl;
						cin>>nbrName;
						cout<<"Enter the distance of neighbour :"<<endl;
						cin>>dist;
						addNeighbour(nbrName,dist);
					}	
			   
			   
			    }
               
               void print()
               {
                  cout<<" "<<name<<"  ";
                  neighbourList.print();  
                }
                
               string getName()
               {
                 return name;
               }

            };
            
            
            
      class Edge: public object
      {
      	public:
      		string Svert;
      		float dist;
      		
      		Edge(){
			  }
			  
			Edge(string Source,float distance){
				Svert=Source;
				dist=distance;
			}
            
            
            };
            
            
            
      class Graph
      {
         LL AdjList;
		 LL EdgList; 
         public:
               void buildGraph(string filename)
               {
                    ifstream in;
                    in.open("PTA.txt");    //graph file name
                    
                    string vertexis;
                    // reading vertixes
                    getline(in,vertexis);
		   			cout<<vertexis;

                    while(vertexis.length()>0)
//for(int i=0;i<11;i++)
                    {   Vertix * v;
                        int sep=vertexis.find(' ');

		       			if(sep!=-1)
                        {	v=new Vertix(vertexis.substr(0,sep));
                         	vertexis=vertexis.substr(sep+1,vertexis.length());}
		       			else
		       			{	v=new Vertix(vertexis);
		       				vertexis=vertexis.substr(0,0);}
			//cout<<v->getName()<<endl;

                        AdjList.insert(v);
			
		}
             //reading edges
AdjList.print();

                    while(!in.eof())
					//for(int i=0;i<10;i++)
                    {

                        string s,d;
                        int weight;  // comment if unweighted graph

                        in>>s>>d>>weight;

						cout<<s<<" "<<d<<" "<<weight<<endl;
//int I;
//cin>>I;
                        int loc =searchInAdjList(s);
//cout<<" "<<loc<<" "<<((Vertix*)AdjList.get(loc))->getName()<<endl;
                        ((Vertix*)AdjList.get(loc))->addNeighbour(d,weight); 
  
                        loc =searchInAdjList(d);       // for undirected graphs 
//cout<<" "<<loc<<" "<<((Vertix*)AdjList.get(loc))->getName()<<endl;
                        ((Vertix*)AdjList.get(loc))->addNeighbour(s,weight);
           				AdjList.print();

                    }

                }
                
                              
        
                // just finding appropriate node to build the neighbour list
                int searchInAdjList(string node)
                {
                    for(int i=0;i<AdjList.getLength()-1;i++)
                       {
                            Vertix * v=(Vertix*)AdjList.get(i);
                            if(v->getName().compare(node)==0)
                                 return i; 
                        }
                }
                
                void print()
                {
                     for(int i=0;i<AdjList.getLength()-1;i++)
                       {
                            Vertix * v=(Vertix*)AdjList.get(i);
                            v->print();
                        }
                 }
                 
                void BreadthFirstSearch(string startVertex, string endVertex) {
    
    				int startIdx = searchInAdjList(startVertex);
    				if (startIdx == -1) {
        			cout << "Start vertex not found in the graph." << endl;
        			return;
    				}
    				int endIdx = searchInAdjList(endVertex);
    				if (endIdx == -1) {
        			cout << "End vertex not found in the graph." << endl;
        			return;
    				}

    
    				queue<int> bfsQueue;

    				bfsQueue.push(startIdx);
    				Vertix* startVertix = static_cast<Vertix*>(AdjList.get(startIdx));
    				startVertix->done = true;

    				map<string, string> parentMap;
    				parentMap[startVertex] = "";

    				while (!bfsQueue.empty()) {
        				int currIdx = bfsQueue.front();
        				bfsQueue.pop();
        				Vertix* currVertix = static_cast<Vertix*>(AdjList.get(currIdx));

        			for (int i = 0; i < currVertix->neighbourList.getLength(); i++) {
            			Neighbour* neighbour = static_cast<Neighbour*>(currVertix->neighbourList.get(i));
            			int neighbourIdx = searchInAdjList(neighbour->name);
            			Vertix* neighbourVertix = static_cast<Vertix*>(AdjList.get(neighbourIdx));

            		if (!neighbourVertix->done) {
                		neighbourVertix->done = true;
                		bfsQueue.push(neighbourIdx);

                
                	parentMap[neighbour->name] = currVertix->name;
            }
        }
    }

    
    			if (parentMap.find(endVertex) == parentMap.end()) {
        			cout << "no path from the start to the end vertex." << endl;
    			}
			    else {
        			string currNode = endVertex;
        			cout << currNode;
        			while (currNode != startVertex) {
            		currNode = parentMap[currNode];
            		cout << " <------ " << currNode;
        		}
        		cout << endl;
    		}

    		for (int i = 0; i < AdjList.getLength(); i++) {
        		Vertix* v = static_cast<Vertix*>(AdjList.get(i));
        		v->done = false;
    		}
}                 
            };
      
      
      int main()
      {
        Graph G;
		G.buildGraph("");
			
      //  G.print();
        string s;
		string d;
    
	cout << "Enter the start vertex: "<<endl;
    cin >> s;
    cout << "Enter the final vertex: "<<endl;
    cin >> d;

    G.BreadthFirstSearch(s, d);
        
          return 0;
      }
