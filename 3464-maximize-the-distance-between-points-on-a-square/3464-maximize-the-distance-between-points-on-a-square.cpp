class Solution {
public:
    long long get1DPosition(vector<int>& point, int side) {
    long long x = point[0];
    long long y = point[1];

    if(y == 0){
        return x; // bottom edge
    } else if(x == side){
        return side + y; // right edge
    } else if(y == side){
        return 3LL * side - x; // top edge
    } else {
        return 4LL * side - y; // left edge
    }
}

bool check(vector<long long>& doubled, int n, int k, int side, long long mid) {
    long long perimeter = 4LL * side;

    for(int i=0; i<n; i++){
        int count = 1; // picked one point
        int idx = i;

        long long lastPostion = doubled[i];

        for(int j=2; j<=k; j++){
            long long target = lastPostion + mid;

            auto itr = lower_bound((begin(doubled) + idx + 1), (begin(doubled) + i + n), target);
            if(itr == (begin(doubled) + i + n)){
                break;
            }
            idx = itr - begin(doubled);
            lastPostion = doubled[idx];
            count++;
        }
        if(count == k && (doubled[i] + perimeter - doubled[idx]) >= mid){
            return true;
        }
    }
    return false;
}

int maxDistance(int side, vector<vector<int>>& points, int k) {
    int n = points.size();
    long long perimeter = 4LL * side;

    vector<long long> positions(n); // store the position of the points on the boundary of the square

    for(int i=0; i<n; i++){
        positions[i] = get1DPosition(points[i], side);
    }

    sort(positions.begin(), positions.end());

    // Doubles the positions to handle the circular nature of the problem
    vector<long long> doubledPositions(2 * n);
    for(int i=0; i<n; i++){
        doubledPositions[i] = positions[i];
        doubledPositions[i + n] = positions[i] + perimeter;
    }

    int low = 0;
    int high = 2 * side;
    
    int result = 0;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(check(doubledPositions, n, k, side, mid)){
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}       

};