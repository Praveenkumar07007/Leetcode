class Solution {
public:
    static bool comparing(vector<int>& a,vector<int>& b) {
    return a[0] < b[0]; 
}
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end(), comparing);
        int max=0,i=0,temp=0,index=0;
        while(max<carpetLen && i<tiles.size()){
            temp+=tiles[i][1]-tiles[i][0]+1;
            while(tiles[i][1]-tiles[index][1]+1>carpetLen && index<i){
                temp-=tiles[index][1]-tiles[index][0]+1;
                index++;
            }
            if(tiles[i][1]-tiles[index][0]+1>carpetLen && index!=i){
                if(max<temp-(tiles[i][1]-tiles[index][0]+1-carpetLen)){
                    max=temp-(tiles[i][1]-tiles[index][0]+1-carpetLen);
                }
            }
            else if(temp>max)
                max=temp;
            i++;
        }
        if(max>carpetLen)
            return carpetLen;
        else
            return max;
    }
};

