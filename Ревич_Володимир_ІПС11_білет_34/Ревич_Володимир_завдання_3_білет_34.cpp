#include <iostream>
using namespace std;

struct node{
    int num;
    node* next;
    
    node(){
        next = NULL;
    }
};

struct graph{
    node* arr[10];
    graph()							
	{
        for (int i = 0; i < 10; i++)
            arr[i] = NULL;
    }
};

graph matrixToGraph(int mtr[10][10]){
    graph graph1;
    node* tempLast;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (mtr[i][j] != 0)
            {
                node* temp;
                temp = new node;
                temp->num = j+1;
                
                if (!graph1.arr[i])
                    graph1.arr[i] = temp;
                else 
                    tempLast->next = temp;
                    
                tempLast = temp;   
            }
    return graph1;
}

//створює структуру суміжності для перевірки
void showStruct(graph graph1, int max){
    cout << "struct:" << endl;
    
    for (int i = 0; i < max; i++)
    {
        node* temp = graph1.arr[i];
        
        cout << "node: " << i+1 << " -> ";  
        while (temp)
        {
            cout << temp->num << "; ";
            temp = temp->next;
        }
        cout << endl;
    }
}
	
	
	int countHangingVertices(graph graph1, int max) {
  	  int hangingVertices = 0;
    
 	   for (int i = 0; i < max; i++) {
  	      node* temp = graph1.arr[i];
  	      int degree = 0;
        
   	     while (temp) {
     	       degree++;
     	       temp = temp->next;
    	    }
    	    
    	    if (degree == 1) {
    	        hangingVertices++;
   	    	}
  	  	}
    
    return hangingVertices;
}


int main(int argc, char** argv) {
    int mtrx1[10][10] = {
        {0,1,1,0,1,0,0,0,0},
        {1,0,0,0,1,0,0,0,0},
        {1,0,0,1,0,0,1,0,0},
        {0,0,1,0,0,0,0,0,0},
        {1,1,0,0,0,1,1,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,1,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };
    
    graph graph1;
    graph1 = matrixToGraph(mtrx1);
   
    showStruct(graph1, 10);
    
    cout<< endl << "Number of hanging vertices: " << countHangingVertices(graph1, 10) << endl;
    
    
    
    return 0;
}
