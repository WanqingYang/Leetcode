class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        row = vec2d.size();
        if(!row) {col = -1;}
        vec = vec2d;
    }

    int next() {
        if(j < col - 1) {
            j++;
            return vec[i][j-1];
        } /*else if(i != col-1 && j == col-1) {
            i++, j = 0;
            return vec[i-1][col-1];
        }*/
        i++, j = 0;
        return vec[i-1][col-1];
        
        /*if(j != 0 && j < col) { //within one row
            return vec[i][j-1];
        } else if(j == 0 && i > 0) { // the first element, not the first row
            int _size = vec[i-1].size();
            return vec[i-1][_size-1];
        } else { //first ele, first row
            
        }*/
    }

    bool hasNext() {
        if(col == -1) {return false;}
        col = vec[i].size();
        while (col == 0) {
            if(i < row) {
                i++;
                col = vec[i].size();
            } else {
                return false;
            }
        }
        if(i < row) {
            if(j < col) {
                return true;
            } else {
                return false;
            }
            /*if(j < col - 1) {
                //j++;
                return true;
            } else if(j == col-1) {
                //i++, j = 0;
                return true;
            } else { return false;}*/
        }
        return false;
    }
    
private:
    int row, col, i = 0, j = 0;
    vector<vector<int>> vec;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */