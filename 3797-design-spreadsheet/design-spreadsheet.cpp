class Spreadsheet {
public:
vector<vector<int>> ss;
    Spreadsheet(int rows) {
        ss.resize(26,vector<int>(rows,0));
    }
    
    void setCell(string cell, int value) {
        int r=cell[0]-'A';
        int c=stoi(cell.substr(1));
        ss[r][c-1]=value;
    }
    
    void resetCell(string cell) {
        int r=cell[0]-'A';
        int c=stoi(cell.substr(1));
        ss[r][c-1]=0;
    }
    bool isvalid(string x){
        return (x[0]>='A'&&x[0]<='Z');
    }
    int getValue(string formula) {
        string x,y;
        int i=1;
        while(formula[i]!='+')
        x+=formula[i++];
        i++;
        while(i<formula.size())
        y+=formula[i++];
        int v1=0,v2=0;
        if(isvalid(x)){
            int r=x[0]-'A';
            int c=stoi(x.substr(1));
            v1=ss[r][c-1];
        }
        else v1=stoi(x);
        if(isvalid(y)){
            int r=y[0]-'A';
            int c=stoi(y.substr(1));
            v2=ss[r][c-1];
        }
        else v2=stoi(y);
        return v1+v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */