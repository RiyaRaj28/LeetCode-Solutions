class Solution {
public:


    int maxDistance(string str, int k)
    {
        int n = 0, s = 0, w = 0, e = 0, maxdis = 0; 

        for(int i=0; i<str.length(); i++)
        {
            if(str[i] == 'N') n++; 
            else if(str[i] == 'S') s++; 
            else if(str[i] == 'W') w++; 
            else if(str[i] == 'E') e++; 

             int vert = min({n, s, k}); 
            int horiz = min({w, e, k-vert}); 

            maxdis =  max(maxdis, count(n, s, vert) + count(e, w, horiz));
        }
        return maxdis; 

    }

    int count(int dis1, int dis2, int times)
    {
        return (abs(dis1-dis2) + 2*times);
    }
};

