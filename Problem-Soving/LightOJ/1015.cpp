int totalDustUnits(int n, vector<int> &dustUnit) {
    int sum = 0;
    for(auto &u : dustUnit) sum += max(u, 0);
    return sum;
}
