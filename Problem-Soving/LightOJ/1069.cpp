void answer(){
    int myPosition, liftPosition; cin >> myPosition >> liftPosition;
    
    // (10) seconds for enter and exit in lift and (9) seconds for lift opening and closing
    int totalTime = 19;
    
    totalTime += (myPosition + max(myPosition, liftPosition) - min(myPosition, liftPosition)) * 4;
    
    cout << totalTime << endl;
}
