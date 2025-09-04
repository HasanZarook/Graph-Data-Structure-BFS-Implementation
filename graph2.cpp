#include <string>
#include <fstream>
#include "LL.cpp"

#include <iostream>
#include "object.h"
using namespace::std;

using namespace std;
      
    
            
      
            
      class Graph
      {
         Linklist AdjList[50];   
int VCount,ECount;

         public:

               void buildGraph(string filename)
               {
VCount=0;
ECount=0;
                    ifstream in;
                    in.open("GraphMaze.txt");    //graph file name
                    
                    string vertexis;
                    // reading vertixes
                    getline(in,vertexis);    //it will read the file in sign the input to vertexis(v1 v2 v3 ... v50)
		   		cout<<vertexis<<endl;
string name;
                    while(vertexis.length()>0)
					{  
                    	int sep=vertexis.find(' ');   //in given range it will find the given character by its vlaue,if doesn't find it will give the last element of the range

		       			if(sep!=-1)
            			{	name=vertexis.substr(0,sep);   //substr has 2 parameters: pos,len   pos-substring start location, len-number of characters in substring
                			vertexis=vertexis.substr(sep+1,vertexis.length());
						}
		       			else							
		       			{
							name=vertexis;
		       				vertexis=vertexis.substr(0,0);}
cout<<sep<<" "<<vertexis<<" -- "<<name<<endl;
			
                       AdjList[VCount++].insertT(name);   //each itearte vcount increase from 
cout<<VCount<<endl;

			
					}
print();
             //reading edges


                  //  while(!in.eof())
for(int l=0;l<11;l++)
                    {

                        string s,d;
                        int weight;  // comment if unweighted graph

                        in>>s>>d>>weight;
ECount++;
//cout<<s<<" "<<d<<" "<<weight<<endl;

                        int loc =searchInAdjList(s);
	
			AdjList[loc].insertT(d);
  
                        loc =searchInAdjList(d);       // for undirected graphs 

			AdjList[loc].insertT(s);
        


//print();



                    }


                }
                
                              
        
                // just finding appropriate node to build the neighbour list
                int searchInAdjList(string node)
                {
                    for(int i=0;i<VCount;i++)
                       {
			
			string s=AdjList[i].get(0);
                          
                         if(s.compare(node)==0)
                                 return i; 
                        }
                }
                

                void print()
                {
                     for(int i=0;i<VCount;i++)
                       {
                            AdjList[i].print();
                        }
                 }
                 
            };
      
      
      int main()
      {
          Graph G;
//G.print();
G.buildGraph("");
        G.print();
          
      }
