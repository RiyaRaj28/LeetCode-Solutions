class Spreadsheet {
public:
    // map<char, vector<int>> mpp;
    // int rows;

    vector<vector<int>>spr; 

    Spreadsheet(int rows) {
        spr = vector<vector<int>>(rows+1, vector<int>(26)); 
        
    }

    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        // string cell_no; 
        // for(int i=1; i<cells.size(); i++)
        // {
        //     cell_no += cells[i]; 
        // }
        // int cell_num = stoi(cell_no); 

        int row = stoi(cell.substr(1)); 
        spr[row][col] = value; 

        // if(mpp.find(cell) == mpp.end())  mpp[cell].resize(rows+1, 0); 
        // mpp[cell][cell_num] = value; 
    }

    void resetCell(string cell) {
        // int col = cell[0] - 'A';
        // string cell_no; 

        //     for(int i=1; i<cells.size(); i++)
        //     {
        //         cell_no += cells[i]; 
        //     }
        //     int cell_num = stoi(cell_no); 
        // int row = stoi(cell.substr(1)); 


        // if (mpp.find(cell) != mpp.end() && mpp[cell].size() > cell_num) { 
        //     mpp[cell][cell_num] = 0;  
        // }

        setCell(cell, 0); 
    }

    int get_val(string cell)
    {
        if(isdigit(cell[0])) return stoi(cell); 

        int col = cell[0] - 'A'; 
        int row = stoi(cell.substr(1)); 

        return spr[row][col]; 
    }

    int getValue(string formula) {
        // string first, second;
        // int pind = 0;

        // for (int i = 1; i < formula.length(); i++) {
        //     if (formula[i] != '+') first += formula[i];
        //     else {
        //         pind = i;
        //         break;
        //     }
        // }

        // for (int i = pind + 1; i < formula.length(); i++) {
        //     second += formula[i];
        // }

        // int fval = 0, sval = 0;
        // if(isalpha(first[0]))
        // {   
        //     char cell = first[0];
        //     string cell_no; 

        //     for(int i=1; i<first.size(); i++)
        //     {
        //         cell_no += first[i]; 
        //     }
        //     int cell_num = stoi(cell_no); 

        //     if (mpp.find(cell) != mpp.end() && mpp[cell].size() > cell_num)  
        //         fval = mpp[cell][cell_num];  
        //     else 
        //         fval = 0;      
        // }
        // else 
        //     fval = stoi(first);  
        
        // // Convert second operand
        // if(isalpha(second[0]))
        //     {
        //         char cell = second[0];
        //         string cell_no; 
        //     for(int i=1; i<second.size(); i++)
        //     {
        //         cell_no +=  second[i]; 
        //     }
        //     int cell_num = stoi(cell_no); 

        //         if (mpp.find(cell) != mpp.end() && mpp[cell].size() > cell_num)  
        //             sval = mpp[cell][cell_num];  
        //         else sval = 0; 
        // }
        // else
        //     sval = stoi(second);

        // return fval + sval;

        formula = formula.substr(1); 
        int plus_ind = formula.find('+'); 

        return get_val(formula.substr(0, plus_ind)) + get_val(formula.substr(plus_ind+1)); 



    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */