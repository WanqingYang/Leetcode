//using iterator
class Vector2D {
    vector<vector<int>> :: iterator i, iEnd;
    int j = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iEnd = vec2d.end();
    }
    
    int next() {
        return (*i)[j++];
    }
    
    bool hasNext() {
        while(i != iEnd && j == (*i).size()) {
            i++, j = 0;
        }
        return i != iEnd;
    }
    
};

//my right but slow code

/*class Vector2D {
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
        }
        i++, j = 0;
        return vec[i-1][col-1];
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