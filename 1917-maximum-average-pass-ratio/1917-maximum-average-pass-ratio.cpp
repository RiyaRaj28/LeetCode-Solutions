class Solution {
public:

    double solve(vector<vector<int>>& classes, int extraStudents, int ind, double total_ratio, double max_ratio, double n)
    {
        if(ind == n) return max_ratio; 

        double pass = classes[ind][0]; 
        double total = classes[ind][1]; 
        double old_ratio = static_cast<double>(pass)/total;

        double new_pass = pass + extraStudents; 
        double new_total = total + extraStudents; 
        double new_ratio = static_cast<double>(new_pass)/new_total; 


        double new_total_ratio = static_cast<double>((total_ratio*n - old_ratio + new_ratio)/n); 
        max_ratio = max(max_ratio, new_total_ratio); 

    return solve(classes, extraStudents, ind+1, total_ratio, max_ratio, n);

    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        // double total_ratio = 0; 
        // double n = classes.size(); 

        // for(int i=0; i<n; i++)
        // {
        //     double pass = classes[i][0];
        //     double total = classes[i][1]; 

        //     double ratio = static_cast<double>(pass)/total; 
        //     total_ratio += ratio; 
        // }

        // total_ratio = total_ratio/n; 

        // return solve(classes, extraStudents, 0, total_ratio, INT_MIN, n);

        // make a org_ratio and delta_ratio values arrays 
        // for whatever max value of delta that we get, we need to 
        // add the extra student to it and to its total 
        // do this until all maxstudents are not over 
        // then divide he ratio by n 

        double n = classes.size();

        // vector<double>delta(n); 
            priority_queue<pair<double, int>>pq; 

        // vector<double>delta(n); 

        for(int i=0; i<n; i++)
        {
            double curr_rat = (double)classes[i][0]/classes[i][1]; 
            double delta = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta_d = delta - curr_rat; 
            pq.push({delta_d, i}); 
        }

            // vector<double>updated(n);
            // for(int i=0; i<n; i++)
            // {
            //     double curr = (double)((classes[i][0]+1)/(classes[i][1] +1));    
            //     // updated[i] = curr; 
            //     pq.push({curr, i}); 
            // }

        while(extraStudents--)
        {
            int ind = pq.top().second;
            pq.pop();
            classes[ind][0]++; 
            classes[ind][1]++; 

            double curr_rat = (double)classes[ind][0]/classes[ind][1]; 
            double delta = (double)(classes[ind][0]+1)/(classes[ind][1]+1);
            double delta_d = delta - curr_rat; 
            pq.push({delta_d, ind}); 
        }
        double result = 0.0;
        for(int i=0; i<n; i++)
        {
            result += (double)classes[i][0]/classes[i][1];
        } 

        return result/n; 
    }
};