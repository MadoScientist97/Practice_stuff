#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class sea{
public:
    struct pos{
        int x;
        int y;    
        pos(){
            x = 0; y = 0;
        }
        pos(int a, int b) {
            x = a;
            y = b;
        }
        pos operator= (const pos& p){
            this->x = p.x;
            this->y = p.y;
        return (*this);
        }
    };
    int mapx=0,mapy=0;
    pos currentpos;
    vector<vector<int> > seamap;
    
    sea(vector<vector<int> > inmap){
        seamap = inmap;
        mapx = seamap.size();
        mapy = seamap[0].size();
    }
    
    pos up(pos p){
        return pos(p.x-1,p.y);
    }
    pos down(pos p){
        return pos(p.x+1,p.y);
    }
    pos right(pos p){
        return pos(p.x,p.y+1);
    }
    pos left(pos p){
        return pos(p.x,p.y-1);
    }
    pos uleft(pos p){
        return pos(p.x-1,p.y-1);
    }
    pos uright(pos p){
        return pos(p.x-1,p.y+1);
    }
    pos dleft(pos p){
        return pos(p.x+1,p.y-1);
    }
    pos dright(pos p){
        return pos(p.x+1,p.y+1);
    }
    
    bool isvalidpos(pos p){
        return (p.x>=0 && p.x<mapx && p.y>=0 && p.y<mapy);
    }

    void printSea(){
        cout<<"============================"<<endl;
        for (auto i = 0;i<mapx;i++){
            for (auto j = 0; j<mapy;j++){
                cout<<seamap[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void removeConnectedNeighbours(pos p){
        queue<pos> nbors;        
        nbors.push(p);
        pos temp;
        while (nbors.size()!=0) {
            currentpos = nbors.front();
            nbors.pop();
            temp = up(currentpos);
            if (isvalidpos(temp) && seamap[temp.x][temp.y]==1){
                nbors.push(temp);
                seamap[temp.x][temp.y] = 0;
            }
            temp = down(currentpos);          
            if (isvalidpos(temp) && seamap[temp.x][temp.y]==1){
                nbors.push(temp);
                seamap[temp.x][temp.y] = 0;
            }
            temp = left(currentpos);
            if (isvalidpos(temp) && seamap[temp.x][temp.y]==1){
                nbors.push(temp);
                seamap[temp.x][temp.y] = 0;
            }
            temp = right(currentpos);
            if (isvalidpos(temp) && seamap[temp.x][temp.y]==1){
                nbors.push(temp);
                seamap[temp.x][temp.y] = 0;
            }
            temp = uleft(currentpos);
            if (isvalidpos(temp) && seamap[temp.x][temp.y]==1){
                nbors.push(temp);
                seamap[temp.x][temp.y] = 0;
            }
            temp = uright(currentpos);
            if (isvalidpos(temp) && seamap[temp.x][temp.y]==1){
                nbors.push(temp);
                seamap[temp.x][temp.y] = 0;
            }
            temp = dleft(currentpos);
            if (isvalidpos(temp) && seamap[temp.x][temp.y]==1){
                nbors.push(temp);
                seamap[temp.x][temp.y] = 0;
            }
            temp = dright(currentpos);
            if (isvalidpos(temp) && seamap[temp.x][temp.y]==1){
                nbors.push(temp);
                seamap[temp.x][temp.y] = 0;
            }
        }
    }

    int getIslandCount(){
        int count=0;
        for (int i=0 ; i < mapx ; i++){
            for (int j=0; j < mapy ; j++){
                if (seamap[i][j] == 1) {
                    seamap[i][j] = 0;
                    count++;
                    cout<<"Count :"<<count<<endl;
                    pos *outerlooppos = new pos(i,j);
                    removeConnectedNeighbours(*outerlooppos);
                    }
                }
            }
        return count;
    }
};


int countIslands(vector<vector<int> > *smap){
    sea *s = new sea(*smap);
    return s->getIslandCount();
}

int main(){
    int row,col;
    while(true){
        cin>>row>>col;
        cin.ignore();
        if (row==0 || col == 0)
            cout<<"Row or column Size Cannot be zero try again!!"<<endl;
        else
            break; 
    }
    vector<vector<int> > seamap;
    for (int i=0;i<row;i++){
        vector<int> r;
        for (int j=0;j<col;j++){
            int temp;
            cin>>temp;
            r.push_back(temp);
        }
        seamap.push_back(r);
    }
    cout<<countIslands(&seamap);
    return 0;
}
