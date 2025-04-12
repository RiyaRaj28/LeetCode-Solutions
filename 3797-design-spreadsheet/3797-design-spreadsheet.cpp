class Spreadsheet {
public:
    map<char, vector<int>> mpp;
    int rows;

    Spreadsheet(int rows) {
        this->rows = rows;
    }

    void setCell(string cells, int value) {
        char cell = cells[0];
        string cell_no; 
        for(int i=1; i<cells.size(); i++)
        {
            cell_no += cells[i]; 
        }
        int cell_num = stoi(cell_no); 

        if(mpp.find(cell) == mpp.end())  mpp[cell].resize(rows+1, 0); 
        mpp[cell][cell_num] = value; 
    }

    void resetCell(string cells) {
        char cell = cells[0];
        string cell_no; 

            for(int i=1; i<cells.size(); i++)
            {
                cell_no += cells[i]; 
            }
            int cell_num = stoi(cell_no); 

        if (mpp.find(cell) != mpp.end() && mpp[cell].size() > cell_num) { 
            mpp[cell][cell_num] = 0;  
        }

    }

    int getValue(string formula) {
        string first, second;
        int pind = 0;

        for (int i = 1; i < formula.length(); i++) {
            if (formula[i] != '+') first += formula[i];
            else {
                pind = i;
                break;
            }
        }

        for (int i = pind + 1; i < formula.length(); i++) {
            second += formula[i];
        }

        int fval = 0, sval = 0;
        if(isalpha(first[0]))
        {   
            char cell = first[0];
            string cell_no; 

            for(int i=1; i<first.size(); i++)
            {
                cell_no += first[i]; 
            }
            int cell_num = stoi(cell_no); 

            if (mpp.find(cell) != mpp.end() && mpp[cell].size() > cell_num)  
                fval = mpp[cell][cell_num];  
            else 
                fval = 0;      
        }
        else 
            fval = stoi(first);  
        
        // Convert second operand
        if(isalpha(second[0]))
            {
                char cell = second[0];
                string cell_no; 
            for(int i=1; i<second.size(); i++)
            {
                cell_no +=  second[i]; 
            }
            int cell_num = stoi(cell_no); 

                if (mpp.find(cell) != mpp.end() && mpp[cell].size() > cell_num)  
                    sval = mpp[cell][cell_num];  
                else sval = 0; 
        }
        else
            sval = stoi(second);

        return fval + sval;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */