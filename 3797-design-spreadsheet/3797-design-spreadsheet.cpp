class Spreadsheet {
public:
    map<char, vector<int>> mpp;
    int rows;

    Spreadsheet(int rows) {
        this->rows = rows;
    }

    void setCell(string cells, int value) {
        // for(const auto&[key, vec] : mpp)
        // {
        //     cout << "setcell" << "Cell: " << key << " -> Values: ";
        //     for(int num : vec )
        //     {
        //         cout << num << " "; 
        //     }
        //     cout << endl; 
        // }
        // // cout << "Size of mpp['O']: " << mpp['O'].size() << endl;
        // // if(mpp.find('O') != mpp.end() && mpp['O'].size() > 70) cout << "reset cell : " << mpp['O'][71] << endl; 
        // int cell_num = cells[1] - '0';

        char cell = cells[0];
        string cell_no; 
        for(int i=1; i<cells.size(); i++)
        {
            cell_no += cells[i]; 
        }
        int cell_num = stoi(cell_no); 

        // // Ensure the vector for this cell is initialized
        // if (mpp[cell].size() <= cell_num) {
        //     mpp[cell].resize(cell_num + 1, 0);  // Resize & initialize with 0
        // }

        // // mpp[cell][cell_num] = value;
        // mpp[cell].push_back(value);

        if(mpp.find(cell) == mpp.end())  mpp[cell].resize(rows+1, 0); 
        // cout << "cell : " << cell << " cell_num : " << cell_num << " value : " << value << endl; 

        mpp[cell][cell_num] = value; 



    }

    void resetCell(string cells) {
        // for(const auto&[key, vec] : mpp)
        // {
        //     cout << "resetcell" << "Cell: " << key << " -> Values: ";
        //     for(int num : vec )
        //     {
        //         cout << num << " "; 
        //     }
        //     cout << endl; 
        // }
        // cout << "Size of mpp['O']: " << mpp['O'].size() << endl;
        // if(mpp.find('O') != mpp.end() && mpp['O'].size() > 70) cout << "reset cell : " << mpp['O'][71] << endl; 
        char cell = cells[0];
        string cell_no; 

            for(int i=1; i<cells.size(); i++)
            {
                cell_no += cells[i]; 
            }
            int cell_num = stoi(cell_no); 

        // cout << " before : " << "cell : " << cell << " cell_num : " << cell_num " val : " << ; 

        if (mpp.find(cell) != mpp.end() && mpp[cell].size() > cell_num) { 
            mpp[cell][cell_num] = 0;  // Reset value to 0
        }

        cout << " after : " << "cell : " << cell << " cell_num : " << cell_num << endl; 
    }

    int getValue(string formula) {
        // for(const auto&[key, vec] : mpp)
        // {
        //     cout << "getval" << "Cell: " << key << " -> Values: ";
        //     for(int num : vec )
        //     {
        //         cout << num << " "; 
        //     }
        //     cout << endl; 
        // }
        // cout << "Size of mpp['O']: " << mpp['O'].size() << endl;
        // if(mpp.find('O') != mpp.end() && mpp['O'].size() > 70) cout << "reset cell : " << mpp['O'][71] << endl; 
        string first, second;
        int pind = 0;

        // Extract first operand
        for (int i = 1; i < formula.length(); i++) {
            if (formula[i] != '+') first += formula[i];
            else {
                pind = i;
                break;
            }
        }

        // Extract second operand
        for (int i = pind + 1; i < formula.length(); i++) {
            second += formula[i];
        }


        int fval = 0, sval = 0;

        // Convert first operand

        if(isalpha(first[0]))
        {   
            char cell = first[0];
            // int cell_num = first[1] - '0';
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
            fval = stoi(first);  // Convert char to int
        

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

        // cout << "first : " << first << ", second : " << second << ", fval : " << fval << ", sval : " << sval << endl;  
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